#include "instuctionstud.h"
#include "ui_instuctionstud.h"
#include "Student/stud.h"

InstuctionStud::InstuctionStud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstuctionStud)
{
    ui->setupUi(this);
}

InstuctionStud::~InstuctionStud()
{
    delete ui;
}

void InstuctionStud::on_pushButton_clicked()
{
    Stud *w22 = new Stud();
    w22->setWindowTitle("Окно работы Студента");
    w22->show();
    close();
}
