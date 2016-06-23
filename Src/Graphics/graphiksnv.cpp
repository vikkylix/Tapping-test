#include "graphiksnv.h"
#include "ui_graphiksnv.h"
#include "Results/rezteststud.h"
#include<QtSql/QSqlDatabase>
#include<qDebug>
#include<QSqlQuery>
#include <QVariant>
#include<QList>
#include <QSqlTableModel>
#include <QMessageBox>



GraphikSNV::GraphikSNV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphikSNV)
{
    ui->setupUi(this);
    QString b01,b02,b03,b04,b05,b06;
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



  ui->Qwt_widget->detachItems(QwtPlotItem::Rtti_PlotItem,true);
  ui->Qwt_widget->setTitle( "График результатов по не ведущей руке" );
  ui->Qwt_widget->setCanvasBackground( Qt::white );

  // Параметры осей координат
  ui->Qwt_widget->setAxisTitle(QwtPlot::yLeft, "Количество кликов");
  ui->Qwt_widget->setAxisTitle(QwtPlot::xBottom, "Время, сек");

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


  ui->Qwt_widget->setAxisScale(QwtPlot::xBottom, 5, 30, 5);
  ui->Qwt_widget->setAxisScale(QwtPlot::yLeft, 0, 48, 8);


     QwtPlotGrid *grid = new QwtPlotGrid();
     grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
     grid->attach( ui->Qwt_widget );


         curve = new QwtPlotCurve();
         curve->setPen( Qt::blue, 6 ); // цвет и толщина кривой

         // Маркеры кривой
         // #include <qwt_symbol.h>
         QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
             QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
         curve->setSymbol( symbol );

         // Добавить точки на ранее созданную кривую
         // Значения точек записываются в массив, затем считываются
         // из этого массива


           points << QPointF(5, b01.toInt())<<QPointF(10, b02.toInt())<<QPointF(15, b03.toInt())<<QPointF(20, b04.toInt())<<QPointF(25, b05.toInt())<<QPointF(30, b06.toInt());




        // for (int i = 0; i < 5; i++) {
       //      points << QPointF( 1.0 * i, 1.0 * i); // произвольное заполнение
       //  }

         curve->setSamples( points ); // ассоциировать набор точек с кривой

         curve->attach( ui->Qwt_widget ); // отобразить кривую на графике



points.clear();

}


GraphikSNV::~GraphikSNV()
{
    delete ui;
}

void GraphikSNV::on_pushButton_clicked()
{
    RezTestStud *w22 = new RezTestStud();
    w22->setWindowTitle("Результаты тестирования");
    w22->show();
    close();
}
