// 	Copyright (C) Kevin Suffern 2000-2007.
//	Revised by mp77 at 2012
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#include "ImageTexture.h"
#include <iostream>

// ---------------------------------------------------------------- default constructor

ImageTexture::ImageTexture(void){
		hres=100;
		vres=100;
		image_ptr=NULL;
		index=0;
}

// ---------------------------------------------------------------- constructor

ImageTexture::ImageTexture(Image* _image_ptr)
{
	hres=_image_ptr->get_hres();
	vres=_image_ptr->get_vres();
	image_ptr=_image_ptr;
	index=0;
}


// ---------------------------------------------------------------- copy constructor




// ---------------------------------------------------------------- assignment operator

ImageTexture& 
ImageTexture::operator= (const ImageTexture& rhs) {
	hres = rhs.hres;
	vres = rhs.vres;
	std::cout<<"Pasa h y v\n";
	image_ptr=rhs.image_ptr;
	std::cout<<"Pasa igual: "<< image_ptr <<" y "<<rhs.image_ptr<<"\n";
	
	
}


// ---------------------------------------------------------------- clone

	


// ---------------------------------------------------------------- destructor

ImageTexture::~ImageTexture(){
	
}


// ---------------------------------------------------------------- get_color

// When we ray trace a triangle mesh object with uv mapping, the mapping pointer may be NULL
// because we can define uv coordinates on an arbitrary triangle mesh.
// In this case we don't use the local hit point because the pixel coordinates are computed 
// from the uv coordinates stored in the ShadeRec object in the uv triangles' hit functions
// See, for example, Listing 29.12.

ColorRGB														
ImageTexture::get_color() {	
	index++;
	
	return (image_ptr->get_color(index));
}





