#include "prepodmain.h"
#include "ui_prepodmain.h"
#include "Auth/mainwindow.h"
#include "Reports/zagruzkaotch.h"
#include "Spravka/spravka.h"

#include<QtSql/QSqlDatabase>
#include<qDebug>
#include<QSqlQuery>
#include <QSqlRecord>
#include<QSqlQueryModel>
#include <QVariant>
#include<QList>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QUuid>


QStringList groupNames, groupIds, studentsFio, studentsId;
QString qq;

PrepodMain::PrepodMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrepodMain)
{
    ui->setupUi(this);
    ui->label_2->setText(FIO);

//    QUuid uuid;
//    uuid.createUuid().toString();

//    QSqlQuery query1111;
//    QString e1111 = "SELECT * FROM \"StudGroup\"";

    QSqlQueryModel model;
    model.setQuery(QString("SELECT * FROM \"forkurator\" WHERE \"Kurator\"='%1'").arg(IDD));
    groupNames.clear();
    groupIds.clear();
     for (int i=0;i<model.rowCount();i++){
         groupNames<<model.record(i).value("studGroupName").toString();
         groupIds<<model.record(i).value("studGroupId").toString();
     }
     QSet<QString> stringSet = QSet<QString>::fromList(groupNames);
     groupNames = stringSet.toList();
     stringSet = QSet<QString>::fromList(groupIds);
     groupIds = stringSet.toList();
     for (int i=0;i<groupNames.count();i++){
         if (groupNames.at(i)=="none"){
             groupNames.removeAt(i);
             groupIds.removeAt(i);
             break;
         }
     }
if (ui->comboBox_2->count()!=0)
{
    ui->comboBox_2->clear();
}
     ui->comboBox_2->addItems(groupNames);

}


PrepodMain::~PrepodMain()
{
    delete ui;
}

void PrepodMain::on_comboBox_2_currentIndexChanged(int index){
    ui->comboBox->clear();
    QSqlQueryModel model;
    QString s = QString("SELECT * FROM \"forkurator\" WHERE \"studGroupId\" = '%1' AND \"Kurator\"='%2' ").arg(groupIds.at(ui->comboBox_2->currentIndex())).arg(IDD);

    model.setQuery(s);
    studentsFio.clear();
    studentsId.clear();
    for (int i=0;i<model.rowCount();i++){
        studentsFio<<model.record(i).value("FIO").toString();
        studentsId<<model.record(i).value("id").toString();
    }
    if (ui->comboBox->count()!=0)
    {
        ui->comboBox->clear();
    }
    ui->comboBox->addItems(studentsFio);
    qDebug()<<studentsFio;
}


void PrepodMain::on_pushButton_clicked()
{
    QSqlQuery queryQ;
    QString e = QString("SELECT * FROM \"ResultTest\" WHERE \"StudentId\" = '%1'").arg(studentsId.at(ui->comboBox->currentIndex()));
    queryQ.exec(e);

    while (queryQ.next()) {
      qq=queryQ.value(0).toString();
      }

ZagruzkaOtch *w2 = new ZagruzkaOtch();
w2->setWindowTitle("Отчеты");
w2->show();
close();
}

void PrepodMain::on_pushButton_2_clicked()
{

    MainWindow *w2 = new MainWindow();
    w2->setWindowTitle("Авторизация");
    w2->show();
    close();

}


void PrepodMain::on_pushButton_3_clicked()
{

Spravka *w22 = new Spravka();
w22->setWindowTitle("Справка");
w22->show();
close();

}

