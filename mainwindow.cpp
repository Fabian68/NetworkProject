#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Modele/Simulation.h"
#include <QDebug>
#include <QTimer>
#include <unistd.h>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qDebug() << "Avant simulation";
    simulation = new Simulation();
    qDebug() << "Après simulation";
    ui->setupUi(this);
    ui->openGlWid->setSimulation(simulation);
    launched = false;
    displayMesh = true;
    displayMap = true;

    /*
    updater = new QTimer(this);
    connect( updater, SIGNAL(timeout()), this, SLOT(&MainWindow::update));
    updater->start(400);*/ //  bidouille
    updater = new QTimer(this);
    updater->setInterval(10);
    updater->start();
    connect( updater, SIGNAL(timeout()), this, SLOT(&MainWindow::update));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::update(){
    //Sleep(11); bidouille
    if(launched) simulation->update();
    ui->openGlWid->update();

}

void MainWindow::on_addV_clicked()
{
    simulation->addCar();
    ui->openGlWid->update();
}

void MainWindow::on_removeV_clicked()
{
    simulation->removeACar();
    ui->openGlWid->update();
}

void MainWindow::on_displayMap_clicked()
{
    if(!displayMap){
        displayMap = true;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Enlever Carte");
    }else{
        displayMap = false;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Afficher Carte");
    }
    ui->openGlWid->update();
}


void MainWindow::on_displayMesh_clicked()
{
    if(!displayMesh){
        displayMesh = true;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Enlever Maille");
    }else{
        displayMesh = false;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Afficher Maille");
    }

    ui->openGlWid->update();
}

void MainWindow::on_zoomOut_clicked()
{
    ui->openGlWid->decreaseZoom();
    ui->openGlWid->update();
}

void MainWindow::on_zoomIn_clicked()
{
    ui->openGlWid->increaseZoom();
    ui->openGlWid->update();
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
    // TODO A ENLEVER
    simulation->update();
    ui->openGlWid->update();
}
