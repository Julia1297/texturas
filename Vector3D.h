#ifndef VECTOR3D_H
#define VECTOR3D_H
class Vector3D
{
    public:
    Vector3D();                                             // Constructor por defecto

    Vector3D(double n);
    Vector3D(double x, double y, double z);
    Vector3D operator+( const Vector3D& v) const;
    Vector3D operator- (const Vector3D& v) const;
    Vector3D operator/ (double m) const;
    Vector3D operator* (double m) const;
    Vector3D operator^ (const Vector3D& v) const;
    double operator* (const Vector3D& v) const;
    friend Vector3D operator* (double n, const Vector3D& v); 
    void mostrar();
    Vector3D& hat();							             // Convertir el vector a un vector unitario y retornar el vector

    public:
    double x, y, z;
};
#endif