#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <ctime>

#include "raylib.h"
#include "particle.hpp"
#include "dimensions.hpp"
#include "random.hpp"
#include "random.hpp"

typedef struct Snow {
	Vector2 vec;
	float radius;
} snow;

int main() 
{
	InitWindow(window_width, window_height, "Snow fall");
	SetTargetFPS(60);

	srand(time_t(0));

	std::vector<snow> vec {};
	
	while (!WindowShouldClose()) {
		ClearBackground(BLACK);
		
		snow particle;
		particle.vec = {randf(0, window_width), -0.10f};
		particle.radius = randf(0, 2);
		vec.push_back(particle);

		for (size_t i = 0; i < vec.size(); i++) {
			if (vec[i].vec.y >= window_height) {
				vec.erase(vec.begin() + i);
			}
			update_particle(&vec[i].vec, vec[i].radius);
		}

		BeginDrawing();
		{
			for (Snow obj: vec) {
				DrawCircleV(obj.vec, obj.radius, RAYWHITE);
			}
		}
		EndDrawing();
	}
	CloseWindow();

	return 0;
}








