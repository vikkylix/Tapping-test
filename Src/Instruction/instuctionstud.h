#ifndef INSTUCTIONSTUD_H
#define INSTUCTIONSTUD_H

#include <QMainWindow>

namespace Ui {
class InstuctionStud;
}

class InstuctionStud : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstuctionStud(QWidget *parent = 0);
    ~InstuctionStud();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InstuctionStud *ui;
};

#endif // INSTUCTIONSTUD_H
