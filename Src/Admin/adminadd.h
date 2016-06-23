#ifndef ADMINADD_H
#define ADMINADD_H

#include <QMainWindow>

namespace Ui {
class AdminAdd;
}

class AdminAdd : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminAdd(QWidget *parent = 0);
    ~AdminAdd();
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
//    void on_comboBox_2_currentIndexChanged(int index);
private:
    Ui::AdminAdd *ui;
};

#endif // ADMINADD_H
