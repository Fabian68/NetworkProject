#include "mapopengl.h"
#include "qpainter.h"
#include <QCoreApplication>
#include <iostream>
#include<QDebug>
#include<QFile>

MapOpenGL::MapOpenGL( QWidget* parent) : QOpenGLWidget (parent)
{

}

void MapOpenGL::initializeGL(){
    bg = new QImage();
    bg->load(QString(":/:/resource/mulhouse.PNG"));
}

void MapOpenGL::setSimulation( Simulation* simul){
    simulation = simul;
}

void MapOpenGL::addMultiplier(){
    multiplier++;
}
void MapOpenGL::lessMultiplier(){
    if(multiplier != 1){
        multiplier--;
    }
}

void MapOpenGL::paintGL(){
    QPainter p(this);
    p.setPen(Qt::white);

    if(drawMap){
        p.setPen(Qt::black);
        QRectF target( 0, 0, 399 * multiplier, 200 * multiplier);
        p.drawImage( target, *bg);
    }

    if(drawMesh){

    }


    /*p.drawLine(QLineF(10, 10, 500, 500));
     p.drawLine(QLineF(500, 10, 10, 500));*/

}

void MapOpenGL::setDrawMesh( bool mesh){
    drawMesh = mesh;
}
void MapOpenGL::setDrawMap( bool map){
    drawMap = map;
}

void MapOpenGL::resizeGL( int width, int heigh){

}

