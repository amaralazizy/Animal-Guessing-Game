#include<stdio.h>
#include<string.h>

#ifndef MYNODE_H_
# define MYNODE_H_


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

struct _line{
    char text[300];
    struct _line* next;
} ;
typedef struct _line line;

int getLinesLength(line* head) {
	int counter = 0;
	for (line* temp = head; temp != NULL; temp = temp->next) {
		counter++;
	}
	return counter;
}

void printLines(line* head) {
	for (line* temp = head; temp != NULL; temp = temp->next) {
		printf("%s", temp->text);
	}
}

void insertLine(int index, char text[], line** head) {
	int length = getLinesLength(*head);

	if (index > length || index < 0) return;

	line* newLine = malloc(sizeof(line));

	strcpy_s(newLine->text, 300, text);

	if (index == 0) {
		newLine->next = *head;
		*head = newLine;
	}
	else {
		line* temp = *head;
		for (int counter = index - 1; temp->next != NULL && counter > 0; temp = temp->next) counter--;
		newLine->next = temp->next;
		temp->next = newLine;
	}
}

void deleteLine(line** head, int position)
{
	line* temp;
	line* prev;
	temp = *head;
	prev = *head;
	for (int i = 0; i < position; i++) {
		if (i == 0 && position == 0) {
			*head = (*head)->next;
			free(temp);
		}
		else {
			if (i == position && temp) {
				prev->next = temp->next;
				free(temp);
			}
			else {
				prev = temp;

				// Position was greater than
				// number of nodes in the list
				if (prev == NULL)
					break;
				temp = temp->next;
			}
		}
	}
}

#endif




