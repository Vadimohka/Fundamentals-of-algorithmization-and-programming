#include "graph.h"
#include <QDebug>
#include <QLine>

Graph::Graph(int LevelNum) {
    levelNum=LevelNum;
    sizeCoordinate=0;
    player =  new Player(100,5,0);
    int x=0,y=0,size=0,sy=0,sx=0;

    QPixmap pixmap(":/new/prefix1/prefix1/ForGraphViewBackGroung.jpeg");
    QPixmap scaledPixmap = pixmap.scaled(1200, 1000, Qt::KeepAspectRatio);
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(scaledPixmap);
    this->addItem(pixmapItem);


    for(int i = 0 ;i <levelNum;i++)
    {
        sizeCoordinate+=2;
        int a= MonteCarlo::monteCarlo(20,40);
        y =  i*25-a*3+250;
        x = 100*(i%4)+a*3+250;
        size = 20;
        if(i+1==levelNum)
            size=40;

        GamePoint *p= new GamePoint(x,y,size);
        GameScene *gamsc= new GameScene();
        p->getGameScene(gamsc);
        // if((i>0&&i<4) ||i==4||i==6 || i==9||i==11 ){
        //     p->getDifficulty(StartT);
        //     p->getType(StartT);
        // }
        // if(i==8||i==10 ||(i>11&&i<16)){
        //     p->getDifficulty(DefaultT);
        //     p->getType(DefaultT);
        // }
        // if(i==5||i==7 ||(i>15&&i<20)){
        //     p->getDifficulty(RestT);
        //     p->getType(RestT);
        // }
        // if(i==20){
        //     p->getDifficulty(BossT);
        //     p->getType(BossT);
        // }
        if(i>=0&&i<8){
            p->getDifficulty(StartT);
            p->getType(StartT);
        }
        if((i>11&&i<16) ||(i>15&&i<20)||(i>7&&i<12)){
            p->getDifficulty(DefaultT);
            p->getType(DefaultT);
        }

        if(i==20){
            p->getDifficulty(BossT);
            p->getType(BossT);
        }

        GamePointsVec.push_back(p);

        if(i>3)
            GamePointsVec[i]->doUnActiv();
        else
            GamePointsVec[i]->doActiv();

        connect(this, &Graph::ClickChangeColor,GamePointsVec[i], &GamePoint::changeBorderColor );
        connect(GamePointsVec[i],&GamePoint::clickSignal,this,&Graph::takeClick);


        //addLine(x+size/2,y+size/2,sx,sy);
        sx=x+size/2;
        sy=y+size/2;
        coordinate.push_back(sx);
        coordinate.push_back(sy);
    }

    for(int i =4; i<levelNum-1;i+=4)
    {
        GamePointsVec[i/4*4+MonteCarlo::monteCarlo(0,3)]->getDifficulty(RestT);
        GamePointsVec[i/4*4+MonteCarlo::monteCarlo(0,3)]->getType(RestT);
    }
    generateMatrix();

    coordinate.push_back(x+size/2);
    coordinate.push_back(y+size/2);

    for(int i =0 ;i <levelNum;i++)
    {
        for(int j = 0; j<levelNum;j++)
        {
            if(matrix[i][j]!=0){
                addLine(coordinate[i * 2], coordinate[i * 2 + 1], coordinate[j * 2], coordinate[j * 2 + 1]);
            }
        }
    }
    for(int i =0; i<GamePointsVec.size();i++){
        addItem(GamePointsVec[i]);
    }
}

void Graph::generateMatrix()
{
    QVector<QVector<int>> myMatrix(levelNum, QVector<int>(levelNum, 0));
    matrix = myMatrix;
    for(int ii = 0 ; ii <levelNum-4;ii+=4)
    {
        if(ii+8>levelNum)
        {
            for(int j = ii; j<ii+4;j++){
                matrix[j][ii+4]=1;
            }
            break;
        }
        for(int i = ii;i<ii+4;i++){

            for(int j = ii+4; j<ii+8;j++){
                matrix[i][j]=MonteCarlo::monteCarlo(0,1);
            }
        }
    }

    for(int i =0 ; i<levelNum-4;i++)
    {
        matrix[i][i+4]=1;
    }

    for(int ii = 0 ; ii <levelNum-4;ii+=4)
    {
        if(ii+8>levelNum)
            break;
        for(int i = ii;i<ii+4;i++){

            for(int j = ii+4; j<ii+8;j++){
                if(matrix[i][j]==1)
                {
                    switch (GamePointsVec[j]->setType())
                    {
                    case 1:{
                        matrix[i][j]=1;
                        break;
                    }
                    case 2:{
                        matrix[i][j]=2;
                        break;
                    }
                    case 4:{
                        matrix[i][j]=4;
                        break;
                    }
                    }
                }
            }
         }
    }

    for(int i =0; i<21;i++)
    {
        QString str;
        for(int j =0 ; j < 21;j++)
        {
            str += QString::number(matrix[i][j])+" ";
        }
        qDebug() << str;
    }
}

void Graph::addLineToScene()
{
    int index;
    for(int i =0 ;i<levelNum;i++)
    {
        if(lastGamePoint==GamePointsVec[i])
        {
            index=i;
        }
    }

    UFloid f;
    QVector <QVector<int>> matrix2=matrix;
    int INF = std::numeric_limits<int>::max();
    for(int i =0; i<21;i++)
    {
        for(int j =0 ; j < 21;j++){
            if(matrix2[i][j]==0)
                matrix2[i][j]=INF;
        }
    }
    QVector <QVector<int>> next=matrix2;
    QVector <QVector<int>> dist=matrix2;
    f.floydWarshall(matrix2,dist,next);
    QVector <int> p=f.getPath(next,index,20);

    QPen pen;
    QColor *c = new QColor(0,100,255);
    pen.setColor(*c);
    pen.setWidth(3);


    for (int i =0; i<p.size()-1;i++)
    {
        this->addLine(coordinate[p[i] * 2], coordinate[p[i] * 2 + 1],coordinate[p[i+1] * 2], coordinate[p[i+1] * 2 + 1],pen);
    }
    this->update();
}

void Graph::doActivSomePoints(GamePoint *GP)
{
    int num;
    for(int i = 0; i<levelNum;i++)
    {
        GamePointsVec[i]->doUnActiv();
    }
    for(int i = 0; i < levelNum;i++)
    {
        if(GP==GamePointsVec[i])
        {
            num=i;
            //qDebug() << "numofpoint=" <<num;
            break;
        }
    }
    for (int i = 0; i < levelNum; ++i) {
        if (matrix[num][i] >= 1) { // Если есть ребро из заданной вершины в вершину i
            GamePointsVec[i]->doActiv();
            //emit ClickChangeColor(Qt::magenta);
            //qDebug() << "numofpoint ACTIVE=" <<i;
        }
    }
}

int Graph::setlevelNum(){return levelNum;}

Graph::~Graph()
{
    operator delete(this);
}

void Graph::takeClick(GamePoint *GP)
{
    lastGamePoint=GP;
    emit ClickChangeColor(Qt::GlobalColor::blue);
    doActivSomePoints(GP);

    GP->setGameScene()->getDif(GP->setDifficulty());
    qDebug() << GP->setGameScene() ;
    GP->setGameScene()->getType(GP->setType());

    qDebug()<<"sozdana scena";
    emit forOpenGameScene(GP->setGameScene());
    this->update();

}

void Graph::easyPath()
{
    addLineToScene();
}
