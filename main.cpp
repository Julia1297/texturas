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

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz, ImageTexture& a){
    
    ColorRGB color=a.get_color();

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin && objetos[i]->sombra == true ){
            // color.r = luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) ;
            // color.g = luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat());
            // color.b = luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat());
            
            // h = ((-1)*r.d).hat();
            // color.r = luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000);
            // color.g = luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000);
            // color.b = luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000);

            h = ((-1)*r.d).hat();
            color.r = acotar( 0.1 + luz.color.r * objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * pow(max(0.0, n * h), 1000));
            color.g = acotar( 0.1 + luz.color.g * objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * pow(max(0.0, n * h), 1000));
            color.b = acotar( 0.1 + luz.color.b * objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor(Punto3D(n.x, n.y, n.z)).r * pow(max(0.0, n * h), 1000));

            tmin = t;
        }
        if ( objetos[i]->hayImpacto(r, t, n, q) && t < tmin && objetos[i]->sombra == false ){
            //std::cout<<"No hay interseccion\n";
            h = ((-1)*r.d).hat();
            color.r = objetos[i]->obtenerColor(r.o).r;
            color.g = objetos[i]->obtenerColor(r.o).g;
            color.b = objetos[i]->obtenerColor(r.o).b;
            tmin = t;
        }
    }
   // std::cout<<"No hay interseccion\n";
    return color;
}

