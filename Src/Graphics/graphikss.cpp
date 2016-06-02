#include "graphikss.h"
#include "ui_graphikss.h"
#include "Results/rezteststud.h"
#include<QtSql/QSqlDatabase>
#include<qDebug>
#include<QSqlQuery>
#include <QVariant>
#include<QList>
#include <QSqlTableModel>
#include <QMessageBox>


GraphikSS::GraphikSS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphikSS)
{
    ui->setupUi(this);

    QString b01,b02,b03,b04,b05,b06;
    QString b1,b2,b3,b4,b5,b6;

    QSqlQuery queryQ;
    QString e1111 = (QString("SELECT \"Button1\", \"Button2\", \"Button3\", \"Button4\", \"Button5\","
                               " \"Button6\" FROM \"ResultTest\" where \"StudentId\" = '%1' AND \"Hand\" = '%2'").arg(IDD).arg(0));

    queryQ.exec(e1111);

    while (queryQ.next()) {
        b01=queryQ.value(0).toString();
        b02=queryQ.value(1).toString();
        b03=queryQ.value(2).toString();
        b04=queryQ.value(3).toString();
        b05=queryQ.value(4).toString();
        b06=queryQ.value(5).toString();


    }

    QSqlQuery queryQQ;
    QString e11111 = (QString("SELECT \"Button1\", \"Button2\", \"Button3\", \"Button4\", \"Button5\","
                               " \"Button6\" FROM \"ResultTest\" where \"StudentId\" = '%1' AND \"Hand\" = '%2'").arg(IDD).arg(1));

    queryQQ.exec(e11111);

    while (queryQQ.next()) {
        b1=queryQQ.value(0).toString();
        b2=queryQQ.value(1).toString();
        b3=queryQQ.value(2).toString();
        b4=queryQQ.value(3).toString();
        b5=queryQQ.value(4).toString();
        b6=queryQQ.value(5).toString();


    }



  ui->Qwt_widget->detachItems(QwtPlotItem::Rtti_PlotItem,true);
  ui->Qwt_widget->setTitle( "Сводный график результатов" );
  ui->Qwt_widget->setCanvasBackground( Qt::white );




  // Параметры осей координат
  ui->Qwt_widget->setAxisTitle(QwtPlot::yLeft, "Количество кликов");
  ui->Qwt_widget->setAxisTitle(QwtPlot::xBottom, "Время, сек");
  ui->Qwt_widget->insertLegend( new QwtLegend() );

  ui->Qwt_widget->setAxisScale(QwtPlot::xBottom, 5, 30, 5);
  ui->Qwt_widget->setAxisScale(QwtPlot::yLeft, 0, 48, 8);


     QwtPlotGrid *grid = new QwtPlotGrid();
     grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
     grid->attach( ui->Qwt_widget );


     QwtPlotPicker *d_picker =
                 new QwtPlotPicker(
                     QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
         QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
         QwtPicker::ActiveOnly, // включение/выключение
         ui->Qwt_widget->canvas() ); // ассоциация с полем

         // Цвет перпендикулярных линий
         d_picker->setRubberBandPen( QColor( Qt::red ) );

         // цвет координат положения указателя
         d_picker->setTrackerPen( QColor( Qt::black ) );

         // непосредственное включение вышеописанных функций
         d_picker->setStateMachine( new QwtPickerDragPointMachine() );


         curve = new QwtPlotCurve();
         curve2 = new QwtPlotCurve();

         curve->setTitle("Не ведущая рука");
         curve2->setTitle("Ведущая рука");

         curve->setPen( Qt::blue, 6 ); // цвет и толщина кривой
        curve2->setPen( Qt::green, 6 );
         // Маркеры кривой
         // #include <qwt_symbol.h>
         QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
             QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
         curve->setSymbol( symbol );

         QwtSymbol *symbol2 = new QwtSymbol( QwtSymbol::Ellipse,
             QBrush( Qt::red ), QPen( Qt::yellow, 2 ), QSize( 8, 8 ) );
         curve2->setSymbol( symbol2 );

         // Добавить точки на ранее созданную кривую
         // Значения точек записываются в массив, затем считываются
         // из этого массива


           points << QPointF(5, b01.toInt())<<QPointF(10, b02.toInt())<<QPointF(15, b03.toInt())<<QPointF(20, b04.toInt())<<QPointF(25, b05.toInt())<<QPointF(30, b06.toInt());
           points2 << QPointF(5, b1.toInt())<<QPointF(10, b2.toInt())<<QPointF(15, b3.toInt())<<QPointF(20, b4.toInt())<<QPointF(25, b5.toInt())<<QPointF(30, b6.toInt());




        // for (int i = 0; i < 5; i++) {
       //      points << QPointF( 1.0 * i, 1.0 * i); // произвольное заполнение
       //  }

         curve->setSamples( points ); // ассоциировать набор точек с кривой
curve2->setSamples( points2 );
         curve->attach( ui->Qwt_widget ); // отобразить кривую на графике
curve2->attach( ui->Qwt_widget );


points.clear();
points2.clear();
}

GraphikSS::~GraphikSS()
{
    delete ui;
}

void GraphikSS::on_pushButton_clicked()
{
    RezTestStud *w22 = new RezTestStud();
    w22->setWindowTitle("Результаты тестирования");
    w22->show();
    close();
}
