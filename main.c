#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

typedef struct Node {
	float x;
	float y;
	struct Node *next;
} node;

#define NODE_MALLOC ((node*) malloc(sizeof(node)));

static node *root, *spoint;

void push(float x, float y) {
	node *new_node = NODE_MALLOC;
	new_node->x = x;
	new_node->y = y;
	new_node->next = root;
	root = new_node;
}

int main() 
{
	const int window_width  = 1200;
	const int window_height =  800;

	InitWindow(window_width, window_height, "gravity");
	SetTargetFPS(60);

	spoint = NODE_MALLOC;
	while(!WindowShouldClose()) {
		ClearBackground(RAYWHITE);

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			push(GetMouseX(), GetMouseY());
		}

		BeginDrawing();
		{
			spoint = root;
			while(spoint != NULL) {
				DrawRectangle(spoint->x, spoint->y, 20, 20, BLACK);
				spoint = spoint->next;
			}
		}
		EndDrawing();
	}
	
	return 0;
}
