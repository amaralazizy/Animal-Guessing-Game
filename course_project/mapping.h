#include<stdio.h>
#include "data.h"
#include "database.h"

node* linesToNodes(line* currLine) {
	node* currNode = (node*)(malloc(sizeof(node)));

	if ((currLine->next)->text[0] == '\n') {
		// this node is an animal
		currNode->yes = NULL;
		currNode->no = NULL;
		currNode->name = currLine->text;
	}
}

line* nodesToLines(node* currNode) {

}
