/**
 *  Integer Stack ADT : private implementation/ algorithms
 *    Stack implemented as a linked list
 *
 *  COMP220: Lab 7 Stacks and Queues
 *  Author:  Karan Nedungadi
 *  Date:    Mar. 8, 2018
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

#include "istack.h"

//HELPER FUNCTIONS
Node2_t* Node2Create(int item);
void Node2Print(Node2_t Node2);

//----- Node2 -----

/*
 * Constructor - return a new Node2 with a given value
*/
Node2_t* Node2Create(int item) {
	Node2_t* Node2 = malloc(sizeof(Node2_t));
	Node2->data = item;
	Node2->next = NULL;
	return Node2;
}

/* 
 * Prints a text declarition of a Node2 on STDOUT
 */
void Node2Print(Node2_t Node2) {
    printf("|\t%d\t| \n", Node2.data);
}

//----- INTEGER STACK -----

IntStack_t istackCreate() {
    Node2_t* dummy = Node2Create(INT_MIN);
    IntStack_t stack = {dummy};
    return stack;
}

void istackDestroy(IntStack_t *stack) {
     while(stack->head->next != NULL) {
         istackPop(stack);
     }
}

void istackPrint(IntStack_t stack) {
    Node2_t* cur = stack.head->next;
    printf("\n-Stack-\n");
    while(cur != NULL) {
        Node2Print(*cur);
        cur = cur->next;
    }
    printf("-----------------\n\n");
}

bool istackIsEmpty(IntStack_t stack) {
     return stack.head->next == NULL;
}

int istackTop(IntStack_t stack) {
    assert(!istackIsEmpty(stack));
    return stack.head->next->data;
}

int istackPop(IntStack_t *stack) {
    assert(!istackIsEmpty(*stack));
    Node2_t*Node2 = stack->head->next;
    stack->head->next = Node2->next;
    if(Node2->next == NULL) {
        stack->head->next = NULL;
    }
    int item = Node2->data;
    free(Node2);
    return item;
}

int istackPush(IntStack_t *stack, int item) {
    Node2_t* newNode2 = Node2Create(item);
    if(istackIsEmpty(*stack)) {
        stack->head->next = newNode2;
    }
    else{
        newNode2->next = stack->head->next;
        stack->head->next = newNode2;
    }
}