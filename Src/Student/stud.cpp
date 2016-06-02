#include "stud.h"
#include "ui_stud.h"
#include "Auth/mainwindow.h"
#include "TappingTest/teppingtest.h"
#include "Instruction/instuctionstud.h"
#include "Results/rezteststud.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

Stud::Stud(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Stud)
{
    ui->setupUi(this);
    ui->label_2->setText(QString("Добро пожаловать, %1 ! \r\n \r\n В главном окне студента Вы можете ознакомиться с инструкцией \r\n"
                                 "по прохождению теппинг-теста. Также, после прохождения теста \r\n"
                                 " сможете ознакомиться с результатами").arg(FIO));

    QSqlQueryModel model;
    QString e = QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1'").arg(IDD);
    model.setQuery(e);
    if (model.rowCount()==0)
        ui->pushButton_2->setDisabled(true);
//    if (queryQ.isNull(false)) ui->pushButton->setDisabled(true);
//    else ui->pushButton->setEnabled(true);
}

Stud::~Stud()
{
    delete ui;
}

void Stud::on_pushButton_clicked()
{
    TeppingTest *w22 = new TeppingTest();
    w22->setWindowTitle("Теппинг-тест");
    w22->show();
    close();
}

void Stud::on_pushButton_2_clicked()
{
    RezTestStud *w2 = new RezTestStud();
    w2->setWindowTitle("Результаты тестирования");
    w2->show();
    close();
}

void Stud::on_pushButton_3_clicked()
{
    InstuctionStud *w22 = new InstuctionStud();
    w22->setWindowTitle("Инструкция по прохождению теппинг-теста");
    w22->show();
    close();
}

void Stud::on_pushButton_4_clicked()
{
    MainWindow *w22 = new MainWindow();
    w22->setWindowTitle("Авторизация");
    w22->show();
    close();
}


