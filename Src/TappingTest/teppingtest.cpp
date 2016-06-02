#include "teppingtest.h"
#include "ui_teppingtest.h"
#include "Auth/mainwindow.h"
#include "Student/stud.h"
#include "qdebug.h"
#include "qtimer.h"
#include "QTime"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

QString gr;
TeppingTest::TeppingTest(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::TeppingTest)
{
    ui->setupUi(this);
    ui->pushButton_1->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->radioButton->setChecked(true);
        ui->stop->setDisabled(true);


}
TeppingTest::~TeppingTest()
{
    delete ui;
}
int n1=0, n2=0, n3=0,n4=0, n5=0, n6=0;
int S1=0,S2=0,S3=0, S4=0, S5=0, S6=0;
int S01=0,S02=0,S03=0, S04=0, S05=0, S06=0;

int i=0;
int k=0, h=0;
float sump=0.0,suml=0.0;
float ksns1=0.0,ksns01=0.0,kfa1=0.0;

void TeppingTest::on_pushButton_1_clicked()
{
    n1++;
}

void TeppingTest::on_pushButton_clicked()
{
    Stud *w2 = new Stud();
    w2->setWindowTitle("Окно работы Студента");
    w2->show();
    close();
}

void TeppingTest::on_pushButton_2_clicked()
{
    n2++;
}

void TeppingTest::on_pushButton_3_clicked()
{
    n3++;
}

void TeppingTest::on_pushButton_4_clicked()
{
    n4++;
}

void TeppingTest::on_pushButton_5_clicked()
{
    n5++;
}

void TeppingTest::on_pushButton_6_clicked()
{
    n6++;
}

void TeppingTest::on_stop_clicked()
{

    QDateTime dt2 = QDateTime::currentDateTime();
    qDebug()<<sump<<"   "<<suml;
    kfa1= ((sump-suml)/(sump+suml))*100;
    qDebug()<<kfa1;
    QSqlQuery query2;
    QSqlQueryModel model;
    model.setQuery(QString("SELECT count( * ) FROM \"ResultTest\" WHERE \"StudentId\" = '%1'").arg(IDD));
    if (model.record(0).value(0)==0)
    {
        query2.prepare("INSERT INTO \"ResultTest\" (\"StudentId\",\"Date\",\"Button1\", \"Button2\", \"Button3\", \"Button4\", "
                   "\"Button5\", \"Button6\", \"ksns\", \"kfa\",  \"Hand\") VALUES (?,?,?,?,?,?,?,?,?,?,?)");
        query2.addBindValue(IDD);
        query2.addBindValue(dt2);
        query2.addBindValue(S1);
        query2.addBindValue(S2);
        query2.addBindValue(S3);
        query2.addBindValue(S4);
        query2.addBindValue(S5);
        query2.addBindValue(S6);
        query2.addBindValue(ksns1);
        query2.addBindValue(kfa1);
        query2.addBindValue(1);
        query2.exec();


        query2.addBindValue(IDD);
        query2.addBindValue(dt2);
        query2.addBindValue(S01);
        query2.addBindValue(S02);
        query2.addBindValue(S03);
        query2.addBindValue(S04);
        query2.addBindValue(S05);
        query2.addBindValue(S06);
        query2.addBindValue(ksns01);
        query2.addBindValue(kfa1);
        query2.addBindValue(0);
        query2.exec();
    }

    else{
        QString s=QString("UPDATE \"ResultTest\" SET \"Date\"='%1',\"Button1\"=%2, \"Button2\"=%3, \"Button3\"=%4, \"Button4\"=%5, "
                          "\"Button5\"=%6, \"Button6\"=%7, \"ksns\"='%8', \"kfa\"='%9' WHERE \"Hand\"='1' AND \"StudentId\"='%10'").arg(dt2.toString()).arg(S1).arg(S2).arg(S3).arg(S4)
                              .arg(S5).arg(S6).arg(ksns1).arg(kfa1).arg(IDD);
        qDebug()<<s<<"\n\r";
        query2.prepare(s);
        query2.exec();
        s= QString("UPDATE \"ResultTest\" SET \"Date\" = '%1',\"Button1\"=%2, \"Button2\"=%3, \"Button3\"=%4, \"Button4\"=%5, "
                           "\"Button5\"=%6, \"Button6\"=%7, \"ksns\"='%8', \"kfa\"='%9' WHERE \"Hand\"='0' AND \"StudentId\"='%10'").arg(dt2.toString()).arg(S01).arg(S02).arg(S03).arg(S04)
                               .arg(S05).arg(S06).arg(ksns01).arg(kfa1).arg(IDD);
        qDebug()<<s<<"\n\r";
        query2.prepare(s);
        query2.exec();
    }
    if(!query2.isActive()) qDebug()<<"error";

    Stud *w22 = new Stud();
    w22->setWindowTitle("Окно работы студента");
    w22->show();
    close();

}
int button =1;

void TeppingTest::on_start_clicked()
{
    ui->radioButton->setDisabled(true);
    ui->radioButton_2->setDisabled(true);
    ui->start->setDisabled(true);
    ui->stop->setDisabled(true);

    n1=0, n2=0, n3=0,n4=0, n5=0, n6=0;

    button=1;
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    timer->start(1000);

    time = new QTime(0,0,30);
    ui->label_2->setText(time->toString());

    time2 = new QTime(0,0,0);
    ui->label_4->setText(time2->toString());


}



void TeppingTest::update()
{

    *time = time->addSecs(-1);
    *time2 = time2->addSecs(1);
    switch (button) {
    case 1:
        ui->pushButton_1->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_1->setEnabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_6->setDisabled(true);
        break;
    case 2:
        ui->pushButton_1->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_1->setDisabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_6->setDisabled(true);
        break;
    case 3:
        ui->pushButton_1->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_1->setDisabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_6->setDisabled(true);
        break;
    case 4:
        ui->pushButton_1->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_1->setDisabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_6->setDisabled(true);
        break;
    case 5:
        ui->pushButton_1->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_1->setDisabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_6->setDisabled(true);
        break;
    case 6:
        ui->pushButton_1->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_1->setDisabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_6->setEnabled(true);
        break;
    default:
        ui->pushButton_1->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->pushButton_1->setEnabled(true);
        ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->pushButton_6->setDisabled(true);
        break;
    }
    ui->label_2->setText(time->toString());
    ui->label_4->setText(time2->toString());


    if (time->second()%5==0)
    {
        button++;
        time2->setHMS(0,0,0);
}

    if (time->toString() == "00:00:00")
    {
        timer->stop();
        time2->setHMS(0,0,0);
        ui->label_4->setText(time2->toString());
        ui->pushButton_1->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->stop->setEnabled(true);
        if(ui->radioButton->isChecked())
        {
            S1=n1;
            S2=n2;
            S3=n3;
            S4=n4;
            S5=n5;
            S6=n6;
            sump=n1+n2+n3+n4+n5+n6;
            ksns1=(((sump)/n1)-6);

        }

        if(ui->radioButton_2->isChecked())
        {
            S01=n1;
                S02=n2;
                S03=n3;
                S04=n4;
                S05=n5;
                S06=n6;
                suml=n1+n2+n3+n4+n5+n6;
                ksns01=(((suml)/n1)-6);

        }
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->start->setEnabled(true);
        ui->stop->setEnabled(true);
        qDebug()<<S1<<S01;
        bool check = (S1&&S01)&&(S2&&S02)&&(S3&&S03)&&(S4&&S04)&&(S5&&S05)&&(S6&&S06);
        if (check == false)
            ui->stop->setDisabled(true);
    }
}
