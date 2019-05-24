#ifndef OBJETO_GEOMETRICO_H
#define OBJETO_GEOMETRICO_H
#include "Rayo.h"
#include "ColorRGB.h"
class ObjetoGeometrico{
    public:
    bool sombra;
    ObjetoGeometrico(bool);
    virtual bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const = 0;
    virtual ColorRGB obtenerColor(Punto3D hitp) = 0;
};
#endif
