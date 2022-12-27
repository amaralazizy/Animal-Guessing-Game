#include <stdio.h>
#include <string.h>
#include "data.h"

node* linesToNodes(line* currLine) {
	static int numLines = 0;

	numLines++;
	if (currLine->text[0] == '\n') {
		return linesToNodes(currLine->next);
	}
	else {
		node* currNode = (node*)(malloc(sizeof(node)));
		strcpy_s(currNode->name, 300, currLine->text);

		if ((currLine->next)->text[0] == '\n') {
			numLines++;
			// this node is an animal
			currNode->yes = NULL;
			currNode->no = NULL;
		}
		else {
			int currLineNum = numLines;
			// this node is a question
			currNode->yes = linesToNodes(currLine->next);

			//line* tempLine = currLine->next->next;
			line* tempLine = currLine->next;
			for (int i = 0; i < (numLines-currLineNum); i++) tempLine = tempLine->next;

			currNode->no = linesToNodes(tempLine);
		}
		return currNode;
	}
}

line *nodesToLines(node *currNode)
{
	line *currLine = (line *)(malloc(sizeof(line)));
	strcpy_s(currLine->text, 300, currNode->name);
	if (!(currNode->yes) && !(currNode->no))
	{
		// this node is an animal
		currLine->next = (line *)(malloc(sizeof(line)));
		char t[300] = "\n";
		strcpy_s((currLine->next)->text ,300, t);
		currLine->next->next = NULL;
	}
	else
	{
		currLine->next = nodesToLines(currNode->yes);
		line *temp = NULL;
		for (temp = currLine->next; temp->next != NULL; temp = temp->next) {

		};
		temp->next = nodesToLines(currNode->no);
	}
	return currLine;
}
