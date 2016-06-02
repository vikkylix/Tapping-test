#ifndef GRAFIKSS_H
#define GRAFIKSS_H

#include <QMainWindow>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>

#include <qwt_legend.h>

#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

#include <qwt_plot_magnifier.h>

#include <qwt_plot_panner.h>

#include <qwt_plot_picker.h>

#include <qwt_picker_machine.h>

extern QString qq;

namespace Ui {
class GrafikSS;
}

class GrafikSS : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrafikSS(QWidget *parent = 0);
    ~GrafikSS();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GrafikSS *ui;
    void addPlot();
    void addPlotGrid();


    QwtPlotCurve *curve;
    QPolygonF points;

    QwtPlotCurve *curve2;
    QPolygonF points2;
    void addCurve();

    void enableMagnifier();
    void enableMovingOnPlot();

    void enablePicker();
};

#endif // GRAFIKSS_H
