#include <stdio.h>
#include "data.h"

//TODO: create a function to read the data from the file and return it as a string
//TODO: create a function that takes as input a pointer of node and produces it as a string
//TODO: create a function that takes as input the string returned from the file
// and produces a pointer of node 

void writeData() {
	FILE* fp;

    errno_t err;

    if ((err = fopen_s(&fp ,"database.txt", "w+")) != 0) {
        // This indicates that the file can not be opened 
        // will print the error message
        fprintf(stderr, "cannot open file '%s': %s\n",
            "database.txt");
    }
    else {
		fprintf(fp, "(\"does it live in water ?\"whale\" (\"Does it have four legs ? \" \"cat\" \"elephant\")) ");
        // whale
        // does it live in water
		fclose(fp);
    }
}