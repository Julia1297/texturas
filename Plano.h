#ifndef PLANO_H
#define PLANO_H
#include "ObjetoGeometrico.h"
#include "ColorRGB.h"
#include "ImageTexture.h"
class Plano : public ObjetoGeometrico
{
    public:
    Plano(Punto3D, Vector3D,bool);
    bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const;
    void establecerColor(double, double, double);

    Punto3D p;
    Vector3D n;
    ColorRGB color;
};
#endif