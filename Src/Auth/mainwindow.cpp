#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Admin/admin.h"
#include "Expert/expert.h"
#include "Student/stud.h"
#include "Prepod/prepodmain.h"
#include <QtSql/QSqlDatabase>
#include<qDebug>
#include<QSqlQuery>
#include <QVariant>
#include<QList>
#include<QMessageBox>
#include <QSqlRecord>
#include<QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


QString FIO, IDD;



void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_clicked()
{

    if (ok==false)
    {
      QMessageBox::information(this, "Ошибка!", "Ошибка подключения к базе данных!");
    }

                QString login = ui->lineEdit->text();
                QString parol= ui->lineEdit_2->text();
                QString gr;

                QSqlQuery query;
                QString e = QString("SELECT * FROM auth WHERE \"login\" = '%1'").arg(login);
                query.exec(e);
                qDebug()<<query.value(0);
                if(!query.isActive())
                qDebug()<< "!!! Database Error !!!";
                QString log,ps,ut;

                while (query.next()) {
                 IDD =query.value(0).toString();
                 FIO = query.value(1).toString();
                 log = query.value(2).toString();
                 ps = query.value(3).toString();
                 gr = query.value(4).toString();
                 ut=query.value(5).toString();
                }


                  if (login == log && parol == ps && ut =="student")
                  {
                      Stud *w22 = new Stud();
                      w22->setWindowTitle("Окно работы Студента");
                      w22->show();
                      close();


                   }
                 else if (login == log && parol == ps && ut =="prepod")
                  {
                      PrepodMain *w2 = new PrepodMain();
                       w2->setWindowTitle("Окно работы ");
                       w2->show();
                       close();

                   }
                  else if (login == log && parol == ps && ut =="admin")
                   {
                  Admin *w22 = new Admin();
                  w22->setWindowTitle("Окно работы администратора БД");
                  w22->show();
                  close();

                    }
                  else if (login == log && parol == ps && ut =="expert")
                   {
                  Expert *w22 = new Expert();
                  w22->setWindowTitle("Окно работы Эксперта");
                  w22->show();
                  close();

                    }
                  else QMessageBox::information(this, "Ошибка!", "Неверный логин или пароль!");





}
