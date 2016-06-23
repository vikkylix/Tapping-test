#ifndef PREPODMAIN_H
#define PREPODMAIN_H

#include <QMainWindow>

extern QString FIO, IDD;

namespace Ui {
class PrepodMain;
}

class PrepodMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrepodMain(QWidget *parent = 0);
    ~PrepodMain();
private slots:
    void on_comboBox_2_currentIndexChanged(int index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


private:
    Ui::PrepodMain *ui;

};

#endif // PREPODMAIN_H
