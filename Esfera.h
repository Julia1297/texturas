// #include "Punto3D.h"
#include "Rayo.h"
#include "ColorRGB.h"
#include "ObjetoGeometrico.h"
#include "ImTexture.h"

class Esfera : public ObjetoGeometrico
{
    public:
    Esfera(Punto3D, double,bool);
    ~Esfera();
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor(Punto3D hitp);
    void setImTexture();

    Punto3D c;
    double r;
    ColorRGB color;
    ImTexture* im;
    Image m;
    SphereMap sm;
};