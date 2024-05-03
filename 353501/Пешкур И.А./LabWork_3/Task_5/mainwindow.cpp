#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count( const QString& Path , long long& folder , long long& file )
{
    QDir dir( Path );

    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );

    QFileInfoList fileList = dir.entryInfoList();

    foreach ( const QFileInfo& fileInfo , fileList )
    {

        if ( fileInfo.isDir() )
        {

            ++ folder;
            count( fileInfo.filePath() , folder , file );

        }
        else
        {

            ++ file;

            // echkere

        }
    }
}

void MainWindow::on_pushButtonOpenFolder_clicked()
{

    QString Path = QFileDialog::getExistingDirectory( this , "gang" , QDir :: homePath() );

    if ( !Path.isEmpty() )
    {
        long long folder = 0;
        long long file = 0;

        count( Path , folder , file );

        ui -> labelFiles -> setText( QString :: number( file ) );
        ui -> labelFolders -> setText( QString :: number( folder ) );

    }
    else
    {

        QMessageBox :: warning( this , "Warning" , "gavno" );
        return;

    }

    QTreeWidgetItem *rootItem = new QTreeWidgetItem( ui->treeWidget );
    rootItem -> setText( 0 , Path );
    setTree( Path , rootItem );

}

QPair< long long , long long > MainWindow :: setTree( const QString &Path , QTreeWidgetItem *parentItem )
{

    QDir folderCurrent( Path );

    QFileInfoList entries = folderCurrent.entryInfoList( QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files );

    long long folder = 0;
    long long file = 0;

    for ( const QFileInfo &entry : entries )
    {

        if ( entry.isDir() )
        {

            QTreeWidgetItem *folderNext = new QTreeWidgetItem( parentItem );
            folderNext -> setText( 0 , entry.fileName() );
            QPair< long long , long long > childCount = setTree( entry.filePath() , folderNext );

        }
        else if ( entry.isFile() )
        {

            QTreeWidgetItem *fileItem = new QTreeWidgetItem( parentItem );
            fileItem -> setText( 0 , entry.fileName() );

        }

    }

    QPair< long long , long long > ret { folder , file };
    return ret;

}

