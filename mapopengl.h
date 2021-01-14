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
    virtual void resizeGL( int width, int height);
    void setDrawMesh( bool mesh);
    void setDrawMap( bool map);
    void setSimulation( Simulation* simul);
    void increaseZoom();
    void decreaseZoom();

private:
    QImage* bg;
    QImage* car;
    Simulation* simulation;
    bool drawMesh = true;
    bool drawMap = true;
    int zoom;
};

#endif // MAPOPENGL_H
