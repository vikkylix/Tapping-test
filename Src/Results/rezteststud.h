#ifndef REZTESTSTUD_H
#define REZTESTSTUD_H

#include <QMainWindow>

extern QString IDD;

namespace Ui {
class RezTestStud;
}

class RezTestStud : public QMainWindow
{
    Q_OBJECT

public:
    explicit RezTestStud(QWidget *parent = 0);
    ~RezTestStud();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::RezTestStud *ui;
};

#endif // REZTESTSTUD_H
