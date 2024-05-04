#include <stdio.h>
#include <stdlib.h>

struct playlist
{
    char Song title[50], Artist name[50], album[50], year[50], duration[50];
    struct list *top, *tail;
};
typedef struct playlist pl;

void enqueue(pl **top, pl **tail, int element)
{
    pl *new_node = (pl *)malloc(sizeof(struct pl));
    new_node->value = element;
    new_node->next = *top;
    if (!(*top))
        *tail = *top;
    else
        *tail = (*top)->next;
    *top = new_node;
    pl *temp = *top;
    while (!(temp->next))
        temp = temp->next;
    *tail = temp;
}

void dequeue(pl **)

    int main()
{
    pl *top = (pl *)malloc(sizeof(struct pl));
    pl *tail = (pl *)malloc(sizeof(struct pl));
    top->next = NULL;
    tail->next = NULL;
}
