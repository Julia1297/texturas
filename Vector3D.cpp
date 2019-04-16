#include "Vector3D.h"
#include <iostream>
#include <math.h>
using namespace std;
Vector3D::Vector3D()
{
}
Vector3D::Vector3D(double n)
{
    x = y = z = n;
}
Vector3D::Vector3D(double _x, double _y, double _z)
{
    x = _x;
    y = _y;
    z = _z;
}
Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return Vector3D(x - v.x, y - v.y, z - v.z);
}
Vector3D Vector3D::operator/(double m) const
{
    return Vector3D(x / m, y/m, z/m);
}

double Vector3D::operator*(const Vector3D &v) const
{
    return (x * v.x + y * v.y + z * v.z);
}

Vector3D Vector3D:: operator* (double m) const
{
    return Vector3D(x*m, y*m, z*m);
}

Vector3D Vector3D::operator^(const Vector3D &v) const
{
    return Vector3D(y*v.z-v.y*z,-(x*v.z-z*v.x),x*v.y-y*v.x);
}

Vector3D operator* (double n, const Vector3D& v){
    return Vector3D(n * v.x, n * v.y, n * v.z);
}

void Vector3D::mostrar()
{
    cout<<"< "<<x << ", "<< y << ", " << z << " >" << endl;
}

Vector3D& Vector3D::hat(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}