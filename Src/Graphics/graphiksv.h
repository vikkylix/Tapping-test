#ifndef GRAPHIKSV_H
#define GRAPHIKSV_H

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
class GraphikSV;
}

class GraphikSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphikSV(QWidget *parent = 0);
    ~GraphikSV();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GraphikSV *ui;
    void addPlot();
    void addPlotGrid();

    QwtPlotCurve *curve;
    QPolygonF points;
    void addCurve();

    void enableMagnifier();
    void enableMovingOnPlot();

    void enablePicker();
};

#endif // GRAPHIKSV_H
