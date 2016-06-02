#include "grafikpv.h"
#include "ui_grafikpv.h"
#include "Prepod/prepodrez.h"

#include <QSqlQuery>

GrafikPV::GrafikPV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GrafikPV)
{
    ui->setupUi(this);

    QString b1,b2,b3,b4,b5,b6;


          QSqlQuery queryQ;
          QString e1111 = (QString("SELECT \"Button1\", \"Button2\", \"Button3\", \"Button4\", \"Button5\","
                                     " \"Button6\" FROM \"ResultTest\" where \"StudentId\" = '%1' AND \"Hand\" = '%2'").arg(qq).arg(1));

          queryQ.exec(e1111);

          while (queryQ.next()) {
              b1=queryQ.value(0).toString();
              b2=queryQ.value(1).toString();
              b3=queryQ.value(2).toString();
              b4=queryQ.value(3).toString();
              b5=queryQ.value(4).toString();
              b6=queryQ.value(5).toString();


          }



        ui->Qwt_Widget->detachItems(QwtPlotItem::Rtti_PlotItem,true);
        ui->Qwt_Widget->setTitle( "График результатов по ведущей руке" );
        ui->Qwt_Widget->setCanvasBackground( Qt::white );

        // Параметры осей координат
        ui->Qwt_Widget->setAxisTitle(QwtPlot::yLeft, "Количество кликов");
        ui->Qwt_Widget->setAxisTitle(QwtPlot::xBottom, "Время, сек");
        QwtPlotPicker *d_picker =
                    new QwtPlotPicker(
                        QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
            QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
            QwtPicker::ActiveOnly, // включение/выключение
            ui->Qwt_Widget->canvas() ); // ассоциация с полем

            // Цвет перпендикулярных линий
            d_picker->setRubberBandPen( QColor( Qt::red ) );

            // цвет координат положения указателя
            d_picker->setTrackerPen( QColor( Qt::black ) );

            // непосредственное включение вышеописанных функций
            d_picker->setStateMachine( new QwtPickerDragPointMachine() );

        ui->Qwt_Widget->setAxisScale(QwtPlot::xBottom, 5, 30, 5);
        ui->Qwt_Widget->setAxisScale(QwtPlot::yLeft, 0, 48, 8);


           QwtPlotGrid *grid = new QwtPlotGrid();
           grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
           grid->attach( ui->Qwt_Widget );


               curve = new QwtPlotCurve();
               curve->setPen( Qt::green, 6 ); // цвет и толщина кривой

               // Маркеры кривой
               // #include <qwt_symbol.h>
               QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
                   QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
               curve->setSymbol( symbol );

               // Добавить точки на ранее созданную кривую
               // Значения точек записываются в массив, затем считываются
               // из этого массива


                 points << QPointF(5, b1.toInt())<<QPointF(10, b2.toInt())<<QPointF(15, b3.toInt())<<QPointF(20, b4.toInt())<<QPointF(25, b5.toInt())<<QPointF(30, b6.toInt());




              // for (int i = 0; i < 5; i++) {
             //      points << QPointF( 1.0 * i, 1.0 * i); // произвольное заполнение
             //  }

               curve->setSamples( points ); // ассоциировать набор точек с кривой

               curve->attach( ui->Qwt_Widget ); // отобразить кривую на графике



     points.clear();
}

GrafikPV::~GrafikPV()
{
    delete ui;
}

void GrafikPV::on_pushButton_clicked()
{
    PrepodRez *w22 = new PrepodRez();
    w22->setWindowTitle("Результаты тестирования");
    w22->show();
    close();
}

