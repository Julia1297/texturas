#include <vector>
#include <iostream>
#include <algorithm> 
#include <math.h>
using namespace std;
#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Rayo.h"
#include "LuzPuntual.h"
#include "Utilitarios.h"
#include "Plano.h"
#include "Triangulo.h"


using namespace std;

double acotar(double n)
{
    if (n > 1.0)
    {
        return 1.0;
    }
    else
    {
        return n;
    }
}

ColorRGB obtenerColorPixel(const Rayo &r, vector<ObjetoGeometrico *> objetos, LuzPuntual luz, LuzPuntual luz_ambiente, ImageTexture& a)
{
    {

        ColorRGB color=a.get_color();

        color.r = 0.0;
        color.g = 0.0;
        color.b = 0.0;

        double t;
        double tmin = 2000000;
        Vector3D n;
        Punto3D q;

        Vector3D h;
        for (int i = 0; i < objetos.size(); i++)
        {
            if (objetos[i]->hayImpacto(r, t, n, q) && t < tmin)
            {
                // color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                // color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                // color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                // tmin = t;
                color.r = objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * luz_ambiente.color.r + objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * luz.color.r * max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * luz.color.r * pow(max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                color.g = objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).g * luz_ambiente.color.g + objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).g * luz.color.g * max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).g * luz.color.g * pow(max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                color.b = objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).b * luz_ambiente.color.b + objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).b * luz.color.b * max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).b * luz.color.b * pow(max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);

                
                


                // double t_sombra;
                // double t_min_sombra = 2000000;
                // Vector3D n_sombra;
                // Punto3D q_sombra;
                // Rayo rayo_sombra(q, (luz.posicion - q)) ;
                // for (int j = 0; j < objetos.size(); j++) {
                //     if ((objetos[j]->hayImpacto(rayo_sombra, t_sombra, n_sombra, q_sombra) && t_sombra < t_min_sombra)) {
                //         color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r;
                //         color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g;
                //         color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b;
                //         t_min_sombra = t_sombra;
                //     }
                // }
                tmin = t;

               
            }
        }
        return color;
    }
}

int main()
{

    Image l;
    l.read_ppm_file("ugh22.ppm");
    ImageTexture a(&l);
    LuzPuntual luz(0.5, 0.5, 0.9,0,130,-550);
    LuzPuntual luz_ambiente(0.5, 0.5, 0.1, 0,0,100);
    vector<ObjetoGeometrico *> escena;

    // ESCENA------------------------------------------------------------------
     Punto3D centroNube(-150.0, -150.0, -50.0);
    double radioNube = 100;
    Esfera nube1(centroNube, radioNube, true);   
    nube1.setImTexture();

    escena.push_back(&nube1);
    


    // VIEWPLANE
    int hres = 1000;
    int vres = 1000;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);

    // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB *pixeles = new ColorRGB[n];

    // ALGORITMO
    for (int fil = 0; fil < vp.vres; fil++)
    {
        for (int col = 0; col < vp.hres; col++)
        {
            // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x = vp.s * (col - vp.hres / 2 + 0.5);
            double y = vp.s * (fil - vp.vres / 2 + 0.5);
            double z = 0;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil * width + col].r = obtenerColorPixel(rayo, escena, luz, luz_ambiente, a).r;
            pixeles[fil * width + col].g = obtenerColorPixel(rayo, escena, luz, luz_ambiente, a).g;
            pixeles[fil * width + col].b = obtenerColorPixel(rayo, escena, luz, luz_ambiente, a).b;
        }
    }
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}