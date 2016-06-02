#include "admindelete.h"
#include "ui_admindelete.h"
#include "admin.h"

#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

QStringList userFIO, userId;
QSqlQueryModel typesModel;

AdminDelete::AdminDelete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminDelete)
{
    ui->setupUi(this);
    userFIO.clear();
    userId.clear();
    ui->comboBox->clear();
    QString s = QString("SELECT * FROM \"Users\"");

    typesModel.setQuery(s);
    for (int i=0;i<typesModel.rowCount();i++){
        userFIO<<typesModel.record(i).value("FIO").toString();
        userId<<typesModel.record(i).value("id").toString();
    }
    ui->comboBox->addItems(userFIO);
}

AdminDelete::~AdminDelete()
{
    delete ui;
}

void AdminDelete::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Внимание!", "Вы действительно хотите удалить эту запись?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {

          QSqlQuery qqq;
          QString sql=(QString ("DELETE "
                                "FROM \"Users\" "
                                "WHERE id = '%1'").arg(userId.at(ui->comboBox->currentIndex())));
          qDebug()<<sql;
          qqq.exec(sql);
          ui->comboBox->clear();

          Admin *w2 = new Admin();
          w2->setWindowTitle("Главное окно Администратора");
          w2->show();
          close();
      }

}

void AdminDelete::on_pushButton_2_clicked()
{
    Admin *w22= new Admin();
    w22->setWindowTitle("Главное окно Администратора");
    w22->show();
    close();
}
