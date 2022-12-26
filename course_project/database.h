#include <stdio.h>
#include <stdlib.h>
#include "data.h"

char *filetext()
{
    char *wtext = (char *)malloc(sizeof(wtext) + 1);
    FILE *fp;
    fopen_s(&fp, "database.txt", "w+");
    printf("%d", sizeof(*fp));
    fgets(wtext, sizeof(*fp), fp);
    fclose(fp);
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