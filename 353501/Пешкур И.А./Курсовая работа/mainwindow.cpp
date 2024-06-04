#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MakeTime();

    screen = QApplication :: screens().at(0);

    ScreenHeigth = screen -> availableGeometry().height();
    ScreenWidth = screen -> availableGeometry().width();

    MakeVector();
    MakeSettings();
    SetBack();

    if( AmmounDay.empty() )
        AmmounDay.push_back( 0 );

    CigsCurrentDay = AmmounDay[ 0 ];

    PositivityIndex = CalculateIndex();
    ui -> stackedWidget -> setCurrentIndex( 0 );
    ui -> labelCigsCurrentDay -> setText( QString :: number( CigsCurrentDay ) );

    Timer.start( 1000 );
    connect( &Timer , SIGNAL( timeout() ) , this , SLOT( TimeChanged() ) );

    {

        ui -> scrollArea -> resize( ScreenWidth , ScreenHeigth );

        ui -> pushButtonMove -> move( ScreenWidth - 10 - ui -> pushButtonMove -> width() , 5 );

        ui -> stackedWidget -> move( ScreenWidth + 10 , 30 );

        ui -> labelTime -> resize( ScreenWidth - 60 , ScreenWidth / 13 );
        ui -> labelTime -> setStyleSheet ( "font-size: " + QString :: number( ScreenWidth / 13 ) + "pt;" + " background-color : white; color : black;");
        ui -> labelTime -> move( 30 , 100 );

        ui -> labelMotivationText -> resize( ScreenWidth , ScreenWidth / 13 );
        ui -> labelMotivationText -> setStyleSheet ( "font-size: " + QString :: number( ScreenWidth / 13 ) + "pt;" + " background-color : white; color : black;");
        ui -> labelMotivationText -> move( 0 , ScreenHeigth / 2 + 120 );

        ui -> pushButtonMinus -> move( 40 , ScreenHeigth / 2 - 20 );
        ui -> pushButtonPlus -> move( ScreenWidth - 40 - ui -> pushButtonPlus -> width() , ScreenHeigth / 2 - 20 );
        ui -> labelCigsCurrentDay -> move( ScreenWidth / 2 - ui -> labelCigsCurrentDay -> width() / 4 , ScreenHeigth / 2 + ui -> labelCigsCurrentDay -> height() / 2 - 20 );

        ui -> pushButtonTotal -> resize( ScreenWidth , ScreenHeigth / 20 );
        ui -> pushButtonTotal -> setStyleSheet ( "font-size : " + QString :: number( ScreenHeigth / 25    ) + "pt; font-weight : 700; ");
        ui -> pushButtonTotal -> move( 0 , ScreenHeigth - 25 - ScreenHeigth / 20 );

    }

    setMotivationText();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonMove_clicked()
{

    QPropertyAnimation* anim = new QPropertyAnimation( ui -> stackedWidget , "pos" , this );

    anim -> setDuration( 750 );

    if( !moveWasPressed )
    {

        anim -> setStartValue( QPoint( ScreenWidth + 10 , 30 ) );
        anim -> setEndValue( QPoint( ScreenWidth - ui -> stackedWidget -> width() - 10 , 30 ) );
        moveWasPressed = true;

    }
    else
    {

        anim -> setStartValue( QPoint( ScreenWidth - ui -> stackedWidget -> width() - 10 , 30 ) );
        anim -> setEndValue( QPoint( ScreenWidth + 10 , 30 ) );
        moveWasPressed = false;

    }

    anim -> start();

}

// settings begin

void MainWindow::on_comboBoxCurrency_currentIndexChanged( int index )
{

    WriteSettings();

}

void MainWindow::on_comboBoxPacksPerDay_currentIndexChanged( int index )
{

    WriteSettings();

}

void MainWindow::on_comboBoxAmmount_currentIndexChanged( int index )
{

    WriteSettings();

}

void MainWindow::on_doubleSpinBox_valueChanged( double arg1 )
{


    WriteSettings();

}

// settings end

// calculating index

long long MainWindow :: CalculateIndex()
{

    long long Result = 0;

    int* temp = new int[ AmmounDay.size() ];
    for( int i = 0 ; i < AmmounDay.size() ; ++ i )
        temp[ i ] = AmmounDay[ i ];

    bitonicsort( temp , ( temp + ( AmmounDay.size() - 1 ) )  );

    int* newTemp = new int[ AmmounDay.size() ];
    for( int i = 0 ; i < AmmounDay.size() ; ++ i )
        newTemp[ i ] = AmmounDay[ i ];

    int position = BinSearch( temp[ AmmounDay.size() - 1 ] , newTemp , 0 , AmmounDay.size() - 1 );

    Result = sum( 1 , 0 , AmmounDay.size() - 1 , std :: max( position - 2 , 0 ) , ( position + 2 ) < ( AmmounDay.size() - 1 ) ? ( position + 2 ) : ( AmmounDay.size() - 1 ) );

    return Result > 4 ? 4 : Result;

}

