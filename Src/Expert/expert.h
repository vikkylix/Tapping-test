#ifndef EXPERT_H
#define EXPERT_H

#include <QMainWindow>

extern QString IDD, FIO;

namespace Ui {
class Expert;
}

class Expert : public QMainWindow
{
    Q_OBJECT

public:
    explicit Expert(QWidget *parent = 0);
    ~Expert();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_currentIndexChanged(int index);


private:
    Ui::Expert *ui;
};

#endif // EXPERT_H
