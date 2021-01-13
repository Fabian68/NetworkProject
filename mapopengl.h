#ifndef MAPOPENGL_H
#define MAPOPENGL_H

#include "Modele/simulation.h"
#include <QOpenGLWidget>

class MapOpenGL : public QOpenGLWidget
{
public:
    MapOpenGL( QWidget* parent = nullptr);

    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL( int width, int heigh);
    void setDrawMesh( bool mesh);
    void setDrawMap( bool map);
    void setSimulation( Simulation* simul);
    void addMultiplier();
    void lessMultiplier();
private:
    QImage* bg;
    QImage* car;
    Simulation* simulation;
    bool drawMesh = true;
    bool drawMap = true;
    int multiplier = 1;
};

#endif // MAPOPENGL_H
