#include <stdio.h>
#include<stdlib.h>
#include "database.h"
#include "user_functions.h"
#include "mapping.h"

int main() {
	line* lines = filetext();
	node* head = linesToNodes(lines);
	handle(&head);
}