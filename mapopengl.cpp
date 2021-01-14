#include "mapopengl.h"
#include "qpainter.h"
#include <QCoreApplication>
#include <iostream>
#include<QDebug>
#include<QFile>

MapOpenGL::MapOpenGL( QWidget* parent) : QOpenGLWidget (parent), zoom{1}
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

void MapOpenGL::increaseZoom(){
    zoom++;
}
void MapOpenGL::decreaseZoom(){
    if(zoom != 1){
        zoom--;
    }
}

void MapOpenGL::paintGL(){

    QPainter p(this);
    p.setPen(Qt::white);

    //draw the map
    if(drawMap){
        p.setPen(Qt::black);
        QRectF target( 0, 0, 399 * zoom, 200 * zoom);
        p.drawImage( target, *bg);
    }

    //draw the mesh
    if(drawMesh){
        /*p.drawLine(QLineF(10, 10, 500, 500));
         p.drawLine(QLineF(500, 10, 10, 500));*/
        //for(int i=0; i < simulation->getMesh().getColSize();){



    }

    //Draw the nodes
    p.setPen(Qt::red);
    for( int i=0; i < simulation->getNodes().size(); i++)
    {
        p.drawEllipse((simulation->getNodes()[i]->getX()-3)*zoom, (simulation->getNodes()[i]->getY()-3)*zoom,6,6);
    }

    //Draw all the ways
    //qDebug() << simulation->getWays().size();
    p.setPen(Qt::blue);
    for( int i=0; i < simulation->getWays().size(); i++){
        Node* node1 = simulation->getWays()[i]->getNode1();
        Node* node2 = simulation->getWays()[i]->getNode2();
        //qDebug() << "node1.x=" << node1->getX() <<  " node1.y=" << node1->getY() << " node2.x=" << node2->getX() << " node2.y=" << node2->getY();
        p.drawLine( QLineF( node1->getX()*zoom, node1->getY()*zoom, node2->getX()*zoom, node2->getY()*zoom));
    }

    //Draw the cars
    vector<Car*> cars = simulation->getCars();
    for( int i=0; i < cars.size(); i++){
        Point point = cars[i]->getPosition();
        QRectF target((point.getX()-6)*zoom, (point.getY()-6)*zoom, 12*zoom, 12*zoom);
        p.drawImage( target, *car);
    }

}

void MapOpenGL::setDrawMesh( bool mesh){
    drawMesh = mesh;
}
void MapOpenGL::setDrawMap( bool map){
    drawMap = map;
}

void MapOpenGL::resizeGL( int width, int height){

}

