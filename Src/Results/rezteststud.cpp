#include "rezteststud.h"
#include "ui_rezteststud.h"
#include "Auth/mainwindow.h"
#include "Student/stud.h"
#include "Graphics/graphiksv.h"
#include "Graphics/graphiksnv.h"
#include "Graphics/graphikss.h"

#include <QSqlQuery>
#include <QDebug>
RezTestStud::RezTestStud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RezTestStud)
{
    ui->setupUi(this);

    QSqlQuery queryQ;
    QString e = QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1' AND \"Hand\"= '%2'").arg(IDD).arg(1);
    queryQ.exec(e);



    QString b1,b2,b3,b4,b5,b6,h,ksnss,kfa;

    while (queryQ.next()) {
      b1=queryQ.value(2).toString();
      b2=queryQ.value(3).toString();
      b3=queryQ.value(4).toString();
      b4=queryQ.value(5).toString();
      b5=queryQ.value(6).toString();
      b6=queryQ.value(7).toString();
      ksnss=queryQ.value(8).toString();
      kfa=queryQ.value(9).toString();
      h=queryQ.value(10).toString();

    }
QList <int> ved;
QList <int> nVed;
int minE = 100;
int maxE = 0;

int minV = minE;
int maxV = maxE;
ved << b1.toInt() << b2.toInt() << b3.toInt() << b4.toInt() << b5.toInt() << b6.toInt();
foreach (int item, ved) {
    if (item<=minV) minV = item;
    if (item>=maxV) maxV = item;
}

QString r;

QSqlQuery queryQ;
QString e = QString("SELECT \"ksns\" FROM \"ResultTest\" WHERE \"StudentId\" = '%1' AND \"Hand\"= '%2'").arg(IDD).arg(1);
queryQ.exec(e);
QString vv;
while (queryQ.next()) {
    vv=queryQ.value(0).toString();
}

if (vv.toDouble()<-17.3){
    r= "Слабая нервная система";
}
if (-17.3<vv.toDouble()<=-6.1){
    r= "Средне-слабая нервная система";
}
if (-6.1<vv.toDouble()<=6.0){
    r= "Средняя нервная система";
}
if (6.0<vv.toDouble()<=17.2){
r= "Средне-слабая нервная система";
}
if (vv.toDouble()>=17.3){
r= "Сильная нервная система";
}



      ui->label_8->setText(QString("r1 = %1").arg(b1));
      ui->label_9->setText(QString("r2 = %1").arg(b2));
      ui->label_10->setText(QString("r3 = %1").arg(b3));
      ui->label_11->setText(QString("r4 = %1").arg(b4));
      ui->label_12->setText(QString("r5 = %1").arg(b5));
      ui->label_13->setText(QString("r6 = %1").arg(b6));
      ui->label_17->setText(QString("Max = %1").arg(maxV));
      ui->label_18->setText(QString("Min = %1").arg(minV));
      ui->label_19->setText(QString("КСНС = %1").arg(ksnss));
      ui->label_38->setText(QString("Коэффициент функциональной асимметрии: %1 \r\n'%2'").arg(kfa).arg(r));


      QSqlQuery query;
      QString eb = QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1' AND \"Hand\"= '%2'").arg(IDD).arg(0);
      query.exec(eb);

      QString b01,b02,b03,b04,b05,b06,h1,ksnss1;

      while (query.next()) {
        b01=query.value(2).toString();
        b02=query.value(3).toString();
        b03=query.value(4).toString();
        b04=query.value(5).toString();
        b05=query.value(6).toString();
        b06=query.value(7).toString();
        ksnss1=query.value(8).toString();
        h1=query.value(10).toString();

        int minNv = minE;
        int maxNv = maxE;
        nVed << b01.toInt() << b02.toInt() << b03.toInt() << b04.toInt() << b05.toInt() << b06.toInt();
        foreach (int item, nVed) {
            if (item<=minNv) minNv = item;
            if (item>=maxNv) maxNv = item;
        }

        qDebug()<<maxV<<" "<<minV<<" "<<maxNv<<" "<<minNv;

        ui->label_21->setText(QString("r1 = %1").arg(b01));
        ui->label_23->setText(QString("r2 = %1").arg(b02));
        ui->label_25->setText(QString("r3 = %1").arg(b03));
        ui->label_27->setText(QString("r4 = %1").arg(b04));
        ui->label_29->setText(QString("r5 = %1").arg(b05));
        ui->label_31->setText(QString("r6 = %1").arg(b06));
        ui->label_33->setText(QString("Max = %1").arg(maxNv));
        ui->label_35->setText(QString("Min = %1").arg(minNv));
        ui->label_37->setText(QString("КСНС = %1").arg(ksnss1));


    }

}

RezTestStud::~RezTestStud()
{
    delete ui;
}


void RezTestStud::on_pushButton_4_clicked()
{
    Stud *w22 = new Stud();
    w22->setWindowTitle("Окно работы Студента");
    w22->show();
    close();
}


void RezTestStud::on_pushButton_clicked()
{
    GraphikSV *w22 = new GraphikSV();
    w22->setWindowTitle("График ведущей руки");
    w22->show();
    close();
}

void RezTestStud::on_pushButton_2_clicked()
{
    GraphikSNV *w22 = new GraphikSNV();
    w22->setWindowTitle("График не ведущей руки");
    w22->show();
    close();
}

void RezTestStud::on_pushButton_3_clicked()
{
    GraphikSS *w22 = new GraphikSS();
    w22->setWindowTitle("Сводный график");
    w22->show();
    close();
}
