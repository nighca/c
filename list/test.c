#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void assert(Bool condition, const char* name){
	if(!condition){
		printf("ERROR: \t%s\n", name);
		exit(1);
	}else{
		printf("PASS: \t%s\n", name);
	}
}


void testCreateNode(){
	NodeCnt cntVal = 1;
    Node* node = createNode(&cntVal);

	assert(*node->cnt == cntVal, "cnt value");
	assert(node->prev == NULL && node->next == NULL, "pointer NULL");
	assert(TRUE, "======= createNode");
}

void testCreateList(){
	List* list = createList();

	assert(list->length == 0, "length 0");
	assert(list->head == NULL && list->tail == NULL, "pointer NULL");
	assert(TRUE, "======= createList");
}

void testPush(){
	NodeCnt val1 = 1;
	NodeCnt val2 = 2;
    Node* node1 = createNode(&val1);
    Node* node2 = createNode(&val2);
    List* list = createList();

	push(list, node1);
	assert(list->length == 1, "length 1");
	assert(list->head == node1, "head node1");
	assert(list->tail == node1, "tail node1");

	push(list, node2);
	assert(list->length == 2, "length 2");
	assert(list->head == node1, "head node1");
	assert(list->tail == node2, "tail node2");

	assert(node1->prev == NULL, "node1 prev NULL");
	assert(node1->next == node2, "node1 next node2");
	assert(node2->prev == node1, "node2 prev node1");
	assert(node2->next == NULL, "node2 next NULL");
	
	assert(TRUE, "======= push");
}

void testUnShift(){
	NodeCnt val1 = 1;
	NodeCnt val2 = 2;
    Node* node1 = createNode(&val1);
    Node* node2 = createNode(&val2);
    List* list = createList();

	unShift(list, node1);
	assert(list->length == 1, "length 1");
	assert(list->head == node1, "head node1");
	assert(list->tail == node1, "tail node1");

	unShift(list, node2);
	assert(list->length == 2, "length 2");
	assert(list->head == node2, "head node1");
	assert(list->tail == node1, "tail node2");

	assert(node2->prev == NULL, "node2 prev NULL");
	assert(node2->next == node1, "node2 next node1");
	assert(node1->prev == node2, "node1 prev node2");
	assert(node1->next == NULL, "node1 next NULL");
	
	assert(TRUE, "======= unShift");
}

void testPop(){
	NodeCnt val1 = 1;
	NodeCnt val2 = 2;
    Node* node1 = createNode(&val1);
    Node* node2 = createNode(&val2);
    List* list = createList();

	push(list, node1);
	push(list, node2);

	Node* pop1 = pop(list);
	assert(list->length == 1, "length 1");
	assert(list->head == node1, "head node1");
	assert(list->tail == node1, "tail node1");
	assert(pop1 == node2, "pop1 eq node2");

	Node* pop2 = pop(list);
	assert(list->length == 0, "length 0");
	assert(list->head == NULL, "head NULL");
	assert(list->tail == NULL, "tail NULL");
	assert(pop2 == node1, "pop2 eq node1");

	assert(pop2->prev == NULL, "prev NULL");
	assert(pop2->next == NULL, "next NULL");
	
	assert(TRUE, "======= pop");
}

void testShift(){
	NodeCnt val1 = 1;
	NodeCnt val2 = 2;
    Node* node1 = createNode(&val1);
    Node* node2 = createNode(&val2);
    List* list = createList();

	push(list, node1);
	push(list, node2);

	Node* shift1 = shift(list);
	assert(list->length == 1, "length 1");
	assert(list->head == node2, "head node1");
	assert(list->tail == node2, "tail node1");
	assert(shift1 == node1, "shift1 eq node1");

	Node* shift2 = shift(list);
	assert(list->length == 0, "length 0");
	assert(list->head == NULL, "head NULL");
	assert(list->tail == NULL, "tail NULL");
	assert(shift2 == node2, "shift2 eq node2");

	assert(shift2->prev == NULL, "prev NULL");
	assert(shift2->next == NULL, "next NULL");
	
	assert(TRUE, "======= shift");
}

void testPushCnt(){
	NodeCnt val1 = 1;
	NodeCnt val2 = 2;
    List* list = createList();

	pushCnt(list, &val1);
	assert(list->length == 1, "length 1");
	assert(list->head->cnt == &val1, "head val1");
	assert(list->tail->cnt == &val1, "tail val1");

	pushCnt(list, &val2);
	assert(list->length == 2, "length 2");
	assert(list->head->cnt == &val1, "head val1");
	assert(list->tail->cnt == &val2, "tail val2");

	assert(TRUE, "======= pushCnt");
}

void testPopCnt(){
	NodeCnt val1 = 1;
	NodeCnt val2 = 2;
    Node* node1 = createNode(&val1);
    Node* node2 = createNode(&val2);
    List* list = createList();

	push(list, node1);
	push(list, node2);

	NodeCnt* pop1 = popCnt(list);
	assert(list->length == 1, "length 1");
	assert(list->head == node1, "head node1");
	assert(list->tail == node1, "tail node1");
	assert(pop1 == node2->cnt, "pop1 eq node2->cnt");

	NodeCnt* pop2 = popCnt(list);
	assert(list->length == 0, "length 0");
	assert(list->head == NULL, "head NULL");
	assert(list->tail == NULL, "tail NULL");
	assert(pop2 == node1->cnt, "pop2 eq node1->cnt");

	assert(TRUE, "======= popCnt");
}

void main(){
	testCreateNode();
	testCreateList();
	testPush();
	testUnShift();
	testPop();
	testShift();
	testPushCnt();
	testPopCnt();
	printf("FINISH\n");
}
