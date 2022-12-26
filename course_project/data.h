#include<stdio.h>

// This node might be a question or an animal
struct _node{
	char * name;
	
	/*
	For Questions:
		yes and no will point to either an animal or another question 
	
	For Animals:
		yes and no will be NULL
	*/
	struct _node* yes;
	struct _node* no;
};
typedef struct _node node;
