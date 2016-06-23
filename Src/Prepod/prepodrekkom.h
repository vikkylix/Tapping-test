#ifndef PREPODREKKOM_H
#define PREPODREKKOM_H

#include <QMainWindow>

extern QString qq;

namespace Ui {
class PrepodRekkom;
}

class PrepodRekkom : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrepodRekkom(QWidget *parent = 0);
    ~PrepodRekkom();
private slots:
    void on_pushButton_clicked();

private:
    Ui::PrepodRekkom *ui;
};

#endif // PREPODREKKOM_H
