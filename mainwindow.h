#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mapopengl.h"
#include "Modele/Simulation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openGlWid_aboutToResize();

    void on_addV_clicked();

    void on_removeV_clicked();

    void on_displayMap_clicked();

    void on_displayMesh_clicked();

    void on_zoomOut_clicked();

    void on_zoomIn_clicked();

    void on_pushButton_clicked();

    void update();

private:
    Simulation* simulation;

    QTimer* updater;

    bool launched;
    bool displayMap;
    bool displayMesh;

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
