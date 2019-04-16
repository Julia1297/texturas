#include "Rayo.h"
#include <iostream>
using namespace std;

 /*Rayo::Rayo()
 {
     o.x=o.y=o.z=0;
     d.x=d.y=0;
     d.z=1;

 }*/


 Rayo::Rayo(): o(0.0), d(0.0, 0.0, 1.0)
{}
   
 Rayo::Rayo(const Punto3D& origen, const Vector3D& direccion): o(origen), d(direccion)//constructor copia
{}
   
 Rayo:: ~Rayo()
 {

 }
