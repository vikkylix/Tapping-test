#include "spravka.h"
#include "ui_spravka.h"
#include "Prepod/prepodmain.h"

Spravka::Spravka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Spravka)
{
    ui->setupUi(this);
}

Spravka::~Spravka()
{
    delete ui;
}

void Spravka::on_pushButton_clicked()
{
    PrepodMain *w2 = new PrepodMain();
    w2->setWindowTitle("Главное окно работы Преподавателя");
    w2->show();
    close();
}
