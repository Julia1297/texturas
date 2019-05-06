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
                // color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                // color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                // color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat()) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1) * r.d + (luz.posicion - q).hat()).hat()), 10000);
                // tmin = t;
                color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);

                
                


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


    LuzPuntual luz(0.5, 0.5, 0.9,0,130,-550);
    LuzPuntual luz_ambiente(0.5, 0.5, 0.1, 0,0,100);
    vector<ObjetoGeometrico *> escena;

    // ESCENA------------------------------------------------------------------
    Punto3D cara(0, 0, -30);
    Esfera esfera_cara(cara, 200);
    esfera_cara.establecerColor(0, 1, 0);

    Punto3D ojo(0, 50, -20);
    Esfera esfera_ojo(ojo, 100);
    esfera_ojo.establecerColor(1, 1, 1);
    
    Punto3D pupila(0, 50, 5);
    Esfera esfera_pupila(pupila, 40);
    esfera_pupila.establecerColor(0, 1, 1);

    Punto3D iris(0, 50, -20);
    Esfera esfera_iris(iris, 20);
    esfera_iris.establecerColor(0,0,0);

    Punto3D brilloOjo(8, 60, 0);
    Esfera esfera_brilloOjo(brilloOjo, 5);
    esfera_brilloOjo.establecerColor(1,1,1);

    Punto3D A_orejaIzquierda(-80,220,-100);
    Punto3D B_orejaIzquierda(-65,190,-100);
    Punto3D C_orejaIzquierda(-95,176,-100);

    Punto3D A_orejaDerecha(65,190,-100);
    Punto3D B_orejaDerecha(80,220,-100);
    Punto3D C_orejaDerecha(95,176,-100);

    Triangulo orejaIzquierda(A_orejaIzquierda,B_orejaIzquierda,C_orejaIzquierda);
    orejaIzquierda.establecerColor(0.8,0.8,0.8);
    Triangulo orejaDerecha(A_orejaDerecha,B_orejaDerecha,C_orejaDerecha);
    orejaDerecha.establecerColor(0.8,0.8,0.8);


    Punto3D A_piernaIzquierda1(-65,-190,-100);
    Punto3D B_piernaIzquierda1(-95,-176,-100);
    Punto3D C_piernaIzquierda1(-70,-260,-100);

    Punto3D A_piernaIzquierda2(-70,-260,-100);
    Punto3D B_piernaIzquierda2(-95,-170,-100);
    Punto3D C_piernaIzquierda2(-100,-260,-100);

    Triangulo piernaIzquierda1(A_piernaIzquierda1,B_piernaIzquierda1,C_piernaIzquierda1);
    piernaIzquierda1.establecerColor(0,1,0);
    Triangulo piernaIzquierda2(A_piernaIzquierda2,B_piernaIzquierda2,C_piernaIzquierda2);
    piernaIzquierda2.establecerColor(0,1,0);

    Punto3D A_piernaIzquierda3(-70,-260,-100);
    Punto3D B_piernaIzquierda3(-100,-260,-100);
    Punto3D C_piernaIzquierda3(-50,-370,-100);

    Punto3D A_piernaIzquierda4(-50,-370,-100);
    Punto3D B_piernaIzquierda4(-100,-260,-100);
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
    Punto3D C_piernaDerecha3(50,-370,-100);

    Punto3D A_piernaDerecha4(100,-260,-100);
    Punto3D B_piernaDerecha4(50,-370,-100);
    Punto3D C_piernaDerecha4(75,-370,-100);

    Triangulo piernaDerecha3(A_piernaDerecha3,B_piernaDerecha3,C_piernaDerecha3);
    piernaDerecha3.establecerColor(0,1,0);
    Triangulo piernaDerecha4(A_piernaDerecha4,B_piernaDerecha4,C_piernaDerecha4);
    piernaDerecha4.establecerColor(0,1,0);

    Punto3D A_brazoIzquierdo1(-200,0,-100);
    Punto3D B_brazoIzquierdo1(-220,-140,-100);
    Punto3D C_brazoIzquierdo1(-180,-25,-100);

    Punto3D A_brazoIzquierdo2(-220,-140,-100);
    Punto3D B_brazoIzquierdo2(-195,-140,-100);
    Punto3D C_brazoIzquierdo2(-180,-25,-100);

    Triangulo brazoIzquierdo1(A_brazoIzquierdo1,B_brazoIzquierdo1,C_brazoIzquierdo1);
    brazoIzquierdo1.establecerColor(0,1,0);
    Triangulo brazoIzquierdo2(A_brazoIzquierdo2,B_brazoIzquierdo2,C_brazoIzquierdo2);
    brazoIzquierdo2.establecerColor(0,1,0);

    Punto3D A_brazoIzquierdo3(-195,-140,-100);
    Punto3D B_brazoIzquierdo3(-220,-140,-100);
    Punto3D C_brazoIzquierdo3(-170,-255,-100);
    
    Punto3D A_brazoIzquierdo4(-170,-255,-100);
    Punto3D B_brazoIzquierdo4(-220,-140,-100);
    Punto3D C_brazoIzquierdo4(-195,-255,-100);

    Triangulo brazoIzquierdo3(A_brazoIzquierdo3,B_brazoIzquierdo3,C_brazoIzquierdo3);
    brazoIzquierdo3.establecerColor(0,1,0);
    Triangulo brazoIzquierdo4(A_brazoIzquierdo4,B_brazoIzquierdo4,C_brazoIzquierdo4);
    brazoIzquierdo4.establecerColor(0,1,0);


    Punto3D A_brazoDerecho1(220,-140,-100);
    Punto3D B_brazoDerecho1(200,0,-100);
    Punto3D C_brazoDerecho1(180,-25,-100);

    Punto3D A_brazoDerecho2(195,-140,-100);
    Punto3D B_brazoDerecho2(220,-140,-100);
    Punto3D C_brazoDerecho2(180,-25,-100);

    Triangulo brazoDerecho1(A_brazoDerecho1,B_brazoDerecho1,C_brazoDerecho1);
    brazoDerecho1.establecerColor(0,1,0);
    Triangulo brazoDerecho2(A_brazoDerecho2,B_brazoDerecho2,C_brazoDerecho2);
    brazoDerecho2.establecerColor(0,1,0);

    Punto3D A_brazoDerecho3(220,-140,-100);
    Punto3D B_brazoDerecho3(195,-140,-100);
    Punto3D C_brazoDerecho3(170,-255,-100);
    Punto3D A_brazoDerecho4(220,-140,-100);
    Punto3D B_brazoDerecho4(170,-255,-100);
    Punto3D C_brazoDerecho4(195,-255,-100);

    Triangulo brazoDerecho3(A_brazoDerecho3,B_brazoDerecho3,C_brazoDerecho3);
    brazoDerecho3.establecerColor(0,1,0);
    Triangulo brazoDerecho4(A_brazoDerecho4,B_brazoDerecho4,C_brazoDerecho4);
    brazoDerecho4.establecerColor(0,1,0);

    //Pie izquierdo

    Punto3D pieIzquierdo_dedo1(-90, -390, -100);
    Esfera esfera_pieIzquierdo_dedo1(pieIzquierdo_dedo1, 8);
    esfera_pieIzquierdo_dedo1.establecerColor(0, 1, 0);

    Punto3D pieIzquierdo_dedo2(-105, -385, -100);
    Esfera esfera_pieIzquierdo_dedo2(pieIzquierdo_dedo2, 10);
    esfera_pieIzquierdo_dedo2.establecerColor(0, 1, 0);

    Punto3D pieIzquierdo_dedo3(-115, -380, -100);
    Esfera esfera_pieIzquierdo_dedo3(pieIzquierdo_dedo3, 8);
    esfera_pieIzquierdo_dedo3.establecerColor(0, 1, 0);

    Punto3D A_pieIzquierdo1(-120,-375,-90);
    Punto3D B_pieIzquierdo1(-105, -385, -100);
    Punto3D C_pieIzquierdo1(-75,-370,-100);

    Punto3D A_pieIzquierdo2(-50,-370,-100);
    Punto3D B_pieIzquierdo2(-75,-370,-100);
    Punto3D C_pieIzquierdo2(-105, -385, -100);

    Punto3D A_pieIzquierdo3(-105, -385, -100);
    Punto3D B_pieIzquierdo3(-85, -395, -100);
    Punto3D C_pieIzquierdo3(-50,-370,-100);

    Triangulo pieIzquierdo1(A_pieIzquierdo1,B_pieIzquierdo1,C_pieIzquierdo1);
    pieIzquierdo1.establecerColor(0,1,0);
    Triangulo pieIzquierdo2(A_pieIzquierdo2,B_pieIzquierdo2,C_pieIzquierdo2);
    pieIzquierdo2.establecerColor(0,1,0);
    Triangulo pieIzquierdo3(A_pieIzquierdo3,B_pieIzquierdo3,C_pieIzquierdo3);
    pieIzquierdo3.establecerColor(0,1,0);

    //Garras pie izquierdo

    Punto3D A_pieIzquierda_garra1(-94, -388, -80);
    Punto3D B_pieIzquierda_garra1(-87, -394,-80);
    Punto3D C_pieIzquierda_garra1(-97, -398,-80);

    Punto3D A_pieIzquierda_garra2(-107, -383, -80);
    Punto3D B_pieIzquierda_garra2(-100, -388,-80);
    Punto3D C_pieIzquierda_garra2(-113, -392,-80);

    Punto3D A_pieIzquierda_garra3(-120, -376, -80);
    Punto3D B_pieIzquierda_garra3(-114, -380,-80);
    Punto3D C_pieIzquierda_garra3(-125, -385,-80);

    Triangulo pieIzquierda_garra1(A_pieIzquierda_garra1,B_pieIzquierda_garra1,C_pieIzquierda_garra1);
    pieIzquierda_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo pieIzquierda_garra2(A_pieIzquierda_garra2,B_pieIzquierda_garra2,C_pieIzquierda_garra2);
    pieIzquierda_garra2.establecerColor(0.7,0.7,0.7);
    Triangulo pieIzquierda_garra3(A_pieIzquierda_garra3,B_pieIzquierda_garra3,C_pieIzquierda_garra3);
    pieIzquierda_garra3.establecerColor(0.7,0.7,0.7);
    //Pie derecho
    Punto3D pieDerecho_dedo1(80, -390, -100);
    Esfera esfera_pieDerecho_dedo1(pieDerecho_dedo1, 8);
    esfera_pieDerecho_dedo1.establecerColor(0, 1, 0);

    Punto3D pieDerecho_dedo2(95, -385, -100);
    Esfera esfera_pieDerecho_dedo2(pieDerecho_dedo2, 10);
    esfera_pieDerecho_dedo2.establecerColor(0, 1, 0);

    Punto3D pieDerecho_dedo3(105, -380, -100);
    Esfera esfera_pieDerecho_dedo3(pieDerecho_dedo3, 8);
    esfera_pieDerecho_dedo3.establecerColor(0, 1, 0);

    Punto3D A_pieDerecho1(95, -385, -100);
    Punto3D B_pieDerecho1(105,-380,-90);
    Punto3D C_pieDerecho1(75,-370,-100);

    Punto3D A_pieDerecho2(75,-370,-100);
    Punto3D B_pieDerecho2(50,-370,-100);
    Punto3D C_pieDerecho2(95, -385, -100);

    Punto3D A_pieDerecho3(80, -390, -100);
    Punto3D B_pieDerecho3(95, -385, -100);
    Punto3D C_pieDerecho3(50,-370,-100);

    Triangulo pieDerecho1(A_pieDerecho1,B_pieDerecho1,C_pieDerecho1);
    pieDerecho1.establecerColor(0,1,0);
    Triangulo pieDerecho2(A_pieDerecho2,B_pieDerecho2,C_pieDerecho2);
    pieDerecho2.establecerColor(0,1,0);
    Triangulo pieDerecho3(A_pieDerecho3,B_pieDerecho3,C_pieDerecho3);
    pieDerecho3.establecerColor(0,1,0);



    //Mano Izquierda
    Punto3D A_manoIzquierda1(-170,-255,-100);
    Punto3D B_manoIzquierda1(-195,-255,-100);
    Punto3D C_manoIzquierda1(-180, -280, -100);

    Punto3D A_manoIzquierda2(-180, -280, -100);
    Punto3D B_manoIzquierda2(-195, -255, -100);
    Punto3D C_manoIzquierda2(-205,-280,-100);

    Punto3D A_manoIzquierda3(-155, -275, -100);
    Punto3D B_manoIzquierda3(-170, -255, -100);
    Punto3D C_manoIzquierda3(-180,-270,-100);

    Punto3D A_manoIzquierda4(-180, -280, -100);
    Punto3D B_manoIzquierda4(-205,-280,-100);
    Punto3D C_manoIzquierda4(-195, -295, -100);

    Punto3D A_manoIzquierda5(-165,-295,-100);
    Punto3D B_manoIzquierda5(-180, -280, -100);
    Punto3D C_manoIzquierda5(-195, -295, -100);
    
    Triangulo manoIzquierda1(A_manoIzquierda1,B_manoIzquierda1,C_manoIzquierda1);
    manoIzquierda1.establecerColor(0,1,0);
    Triangulo manoIzquierda2(A_manoIzquierda2,B_manoIzquierda2,C_manoIzquierda2);
    manoIzquierda2.establecerColor(0,1,0);
    Triangulo manoIzquierda3(A_manoIzquierda3,B_manoIzquierda3,C_manoIzquierda3);
    manoIzquierda3.establecerColor(0,1,0);
    Triangulo manoIzquierda4(A_manoIzquierda4,B_manoIzquierda4,C_manoIzquierda4);
    manoIzquierda4.establecerColor(0,1,0);
    Triangulo manoIzquierda5(A_manoIzquierda5,B_manoIzquierda5,C_manoIzquierda5);
    manoIzquierda5.establecerColor(0,1,0);
    
    //Dedos de mano izquierda
    Punto3D A_manoIzquierda_dedo1(-165, -295,-100);
    Punto3D B_manoIzquierda_dedo1(-175, -295,-100);
    Punto3D C_manoIzquierda_dedo1(-150, -315, -100);

    Punto3D A_manoIzquierda_dedo2(-150, -315, -100);
    Punto3D B_manoIzquierda_dedo2(-175, -295, -100);
    Punto3D C_manoIzquierda_dedo2(-157, -315,-100);

    Punto3D A_manoIzquierda_dedo3(-180, -295,-100);
    Punto3D B_manoIzquierda_dedo3(-195, -295, -100);
    Punto3D C_manoIzquierda_dedo3(-160, -310, -100);


    Punto3D A_manoIzquierda_dedo4(-155, -275, -100);
    Punto3D B_manoIzquierda_dedo4(-165, -273, -100);
    Punto3D C_manoIzquierda_dedo4(-150, -300,-100);

    Punto3D A_manoIzquierda_dedo5(-150, -300,-100);
    Punto3D B_manoIzquierda_dedo5(-165, -273, -100);
    Punto3D C_manoIzquierda_dedo5(-155, -300,-100);

    Triangulo manoIzquierda_dedo1(A_manoIzquierda_dedo1,B_manoIzquierda_dedo1,C_manoIzquierda_dedo1);
    manoIzquierda_dedo1.establecerColor(0,1,0);
    Triangulo manoIzquierda_dedo2(A_manoIzquierda_dedo2,B_manoIzquierda_dedo2,C_manoIzquierda_dedo2);
    manoIzquierda_dedo2.establecerColor(0,1,0);
    Triangulo manoIzquierda_dedo3(A_manoIzquierda_dedo3,B_manoIzquierda_dedo3,C_manoIzquierda_dedo3);
    manoIzquierda_dedo3.establecerColor(0,1,0);

    Triangulo manoIzquierda_dedo4(A_manoIzquierda_dedo4,B_manoIzquierda_dedo4,C_manoIzquierda_dedo4);
    manoIzquierda_dedo4.establecerColor(0,1,0);
    Triangulo manoIzquierda_dedo5(A_manoIzquierda_dedo5,B_manoIzquierda_dedo5,C_manoIzquierda_dedo5);
    manoIzquierda_dedo5.establecerColor(0,1,0);



    Punto3D A_manoIzquierda_garra1(-160, -313,-80);
    Punto3D B_manoIzquierda_garra1(-151, -313,-80);
    Punto3D C_manoIzquierda_garra1(-149, -319,-80);

    Punto3D A_manoIzquierda_garra2(-155, -300,-80);
    Punto3D B_manoIzquierda_garra2(-150, -300,-80);
    Punto3D C_manoIzquierda_garra2(-153, -308,-80);

    Triangulo manoIzquierda_garra1(A_manoIzquierda_garra1,B_manoIzquierda_garra1,C_manoIzquierda_garra1);
    manoIzquierda_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo manoIzquierda_garra2(A_manoIzquierda_garra2,B_manoIzquierda_garra2,C_manoIzquierda_garra2);
    manoIzquierda_garra2.establecerColor(0.7,0.7,0.7);

    //Dedos de mano derecha
    Punto3D A_manoDerecha1(195,-255,-100);
    Punto3D B_manoDerecha1(170,-255,-100);
    Punto3D C_manoDerecha1(180, -280, -100);

    Punto3D A_manoDerecha2(195, -255, -100);
    Punto3D B_manoDerecha2(180, -280, -100);
    Punto3D C_manoDerecha2(205,-280,-100);

    Punto3D A_manoDerecha3(170, -255, -100);
    Punto3D B_manoDerecha3(155, -275, -100);
    Punto3D C_manoDerecha3(180,-270,-100);

    Punto3D A_manoDerecha4(205,-280,-100);
    Punto3D B_manoDerecha4(180, -280, -100);
    Punto3D C_manoDerecha4(195, -295, -100);

    Punto3D A_manoDerecha5(180, -280, -100);
    Punto3D B_manoDerecha5(165,-295,-100);
    Punto3D C_manoDerecha5(195, -295, -100);
    
    Triangulo manoDerecha1(A_manoDerecha1,B_manoDerecha1,C_manoDerecha1);
    manoDerecha1.establecerColor(0,1,0);
    Triangulo manoDerecha2(A_manoDerecha2,B_manoDerecha2,C_manoDerecha2);
    manoDerecha2.establecerColor(0,1,0);
    Triangulo manoDerecha3(A_manoDerecha3,B_manoDerecha3,C_manoDerecha3);
    manoDerecha3.establecerColor(0,1,0);
    Triangulo manoDerecha4(A_manoDerecha4,B_manoDerecha4,C_manoDerecha4);
    manoDerecha4.establecerColor(0,1,0);
    Triangulo manoDerecha5(A_manoDerecha5,B_manoDerecha5,C_manoDerecha5);
    manoDerecha5.establecerColor(0,1,0);
    
    Punto3D A_manoDerecha_dedo1(175, -295,-100);
    Punto3D B_manoDerecha_dedo1(165, -295,-100);
    Punto3D C_manoDerecha_dedo1(150, -315, -100);

    Punto3D A_manoDerecha_dedo2(175, -295, -100);
    Punto3D B_manoDerecha_dedo2(150, -315, -100);
    Punto3D C_manoDerecha_dedo2(157, -315,-100);

    Punto3D A_manoDerecha_dedo3(195, -295, -100);
    Punto3D B_manoDerecha_dedo3(180, -295,-100);
    Punto3D C_manoDerecha_dedo3(160, -310, -100);


    Punto3D A_manoDerecha_dedo4(165, -273, -100);
    Punto3D B_manoDerecha_dedo4(155, -275, -100);
    Punto3D C_manoDerecha_dedo4(150, -300,-100);

    Punto3D A_manoDerecha_dedo5(165, -273, -100);
    Punto3D B_manoDerecha_dedo5(150, -300,-100);
    Punto3D C_manoDerecha_dedo5(155, -300,-100);

    Triangulo manoDerecha_dedo1(A_manoDerecha_dedo1,B_manoDerecha_dedo1,C_manoDerecha_dedo1);
    manoDerecha_dedo1.establecerColor(0,1,0);
    Triangulo manoDerecha_dedo2(A_manoDerecha_dedo2,B_manoDerecha_dedo2,C_manoDerecha_dedo2);
    manoDerecha_dedo2.establecerColor(0,1,0);
    Triangulo manoDerecha_dedo3(A_manoDerecha_dedo3,B_manoDerecha_dedo3,C_manoDerecha_dedo3);
    manoDerecha_dedo3.establecerColor(0,1,0);

    Triangulo manoDerecha_dedo4(A_manoDerecha_dedo4,B_manoDerecha_dedo4,C_manoDerecha_dedo4);
    manoDerecha_dedo4.establecerColor(0,1,0);
    Triangulo manoDerecha_dedo5(A_manoDerecha_dedo5,B_manoDerecha_dedo5,C_manoDerecha_dedo5);
    manoDerecha_dedo5.establecerColor(0,1,0);



    Punto3D A_manoDerecha_garra1(151, -313,-80);
    Punto3D B_manoDerecha_garra1(160, -313,-80);
    Punto3D C_manoDerecha_garra1(149, -319,-80);

    Punto3D A_manoDerecha_garra2(150, -300,-80);
    Punto3D B_manoDerecha_garra2(155, -300,-80);
    Punto3D C_manoDerecha_garra2(153, -308,-80);

    Triangulo manoDerecha_garra1(A_manoDerecha_garra1,B_manoDerecha_garra1,C_manoDerecha_garra1);
    manoDerecha_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo manoDerecha_garra2(A_manoDerecha_garra2,B_manoDerecha_garra2,C_manoDerecha_garra2);
    manoDerecha_garra2.establecerColor(0.7,0.7,0.7);

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

    escena.push_back(&esfera_pieDerecho_dedo1);
    escena.push_back(&esfera_pieDerecho_dedo2);
    escena.push_back(&esfera_pieDerecho_dedo3);

    escena.push_back(&pieDerecho1);
    escena.push_back(&pieDerecho2);
    escena.push_back(&pieDerecho3);

    escena.push_back(&manoIzquierda1);
    escena.push_back(&manoIzquierda2);
    escena.push_back(&manoIzquierda3);
    escena.push_back(&manoIzquierda4);
    escena.push_back(&manoIzquierda5);

    escena.push_back(&manoIzquierda_dedo1);
    escena.push_back(&manoIzquierda_dedo3);
  
    escena.push_back(&manoIzquierda_dedo2);
    escena.push_back(&manoIzquierda_dedo4);
    escena.push_back(&manoIzquierda_dedo5);

    escena.push_back(&manoIzquierda_garra1);
    escena.push_back(&manoIzquierda_garra2);

    escena.push_back(&manoDerecha1);
    escena.push_back(&manoDerecha2);
    escena.push_back(&manoDerecha3);
    escena.push_back(&manoDerecha4);
    escena.push_back(&manoDerecha5);

    escena.push_back(&manoDerecha_dedo1);
    escena.push_back(&manoDerecha_dedo3);
  
    escena.push_back(&manoDerecha_dedo2);
    escena.push_back(&manoDerecha_dedo4);
    escena.push_back(&manoDerecha_dedo5);

    escena.push_back(&manoDerecha_garra1);
    escena.push_back(&manoDerecha_garra2);

    escena.push_back(&pieIzquierda_garra1);
    escena.push_back(&pieIzquierda_garra2);
    escena.push_back(&pieIzquierda_garra3);

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