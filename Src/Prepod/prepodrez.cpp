#include "prepodrez.h"
#include "ui_prepodrez.h"
#include "prepodmain.h"
#include "Graphics/grafikpnv.h"
#include "Graphics/grafikpv.h"
#include "Graphics/grafikss.h"
#include "Reports/zagruzkaotch.h"
#include <QAxObject>
#include <QSqlQuery>
#include <QDebug>
#include <QIODevice>
#include <QFile>
#include <QTextCodec>
#include <QSqlQueryModel>
#include <QSqlRecord>

PrepodRez::PrepodRez(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrepodRez)
{
    ui->setupUi(this);

    QSqlQuery queryQ;
    QString e = QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1' AND \"Hand\"= '%2'").arg(qq).arg(1);
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






      ui->label_8->setText(QString("r1 = %1").arg(b1));
      ui->label_9->setText(QString("r2 = %1").arg(b2));
      ui->label_10->setText(QString("r3 = %1").arg(b3));
      ui->label_11->setText(QString("r4 = %1").arg(b4));
      ui->label_12->setText(QString("r5 = %1").arg(b5));
      ui->label_13->setText(QString("r6 = %1").arg(b6));
      ui->label_17->setText(QString("Max = %1").arg(maxV));
      ui->label_18->setText(QString("Min = %1").arg(minV));
      ui->label_19->setText(QString("КСНС = %1").arg(ksnss));
      ui->label_38->setText(QString("Коэффициент функциональной асимметрии: %1").arg(kfa));


      QSqlQuery query;
      QString eb = QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1' AND \"Hand\"= '%2'").arg(qq).arg(0);
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

PrepodRez::~PrepodRez()
{
    delete ui;
}

void PrepodRez::on_pushButton_clicked()
{
    GrafikPV *w2 = new GrafikPV;
    w2->setWindowTitle("График ведущей руки");
    w2->show();
    close();
}

void PrepodRez::on_pushButton_2_clicked()
{
    GrafikPNV *w2 = new GrafikPNV;
    w2->setWindowTitle("График не ведущей руки");
    w2->show();
    close();
}

void PrepodRez::on_pushButton_3_clicked()
{
    GrafikSS *w2 = new GrafikSS;
    w2->setWindowTitle("Сводный график");
    w2->show();
    close();
}

void PrepodRez::on_pushButton_4_clicked()
{
    ZagruzkaOtch *w2 = new ZagruzkaOtch;
    w2->setWindowTitle("Отчеты");
    w2->show();
    close();
}

void PrepodRez::on_pushButton_5_clicked()
{
    QString fio;
    QSqlQueryModel q;
    QString ss = QString("SELECT \"FIO\" FROM \"Users\" WHERE \"id\"='%1'").arg(qq);
    q.setQuery(ss);
    fio = q.record(0).value(0).toString();

    QAxObject *word = new QAxObject("Word.Application", this);
        QAxObject *documents = word->querySubObject("Documents"); //получаем коллекцию документов
        QAxObject *document = documents->querySubObject("Add()"); //добавляем свой документ в коллекцию
        word->setProperty("Visible", true);


        QAxObject* ActiveDocument = word->querySubObject("ActiveDocument()");
            QAxObject* Range = ActiveDocument->querySubObject("Range()");
            Range->querySubObject("InsertAfter(Text)",QString("Отчет \n\r по результатам тестирования "
                                                              "студента: %1 \n\r Ведущая рука: \n"
                                                              "%2 \n"
                                                              "%4 \n"
                                                              "%6 \n"
                                                              "%8 \n"
                                                              "%9 \n "
                                                              "%10 \n"
                                                              "%3   %5   %7"
                                                              ""
                                                              "\n\r Не ведущая рука: \n"
                                                              "%11 \n"
                                                              "%12 \n"
                                                              "%13 \n"
                                                              "%14 \n"
                                                              "%15 \n "
                                                              "%16 \n"
                                                              "%17   %18   %19 \n\r"
                                                              "%20").arg(fio).arg(ui->label_8->text())
                                  .arg(ui->label_17->text())
                                  .arg(ui->label_9->text())
                                  .arg(ui->label_18->text())
                                  .arg(ui->label_10->text())
                                  .arg(ui->label_19->text())
                                  .arg(ui->label_11->text()).
                                  arg(ui->label_12->text())
                                  .arg(ui->label_13->text())
                                       .arg(ui->label_21->text())
                                       .arg(ui->label_23->text())
                                       .arg(ui->label_25->text())
                                       .arg(ui->label_27->text())
                                       .arg(ui->label_29->text())
                                       .arg(ui->label_31->text())
                                       .arg(ui->label_33->text())
                                       .arg(ui->label_35->text())
                                       .arg(ui->label_37->text())
                                       .arg(ui->label_38->text()));

            QAxObject *shrift = Range->querySubObject("Font");
                QString lol = shrift->property("Name").toString();
                shrift->setProperty("Size", 14); //задаем размер шрифта
            QTextCodec *codec = QTextCodec::codecForName("CP-1251");
                              QTextCodec::setCodecForLocale(codec);

}
