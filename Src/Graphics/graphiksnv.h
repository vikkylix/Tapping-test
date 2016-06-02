#ifndef GRAPHIKSNV_H
#define GRAPHIKSNV_H

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

extern QString IDD;

namespace Ui {
class GraphikSNV;
}

class GraphikSNV : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphikSNV(QWidget *parent = 0);
    ~GraphikSNV();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GraphikSNV *ui;
    void addPlot();
    void addPlotGrid();

    QwtPlotCurve *curve;
    QPolygonF points;
    void addCurve();

    void enableMagnifier();
    void enableMovingOnPlot();

    void enablePicker();
};

#endif // GRAPHIKSNV_H
