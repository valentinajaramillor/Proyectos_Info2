#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proyectil.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    //Create a Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,-650,650,650);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    ui->graphicsView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg")));


    //Create an Item to put into the scene
    jugador1 = new Globo();

    //add the item to the scene
    scene->addItem(jugador1);

    //make rect focusable
    jugador1->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador1->setFocus();

    jugador1->setPos(50,-50);


    //create the score/Health
    //score = new Score();
    //scene->addItem(score);
    //health = new Health();
    //health->setPos(health->x(),health->y()+25);
    //scene->addItem(health);


    //Spawn enemies
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(1000);

//    //play background music
//    QMediaPlayer * music = new QMediaPlayer;
//    music->setMedia(QUrl("qrc:/sounds/hola.mp3"));
//    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::spawn()
{
    //create enemies
    Proyectil * proyectil = new Proyectil();
    scene->addItem(proyectil);
}

