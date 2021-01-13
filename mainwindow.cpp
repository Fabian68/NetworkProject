#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Modele/Simulation.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "Avant simulation";
    simulation = new Simulation();
    qDebug() << "Après simulation";
    ui->setupUi(this);
    launched = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addV_clicked()
{

}

void MainWindow::on_removeV_clicked()
{

}

void MainWindow::on_displayMap_clicked()
{

}


void MainWindow::on_displayMesh_clicked()
{

}

void MainWindow::on_zoomOut_clicked()
{

}

void MainWindow::on_zoomIn_clicked()
{

}

void MainWindow::on_openGlWid_aboutToResize()
{

}

void MainWindow::on_pushButton_clicked()
{
    if(!launched){
        launched = true;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Arreter");
    }else{
        launched = false;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Lancer");
    }
}
