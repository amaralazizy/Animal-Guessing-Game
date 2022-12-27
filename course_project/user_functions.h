#include "data.h"
#include <stdlib.h>
#include <string.h>

int handle(node** q) 
{
	char answer;
	char animal[30];
	char question[300];
	
	printf("%s", (*q)->name);
	printf("\nEnter (Y) for yes or (N) for no: ");
	scanf_s(" %c", &answer);
	if ((*q)->yes == NULL && (*q)->no == NULL) 
	{
		if (answer == 'N' || answer == 'n') 
		{
			node* newnode = (node *)malloc(sizeof(node));
			node* yesNewNode = (node *)malloc(sizeof(node));;
			node* noNewNode = (node *)malloc(sizeof(node));;
			printf("What was the animal name?");
			getchar();
			fgets(animal, 30, stdin);
			printf("What should I have asked you?");
			fgets(question, 300, stdin);
			newnode->name = question;
			yesNewNode->name = animal;
			noNewNode->name = (*q)->name;
			yesNewNode->yes = NULL;
			yesNewNode->no = NULL;
			noNewNode->yes = NULL;
			noNewNode->no = NULL;
			newnode->yes = yesNewNode;
			newnode->no = noNewNode;
			* q = newnode;
		}
		printf("Do you want to play again?\n");
		printf("Enter (Y) for yes or (N) for no: ");
		scanf_s(" %c", &answer); //Not complete yet
		if (answer == 'y' || answer == 'Y')
			return 1;
		else if (answer == 'n' || answer == 'N')
			return 0;
	}

	else 
	{
		if (answer == 'y' || answer == 'Y') 
		{
			handle(&((*q)->yes));
		}
		else if (answer == 'n' || answer == 'N') {
			handle(&((*q)->no));
		}
	}
}