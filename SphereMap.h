#pragma once

#include "Constants.h"
#include "Punto3D.h"
#include "Maths.h"

class SphereMap{		
	public:
	
		SphereMap(void);									
		
		SphereMap(const SphereMap& sm);					

		SphereMap& 											
		operator= (const SphereMap& rhs);		

		virtual SphereMap*									
		clone(void) const;				

		~SphereMap(void);									
		
		virtual void
		get_texel_coordinates(	const 	Punto3D& 	local_hit_point, 
								const 	int 		xres, 
								const 	int 		yres, 
										int& 		row, 
										int& 		column) const;
};