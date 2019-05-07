#ifndef __OPEN_CYLINDER__
#define __OPEN_CYLINDER__

#include "ObjetoGeometrico.h"

class OpenCylinder: public ObjetoGeometrico {

public:

    OpenCylinder(void);

    OpenCylinder(const double bottom, const double top, const double radius);

    OpenCylinder(const OpenCylinder& c);

    OpenCylinder* clone (void) const;

    OpenCylinder&
    operator= (const OpenCylinder& rhs);

    ~OpenCylinder(void);

    bool hayImpacto(const Rayo& ray, double& t) const;

protected:

    double		y0;				// bottom y value
    double		y1;				// top y value
    double		radius;			// radius
    double		inv_radius;  	// one over the radius
};

#endif