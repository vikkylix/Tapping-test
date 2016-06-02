#include "expert.h"
#include "ui_expert.h"
#include "Auth/mainwindow.h"

#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

QStringList NameSys, SysId;
Expert::Expert(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Expert)
{
    ui->setupUi(this);
    ui->label->setText(QString("Вы вошли как %1").arg(FIO));

    QSqlQueryModel model;
    model.setQuery(QString("SELECT * FROM \"SpravRecom\""));
    for(int i=0;i<model.rowCount();i++)
    {
        NameSys<<model.record(i).value("Result").toString();
        SysId<<model.record(i).value("idRec").toString();
    }

    qDebug()<<NameSys<<"\r\n"<<SysId;

    ui->comboBox->addItems(NameSys);
    ui->label_3->setText(model.record(ui->comboBox->currentIndex()).value("Description").toString());
    ui->textEdit->setText(model.record(ui->comboBox->currentIndex()).value("Recommend").toString());

}

Expert::~Expert()
{
    delete ui;
}


void Expert::on_pushButton_2_clicked()
{
 MainWindow *w2 = new MainWindow();
 w2->setWindowTitle("Авторизация");
 w2->show();
 close();
}

void Expert::on_comboBox_currentIndexChanged(int index)
{


    QSqlQueryModel *model = new QSqlQueryModel;
    QString s = QString("SELECT * FROM \"SpravRecom\" WHERE \"idRec\" = '%1' ").arg(SysId.at(ui->comboBox->currentIndex()));

    model->setQuery(s);
    ui->label_3->setText(model->record(0).value("Description").toString());
    ui->textEdit->setText(model->record(0).value("Recommend").toString());
    qDebug()<<model->record(0).value("Description").toString()<<model->record(0).value("Recommend").toString();

}

void Expert::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Внимание!", "Вы действительно хотите изменить эту запись?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
    QSqlQuery query;
    query.prepare(QString("UPDATE \"SpravRecom\" SET \"Recommend\"= '%1' WHERE \"idRec\" = '%2'").arg(ui->textEdit->toPlainText()).arg(SysId.at(ui->comboBox->currentIndex())));
            query.exec();


      }
}

