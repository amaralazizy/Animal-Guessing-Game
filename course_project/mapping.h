#include <stdio.h>
#include "data.h"
#include "database.h"

node* linesToNodes(line* currLine) {
	static int numLines = 0;

	numLines++;
	if (currLine->text[0] == '\n') {
		return linesToNodes(currLine->next);
	}
	else {
		node* currNode = (node*)(malloc(sizeof(node)));
		currNode->name = currLine->text;

		if ((currLine->next)->text[0] == '\n') {
			// this node is an animal
			currNode->yes = NULL;
			currNode->no = NULL;
		}
		else {
			int currLineNum = numLines;
			// this node is a question
			currNode->yes = linesToNodes(currLine->next);

			//line* temp1 = currLine->next->next;
			//if (temp1->text[0] == '\n' && (temp1->next->next)->text[0] == '\n') {
			//	// this is the last question in the branch
			//	currNode->no = linesToNodes(temp1->next);
			//}
			//else {
			//	int co = 1;

			//	node* temp;
			//	for (temp = currNode->yes->yes; temp != NULL; temp = temp->yes) co++;
			//	for (temp = currNode->yes->no; temp != NULL; temp = temp->no) co++;

			line* tempLine = currLine->next->next;
			for (int i = 0; i < (numLines-currLineNum); i++) tempLine = tempLine->next;

			currNode->no = linesToNodes(tempLine);
			//}
		}
		return currNode;
	}
}

line *nodesToLines(node *currNode)
{
	line *currLine = (line *)(malloc(sizeof(line)));
	currLine->text = currNode->name;
	if ((!currNode->yes) && (!currNode->no))
	{
		// this node is an animal
		currLine->next = (line *)(malloc(sizeof(line)));
		(currLine->next)->text = '\n';
		currLine->next->next = NULL;
	}
	else
	{
		currLine->next = nodesToLines(curNode->yes);
		line *temp = NULL;
		for (temp = currLine->next; temp->next != NULL; temp = temp->next)
			;
		temp->next = nodesToLines(curNode->no);
	}
	return currLine;
}
