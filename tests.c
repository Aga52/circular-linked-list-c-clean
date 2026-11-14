#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main(void)
{
    Node *node = createNode(25);

    assert(node != NULL);
    assert(node->value == 25);
    assert(node->next == node);

    free(node);

    Node *head = NULL;

    assert(insertBefore(&head, 10, 5) == 0);
    assert(head == NULL);

    assert(insertEnd(&head, 10) == 1);
    assert(head != NULL);
    assert(head->value == 10);
    assert(head == head->next);

    assert(insertEnd(&head, 20) == 1);
    assert(head->value == 10);
    assert(head->next->value == 20);
    assert(head->next->next == head);

    assert(insertBefore(&head, 20, 15) == 1);
    assert(head->next->value == 15);
    assert(head->next->next->value == 20);

    assert(insertBefore(&head, 10, 5) == 1);
    assert(head->value == 5);
    assert(head->next->value == 10);

    assert(insertBefore(&head, 99, 50) == 0);

    destroyList(&head);
    assert(head == NULL);

    assert(insertEnd(&head, 10) == 1);
    assert(insertBefore(&head, 10, 5) == 1);

    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next == head);

    destroyList(&head);
    assert(head == NULL);

    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 20) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 30) == 1);

    assert(insertBefore(&head, 10, 5) == 1);

    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next->next->next->next == head);

    destroyList(&head);
    assert(head == NULL);

    FILE *testFile;

    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 20) == 1);
    assert(insertEnd(&head, 30) == 1);

    testFile = tmpfile();
    assert(testFile != NULL);

    printList(head, testFile);

    char outputText[100];

    rewind(testFile);

    assert(fgets(outputText, sizeof(outputText), testFile) != NULL);
    assert(strcmp(outputText, "10 20 30 \n") == 0);

    fclose(testFile);

    destroyList(&head);
    assert(head == NULL);

    return 0;
}