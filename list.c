#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *createNode(int value)
{
    Node *newNode;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->value = value;
    newNode->next = newNode;

    return newNode;
}

int insertEnd(Node **head, int value)
{
    Node *newNode;
    Node *currentNode;

    if (head == NULL)
    {
        return 0;
    }

    newNode = createNode(value);

    if (newNode == NULL)
    {
        return 0;
    }
    
    if (*head == NULL)
    {
        *head = newNode;
        return 1;
    }

    currentNode = *head;

    while (currentNode->next != *head)
    {
        currentNode = currentNode->next;
    }

    newNode->next = *head;
    currentNode->next = newNode;
    
    return 1;
}

static void printRecursive(const Node *currentNode, const Node *head, FILE *output)
{
    fprintf(output, "%d ", currentNode->value);

    if (currentNode->next != head)
    {
        printRecursive(currentNode->next, head, output);
    }
}

void printList(const Node *head, FILE *output)
{
    if (head == NULL)
    {
        fprintf(output, "Sarasas tuscias.\n");
        return;
    }

    printRecursive(head, head, output);
    
    fprintf(output, "\n");
}

void destroyList(Node **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    Node *currentNode;
    Node *nextNode;

    currentNode = (*head)->next;

    while (currentNode != *head)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    
    free(*head);
    *head = NULL;
}

int insertBefore(Node **head, int targetValue, int newValue)
{
    Node *currentNode;
    Node *previousNode;
    Node *newNode;

    if (head == NULL || *head == NULL)
    {
        return 0;
    }

    currentNode = *head;
    previousNode = *head;

    while (previousNode->next != *head)
    {
        previousNode = previousNode->next;
    }
    
    do
    {
        if (currentNode->value == targetValue)
        {
            break;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;

    } while (currentNode != *head);

    if (currentNode->value != targetValue)
    {
        return 0;
    }

    newNode = createNode(newValue);

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->next = currentNode;
    previousNode->next = newNode;

    if (currentNode == *head)
    {
        *head = newNode;
    }

    return 1;
}