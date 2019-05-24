#include "ImTexture.h"
#include <iostream>

// ---------------------------------------------------------------- default constructor

ImTexture::ImTexture(void)
	:hres(100),
		vres(100),
		image_ptr(NULL),
		SphereMap_ptr(NULL)
{}


// ---------------------------------------------------------------- constructor

ImTexture::ImTexture(Image* _image_ptr)
	:	hres(_image_ptr->get_hres()),
		vres(_image_ptr->get_vres()),
		image_ptr(_image_ptr),
		SphereMap_ptr(NULL)
{}


// ---------------------------------------------------------------- copy constructor

ImTexture::ImTexture(const ImTexture& it)
	: hres(it.hres),
		vres(it.vres)
{
	if (it.image_ptr)
		*image_ptr = *it.image_ptr;
	else
		image_ptr = NULL;
		
	if (it.SphereMap_ptr)
		SphereMap_ptr = it.SphereMap_ptr->clone();
	else
		SphereMap_ptr = NULL;
}


// ---------------------------------------------------------------- assignment operator

ImTexture& 
ImTexture::operator= (const ImTexture& rhs) {
	if (this == &rhs)
		return (*this);
	
	
	hres = rhs.hres;
	vres = rhs.vres;
	
	if (image_ptr) {
		delete image_ptr;
		image_ptr = NULL;
	}
	
	if (rhs.image_ptr)
		*image_ptr = *rhs.image_ptr;
	
	if (SphereMap_ptr) {
		delete SphereMap_ptr;
		SphereMap_ptr = NULL;
	}
	
	if (rhs.SphereMap_ptr)
		SphereMap_ptr = rhs.SphereMap_ptr->clone();

	return (*this);
}


// ---------------------------------------------------------------- clone

ImTexture*										
ImTexture::clone(void) const {
	return (new ImTexture (*this));
}	


// ---------------------------------------------------------------- destructor

ImTexture::~ImTexture (void) {

	if (image_ptr) {
		delete image_ptr;
		image_ptr = NULL;
	}
	
	if (SphereMap_ptr) {
		delete SphereMap_ptr;
		SphereMap_ptr = NULL;
	}
}


// ---------------------------------------------------------------- get_color

// When we ray trace a triangle mesh object with uv SphereMap, the SphereMap pointer may be NULL
// because we can define uv coordinates on an arbitrary triangle mesh.
// In this case we don't use the local hit point because the pixel coordinates are computed 
// from the uv coordinates stored in the ShadeRec object in the uv triangles' hit functions
// See, for example, Listing 29.12.

ColorRGB														
ImTexture::get_color(const Punto3D& sr) const {	
	int row;
	int column;
		
	if (SphereMap_ptr)
		SphereMap_ptr->get_texel_coordinates(sr, hres, vres, row, column);
	//std::cout<<"Le row:"<<row<<" Le column:"<<column<<std::endl; 
	return (image_ptr->get_color(row, column));
}