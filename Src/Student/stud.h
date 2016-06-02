#ifndef STUD_H
#define STUD_H

#include <QMainWindow>

extern QString FIO, IDD;

namespace Ui {
class Stud;
}

class Stud:public QMainWindow
{
    Q_OBJECT
public:
    explicit Stud(QWidget *parent = 0);
    ~Stud();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Stud *ui;
};

#endif // STUD_H