// counting sig buttons

void MainWindow::on_pushButtonMinus_clicked()
{

    CigsCurrentDay = CigsCurrentDay == 0 ? 0 : -- CigsCurrentDay;
    AmmounDay[ AmmounDay.size() - 1 ] = CigsCurrentDay;
    update( 1 , 0 , AmmounDay.size() - 1 , AmmounDay.size() - 1 , CigsCurrentDay );
    ui -> labelCigsCurrentDay -> setText( QString :: number( CigsCurrentDay ) );
    WriteVector();

}

void MainWindow::on_pushButtonPlus_clicked()
{

    WriteTime();
    ++ CigsCurrentDay;
    AmmounDay[ AmmounDay.size() - 1 ] = CigsCurrentDay;
    secundes = 0;
    minutes = 0;
    hours = 0;
    days = 0;
    update( 1 , 0 , AmmounDay.size() - 1 , AmmounDay.size() - 1 , CigsCurrentDay );
    ui -> labelCigsCurrentDay -> setText( QString :: number( CigsCurrentDay ) );
    WriteVector();

}

// new day started

void MainWindow :: AddNewDay()
{

    AmmounDay.push_back( 0 );
    ui  ->  labelCigsCurrentDay -> setText( "0" );
    CigsCurrentDay = 0;
    WriteVector();

}

void MainWindow :: MakeVector()
{

    QString standardPath = QStandardPaths :: writableLocation( QStandardPaths :: AppDataLocation );
    QString fileName = standardPath + "/VectorAmmount.txt";

    QFile file( fileName );
    file.open( QIODevice::ReadWrite | QIODevice::Text );

    QTextStream in( &file );

    while ( !in.atEnd() )
    {

        QString line = XorEncrypt( in.readLine() );

        if( line.length() != 0 )
            AmmounDay.push_back( QSToLL( line ) );

    }

    t = new int[ AmmounDay.size() * 4 ];
    int* temp = new int[ AmmounDay.size() ];
    for( int i = 0 ; i < AmmounDay.size() ; ++ i )
        temp[ i ] = AmmounDay[ i ];
    build( temp , 1 , 0 , AmmounDay.size() - 1 );

    file.close();

}

void MainWindow :: WriteVector()
{

    QString standardPath = QStandardPaths :: writableLocation( QStandardPaths :: AppDataLocation );
    QString fileName = standardPath + "/VectorAmmount.txt";

    QFile file( fileName );

    file.open( QIODevice::ReadWrite | QIODevice::Text );

    QTextStream out( &file );

    for( long long i = 0  ; i < AmmounDay.size() ; ++ i )
    {

        out << XorEncrypt( QString :: number( AmmounDay[ i ] ) )  << "\n";

    }

    file.close();

}

void MainWindow :: MakeTime()
{

    QString standardPath = QStandardPaths :: writableLocation( QStandardPaths :: AppDataLocation );
    QString fileName = standardPath + "/TimeValue.txt";

    QFile file( fileName );

    file.open( QIODevice::ReadWrite | QIODevice::Text );

    QTextStream in( &file );

    QString line = in.readLine();

    if( line.length() == 0 )
    {

        secundes = 0;
        minutes = 0;
        hours = 0;
        days = 0;
        WriteTime();

    }
    else
    {

        long long j = 0;
        QString TempNum = "";

        //  setting date

        {

            while( line.at( j ) != ' ' && j < line.size() )
            {

                TempNum += line.at( j );
                ++ j;

            }

            int year = QSToLL( TempNum );

            ++ j;
            TempNum = "";

            while( line.at( j ) != ' ' && j < line.size() )
            {

                TempNum += line.at( j );
                ++ j;

            }

            int month = QSToLL( TempNum );

            ++ j;
            TempNum = "";

            while( line.at( j ) != ' ' && j < line.size() )
            {

                TempNum += line.at( j );
                ++ j;

            }

            int day = QSToLL( TempNum );

            ++ j;
            TempNum = "";

            LastSigDate = QDate( year , month , day );

            while( LastSigDate != QDate :: currentDate() )
            {

                ++ days;
                LastSigDate.addDays( 1 );

            }

        }

        // setting time
        QTime vremechko = QTime :: currentTime();

        {

            while( line.at( j ) != ' ' && j < line.size() )
            {

                TempNum += line.at( j );
                ++ j;

            }

            hours = vremechko.hour() - QSToLL( TempNum );

            ++ j;
            TempNum = "";

            while( line.at( j ) != ' ' && j < line.size() )
            {

                TempNum += line.at( j );
                ++ j;

            }

            minutes = vremechko.minute() - QSToLL( TempNum );

            ++ j;
            TempNum = "";

            while(  j < line.size()  && line.at( j ) != ' ' )
            {

                TempNum += line.at( j );
                ++ j;

            }

            secundes = vremechko.second() - QSToLL( TempNum );

            if( secundes < 0 )
            {

                -- minutes;
                secundes += 60;

            }

            if( minutes < 0 )
            {

                -- hours;
                minutes += 60;

            }

            if( hours < 0 )
            {

                -- days;
                hours += 24;

            }

        }

    }

    file.close();

}