int main()
{
    Image l;
    l.read_ppm_file("fondo.ppm");
    ImageTexture a(&l);
    LuzPuntual luz(1,1,1,100,-100,-2050);
    LuzPuntual luz_ambiente(0.5, 0.5, 0.1, 0,0,100);
    vector<ObjetoGeometrico *> escena;

    // ESCENA-----------------------------------------------------------------
    Punto3D cara(0, 0, 0);
    Esfera esfera_cara(cara, 200, true);
    esfera_cara.setImTexture("mike-face.ppm");
    //esfera fiesta
    Punto3D fiesta(0, 475, 0);
    Esfera esfera_fiesta(fiesta, 115, true);
    esfera_fiesta.setImTexture("discoTexture.ppm");

    //esferas de colores
    Punto3D colores1(-240, -470, 0);
    Esfera esfera_colores1(colores1, 55, true);
    esfera_colores1.setImTexture("texture1.ppm");

    Punto3D colores2(-155, -395, 0);
    Esfera esfera_colores2(colores2, 55, true);
    esfera_colores2.setImTexture("texture2.ppm");

    Punto3D colores3(-80, -475, 0);
    Esfera esfera_colores3(colores3, 55, true);
    esfera_colores3.setImTexture("texture2.ppm");

    Punto3D colores4(-40, -375, 0);
    Esfera esfera_colores4(colores4, 55, true);
    esfera_colores4.setImTexture("texture1.ppm");

    Punto3D colores5(75, -370, 0);
    Esfera esfera_colores5(colores5, 55, true);
    esfera_colores5.setImTexture("texture2.ppm");

    Punto3D colores6(50, -475, 0);
    Esfera esfera_colores6(colores6, 55, true);
    esfera_colores6.setImTexture("texture2.ppm");

    Punto3D colores7(155, -450, 0);
    Esfera esfera_colores7(colores7, 55, true);
    esfera_colores7.setImTexture("texture1.ppm");

    Punto3D colores8(260, -475, 0);
    Esfera esfera_colores8(colores8, 55, true);
    esfera_colores8.setImTexture("texture1.ppm");

//esferas de deporte

    Punto3D deporte1(420, -475, 0);
    Esfera esfera_deporte1(deporte1, 35, true);
    esfera_deporte1.setImTexture("tenis.ppm");

    Punto3D deporte2(520, -390, 0);
    Esfera esfera_deporte2(deporte2, 75, true);
    esfera_deporte2.setImTexture("voley.ppm");

    Punto3D deporte3(680, -400, 0);
    Esfera esfera_deporte3(deporte3, 65, true);
    esfera_deporte3.setImTexture("basketball.ppm");

    Punto3D deporte4(880, -545, 0);
    Esfera esfera_deporte4(deporte4, 55, true);
    esfera_deporte4.setImTexture("futbol.ppm");

//foquitos de arriba
    Punto3D foquito1(-880, 545, 0);
    Esfera esfera_foquito1(foquito1, 55, true);
    esfera_foquito1.setImTexture("luz2.ppm");
    
    Punto3D foquito2(-735, 570, 0);
    Esfera esfera_foquito2(foquito2, 30, true);
    esfera_foquito2.setImTexture("luz1.ppm");

    Punto3D foquito3(-590, 545, 0);
    Esfera esfera_foquito3(foquito3, 55, true);
    esfera_foquito3.setImTexture("luz2.ppm");

    Punto3D foquito4(-445, 570, 0);
    Esfera esfera_foquito4(foquito4, 30, true);
    esfera_foquito4.setImTexture("luz1.ppm");
    
    Punto3D foquito5(-300, 545, 0);
    Esfera esfera_foquito5(foquito5, 55, true);
    esfera_foquito5.setImTexture("luz2.ppm");
    
    Punto3D foquito6(-155, 570, 0);
    Esfera esfera_foquito6(foquito6,30, true);
    esfera_foquito6.setImTexture("luz1.ppm");

    Punto3D foquito7(155, 570, 0);
    Esfera esfera_foquito7(foquito7, 30, true);
    esfera_foquito7.setImTexture("luz1.ppm");
    
    Punto3D foquito8(300, 545, 0);
    Esfera esfera_foquito8(foquito8, 55, true);
    esfera_foquito8.setImTexture("luz2.ppm");

    Punto3D foquito9(445, 570, 0);
    Esfera esfera_foquito9(foquito9, 30, true);
    esfera_foquito9.setImTexture("luz1.ppm");

    Punto3D foquito10(590, 545, 0);
    Esfera esfera_foquito10(foquito10, 55, true);
    esfera_foquito10.setImTexture("luz2.ppm");
    
    Punto3D foquito11(735, 570, 0);
    Esfera esfera_foquito11(foquito11, 30, true);
    esfera_foquito11.setImTexture("luz1.ppm");
    
    Punto3D foquito12(880, 545, 0);
    Esfera esfera_foquito12(foquito12, 55, true);
    esfera_foquito12.setImTexture("luz2.ppm");

//logo
    Punto3D logotipo(-850, -405, 0);
    Esfera esfera_logotipo(logotipo, 90, true);
    esfera_logotipo.setImTexture("logo_1.ppm");  

//orejas

    Punto3D A_orejaIzquierda(-80,220,-100);
    Punto3D B_orejaIzquierda(-65,190,-100);
    Punto3D C_orejaIzquierda(-95,176,-100);

    Punto3D A_orejaDerecha(65,190,-100);
    Punto3D B_orejaDerecha(80,220,-100);
    Punto3D C_orejaDerecha(95,176,-100);

    Triangulo orejaIzquierda(A_orejaIzquierda,B_orejaIzquierda,C_orejaIzquierda, false);
    orejaIzquierda.establecerColor(0.8,0.8,0.8);
    Triangulo orejaDerecha(A_orejaDerecha,B_orejaDerecha,C_orejaDerecha, false);
    orejaDerecha.establecerColor(0.8,0.8,0.8);


    Punto3D A_piernaIzquierda1(-65,-190,-100);
    Punto3D B_piernaIzquierda1(-95,-176,-100);
    Punto3D C_piernaIzquierda1(-70,-260,-100);

    Punto3D A_piernaIzquierda2(-70,-260,-100);
    Punto3D B_piernaIzquierda2(-95,-170,-100);
    Punto3D C_piernaIzquierda2(-100,-260,-100);

    Triangulo piernaIzquierda1(A_piernaIzquierda1,B_piernaIzquierda1,C_piernaIzquierda1, false);
    piernaIzquierda1.establecerColor(0.317, 0.537, 0.298);
    Triangulo piernaIzquierda2(A_piernaIzquierda2,B_piernaIzquierda2,C_piernaIzquierda2, false);
    piernaIzquierda2.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_piernaIzquierda3(-70,-260,-100);
    Punto3D B_piernaIzquierda3(-100,-260,-100);
    Punto3D C_piernaIzquierda3(-50,-370,-100);

    Punto3D A_piernaIzquierda4(-50,-370,-100);
    Punto3D B_piernaIzquierda4(-100,-260,-100);
    Punto3D C_piernaIzquierda4(-75,-370,-100);

    Triangulo piernaIzquierda3(A_piernaIzquierda3,B_piernaIzquierda3,C_piernaIzquierda3, false);
    piernaIzquierda3.establecerColor(0.317, 0.537, 0.298);
    Triangulo piernaIzquierda4(A_piernaIzquierda4,B_piernaIzquierda4,C_piernaIzquierda4, false);
    piernaIzquierda4.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_piernaDerecha1(95,-176,-100);
    Punto3D B_piernaDerecha1(65,-190,-100);
    Punto3D C_piernaDerecha1(70,-260,-100);

    Punto3D A_piernaDerecha2(95,-170,-100);
    Punto3D B_piernaDerecha2(70,-260,-100);
    Punto3D C_piernaDerecha2(100,-260,-100);

    Triangulo piernaDerecha1(A_piernaDerecha1,B_piernaDerecha1,C_piernaDerecha1, false);
    piernaDerecha1.establecerColor(0.317, 0.537, 0.298);
    Triangulo piernaDerecha2(A_piernaDerecha2,B_piernaDerecha2,C_piernaDerecha2, false);
    piernaDerecha2.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_piernaDerecha3(100,-260,-100);
    Punto3D B_piernaDerecha3(70,-260,-100);
    Punto3D C_piernaDerecha3(50,-370,-100);

    Punto3D A_piernaDerecha4(100,-260,-100);
    Punto3D B_piernaDerecha4(50,-370,-100);
    Punto3D C_piernaDerecha4(75,-370,-100);

    Triangulo piernaDerecha3(A_piernaDerecha3,B_piernaDerecha3,C_piernaDerecha3,  false);
    piernaDerecha3.establecerColor(0.317, 0.537, 0.298);
    Triangulo piernaDerecha4(A_piernaDerecha4,B_piernaDerecha4,C_piernaDerecha4,  false);
    piernaDerecha4.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_brazoIzquierdo1(-200,0,-100);
    Punto3D B_brazoIzquierdo1(-220,-140,-100);
    Punto3D C_brazoIzquierdo1(-180,-25,-100);

    Punto3D A_brazoIzquierdo2(-220,-140,-100);
    Punto3D B_brazoIzquierdo2(-195,-140,-100);
    Punto3D C_brazoIzquierdo2(-180,-25,-100);

    Triangulo brazoIzquierdo1(A_brazoIzquierdo1,B_brazoIzquierdo1,C_brazoIzquierdo1,  false);
    brazoIzquierdo1.establecerColor(0.317, 0.537, 0.298);
    Triangulo brazoIzquierdo2(A_brazoIzquierdo2,B_brazoIzquierdo2,C_brazoIzquierdo2,  false);
    brazoIzquierdo2.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_brazoIzquierdo3(-195,-140,-100);
    Punto3D B_brazoIzquierdo3(-220,-140,-100);
    Punto3D C_brazoIzquierdo3(-170,-255,-100);
    
    Punto3D A_brazoIzquierdo4(-170,-255,-100);
    Punto3D B_brazoIzquierdo4(-220,-140,-100);
    Punto3D C_brazoIzquierdo4(-195,-255,-100);

    Triangulo brazoIzquierdo3(A_brazoIzquierdo3,B_brazoIzquierdo3,C_brazoIzquierdo3, false);
    brazoIzquierdo3.establecerColor(0.317, 0.537, 0.298);
    Triangulo brazoIzquierdo4(A_brazoIzquierdo4,B_brazoIzquierdo4,C_brazoIzquierdo4, false);
    brazoIzquierdo4.establecerColor(0.317, 0.537, 0.298);


    Punto3D A_brazoDerecho1(220,-140,-100);
    Punto3D B_brazoDerecho1(200,0,-100);
    Punto3D C_brazoDerecho1(180,-25,-100);

    Punto3D A_brazoDerecho2(195,-140,-100);
    Punto3D B_brazoDerecho2(220,-140,-100);
    Punto3D C_brazoDerecho2(180,-25,-100);

    Triangulo brazoDerecho1(A_brazoDerecho1,B_brazoDerecho1,C_brazoDerecho1, false);
    brazoDerecho1.establecerColor(0.317, 0.537, 0.298);
    Triangulo brazoDerecho2(A_brazoDerecho2,B_brazoDerecho2,C_brazoDerecho2, false);
    brazoDerecho2.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_brazoDerecho3(220,-140,-100);
    Punto3D B_brazoDerecho3(195,-140,-100);
    Punto3D C_brazoDerecho3(170,-255,-100);
    Punto3D A_brazoDerecho4(220,-140,-100);
    Punto3D B_brazoDerecho4(170,-255,-100);
    Punto3D C_brazoDerecho4(195,-255,-100);

    Triangulo brazoDerecho3(A_brazoDerecho3,B_brazoDerecho3,C_brazoDerecho3, false);
    brazoDerecho3.establecerColor(0.317, 0.537, 0.298);
    Triangulo brazoDerecho4(A_brazoDerecho4,B_brazoDerecho4,C_brazoDerecho4, false);
    brazoDerecho4.establecerColor(0.317, 0.537, 0.298);

    //Pie izquierdo

    Punto3D pieIzquierdo_dedo1(-90, -390, -100);
    Esfera esfera_pieIzquierdo_dedo1(pieIzquierdo_dedo1, 8, false);
    esfera_pieIzquierdo_dedo1.establecerColor(0.317, 0.537, 0.298);

    Punto3D pieIzquierdo_dedo2(-105, -385, -100);
    Esfera esfera_pieIzquierdo_dedo2(pieIzquierdo_dedo2, 10, false);
    esfera_pieIzquierdo_dedo2.establecerColor(0.317, 0.537, 0.298);

    Punto3D pieIzquierdo_dedo3(-115, -380, -100);
    Esfera esfera_pieIzquierdo_dedo3(pieIzquierdo_dedo3, 8, false);
    esfera_pieIzquierdo_dedo3.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_pieIzquierdo1(-120,-375,-90);
    Punto3D B_pieIzquierdo1(-105, -385, -100);
    Punto3D C_pieIzquierdo1(-75,-370,-100);

    Punto3D A_pieIzquierdo2(-50,-370,-100);
    Punto3D B_pieIzquierdo2(-75,-370,-100);
    Punto3D C_pieIzquierdo2(-105, -385, -100);

    Punto3D A_pieIzquierdo3(-105, -385, -100);
    Punto3D B_pieIzquierdo3(-85, -395, -100);
    Punto3D C_pieIzquierdo3(-50,-370,-100);

    Triangulo pieIzquierdo1(A_pieIzquierdo1,B_pieIzquierdo1,C_pieIzquierdo1, false);
    pieIzquierdo1.establecerColor(0.317, 0.537, 0.298);
    Triangulo pieIzquierdo2(A_pieIzquierdo2,B_pieIzquierdo2,C_pieIzquierdo2, false);
    pieIzquierdo2.establecerColor(0.317, 0.537, 0.298);
    Triangulo pieIzquierdo3(A_pieIzquierdo3,B_pieIzquierdo3,C_pieIzquierdo3, false);
    pieIzquierdo3.establecerColor(0.317, 0.537, 0.298);

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

    Triangulo pieIzquierda_garra1(A_pieIzquierda_garra1,B_pieIzquierda_garra1,C_pieIzquierda_garra1, false);
    pieIzquierda_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo pieIzquierda_garra2(A_pieIzquierda_garra2,B_pieIzquierda_garra2,C_pieIzquierda_garra2, false);
    pieIzquierda_garra2.establecerColor(0.7,0.7,0.7);
    Triangulo pieIzquierda_garra3(A_pieIzquierda_garra3,B_pieIzquierda_garra3,C_pieIzquierda_garra3, false);
    pieIzquierda_garra3.establecerColor(0.7,0.7,0.7);
    //Pie derecho
    Punto3D pieDerecho_dedo1(80, -390, -100);
    Esfera esfera_pieDerecho_dedo1(pieDerecho_dedo1, 8, false);
    esfera_pieDerecho_dedo1.establecerColor(0.317, 0.537, 0.298);

    Punto3D pieDerecho_dedo2(95, -385, -100);
    Esfera esfera_pieDerecho_dedo2(pieDerecho_dedo2, 10, false);
    esfera_pieDerecho_dedo2.establecerColor(0.317, 0.537, 0.298);

    Punto3D pieDerecho_dedo3(105, -380, -100);
    Esfera esfera_pieDerecho_dedo3(pieDerecho_dedo3, 8, false);
    esfera_pieDerecho_dedo3.establecerColor(0.317, 0.537, 0.298);

    Punto3D A_pieDerecho1(95, -385, -100);
    Punto3D B_pieDerecho1(105,-380,-90);
    Punto3D C_pieDerecho1(75,-370,-100);

    Punto3D A_pieDerecho2(75,-370,-100);
    Punto3D B_pieDerecho2(50,-370,-100);
    Punto3D C_pieDerecho2(95, -385, -100);

    Punto3D A_pieDerecho3(80, -390, -100);
    Punto3D B_pieDerecho3(95, -385, -100);
    Punto3D C_pieDerecho3(50,-370,-100);

    Triangulo pieDerecho1(A_pieDerecho1,B_pieDerecho1,C_pieDerecho1, false);
    pieDerecho1.establecerColor(0.317, 0.537, 0.298);
    Triangulo pieDerecho2(A_pieDerecho2,B_pieDerecho2,C_pieDerecho2, false);
    pieDerecho2.establecerColor(0.317, 0.537, 0.298);
    Triangulo pieDerecho3(A_pieDerecho3,B_pieDerecho3,C_pieDerecho3, false);
    pieDerecho3.establecerColor(0.317, 0.537, 0.298);

   //Garras pie derecho

    Punto3D A_pieDerecho_garra1(77, -395,-80);
    Punto3D B_pieDerecho_garra1(84, -389, -80);
    Punto3D C_pieDerecho_garra1(87, -399,-80);

    Punto3D A_pieDerecho_garra2(90, -389,-80);
    Punto3D B_pieDerecho_garra2(97, -384, -80);
    Punto3D C_pieDerecho_garra2(103, -391,-80);

    Punto3D A_pieDerecho_garra3(104, -381,-80);
    Punto3D B_pieDerecho_garra3(110, -377, -80);
    Punto3D C_pieDerecho_garra3(115, -386,-80);

    Triangulo pieDerecho_garra1(A_pieDerecho_garra1,B_pieDerecho_garra1,C_pieDerecho_garra1, false);
    pieDerecho_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo pieDerecho_garra2(A_pieDerecho_garra2,B_pieDerecho_garra2,C_pieDerecho_garra2, false);
    pieDerecho_garra2.establecerColor(0.7,0.7,0.7);
    Triangulo pieDerecho_garra3(A_pieDerecho_garra3,B_pieDerecho_garra3,C_pieDerecho_garra3, false);
    pieDerecho_garra3.establecerColor(0.7,0.7,0.7);

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
    
    Triangulo manoIzquierda1(A_manoIzquierda1,B_manoIzquierda1,C_manoIzquierda1, false);
    manoIzquierda1.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda2(A_manoIzquierda2,B_manoIzquierda2,C_manoIzquierda2, false);
    manoIzquierda2.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda3(A_manoIzquierda3,B_manoIzquierda3,C_manoIzquierda3, false);
    manoIzquierda3.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda4(A_manoIzquierda4,B_manoIzquierda4,C_manoIzquierda4, false);
    manoIzquierda4.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda5(A_manoIzquierda5,B_manoIzquierda5,C_manoIzquierda5, false);
    manoIzquierda5.establecerColor(0.317, 0.537, 0.298);
    
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

    Triangulo manoIzquierda_dedo1(A_manoIzquierda_dedo1,B_manoIzquierda_dedo1,C_manoIzquierda_dedo1, false);
    manoIzquierda_dedo1.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda_dedo2(A_manoIzquierda_dedo2,B_manoIzquierda_dedo2,C_manoIzquierda_dedo2, false);
    manoIzquierda_dedo2.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda_dedo3(A_manoIzquierda_dedo3,B_manoIzquierda_dedo3,C_manoIzquierda_dedo3, false);
    manoIzquierda_dedo3.establecerColor(0.317, 0.537, 0.298);

    Triangulo manoIzquierda_dedo4(A_manoIzquierda_dedo4,B_manoIzquierda_dedo4,C_manoIzquierda_dedo4, false);
    manoIzquierda_dedo4.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoIzquierda_dedo5(A_manoIzquierda_dedo5,B_manoIzquierda_dedo5,C_manoIzquierda_dedo5, false);
    manoIzquierda_dedo5.establecerColor(0.317, 0.537, 0.298);



    Punto3D A_manoIzquierda_garra1(-160, -313,-80);
    Punto3D B_manoIzquierda_garra1(-151, -313,-80);
    Punto3D C_manoIzquierda_garra1(-149, -319,-80);

    Punto3D A_manoIzquierda_garra2(-155, -300,-80);
    Punto3D B_manoIzquierda_garra2(-150, -300,-80);
    Punto3D C_manoIzquierda_garra2(-153, -308,-80);

    Triangulo manoIzquierda_garra1(A_manoIzquierda_garra1,B_manoIzquierda_garra1,C_manoIzquierda_garra1, false);
    manoIzquierda_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo manoIzquierda_garra2(A_manoIzquierda_garra2,B_manoIzquierda_garra2,C_manoIzquierda_garra2, false);
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
    
    Triangulo manoDerecha1(A_manoDerecha1,B_manoDerecha1,C_manoDerecha1, false);
    manoDerecha1.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha2(A_manoDerecha2,B_manoDerecha2,C_manoDerecha2, false);
    manoDerecha2.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha3(A_manoDerecha3,B_manoDerecha3,C_manoDerecha3, false);
    manoDerecha3.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha4(A_manoDerecha4,B_manoDerecha4,C_manoDerecha4, false);
    manoDerecha4.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha5(A_manoDerecha5,B_manoDerecha5,C_manoDerecha5, false);
    manoDerecha5.establecerColor(0.317, 0.537, 0.298);
    
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

    Triangulo manoDerecha_dedo1(A_manoDerecha_dedo1,B_manoDerecha_dedo1,C_manoDerecha_dedo1, false);
    manoDerecha_dedo1.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha_dedo2(A_manoDerecha_dedo2,B_manoDerecha_dedo2,C_manoDerecha_dedo2, false);
    manoDerecha_dedo2.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha_dedo3(A_manoDerecha_dedo3,B_manoDerecha_dedo3,C_manoDerecha_dedo3, false);
    manoDerecha_dedo3.establecerColor(0.317, 0.537, 0.298);

    Triangulo manoDerecha_dedo4(A_manoDerecha_dedo4,B_manoDerecha_dedo4,C_manoDerecha_dedo4, false);
    manoDerecha_dedo4.establecerColor(0.317, 0.537, 0.298);
    Triangulo manoDerecha_dedo5(A_manoDerecha_dedo5,B_manoDerecha_dedo5,C_manoDerecha_dedo5, false);
    manoDerecha_dedo5.establecerColor(0.317, 0.537, 0.298);



    Punto3D A_manoDerecha_garra1(151, -313,-80);
    Punto3D B_manoDerecha_garra1(160, -313,-80);
    Punto3D C_manoDerecha_garra1(149, -319,-80);

    Punto3D A_manoDerecha_garra2(150, -300,-80);
    Punto3D B_manoDerecha_garra2(155, -300,-80);
    Punto3D C_manoDerecha_garra2(153, -308,-80);

    Triangulo manoDerecha_garra1(A_manoDerecha_garra1,B_manoDerecha_garra1,C_manoDerecha_garra1, false);
    manoDerecha_garra1.establecerColor(0.7,0.7,0.7);
    Triangulo manoDerecha_garra2(A_manoDerecha_garra2,B_manoDerecha_garra2,C_manoDerecha_garra2, false);
    manoDerecha_garra2.establecerColor(0.7,0.7,0.7);


    escena.push_back(&esfera_cara);
    escena.push_back(&esfera_fiesta);
    
    escena.push_back(&esfera_colores1);
    escena.push_back(&esfera_colores2);
    escena.push_back(&esfera_colores3);
    escena.push_back(&esfera_colores4);
    escena.push_back(&esfera_colores5);
    escena.push_back(&esfera_colores6);
    escena.push_back(&esfera_colores7);
    escena.push_back(&esfera_colores8);

    escena.push_back(&esfera_deporte1);
    escena.push_back(&esfera_deporte2);
    escena.push_back(&esfera_deporte3);
    escena.push_back(&esfera_deporte4);

    escena.push_back(&esfera_foquito1);
    escena.push_back(&esfera_foquito2);
    escena.push_back(&esfera_foquito3);
    escena.push_back(&esfera_foquito4);
    escena.push_back(&esfera_foquito5);
    escena.push_back(&esfera_foquito6);
    escena.push_back(&esfera_foquito7);
    escena.push_back(&esfera_foquito8);
    escena.push_back(&esfera_foquito9);
    escena.push_back(&esfera_foquito10);
    escena.push_back(&esfera_foquito11);
    escena.push_back(&esfera_foquito12);
    
    escena.push_back(&esfera_logotipo); 

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

    escena.push_back(&pieDerecho_garra1);
    escena.push_back(&pieDerecho_garra2);
    escena.push_back(&pieDerecho_garra3);
    
    ColorRGB color_pixel;


    // VIEWPLANE
    int hres = 1920;
    int vres = 1200;
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

                       color_pixel = obtenerColorPixel(rayo, escena, luz, a);

            pixeles[fil*width+col].r = color_pixel.r;
            pixeles[fil*width+col].g = color_pixel.g;
            pixeles[fil*width+col].b = color_pixel.b;
        }
    }
    savebmp("img1.bmp", width, height, dpi, pixeles);
    return 0;
}