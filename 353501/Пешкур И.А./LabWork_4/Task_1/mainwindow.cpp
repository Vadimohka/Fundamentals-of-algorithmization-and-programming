#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene = new QGraphicsScene( this );
    ui -> graphicsView -> setScene( scene );

    scene -> setSceneRect( -500 , -250 , 1000 , 500 );
    a = new long long[ 250 ];
    randomMerger( a );
    drawPalki( a );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonMerge_clicked()
{

    canSort = false;
    time = 0;
    randomMerger( a );
    time = 0;
    drawPalki( a );

}

void MainWindow::on_pushButtonBubbe_clicked()
{
    canSort = false;
    canSort = true;
    time = 0;
    sortBubble( a );

}

void MainWindow::on_pushButtonQuick_clicked()
{

    canSort = false;
    canSort = true;
    time = 0;
    quickSort( a , 0 , 249 );

}

void MainWindow::on_pushButtonHeap_clicked()
{

    canSort = false;
    canSort = true;
    time = 0;
    heapSort( a );

}

void MainWindow::on_pushButtonMerge_2_clicked()
{

    canSort = false;
    canSort = true;
    time = 0;
    mergeSort( a , 0 , 249 );

}

void MainWindow :: drawPalki( long long* a )
{

    scene -> clear();

    long long tempTime = time;
    time /= 2;

    for( long long i = 0 ; i < 250 ; ++ i )
    {

        QGraphicsRectItem *item = new QGraphicsRectItem;
        item -> setRect( -500 + i * 4 , 250 , 4 , -a[ i ] * 2 );
        scene -> addItem( item );
        ui -> labelTime -> setText( QString :: number( time / 100 / 60 / 60 ) + "." + QString :: number( ( time / 100 / 60 ) % 60 ) + "." + QString :: number( ( time / 100 ) % 60 ) + "." + QString :: number( time % 100 ) );

    }

    time = tempTime;

    QCoreApplication::processEvents();

    ++ time;

}

void MainWindow :: findedElement( long long pos , long long Value )
{

    QGraphicsRectItem *item = new QGraphicsRectItem;
    item -> setBrush( QBrush( QColor( 1 , 120 , 1 ) ) );
    item -> setRect( -500 + pos * 4 , 250 , 4 , -Value * 2 );
    scene -> addItem( item );
    QCoreApplication::processEvents();

}

void MainWindow :: randomMerger( long long* a )
{

    bool b[ 250 ]{};
    long long rand;
    long long i = 0;

    while( i < 250 )
    {
        rand = QRandomGenerator::global()->bounded( 250 );

        if( !b[ rand ] )
        {
            a[ rand ] = i + 1;
            b[ rand ] = true;
            ++ i;
        }
    }

}

void MainWindow :: sortBubble( long long* a )
{

    for( long long i = 0 ; i < 249 ; ++ i )
    {

        for( long long j = i + 1 ; j < 250 ; ++ j )
        {

            if( a[ i ] > a[ j ] )
            {

                std :: swap( a[ i ] , a[ j ] );
                drawPalki( a );

            }

            if( !canSort )
                return;

        }

    }

}

long long MainWindow :: partition( long long* a , long long start , long long end )
{

    long long pivot = a[ start ];

    long long count = 0;

    for ( long long i = start + 1 ; i <= end ; ++i )
    {
        if ( a[ i ] <= pivot )
            ++ count;
    }

    long long pivotIndex = start + count;
    std :: swap( a[ pivotIndex ] , a[ start ] );
    drawPalki( a );

    long long i = start, j = end;

    while ( i < pivotIndex && j > pivotIndex )
    {

        while ( a[ i ] <= pivot )
        {

            ++ i;

        }

        while ( a[ j ] > pivot )
        {

            -- j;

        }

        if ( i < pivotIndex && j > pivotIndex )
        {

            std :: swap( a[ i ++ ] , a[ j -- ] );
            drawPalki( a );

        }

    }

    return pivotIndex;

}

