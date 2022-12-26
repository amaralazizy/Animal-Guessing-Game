#include <stdio.h>
#include<stdlib.h>
#include "data.h"

int main() {
	node* q1 = malloc(sizeof(node));
	char _q1[200] = "does it live in water";
	q1->name = _q1;

	node* a1 = malloc(sizeof(node));
	char _a1[200] = "whale";
	a1->name = _a1;
	a1->no = NULL;
	a1->yes = NULL;

	node* a2 = malloc(sizeof(node));
	char _a2[200] = "cat";
	a2->name = _a2;
	a2->no = NULL;
	a2->yes = NULL;

	q1->yes = a1;
	q1->no = a2;
}