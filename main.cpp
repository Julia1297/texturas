#include <vector>
#include <iostream>
#include <math.h>
#include "Vector3D.h"
#include "Esfera.h"
#include "Plano.h"
#include "Triangulo.h"
#include "ViewPlane.h"
#include "LuzPuntual.h"
#include "Utilitarios.h"

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

ColorRGB obtenerColorPixel(const Rayo &r, vector<ObjetoGeometrico *> objetos, LuzPuntual luz, LuzPuntual luz_ambiente)
{
    {

        ColorRGB color;

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
                color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                tmin = t;
            }
        }
        return color;
    }
}

int main()
{

    LuzPuntual luz(0.5, 0.5, 0.5,-350,-250,-80);
    LuzPuntual luz_ambiente(0.5, 0.5, 0.5, 0.0, 0.0, 0.0);
    vector<ObjetoGeometrico *> escena;

    // ESCENA------------------------------------------------------------------
    Punto3D cara(0, 0, -100);
    Esfera esfera_cara(cara, 200);
    esfera_cara.establecerColor(0, 1, 0);

    Punto3D ojo(0, 50, -50);
    Esfera esfera_ojo(ojo, 100);
    esfera_ojo.establecerColor(1, 1, 1);
    
    Punto3D pupila(0, 50, -25);
    Esfera esfera_pupila(pupila, 40);
    esfera_pupila.establecerColor(0, 1, 1);

    Punto3D iris(0, 50, -15);
    Esfera esfera_iris(iris, 20);
    esfera_iris.establecerColor(0,0,0);

    Punto3D brilloOjo(7, 62, -0);
    Esfera esfera_brilloOjo(brilloOjo, 5);
    esfera_brilloOjo.establecerColor(1,1,1);

    Punto3D A_orejaIzquierda(-65,190,-100);
    Punto3D B_orejaIzquierda(-80,220,-100);
    Punto3D C_orejaIzquierda(-95,176,-100);

    Punto3D A_orejaDerecha(65,190,-100);
    Punto3D B_orejaDerecha(80,220,-100);
    Punto3D C_orejaDerecha(95,176,-100);

    Triangulo orejaIzquierda(A_orejaIzquierda,B_orejaIzquierda,C_orejaIzquierda);
    orejaIzquierda.establecerColor(1,1,1);
    Triangulo orejaDerecha(A_orejaDerecha,B_orejaDerecha,C_orejaDerecha);
    orejaDerecha.establecerColor(1,1,1);


    Punto3D A_piernaIzquierda1(-95,-176,-100);
    Punto3D B_piernaIzquierda1(-65,-190,-100);
    Punto3D C_piernaIzquierda1(-70,-260,-100);

    Punto3D A_piernaIzquierda2(-95,-170,-100);
    Punto3D B_piernaIzquierda2(-70,-260,-100);
    Punto3D C_piernaIzquierda2(-100,-260,-100);

    Triangulo piernaIzquierda1(A_piernaIzquierda1,B_piernaIzquierda1,C_piernaIzquierda1);
    piernaIzquierda1.establecerColor(0,1,0);
    Triangulo piernaIzquierda2(A_piernaIzquierda2,B_piernaIzquierda2,C_piernaIzquierda2);
    piernaIzquierda2.establecerColor(0,1,0);

    Punto3D A_piernaIzquierda3(-100,-260,-100);
    Punto3D B_piernaIzquierda3(-70,-260,-100);
    Punto3D C_piernaIzquierda3(-50,-360,-100);

    Punto3D A_piernaIzquierda4(-100,-260,-100);
    Punto3D B_piernaIzquierda4(-50,-360,-100);
    Punto3D C_piernaIzquierda4(-75,-360,-100);

    Triangulo piernaIzquierda3(A_piernaIzquierda3,B_piernaIzquierda3,C_piernaIzquierda3);
    piernaIzquierda3.establecerColor(0,1,0);
    Triangulo piernaIzquierda4(A_piernaIzquierda4,B_piernaIzquierda4,C_piernaIzquierda4);
    piernaIzquierda4.establecerColor(0,1,0);

    Punto3D A_piernaDerecha1(95,-176,-100);
    Punto3D B_piernaDerecha1(65,-190,-100);
    Punto3D C_piernaDerecha1(70,-260,-100);

    Punto3D A_piernaDerecha2(95,-170,-100);
    Punto3D B_piernaDerecha2(70,-260,-100);
    Punto3D C_piernaDerecha2(100,-260,-100);

    Triangulo piernaDerecha1(A_piernaDerecha1,B_piernaDerecha1,C_piernaDerecha1);
    piernaDerecha1.establecerColor(0,1,0);
    Triangulo piernaDerecha2(A_piernaDerecha2,B_piernaDerecha2,C_piernaDerecha2);
    piernaDerecha2.establecerColor(0,1,0);

    Punto3D A_piernaDerecha3(100,-260,-100);
    Punto3D B_piernaDerecha3(70,-260,-100);
    Punto3D C_piernaDerecha3(50,-360,-100);

    Punto3D A_piernaDerecha4(100,-260,-100);
    Punto3D B_piernaDerecha4(50,-360,-100);
    Punto3D C_piernaDerecha4(75,-360,-100);

    Triangulo piernaDerecha3(A_piernaDerecha3,B_piernaDerecha3,C_piernaDerecha3);
    piernaDerecha3.establecerColor(0,1,0);
    Triangulo piernaDerecha4(A_piernaDerecha4,B_piernaDerecha4,C_piernaDerecha4);
    piernaDerecha4.establecerColor(0,1,0);


    escena.push_back(&esfera_cara);
    escena.push_back(&esfera_ojo);
    escena.push_back(&esfera_pupila);
    escena.push_back(&esfera_iris);
    escena.push_back(&esfera_brilloOjo);

    escena.push_back(&orejaIzquierda);
    escena.push_back(&orejaDerecha);

    escena.push_back(&piernaIzquierda1);
    escena.push_back(&piernaIzquierda2);
    escena.push_back(&piernaIzquierda3);
    escena.push_back(&piernaIzquierda4);

    escena.push_back(&piernaDerecha1);
    escena.push_back(&piernaDerecha2);
    escena.push_back(&piernaDerecha3);
    escena.push_back(&piernaDerecha4);

    // VIEWPLANE
    int hres = 1000;
    int vres = 800;
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

            pixeles[fil * width + col].r = obtenerColorPixel(rayo, escena, luz, luz_ambiente).r;
            pixeles[fil * width + col].g = obtenerColorPixel(rayo, escena, luz, luz_ambiente).g;
            pixeles[fil * width + col].b = obtenerColorPixel(rayo, escena, luz, luz_ambiente).b;
        }
    }
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}