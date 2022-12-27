#include "data.h"
#include <stdlib.h>
#include <string.h>

//Function to get answers from the user
int handle(node** q) 
{
	char answer;
	char animal[30];
	char question[300];
	//To show the user the question or the guessed animal and check user's answer
	printf("%s", (*q)->name);
	printf("\nEnter (Y) for yes or (N) for no: ");
	scanf_s(" %c", &answer);
	if ((*q)->yes == NULL && (*q)->no == NULL)//To check wether it is an animal or question 
	{
		if (answer == 'N' || answer == 'n') //To check if the guessed animal is incorrect
		{
			node* newnode = (node *)malloc(sizeof(node));
			node* yesNewNode = (node *)malloc(sizeof(node));;
			node* noNewNode = (node *)malloc(sizeof(node));;
			//prompt the user enter the new question and animal 
			printf("What was the animal name?\n");
			getchar();
			fgets(animal, 30, stdin);
			printf("What should I have asked you?\n");
			fgets(question, 300, stdin);
			//Saving new data inside the tree
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
		//Ask the user if he wants to play again
		printf("Do you want to play again?\n");
		printf("Enter (Y) for yes or (N) for no: ");
		scanf_s(" %c", &answer); //Not complete yet
		if (answer == 'y' || answer == 'Y')
			return 1;
		else if (answer == 'n' || answer == 'N')
			return 0;
	}
	//If the data was a question
	else 
	{
		if (answer == 'y' || answer == 'Y') 
		{
			handle(&((*q)->yes)); //Recursing the function and repeat for the next node
		}
		else if (answer == 'n' || answer == 'N') {
			handle(&((*q)->no)); //Recursing the function and repeat for the next node
		}
	}
}