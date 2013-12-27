#ifndef _LIST_H
#define _LIST_H

#define TRUE 1
#define FALSE 0

typedef int Bool;

typedef int NodeCnt;

typedef struct _Node{
    struct _Node* prev;
    struct _Node* next;
    NodeCnt* cnt;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;

    int length;
} List;

Node* createNode(NodeCnt* cnt);

List* createList();

Bool hasNode(List* list, Node* a);

void insertAfter(List* list, Node* a, Node* b);

void removeNode(List* list, Node* n);

void unShift(List* list, Node* n);

void push(List* list, Node* n);

Node* pop(List* list);

Node* shift(List* list);

void pushCnt(List* list, NodeCnt* cnt);

NodeCnt* popCnt(List* list);

#endif
