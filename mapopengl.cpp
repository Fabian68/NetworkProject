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

void MapOpenGL::paintGL(){
    QPainter p(this);

    p.setPen(Qt::white);
    QRectF target( 10, 10, 409, 210);
    //QRectF source( 0.0, 0.0, 399, 200);
    p.drawImage( target, *bg);


    /*p.drawLine(QLineF(10, 10, 500, 500));
     p.drawLine(QLineF(500, 10, 10, 500));*/

}

void MapOpenGL::resizeGL( int width, int heigh){

}

