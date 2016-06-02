#include "adminadd.h"
#include "ui_adminadd.h"
#include "QSqlQueryModel"
#include <QSqlRecord>
#include <QUuid>
#include <QSqlQuery>
#include "adminadd.h"
#include <QDebug>
#include "admin.h"
#include "Auth/mainwindow.h"

QStringList userTypesNameRu, userTypesId, studGroupId, studGroupName, kuratorId, kuratorName;

AdminAdd::AdminAdd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAdd)
{
    ui->setupUi(this);
    userTypesNameRu.clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    QSqlQueryModel typesModel;
        QString s = QString("SELECT * FROM \"userTypes\"");

    typesModel.setQuery(s);
    for (int i=0;i<typesModel.rowCount();i++){
        userTypesNameRu<<typesModel.record(i).value("userTypesNameRu").toString();
        userTypesId<<typesModel.record(i).value("userTypesId").toString();
    }
    ui->comboBox->addItems(userTypesNameRu);

}

AdminAdd::~AdminAdd()
{
    delete ui;
}

void AdminAdd::on_comboBox_currentIndexChanged(int index){
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    studGroupName.clear();
    userTypesNameRu.clear();

    studGroupId.clear();studGroupName.clear();kuratorId.clear();kuratorName.clear();
    if (ui->comboBox->currentText() == "Студент")
    {   ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        QSqlQueryModel model;
        QString s = QString("SELECT * FROM \"StudGroup\" WHERE \"studGroupName\" != 'Сотрудник'");
        model.setQuery(s);
        for (int i=0;i<model.rowCount();i++){
            studGroupName<<model.record(i).value("studGroupName").toString();
            studGroupId<<model.record(i).value("studGroupId").toString();
        }
        ui->comboBox_2->addItems(studGroupName);
        s = QString("SELECT * FROM \"kurators\"");
        model.setQuery(s);
        for (int i=0;i<model.rowCount();i++){
            kuratorName<<model.record(i).value("ФИО").toString();
            kuratorId<<model.record(i).value("id").toString();
        }
        ui->comboBox_3->addItems(kuratorName);
    }
    else{
        ui->comboBox_2->setCurrentText("Сотрудник");
        ui->comboBox_2->setDisabled(true);
        ui->comboBox_3->setCurrentText("Сотрудник");
        ui->comboBox_3->setDisabled(true);
    }
}

void AdminAdd::on_pushButton_clicked(){
    QUuid uuid;
    QString userId = uuid.createUuid().toString();
    QString login, password, fio, userType, userGroup, kurator;
    fio = ui->lineEdit->text();
    login = ui->lineEdit_2->text();
    password = ui->lineEdit_3->text();
    userType=userTypesId.at(ui->comboBox->currentIndex());
    qDebug()<<userType;
    if (ui->comboBox->currentText()!="Студент")
        {
            QSqlQueryModel model;
            QString s = QString("SELECT * FROM \"StudGroup\" WHERE \"studGroupName\" = 'Сотрудник'");
            model.setQuery(s);
            userGroup = model.record(0).value(0).toString();
            qDebug()<<userGroup;
            kurator.append(NULL);
            QSqlQuery q;
            q.prepare("INSERT INTO \"Users\" (\"id\",\"FIO\",\"login\",\"password\", \"userType\", \"group\", \"Kurator\") VALUES(?,?,?,?,?,?,?)");
            q.addBindValue(userId);
            q.addBindValue(fio);
            q.addBindValue(login);
            q.addBindValue(password);
            q.addBindValue(userType);
            q.addBindValue(userGroup);
            q.addBindValue(kurator);
            q.exec();
        }
    else {

        userGroup = studGroupId.at(ui->comboBox_2->currentIndex());
        kurator = kuratorId.at(ui->comboBox_3->currentIndex());
        qDebug()<<userGroup;
        qDebug()<<kurator;

        QSqlQuery q;
        q.prepare("INSERT INTO \"Users\" (\"id\",\"FIO\",\"login\",\"password\", \"userType\", \"group\", \"Kurator\") VALUES(?,?,?,?,?,?,?)");
        q.addBindValue(userId);
        q.addBindValue(fio);
        q.addBindValue(login);
        q.addBindValue(password);
        q.addBindValue(userType);
        q.addBindValue(userGroup);
        q.addBindValue(kurator);
        q.exec();
    }

    Admin *w2 = new Admin();
    w2->setWindowTitle("Главное окно Администратора");
    w2->show();
    close();
}

void AdminAdd::on_pushButton_2_clicked()
{
    Admin *w2 = new Admin();
    w2->setWindowTitle("Главное окно Администратора");
    w2->show();
    close();
}

