#ifndef PREPODREZ_H
#define PREPODREZ_H

#include <QMainWindow>

extern QString qq;

namespace Ui {
class PrepodRez;
}

class PrepodRez : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrepodRez(QWidget *parent = 0);
    ~PrepodRez();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::PrepodRez *ui;
};

#endif // PREPODREZ_H
