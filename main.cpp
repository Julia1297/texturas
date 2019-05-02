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

    LuzPuntual luz(0.2, 0.3, 0.6,-350,-250,-80);
    LuzPuntual luz_ambiente(0.8, 0.7, 0.4, 0.0, 0.0, 0.0);
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
    Punto3D C_piernaIzquierda3(-50,-370,-100);

    Punto3D A_piernaIzquierda4(-100,-260,-100);
    Punto3D B_piernaIzquierda4(-50,-370,-100);
    Punto3D C_piernaIzquierda4(-75,-370,-100);

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

    Punto3D A_brazoIzquierdo1(-200,0,-100);
    Punto3D B_brazoIzquierdo1(-270,-140,-100);
    Punto3D C_brazoIzquierdo1(-180,-25,-100);

    Punto3D A_brazoIzquierdo2(-270,-140,-100);
    Punto3D B_brazoIzquierdo2(-245,-140,-100);
    Punto3D C_brazoIzquierdo2(-180,-25,-100);
    Triangulo brazoIzquierdo1(A_brazoIzquierdo1,B_brazoIzquierdo1,C_brazoIzquierdo1);
    brazoIzquierdo1.establecerColor(0,1,0);
    Triangulo brazoIzquierdo2(A_brazoIzquierdo2,B_brazoIzquierdo2,C_brazoIzquierdo2);
    brazoIzquierdo2.establecerColor(0,1,0);

    Punto3D A_brazoIzquierdo3(-270,-140,-100);
    Punto3D B_brazoIzquierdo3(-245,-140,-100);
    Punto3D C_brazoIzquierdo3(-220,-255,-100);

    Punto3D A_brazoIzquierdo4(-270,-140,-100);
    Punto3D B_brazoIzquierdo4(-220,-255,-100);
    Punto3D C_brazoIzquierdo4(-245,-255,-100);

    Triangulo brazoIzquierdo3(A_brazoIzquierdo3,B_brazoIzquierdo3,C_brazoIzquierdo3);
    brazoIzquierdo3.establecerColor(0,1,0);
    Triangulo brazoIzquierdo4(A_brazoIzquierdo4,B_brazoIzquierdo4,C_brazoIzquierdo4);
    brazoIzquierdo4.establecerColor(0,1,0);


    Punto3D A_brazoDerecho1(200,0,-100);
    Punto3D B_brazoDerecho1(320,0,-100);
    Punto3D C_brazoDerecho1(180,-25,-100);
    Punto3D A_brazoDerecho2(320,0,-100);
    Punto3D B_brazoDerecho2(320,-25,-100);
    Punto3D C_brazoDerecho2(180,-25,-100);
    Triangulo brazoDerecho1(A_brazoDerecho1,B_brazoDerecho1,C_brazoDerecho1);
    brazoDerecho1.establecerColor(0,1,0);
    Triangulo brazoDerecho2(A_brazoDerecho2,B_brazoDerecho2,C_brazoDerecho2);
    brazoDerecho2.establecerColor(0,1,0);

    Punto3D A_brazoDerecho3(320,0,-100);
    Punto3D B_brazoDerecho3(295,0,-100);
    Punto3D C_brazoDerecho3(260,130,-100);

    Punto3D A_brazoDerecho4(260,130,-100);
    Punto3D B_brazoDerecho4(280,130,-100);
    Punto3D C_brazoDerecho4(320,0,-100);

    Triangulo brazoDerecho3(A_brazoDerecho3,B_brazoDerecho3,C_brazoDerecho3);
    brazoDerecho3.establecerColor(0,1,0);
    Triangulo brazoDerecho4(A_brazoDerecho4,B_brazoDerecho4,C_brazoDerecho4);
    brazoDerecho4.establecerColor(0,1,0);

    Punto3D pieIzquierdo_dedo1(-75, -400, -100);
    Esfera esfera_pieIzquierdo_dedo1(pieIzquierdo_dedo1, 8);
    esfera_pieIzquierdo_dedo1.establecerColor(0, 1, 0);

    Punto3D pieIzquierdo_dedo2(-90, -395, -100);
    Esfera esfera_pieIzquierdo_dedo2(pieIzquierdo_dedo2, 10);
    esfera_pieIzquierdo_dedo2.establecerColor(0, 1, 0);

    Punto3D pieIzquierdo_dedo3(-100, -390, -100);
    Esfera esfera_pieIzquierdo_dedo3(pieIzquierdo_dedo3, 8);
    esfera_pieIzquierdo_dedo3.establecerColor(0, 1, 0);

    Punto3D A_pieIzquierdo1(-100,-390,-90);
    Punto3D B_pieIzquierdo1(-90, -395, -100);
    Punto3D C_pieIzquierdo1(-75,-370,-100);

    Punto3D A_pieIzquierdo2(-75,-370,-100);
    Punto3D B_pieIzquierdo2(-50,-370,-100);
    Punto3D C_pieIzquierdo2(-90, -395, -100);

    Punto3D A_pieIzquierdo3(-90, -395, -100);
    Punto3D B_pieIzquierdo3(-75, -400, -100);
    Punto3D C_pieIzquierdo3(-50,-370,-100);

    Triangulo pieIzquierdo1(A_pieIzquierdo1,B_pieIzquierdo1,C_pieIzquierdo1);
    pieIzquierdo1.establecerColor(0,1,0);
    Triangulo pieIzquierdo2(A_pieIzquierdo2,B_pieIzquierdo2,C_pieIzquierdo2);
    pieIzquierdo2.establecerColor(0,1,0);
    Triangulo pieIzquierdo3(A_pieIzquierdo3,B_pieIzquierdo3,C_pieIzquierdo3);
    pieIzquierdo3.establecerColor(0,1,0);


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

    escena.push_back(&brazoIzquierdo1);
    escena.push_back(&brazoIzquierdo2);
    escena.push_back(&brazoIzquierdo3);
    escena.push_back(&brazoIzquierdo4);

    escena.push_back(&brazoDerecho1);
    escena.push_back(&brazoDerecho2);
    escena.push_back(&brazoDerecho3);
    escena.push_back(&brazoDerecho4);

    escena.push_back(&esfera_pieIzquierdo_dedo1);
    escena.push_back(&esfera_pieIzquierdo_dedo2);
    escena.push_back(&esfera_pieIzquierdo_dedo3);

    escena.push_back(&pieIzquierdo1);
    escena.push_back(&pieIzquierdo2);
    escena.push_back(&pieIzquierdo3);
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

            pixeles[fil * width + col].r = obtenerColorPixel(rayo, escena, luz, luz_ambiente).r;
            pixeles[fil * width + col].g = obtenerColorPixel(rayo, escena, luz, luz_ambiente).g;
            pixeles[fil * width + col].b = obtenerColorPixel(rayo, escena, luz, luz_ambiente).b;
        }
    }
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}