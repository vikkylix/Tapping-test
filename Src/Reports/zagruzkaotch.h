#ifndef ZAGRUZKAOTCH_H
#define ZAGRUZKAOTCH_H

#include <QMainWindow>
extern QString qq;
namespace Ui {
class ZagruzkaOtch;
}

class ZagruzkaOtch : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZagruzkaOtch(QWidget *parent = 0);
    ~ZagruzkaOtch();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::ZagruzkaOtch *ui;
};

#endif // ZAGRUZKAOTCH_H
