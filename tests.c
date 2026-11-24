#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void testCreateNode(void)
{
    int value = 25;

    Node *node = createNode(value);

    assert(node != NULL);
    assert(node->value == 25);
    assert(node->next == node);

    free(node);
}

static void testInsertEndIntoEmptyList(void)
{
    Node *head = NULL;

    int result = insertEnd(&head, 5);

    assert(result == 1);
    assert(head != NULL);
    assert(head->value == 5);
    assert(head->next == head);

    destroyList(&head);
}

static void testInsertEndIntoNonEmptyList(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 5) == 1);

    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 7) == 1);

    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next->value == 7);
    assert(head->next->next->next == head);

    destroyList(&head);
}

static void testInsertEndWithDuplicates(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 10) == 1);

    int result = insertEnd(&head, 10);

    assert(result == 1);
    assert(head->value == 10);
    assert(head->next != head);
    assert(head->next->value == 10);
    assert(head->next->next == head);

    destroyList(&head);
}

static void testInsertBeforeIntoEmptyList(void)
{
    Node *head = NULL;

    int result = insertBefore(&head, 10, 5);

    assert(result == 0);
    assert(head == NULL);
}

static void testInsertBeforeMiddle(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 5) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 7) == 1);

    int result = insertBefore(&head, 10, 8);

    assert(result == 1);
    assert(head->value == 5);
    assert(head->next->value == 8);
    assert(head->next->next->value == 10);
    assert(head->next->next->next->value == 7);
    assert(head->next->next->next->next == head);

    destroyList(&head);
}

static void testInsertBeforeFirstElement(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 5) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 7) == 1);
    Node *oldHead = head;

    int result = insertBefore(&head, 5, 3);

    assert(result == 1);
    assert(head != oldHead);
    assert(head->value == 3);
    assert(head->next == oldHead);
    assert(head->next->value == 5);
    assert(head->next->next->value == 10);
    assert(head->next->next->next->value == 7);
    assert(head->next->next->next->next == head);

    destroyList(&head);
}

static void testInsertBeforeLastElement(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 5) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 7) == 1);

    int result = insertBefore(&head, 7, 6);

    assert(result == 1);
    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next->value == 6);
    assert(head->next->next->next->value == 7);
    assert(head->next->next->next->next == head);

    destroyList(&head);
}

static void testInsertBeforeSingleElement(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 10) == 1);

    int result = insertBefore(&head, 10, 5);

    assert(result == 1);
    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next == head);

    destroyList(&head);
}

static void testInsertBeforeMissingElement(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 5) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 7) == 1);

    int result = insertBefore(&head, 99, 8);

    assert(result == 0);
    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next->value == 7);
    assert(head->next->next->next == head);

    destroyList(&head);
}

static void testInsertBeforeFirstDuplicate(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 20) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 30) == 1);

    int result = insertBefore(&head, 10, 5);

    assert(result == 1);
    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next->value == 20);
    assert(head->next->next->next->value == 10);
    assert(head->next->next->next->next->value == 30);
    assert(head->next->next->next->next->next == head);

    destroyList(&head);
}

static void testDestroyEmptyList(void)
{
    Node *head = NULL;

    destroyList(&head);
    destroyList(NULL);

    assert(head == NULL);
}

static void testDestroyNonEmptyList(void)
{
    Node *head = NULL;
    assert(insertEnd(&head, 5) == 1);
    assert(insertEnd(&head, 10) == 1);
    assert(insertEnd(&head, 7) == 1);

    destroyList(&head);

    assert(head == NULL);
}

int main(void)
{
    testCreateNode();
    testInsertEndIntoEmptyList();
    testInsertEndIntoNonEmptyList();
    testInsertEndWithDuplicates();
    testInsertBeforeIntoEmptyList();
    testInsertBeforeMiddle();
    testInsertBeforeFirstElement();
    testInsertBeforeLastElement();
    testInsertBeforeSingleElement();
    testInsertBeforeMissingElement();
    testInsertBeforeFirstDuplicate();
    testDestroyEmptyList();
    testDestroyNonEmptyList();

    return 0;
}