void MainWindow :: quickSort( long long* a , long long start , long long end )
{

    if ( start >= end )
        return;

    int p = partition( a , start , end );

    if( !canSort )
        return;

    quickSort( a , start , p - 1 );

    if( !canSort )
        return;

    quickSort( a , p + 1 , end );

    if( !canSort )
        return;
}

void MainWindow :: heapify( long long* a , long long n , long long i )
{

    long long largest = i;

    long long l = 2 * i + 1;

    long long r = 2 * i + 2;

    if ( l < n && a[ l ] > a[ largest ] )
        largest = l;

    if ( r < n && a[ r ] > a[ largest ] )
        largest = r;

    if ( largest != i )
    {

        std :: swap( a[ i ] , a[ largest ] );
        drawPalki( a );
        heapify( a , n , largest );

    }

    if( !canSort )
        return;

}

void MainWindow :: heapSort( long long* a )
{

    for ( long long i = 250 / 2 - 1 ; i >= 0 ; -- i )
    {

        if( !canSort )
            return;

        heapify( a , 250 , i );

    }

    for ( long long i = 250 - 1 ; i > 0 ; -- i )
    {

        std :: swap( a[ 0 ] , a[ i ] );
        drawPalki( a );

        if( !canSort )
            return;

        heapify( a , i , 0 );

    }
}

void MainWindow :: merge( long long* a , long long left , long long mid , long long right )
{

    int const arrayOne = mid - left + 1;
    int const arrayTwo = right - mid;

    long long *leftArray = new long long[ arrayOne ], *rightArray = new long long[ arrayTwo ];

    if( !canSort )
        return;

    for ( long long i = 0 ; i < arrayOne ; ++ i )
        leftArray[ i ] = a[ left + i ];

    for ( long long j = 0 ; j < arrayTwo ; ++ j )
        rightArray[ j ] = a[ mid + 1 + j ];

    long long indexOfArrayOne = 0, indexOfArrayTwo = 0;
    long long indexOfMergedArray = left;

    while (indexOfArrayOne < arrayOne && indexOfArrayTwo < arrayTwo) {

        if ( leftArray[ indexOfArrayOne ] <= rightArray[ indexOfArrayTwo ] )
        {

            a[ indexOfMergedArray ] = leftArray[ indexOfArrayOne ];
            drawPalki( a );
            ++ indexOfArrayOne;

        }
        else
        {

            a[ indexOfMergedArray ] = rightArray[ indexOfArrayTwo ];
            drawPalki( a );
            ++ indexOfArrayTwo;
        }
        ++ indexOfMergedArray;

        if( !canSort )
            return;
    }

    while ( indexOfArrayOne < arrayOne )
    {
        a[ indexOfMergedArray ] = leftArray[ indexOfArrayOne ];
        drawPalki( a );
        ++ indexOfArrayOne;
        ++ indexOfMergedArray;

        if( !canSort )
            return;

    }

    while ( indexOfArrayTwo < arrayTwo )
    {

        a[ indexOfMergedArray ] = rightArray[ indexOfArrayTwo ];
        drawPalki( a );
        ++ indexOfArrayTwo;
        ++ indexOfMergedArray;

        if( !canSort )
            return;

    }

}

void MainWindow :: mergeSort( long long* a , long long begin, long long end )
{
    if ( begin >= end )
        return;

    long long mid = begin + (end - begin) / 2;

    if( !canSort )
        return;

    mergeSort( a , begin , mid );
    mergeSort( a , mid + 1 , end );
    merge( a , begin , mid , end );

}

long long MainWindow :: BinSearch( long long Value , long long l , long long mid , long long r )
{

    if( a[ mid ] == Value )
        return mid;
    if( ( l > r ) || ( l == r && l == mid && a[ mid ] != Value ) )
        return -1;
    if( a[ mid ] > Value )
        return BinSearch( Value , l , ( mid + l ) / 2 , mid );

    return BinSearch( Value , mid , ( mid + r ) / 2 , r );

}

