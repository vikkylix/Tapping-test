#include "zagruzkaotch.h"
#include "ui_zagruzkaotch.h"
#include "Prepod/prepodrez.h"
#include "Prepod/prepodrekkom.h"
#include "Prepod/prepodmain.h"
#include <QSqlQueryModel>
#include <QSqlRecord>


ZagruzkaOtch::ZagruzkaOtch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ZagruzkaOtch)
{
    ui->setupUi(this);
    QSqlQueryModel model;
    model.setQuery(QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1'").arg(qq));
    if (model.rowCount()==0){
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
        ui->label->setText("Студент не проходил теппинг-тест");
    }
}

ZagruzkaOtch::~ZagruzkaOtch()
{
    delete ui;
}

void ZagruzkaOtch::on_pushButton_clicked()
{
    PrepodRez *w22 = new PrepodRez();
    w22->setWindowTitle("Результаты теппинг-теста");
    w22->show();
    close();
}

void ZagruzkaOtch::on_pushButton_2_clicked()
{
    PrepodRekkom *w22 = new PrepodRekkom();
    w22->setWindowTitle("Рекоммендация");
    w22->show();
    close();
}

void ZagruzkaOtch::on_pushButton_3_clicked()
{
    PrepodMain *w22 = new PrepodMain();
    w22->setWindowTitle("Преподаватель");
    w22->show();
    close();
}
