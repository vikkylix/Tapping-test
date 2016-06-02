#ifndef ADMINDELETE_H
#define ADMINDELETE_H

#include <QMainWindow>

namespace Ui {
class AdminDelete;
}

class AdminDelete : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminDelete(QWidget *parent = 0);
    ~AdminDelete();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::AdminDelete *ui;
};

#endif // ADMINDELETE_H