bool MainWindow :: isSorted( long long* a )
{

    for( long long i = 1 ; i < 250 ; ++ i )
    {

        if( a[ i ] < a[ i - 1 ] )
            return false;

    }

    return true;

}

void MainWindow::on_pushButtonFindElement_clicked()
{

    -- time;
    drawPalki( a );

    if( !isSorted( a ) )
    {

        ui -> labelFind -> setText( "Not sorted" );
        return;

    }

    long long ElementPos = BinSearch( ui -> spinBox -> value() , 0 , 125 , 249 );

    if( ElementPos != -1 )
    {

        ui -> labelFind -> setText( QString :: number( ElementPos ) );
        QGraphicsRectItem *item = new QGraphicsRectItem;
        item -> setRect( -500 + ElementPos * 4 , 250 , 4 , -a[ ElementPos ] * 2 );
        item -> setBrush( QBrush( QColor( 0 , 150 , 0 ) ) );
        scene -> addItem( item );
        scene -> update();

    }
    else
    {

        ui -> labelFind -> setText( "-1" );

    }

}

void MainWindow::on_pushButton_clicked()
{

    canSort = false;
    canSort = true;
    time = 0;
    superSort( a );

}

void MainWindow :: superSort( long long* a )
{

    while( !isSorted( a ) )
    {

        if( !canSort )
            return;
        std :: swap( a[ QRandomGenerator :: global() -> bounded( 250 ) ] , a[ QRandomGenerator :: global() -> bounded( 250 ) ] );
        drawPalki( a );

    }

}

void MainWindow :: interpolationSort( long long* a ,  long long low, long long high)
{

    if ( high == -100 )
        high = 250 - 1;

    if ( high <= low )
        return;

    if ( high - low == 1 )
    {

        if ( a[ low ] > a[ high ] )
            std :: swap( a[ low ] , a[ high ] );
        if( !canSort )
            return;
        drawPalki( a );

        return;

    }

    long long min = 251;
    long long max = -1;

    for ( long long i = low ; i <= high ; ++ i )
    {

        long long el = a[ i ];
        if ( el < min )
            min = el;
        if ( el > max )
            max = el;
        if( !canSort )
            return;

    }

    if ( min == max )
        return;

    QVector< QVector< long long > > buckets;
    buckets.resize( high - low + 1 );

    for ( long long i = low ; i <= high ; ++ i )
    {

        if( !canSort )
            return;
        long long el = a[ i ];
        long long bucket = static_cast< long long >( ( el - min ) / ( max - min ) ) * ( buckets.size() - 1 );
        buckets[ bucket ].push_back( el );

    }

    long long curpos = low;
    for ( long long i = 0 ; i < buckets.size() ; ++ i )
    {
        if ( buckets[ i ].empty() )
            continue;

        if( !canSort )
            return;

        long long buckstart = curpos;

        for ( const auto& e : buckets[ i ] )
        {

            a[ curpos ++ ] = e;
            if( !canSort )
                return;
            //drawPalki( a );

        }
        drawPalki( a );
        interpolationSort( a , buckstart , curpos - 1 );
        drawPalki( a );

    }

}

long long MainWindow :: BinPow( long long num, long long pow, long long mod)
{

    if( pow == 0 )
        return 1;

    if( pow % 2 == 1 )
        return num * BinPow( num , pow - 1 , mod ) % mod;
    else
    {

        long long temp = BinPow( num , pow / 2 , mod );
        return ( temp * temp ) % mod;

    }

}

void MainWindow::on_pushButtonInter_clicked()
{

    canSort = false;
    canSort = true;
    time = 0;
    interpolationSort( a , 0 , 249 );

}

