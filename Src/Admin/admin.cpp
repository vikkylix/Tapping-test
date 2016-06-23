#include "admin.h"
#include "QSqlQueryModel"
#include "adminadd.h"
#include "admindelete.h"
#include "Auth/mainwindow.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM \"userAdmin\"");
    ui->tableView->setModel(model);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked(){
    AdminAdd *w2 = new AdminAdd();
    w2->setWindowTitle("Добавление пользователя");
    w2->show();
    close();
}


void Admin::on_pushButton_2_clicked(){
    AdminDelete *w2 = new AdminDelete();
    w2->setWindowTitle("Удаление пользователя");
    w2->show();
    close();
}

void Admin::on_pushButton_3_clicked(){
    MainWindow *w2 = new MainWindow();
    w2->setWindowTitle("Авторизация");
    w2->show();
    close();
}

