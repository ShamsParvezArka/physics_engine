#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <raylib.h>

void update_gravity(Rectangle *rec, int window_width, int window_height);

#endif 

#ifndef PHYSICS_IMPELMENTATION_
void update_gravity(Rectangle *rec, int window_width, int window_height)
{
	if (rec->y + rec->height < window_height) {
		rec->y += 5;
	}
}
#endif // PHYSICS_IMPLEMENTATION

