#include <stdio.h>
#include "data.h"
#include "database.h"

node *linesToNodes(line *currLine)
{
	node *currNode = (node *)(malloc(sizeof(node)));

	if ((currLine->next)->text[0] == '\n')
	{
		// this node is an animal
		currNode->yes = NULL;
		currNode->no = NULL;
		currNode->name = currLine->text;
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
