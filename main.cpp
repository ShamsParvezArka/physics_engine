#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <ctime>
#include <cmath>
#include <unistd.h>

#include "raylib.h"
#include "dimensions.h"

typedef struct SnowFleck {
	Vector2 vec;
	float radius;
} snow_fleck;

float randf() 
{
	return (float) rand() / (float) RAND_MAX;
}

void update_gravity(Vector2 *obj, float speed) 
{
	if (obj->y < window_height) {
		obj->y += speed;
		obj->x = obj->x + sinf(obj->y); //Oscilating movement with sin(x) function
	}
}

int main() 
{
	InitWindow(window_width, window_height, "Snow fall");
	SetTargetFPS(60);

	srand(time_t(0));
	std::vector<SnowFleck> snow {};
	
	while (!WindowShouldClose()) {
		ClearBackground(BLACK);
		
		snow_fleck particle;
		particle.vec = {randf()*window_width, -0.10f};
		particle.radius = randf()*2;
		snow.push_back(particle);

		for (SnowFleck &obj: snow) 
			update_gravity(&obj.vec, obj.radius);

		BeginDrawing();
		{
			for (SnowFleck obj: snow) {
				DrawCircleV(obj.vec, obj.radius, RAYWHITE);
			}
		}
		EndDrawing();
	}
	CloseWindow();

	return 0;
}








