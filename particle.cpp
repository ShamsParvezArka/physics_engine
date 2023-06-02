#include "dimensions.hpp"
#include "particle.hpp"

void update_particle(Vector2 *object, float radius)
{
	if (object->y + radius < window_height) {
		object->y += radius;
		object->x = object->x + sinf(object->y);
	}
}
