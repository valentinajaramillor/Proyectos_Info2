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

private:
    Ui::inicio *ui;
};

#endif // INICIO_H