void MainWindow :: WriteTime()
{

    QString standardPath = QStandardPaths :: writableLocation( QStandardPaths :: AppDataLocation );
    QString fileName = standardPath + "/TimeValue.txt";

    QFile file( fileName );

    file.open( QIODevice::ReadWrite | QIODevice::Text );

    QTextStream out( &file );

    QTime vaibik = QTime :: currentTime();

    out << QString :: number( QDate :: currentDate().year() ) << " " << QString :: number( QDate :: currentDate().month() ) << " " << QString :: number( QDate :: currentDate().day() ) << " " << QString :: number( vaibik.hour() ) << " " << QString :: number( vaibik.minute() ) << " " << QString :: number( vaibik.second() ) ;

    file.close();

}

void MainWindow :: MakeSettings()
{

    QString standardPath = QStandardPaths :: writableLocation( QStandardPaths :: AppDataLocation );
    QString fileName = standardPath + "/Settings.txt";

    QFile file( fileName );
    file.open( QIODevice::ReadWrite | QIODevice::Text );

    QTextStream in( &file );

    QString line = in.readLine();

    if( line.length() == 0 )
    {

        WriteSettings();

    }
    else
    {

        ui -> comboBoxAmmount -> setCurrentIndex( line.at( 0 ).unicode() - 48 );
        ui -> comboBoxCurrency -> setCurrentIndex( line.at( 1 ).unicode() - 48 );
        ui -> comboBoxPacksPerDay -> setCurrentIndex( line.at( 2 ).unicode() - 48 );
        ui -> doubleSpinBox -> setValue( ( long double )( line.at( 3 ).unicode() - 48 ) + ( long double )( line.at( 4 ).unicode() - 48 ) / 10.0 );

    }

    file.close();

}

void MainWindow :: WriteSettings()
{

    QString standardPath = QStandardPaths :: writableLocation( QStandardPaths :: AppDataLocation );
    QString fileName = standardPath + "/Settings.txt";

    QFile file( fileName );

    file.open( QIODevice::ReadWrite | QIODevice::Text );

    QTextStream out( &file );

    out << QString :: number( ui -> comboBoxAmmount -> currentIndex() ) << QString :: number( ui -> comboBoxCurrency -> currentIndex() ) << QString :: number( ui -> comboBoxPacksPerDay -> currentIndex() ) << QString :: number( ( long long )( ui -> doubleSpinBox -> value() ) ) << QString :: number( ( long long )( ui -> doubleSpinBox -> value() * 10.0 ) % 10 );

    file.close();

}

long long MainWindow :: QSToLL( QString number )
{

    long long Res = 0;

    for( long long i = 0 ; i < number.length() ; ++ i )
    {

        Res = Res * 10 + ( number.at( i ).unicode() - 48 );

    }

    return Res;

}

void MainWindow :: TimeChanged()
{

    ++ secundes;

    if( secundes == 60 )
    {

        secundes = 0;
        ++ minutes;

    }

    if( minutes == 60 )
    {

        minutes = 0;
        ++ hours;

    }

    if( hours == 24 )
    {

        hours = 0;
        ++ days;

    }

    ui -> labelTime -> setText( QString :: number( days ) + " d, " + QString :: number( hours ) + " h, " + QString :: number( minutes ) + " min, " + QString :: number( secundes ) + " sec" );
    ui -> labelTime -> setAlignment( Qt :: AlignCenter );

    if( QTime :: currentTime().hour() == 0 && QTime :: currentTime().minute() == 0 && QTime :: currentTime().second() == 0 )
    {

        AddNewDay();

    }

}

