#pragma once

#include "Image.h"
#include "ColorRGB.h"
#include "SphereMap.h"


class ImTexture{	
	public:
	
		ImTexture(void);									
			
		ImTexture(Image* _image_ptr);					
				
		ImTexture(const ImTexture& it);				

		ImTexture& 										
		operator= (const ImTexture& rhs);		

		virtual ImTexture*								
		clone(void) const;				

		virtual
		~ImTexture(void) ;								
		
		virtual ColorRGB																				
		get_color(const Punto3D& sr) const;
						
		void
		set_image(Image* _image_ptr);
		
		void
		set_SphereMap(SphereMap* map_ptr);	
		
	private:
	
		int 		hres;			// horizontal resolution of the image
		int			vres;			// vertical resolution of the image
		Image*		image_ptr;		// the image
		SphereMap*	SphereMap_ptr;	// SphereMap technique used, if any
};


// ---------------------------------------------------------------- set_image

inline void
ImTexture::set_image(Image* _image_ptr) {
	image_ptr = _image_ptr;
	hres = image_ptr->get_hres();
	vres = image_ptr->get_vres();
}


// ---------------------------------------------------------------- set_SphereMap

inline void
ImTexture::set_SphereMap(SphereMap* map_ptr) {
	SphereMap_ptr = map_ptr;
}
