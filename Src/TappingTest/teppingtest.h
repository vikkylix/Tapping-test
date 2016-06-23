#ifndef TEPPINGTEST_H
#define TEPPINGTEST_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>

extern QString FIO, gr, IDD;
namespace Ui {
class TeppingTest;
}
class TeppingTest : public QMainWindow
{
    Q_OBJECT
public:
    QTimer *timer;
    QTime *time;
    QTime *time2;
    int timeSecC;
    explicit TeppingTest(QWidget *parent = 0);
    ~TeppingTest();
signals:

public slots:
    void on_pushButton_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_start_clicked();
    void on_stop_clicked();
    void update();

private:
    Ui::TeppingTest *ui;
};

#endif // TEPPINGTEST_H
