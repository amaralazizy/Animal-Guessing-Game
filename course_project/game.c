#include <stdio.h>
#include<stdlib.h>
#include "database.h"
#include "user_functions.h"
#include "mapping.h"



int main() {
	initDatabase();
	line* lines = filetext();
	node* head = linesToNodes(lines);

	char answer = 'y';
	while(answer == 'y' || answer == 'Y') {
		head = handle(head);
		//Ask the user if he wants to play again
		printf("Do you want to play again?\n");
		printf("Enter (Y) for yes or (N) for no: ");
		scanf_s(" %c", &answer); //Not complete yet
	}
	//for (line* temp = lines; temp->next != NULL; temp = temp->next) printf("%s", temp->text);
	lines = nodesToLines(head);
	writeData(lines);
}
