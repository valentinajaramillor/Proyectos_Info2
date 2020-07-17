#ifndef INICIO_H
#define INICIO_H

#include <QWidget>

namespace Ui {
class inicio;
}

class inicio : public QWidget
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();
    int decision;

private slots:

   void on_iniciarsesion_button_clicked();

   void on_registrarse_button_clicked();

   void on_sinregistro_button_clicked();

private:
    Ui::inicio *ui;

};

#endif // INICIO_H
