#ifndef LIST_H
#define LIST_H
#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *createNode(int value);
int insertEnd(Node **head, int value);
void printList(const Node *head, FILE *output);
void destroyList(Node **head);
int insertBefore(Node **head, int targetValue, int newValue);

#endif