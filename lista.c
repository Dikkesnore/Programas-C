/**********************************************************
 *                                                        *
 *    This code creates a simple list structure.          *  
 *    It stores integers (easy to convert to another      *
 *    list type from this code) and can grow at will      *
 *    using memory allocation and memory de-allocation    *
 *                                                        *
 **********************************************************/

#include <stdio.h>
#include <malloc.h>

#ifndef NULL
#define NULL 0x00
#endif

typedef struct node
{
    int num;
    struct node *next;
}node;

// Prototypes
void add(node *list, int num);
void release(node *list);
void printList(node *list);
void pop(node *list);

int main()
{
    node *list = malloc(sizeof(node));
    if(list == NULL)
    {
        return 1;
    }
    list->num = 1;
    list->next = NULL;

    add(list, 2);
    add(list, 3);
    pop(list);
    add(list, 4);
    printList(list);

    release(list);
    return 0;
}

void add(node *list, int num)
{
    if (list->next == NULL)
    {
        list->next = malloc(sizeof(node));
        if (list->next != NULL)
        {
            list->next->num = num;
            list->next->next = NULL;
        }
        else
        {
            printf("Error while adding %d to the list, coudn't create space in memory.\n", num);
        }
    }
    else
    {
        add(list->next, num);
    }
}

void pop(node *list)
{
    if (list->next == NULL)
    {
        printf("List has only one element, therefore this is gonna release it.\n");
        free(list);
    }
    else if (list->next->next == NULL)
    {
        free(list->next->next);
        list->next = NULL;
    }
    else
    {
        pop(list->next);
    }
}

void printList(node *list)
{
    if(list->next == NULL)
    {
        printf("%d\n", list->num);
    }
    else
    {
        printf("%d\n", list->num);
        printList(list->next);
    }
}

void release(node *list)
{
    if(list->next == NULL)
    {
        free(list);
    }
    else
    {
        release(list->next);
        free(list);
    }
}
