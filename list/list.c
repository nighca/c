#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Node* createNode(NodeCnt* cnt){
    if(cnt == NULL){
		cnt = malloc(sizeof(NodeCnt));
	}

	Node* node = malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->cnt = cnt;

    return node;
}

List* createList(){
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

Bool hasNode(List* list, Node* a){
    Node* n = list->head;

	if(a == NULL){
		return FALSE;
	}

    while(n != NULL){
        if(n == a){
            return TRUE;
        }

        n = n->next;
    }

    return FALSE;
}

void insertAfter(List* list, Node* a, Node* b){
    if(a != NULL && !hasNode(list, a)){
        return;
    }

    if(a == NULL){
        b->prev = NULL;
        b->next = list->head;

		if(list->head != NULL){
	        list->head->prev = b;
		}
        list->head = b;
    }else{
        b->prev = a;
        b->next = a->next;

		if(a->next != NULL){
			a->next->prev = b;
		}
        a->next = b;
    }

    if(b->next == NULL){
        list->tail = b;
    }

	list->length++;
}

void removeNode(List* list, Node* n){
    if(!hasNode(list, n)){
        return;
    }

    Node* prev = n->prev;
    Node* next = n->next;

    if(prev == NULL){
        list->head = next;
    }else{
        prev->next = next;
    }

    if(next == NULL){
        list->tail = prev;
    }else{
        next->prev = prev;
    }

    n->prev = NULL;
    n->next = NULL;

	list->length--;
}

void unShift(List* list, Node* n){
    Node* a = NULL;
    insertAfter(list, a, n);
}

void push(List* list, Node* n){
    insertAfter(list, list->tail, n);
}

Node* pop(List* list){
    Node* n = list->tail;

    if(n != NULL){
        removeNode(list, n);
    }

    return n;
}

Node* shift(List* list){
    Node* n = list->head;

    if(n != NULL){
        removeNode(list, n);
    }

    return n;
}

void pushCnt(List* list, NodeCnt* cnt){
    Node* node = createNode(cnt);
    push(list, node);
}

NodeCnt* popCnt(List* list){
    Node* node = pop(list);
    return node->cnt;
}
