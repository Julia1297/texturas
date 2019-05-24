// 	Copyright (C) Kevin Suffern 2000-2007.
//	Revised by mp77 at 2012
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#pragma once

#include "Image.h"
//#include "Mapping.h"
//#include "Texture.h"

class ImageTexture {	
	public:

	
		ImageTexture(void);									
			
		ImageTexture(Image* _image_ptr);					
				
		ImageTexture(const ImageTexture& it);				

		ImageTexture& 										
		operator= (const ImageTexture& rhs);		
			

		virtual
		~ImageTexture(void) ;								
		
		virtual ColorRGB																				
		get_color();
						
		void
		set_image(Image* _image_ptr);

		void setU(int ru);

		void setV(int rv);
	public:	
	    int index;
		int 		hres;			// horizontal resolution of the image
		int			vres;			// vertical resolution of the image
		Image*		image_ptr;		// the image
};


// ---------------------------------------------------------------- set_image

inline void
ImageTexture::set_image(Image* _image_ptr) {
	image_ptr = _image_ptr;
	hres = image_ptr->get_hres();
	vres = image_ptr->get_vres();
}


// ---------------------------------------------------------------- set_mapping

