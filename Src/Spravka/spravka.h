#ifndef SPRAVKA_H
#define SPRAVKA_H

#include <QMainWindow>

namespace Ui {
class Spravka;
}

class Spravka : public QMainWindow
{
    Q_OBJECT

public:
    explicit Spravka(QWidget *parent = 0);
    ~Spravka();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Spravka *ui;
};

#endif // SPRAVKA_H
