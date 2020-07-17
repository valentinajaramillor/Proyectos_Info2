#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "globo.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void spawn();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    Globo * jugador1;
};
#endif // MAINWINDOW_H
