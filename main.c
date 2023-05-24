#include <stdio.h>

#define LIST_IMPLEMENTATION
#include "list.h"

#define PHYSICS_IMPELMENTATION
#include "physics.h"

int main() 
{
	// INITIALIZE
	const int window_width  = 600;
	const int window_height = 600;

	InitWindow(window_width, window_width, "gravity");
	SetTargetFPS(60);

	Rectangle rec = {window_width/2, window_height/2, 30, 30};
	node *spoint = NODE_MALLOC;

	while(!WindowShouldClose()) {
		// UPDATE
		ClearBackground(RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Rectangle rect = {GetMouseX(), GetMouseY(), 30, 30};
			push_rect(rect);
		}

		spoint = root;
		while (spoint != NULL) {
			update_gravity(&spoint->obj, window_width, window_height);
			spoint = spoint->next;
		}

		// RENDER
		BeginDrawing();
		{
			spoint = root;
			while (spoint != NULL) {
				DrawRectangleRec(spoint->obj, BLACK);
				spoint = spoint->next;
			}
		}
		EndDrawing();
	}
	
	return 0;
}
