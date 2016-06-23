#include "Auth/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QProcess>
#include <QTableView>
#include <QMessageBox>
#include <QStringList>
#include <QSqlDatabase>

bool ok;
QSqlDatabase sdb = QSqlDatabase::addDatabase("QPSQL");
int main(int argc, char *argv[])
{

    sdb.setHostName("127.0.0.1");
                    sdb.setPort(5432);
                    sdb.setDatabaseName("MarkovaDB");
                    sdb.setUserName("postgres");
                    sdb.setPassword("postgres");
                    ok = sdb.open();
                if (!sdb.open()) {

                        qDebug() << "Ошибка подключения к базе данных!";
                        return -1;
                    }

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Авторизация");



    w.show();

    return a.exec();
}
