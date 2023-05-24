#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <raylib.h>

typedef struct Node {
	Rectangle obj;
	struct Node *next;
} node;

#define NODE_MALLOC ((node*) malloc(sizeof(node)));
static node *root;

void push(float x, float y);

#endif

#ifndef LIST_IMPLEMENTATION_

void push_rect(Rectangle rect) {
	node *new_node = NODE_MALLOC;
	new_node->obj = rect;
	new_node->next = root;
	root = new_node;
}

#endif
