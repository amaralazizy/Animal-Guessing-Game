#include "data.h"
#include <stdlib.h>
#include <string.h>

//Function to get answers from the user
node* handle(node* q) 
{
	char answer;
	char animal[300];
	char question[300];
	//To show the user the question or the guessed animal and check user's answer
	printf("%s", q->name);
	printf("\nEnter (Y) for yes or (N) for no: ");
	scanf_s(" %c", &answer);
	if (q->yes == NULL && q->no == NULL)//To check wether it is an animal or question 
	{
		if (answer == 'N' || answer == 'n') //To check if the guessed animal is incorrect
		{
			node* newnode = (node *)malloc(sizeof(node));
			node* yesNewNode = (node *)malloc(sizeof(node));;
			node* noNewNode = (node *)malloc(sizeof(node));;
			//prompt the user enter the new question and animal 
			printf("What was the animal name? ");
			getchar();
			fgets(animal, 300, stdin);
			printf("What should I have asked you? ");
			fgets(question, 300, stdin);
			//Saving new data inside the tree
			strcpy_s(newnode->name ,300,question);
			strcpy_s(yesNewNode->name ,300,animal);
			strcpy_s(noNewNode->name,300,q->name);
			yesNewNode->yes = NULL;
			yesNewNode->no = NULL;
			noNewNode->yes = NULL;
			noNewNode->no = NULL;
			newnode->yes = yesNewNode;
			newnode->no = noNewNode;
			return newnode;
		}
		return q;
	}
	//If the data was a question
	else 
	{
		if (answer == 'y' || answer == 'Y') 
		{
			q->yes = handle(q->yes); //Recursing the function and repeat for the next node
		}
		else if (answer == 'n' || answer == 'N') {
			q->no = handle(q->no); //Recursing the function and repeat for the next node
		}
		return q;
	}
}