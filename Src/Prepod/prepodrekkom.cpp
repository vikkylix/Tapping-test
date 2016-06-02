#include "prepodrekkom.h"
#include "ui_prepodrekkom.h"
#include "Reports/zagruzkaotch.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>

QStringList idres,valuee, res, description, reccom;
PrepodRekkom::PrepodRekkom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrepodRekkom)
{
    ui->setupUi(this);
    QString fio;
    QSqlQueryModel q;
    QString ss = QString("SELECT \"FIO\" FROM \"Users\" WHERE \"id\"='%1'").arg(qq);
    q.setQuery(ss);
    fio = q.record(0).value(0).toString();
    ui->label->setText(QString("Реккомендация по студенту: %1").arg(fio));
    QSqlQueryModel model;
    QString s = "SELECT * FROM \"SpravRecom\"";
    model.setQuery(s);
    for (int i=0; i<model.rowCount();i++)
    {
        idres<<model.record(i).value("idRec").toString();
        valuee<<model.record(i).value("Value").toString();
        res<<model.record(i).value("Result").toString();
        description<<model.record(i).value("Description").toString();
        reccom<<model.record(i).value("Recommend").toString();
    }



    QSqlQuery queryQ;
    QString e = QString("SELECT \"ksns\" FROM \"ResultTest\" WHERE \"StudentId\" = '%1' AND \"Hand\"= '%2'").arg(qq).arg(1);
    queryQ.exec(e);
    QString vv;
    while (queryQ.next()) {
        vv=queryQ.value(0).toString();
    }
    QString resTb,descrTb, recomendTb;

    if (vv.toDouble()<-17.3){
        resTb = res.at(0);
        descrTb = description.at(0);
        recomendTb = reccom.at(0);
    }
    if (-17.3<vv.toDouble()<=-6.1){
        resTb = res.at(4);
        descrTb = description.at(4);
        recomendTb = reccom.at(4);
    }
    if (-6.1<vv.toDouble()<=6.0){
        resTb = res.at(1);
        descrTb = description.at(1);
        recomendTb = reccom.at(1);
    }
    if (6.0<vv.toDouble()<=17.2){
        resTb = res.at(3);
        descrTb = description.at(3);
        recomendTb = reccom.at(3);
    }
    if (vv.toDouble()>=17.3){
        resTb = res.at(2);
        descrTb = description.at(2);
        recomendTb = reccom.at(2);
    }
    ui->label_2->setText(resTb);
    ui->label_3->setText(descrTb);
    ui->label_4->setText(recomendTb);
}


PrepodRekkom::~PrepodRekkom()
{
    delete ui;
}


void PrepodRekkom::on_pushButton_clicked()
{
    ZagruzkaOtch *w2 = new ZagruzkaOtch();
    w2->setWindowTitle("");
    w2->show();
    close();
}
