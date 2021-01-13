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
    car = new QImage();
    car->load(QString(":/:/resource/voiture.png"));
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

    //draw the map
    if(drawMap){
        p.setPen(Qt::black);
        QRectF target( 0, 0, 399 * multiplier, 200 * multiplier);
        p.drawImage( target, *bg);
    }

    //draw the mesh
    if(drawMesh){
        /*p.drawLine(QLineF(10, 10, 500, 500));
         p.drawLine(QLineF(500, 10, 10, 500));*/
    }

    //Draw all the ways
    qDebug() << simulation->getWays().size();
    int i;
    for( i=0; i < simulation->getWays().size(); i++){
        Node* node1 = simulation->getWays()[i]->getNode1();
        Node* node2 = simulation->getWays()[i]->getNode2();
        qDebug() << "node1.x=" << node1->getX() <<  " node1.y=" << node1->getY() << " node2.x=" << node2->getX() << " node2.y=" << node2->getY();
        p.drawLine( QLineF( node1->getX()*multiplier, node1->getY()*multiplier, node2->getX()*multiplier, node2->getY()*multiplier));
    }

    //Draw the cars
    vector<Car*> cars = simulation->getCars();
    for( i=0; i < cars.size(); i++){
        Point point = cars[i]->getPosition();
        QRectF target( (point.getX()-1.5)*multiplier, (point.getY()-1)*multiplier, (point.getX()+1.5)*multiplier, (point.getY()+1)*multiplier);
        p.drawImage( target, *car);
    }

}

void MapOpenGL::setDrawMesh( bool mesh){
    drawMesh = mesh;
}
void MapOpenGL::setDrawMap( bool map){
    drawMap = map;
}

void MapOpenGL::resizeGL( int width, int heigh){

}

