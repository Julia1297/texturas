#include "Punto3D.h"
#include <iostream>
using namespace std;
Punto3D::Punto3D()
{
}
Punto3D::Punto3D(double n) 
{
    x = y = z = n;
}
Punto3D::Punto3D(double v_x, double v_y, double v_z)
{
    x = v_x;
    y = v_y;
    z = v_z;
}
Punto3D::Punto3D(const Punto3D& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}
Punto3D::~Punto3D(){

}
Vector3D Punto3D::operator- (const Punto3D& p) const{
    return Vector3D(x - p.x, y - p.y, z - p.z);
}
Punto3D Punto3D::operator+ (const Vector3D& v) const{
    return Punto3D(x + v.x, y + v.y, z + v.z);
}         
Punto3D Punto3D::operator- (const Vector3D& v) const{
    return Punto3D(x - v.x, y - v.y, z - v.z);
}          
Punto3D Punto3D::operator* (const double n) const{
    return Punto3D(x * n, y * n, z * n);
}             
Punto3D operator* (double n, const Punto3D& p){
    return Punto3D(n * p.x, n * p.y, n * p.z);
}
void Punto3D::mostrar()
{
    cout << "( " << x << ", "<< y << ", " << z << " )" << endl;
}