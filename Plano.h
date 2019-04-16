#ifndef PLANO_H
#define PLANO_H
#include "ObjetoGeometrico.h"
#include "ColorRGB.h"
#include <iostream>
using namespace std;

class Plano : public ObjetoGeometrico
{
    public:
    Plano(Punto3D, Vector3D);
    bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const;
    ColorRGB obtenerColor();
    void establecerColor(double, double, double);

    Punto3D p;
    Vector3D n;
    ColorRGB color;
    double limSup;
    double limInf;
    double limIzq;
    double limDer ;
};
#endif