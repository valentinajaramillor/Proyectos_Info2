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





    vidas=3;
    nivel=1;

    //Spawn enemies
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));

    actualizar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()
{
    // This will display the lives and level
    ui->vidas_lcd->display(vidas);
    ui->nivel_lcd->display(nivel);
    //checklost();
}
void MainWindow::spawn()
{
    //create enemies
    Proyectil * proyectil = new Proyectil();
    scene->addItem(proyectil);
}


void MainWindow::on_iniciar_button_clicked()
{
    //Create an Item to put into the scene
    jugador1 = new Globo();

    //add the item to the scene
    scene->addItem(jugador1);

    //make rect focusable
    jugador1->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador1->setFocus();

    jugador1->setPos(50,-50);

    timer->start(1000);

}
