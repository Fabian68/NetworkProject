#ifndef MAPOPENGL_H
#define MAPOPENGL_H

//#include "modele/simulation.h"
#include <QOpenGLWidget>

class MapOpenGL : public QOpenGLWidget
{
public:
    MapOpenGL( QWidget* parent = NULL);

    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL( int width, int heigh);

    //void setSimulation( Simulation simul);
private:
    QImage* bg;
    //Simulation simulation;
};

#endif // MAPOPENGL_H