long double MainWindow :: TotalPrice()
{

    long double Res = 0;

    long double Ammo = ui -> comboBoxPacksPerDay -> currentIndex() == 0 ? 0.5 : ui -> comboBoxPacksPerDay -> currentIndex();

    Ammo *= ( ( long double )( ( ui -> comboBoxAmmount -> currentIndex() + 1 ) * 5 ) );

    for( long long i = 0 ; i < AmmounDay.size() ; ++ i )
    {

        Res += ( ( Ammo - AmmounDay[ i ] ) / ( long double )( ( ui -> comboBoxAmmount -> currentIndex() + 1 ) * 5 ) * ( ui -> doubleSpinBox -> value() ) );

    }

    return Res;

}

void MainWindow :: on_pushButtonTotal_clicked()
{

    QMessageBox messagebox;
    messagebox.setText( "You have been saved " + QString :: number( TotalPrice() , 'f' , 2 ) + " " + ui -> comboBoxCurrency -> currentText() );
    messagebox.exec();

}

void MainWindow :: SetBack()
{

    ui -> labelBackground -> resize( ScreenWidth , ScreenHeigth );
    ui -> labelBackground -> move( 0 , 0 );
    QPixmap pix(":/fronts/fronts/" + QString :: number( CalculateIndex() * 3 + GenerateRandomNumMod( 3 ) ) +".jpg");
    ui -> labelBackground -> setPixmap( pix.scaled( ScreenWidth , ScreenHeigth ) );

}

long  long MainWindow :: GenerateRandomNum()
{

    long long sec = QTime :: currentTime().second();
    long long min = QTime :: currentTime().minute() * sec;
    long long hour = QTime :: currentTime().hour() * sec / min;
    long long msec = QTime :: currentTime().msec() * hour * min / sec;

    return sec + min + hour + msec;

}

long long MainWindow :: GenerateRandomNumMod( long long mod )
{

    return GenerateRandomNum() % mod;

}

void MainWindow :: setMotivationText()
{

    QFile file( ":/text/text/" + QString :: number( CalculateIndex() ) );
    file.open( QIODevice::ReadOnly| QIODevice::Text );

    QTextStream in( &file );

    long long RandNum = GenerateRandomNumMod( 5 );

    QString line;

    while( !in.atEnd() && RandNum >= 0 )
    {

        line = in.readLine();
        -- RandNum;

    }

    ui -> labelMotivationText -> setText( line );
    ui -> labelMotivationText -> setAlignment( Qt :: AlignCenter );

    file.close();

}

QString MainWindow :: XorEncrypt( QString str )
{
    QString result;
    QString _key = "Vaibik";
    int keyLength = _key.length();

    QChar char1;
    QChar char2;

    QChar encryptedChar;

    for ( int i = 0 ; i < str.length() ; ++ i )
    {

        char1 = str.at(i);
        char2 = _key.at(i % keyLength);

        encryptedChar = QChar(char1.unicode() ^ char2.unicode());

        result += encryptedChar;

    }

    return result;
}

void MainWindow :: bitseqsort( int* l , int* r , bool inv )
{
    if ( r - l <= 1 ) return;

    int *m = l + ( r - l ) / 2;

    for ( int *i = l , *j = m ; i < m && j < r ; ++ i , ++ j)
    {

        if ( inv ^ ( *i > *j ) )  std :: swap( *i, *j );

    }

    bitseqsort( l , m , inv );
    bitseqsort( m , r , inv );
}

void MainWindow :: makebitonic( int* l , int* r )
{

    if ( r - l <= 1 ) return;

    int *m = l + ( r - l ) / 2;

    makebitonic( l , m );
    bitseqsort( l , m , 0 );

    makebitonic( m , r );
    bitseqsort( m , r , 1 );
}

void MainWindow :: bitonicsort( int* l , int* r )
{

    int n = 1;
    int inf = 1 + *max_element( l , r );

    while(n < r - l) n *= 2;

    int* a = new int[n];
    int cur = 0;

    for( int *i = l ; i < r ; ++ i )
        a[ cur ++ ] = *i;

    while( cur < n ) a[ cur ++ ] = inf;

    makebitonic( a , a + n );
    bitseqsort( a , a + n , 0 );

    cur = 0;

    for( int *i = l ; i < r ; ++ i )
        *i = a[ cur ++ ];

    delete a;

}

int* MainWindow :: max_element( int* a , int* b )
{

    return a > b ? a : b;

}

int MainWindow :: BinSearch( int val , int* a , int l , int r )
{

    int md = ( l + r ) / 2;

    if( l > r )
        return -1;
    if( a[ md ] > val )
        return BinSearch( val , a , l , md - 1 );
    if( a[ md ] < val )
        return BinSearch( val , a , md + 1 , r );

    return md;

}

void MainWindow :: build ( int a[], int v, int tl, int tr )
{
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int MainWindow :: sum (int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, std :: min(r,tm))
           + sum (v*2+1, tm+1, tr, std :: max(l,tm+1), r);
}

void MainWindow :: update (int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
