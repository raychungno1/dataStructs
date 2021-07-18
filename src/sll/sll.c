#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

void sllAddFirst (struct sllNode **headPtr, int data) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}

	/* rearrange pointers to insert node at front */
	node->data = data;
	node->next = *headPtr;
	*headPtr = node;
}

void sllAddLast (struct sllNode **headPtr, int data) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}
	
	/* traverse to end of list */
	while (*headPtr != NULL) headPtr = &(*headPtr)->next; /* update pointer */

	/* rearrange pointers to insert node at front */
	node->data = data;
	node->next = *headPtr;
	*headPtr = node;
}

void sllClear (struct sllNode **headPtr) {

	/* temporary node to free memory */
	struct sllNode *temp;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = *headPtr; /* store current node into temp */
		*headPtr = (*headPtr)->next; /* update pointer */

		free(temp), temp = NULL; /* clear node */
	}

}

int sllContains (struct sllNode **headPtr, int data) {

	/* while the current node is not null */
	while (*headPtr != NULL) {
		if (data == (*headPtr)->data) return 1; /* return 1 if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* return 0 if no match found */	
	return 0;
}

void sllPrint (struct sllNode **headPtr) {

	/* opening bracket */
	printf("{");

	/* while the current node is not null */
	while (*headPtr != NULL) {
		printf("%i", (*headPtr)->data); /* use print func */
		if ((*headPtr)->next != NULL) printf(", "); /* print comma if node isn't the last node */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* ending bracket */
	printf("}\n");	
}

void sllRemove (struct sllNode **headPtr, int data) {

	/* temporary storage to free memory */
	struct sllNode *temp;

	/* while the current node is not null or a match is not found */
	while (*headPtr != NULL && data != (*headPtr)->data) {
		headPtr = &(*headPtr)->next; /* update pointer */
	}
	
	/* return if list is empty or match is not found */
	if (*headPtr == NULL) return;

	/* remove selected node */
	temp = *headPtr;
	*headPtr = (*headPtr)->next;

	/* free the node */
	free(temp), temp = NULL;
}

int sllRemoveFirst (struct sllNode **headPtr) {

	int data; /* output var */
	struct sllNode *temp = *headPtr; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* shift head pointer to second node */
	data = temp->data;
	*headPtr = (*headPtr)->next;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int sllRemoveLast (struct sllNode **headPtr) {

	int data; /* output var */
	struct sllNode *temp; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* traverse to end of list */
	while ((*headPtr)->next != NULL) headPtr = &(*headPtr)->next; /* update pointer */

	/* remove last node */
	temp = *headPtr;
	data = temp->data;
	*headPtr = NULL;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int sllSize (struct sllNode **headPtr) {

	/* initialize output */
	int size = 0;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		size++; /* update size & pointer */
		headPtr = &(*headPtr)->next;
	}

	/* output */
	return size;
}

