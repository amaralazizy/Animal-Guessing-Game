#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "data.h"


line* filetext() {
    FILE* ptr;
    line* head = (line *)malloc(sizeof(line));
    head->next = NULL;
    char str[300];
    fopen_s(&ptr, "database.txt", "a+");

    if (ptr == NULL) {
        printf("file can't be opened \n");
    }

    printf("content of this file are \n");
    fgets(str, 300, ptr);
	strcpy_s(head->text, 300, str);

    int i = 1;
    while (fgets(str, 300, ptr) != NULL) {
		insertLine(i, str, &head);
		i++;
    }
    fclose(ptr);
    return head;
}

void writeData()
{
    FILE *fp;

    errno_t err;

    if ((err = fopen_s(&fp, "database.txt", "w+")) != 0)
    {
        // This indicates that the file can not be opened
        // will print the error message
        fprintf(stderr, "cannot open file '%s': %s\n",
                "database.txt");
    }
    else
    {
        fprintf(fp, "(\"does it live in water ?\"whale\" (\"Does it have four legs ? \" \"cat\" \"elephant\")) ");
        // whale
        // does it live in water
        fclose(fp);
    }
}