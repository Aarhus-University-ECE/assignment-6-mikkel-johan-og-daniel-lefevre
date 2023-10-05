#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void add(node* head, int x) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: A new node containing x is added to the end of the list
  assert(head != NULL);
  node* p = head;
  while (p->next != NULL) {
    p = p->next;
  } // p points to the last element
  node* element = malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element;
}

// exersice 3.b
int size(node *l) {
  assert(l);
  int counter = 0;
  node* p = l;
  while(p->next != NULL){
    p = p->next;
    counter++;
  }
	return counter;
}

// exersice 3.c and 3.d
void printout(node *l) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: The values of the list are printed out
  node* p = l->next;
  //The While-loop traverses the linked list and prints every element
  while (p != NULL) {
    printf("%d, ", p->data);
    p = p->next;
  }
  printf("\n");
}

// exersice 3.e
int largest(node *head) {
  // pre:  head poinst to the first, empty element.
  // 	     The last element's next is NULL.
  // post: Returns the largest value of the list

  // Sets the record to be the first node to be the record
  int record = head->data;
  while(head != NULL) {
    if (head->data > record) {
      // Checks if the next nodes data is larger and if it is, it sets this as the new record
      record = head->data;
    }
    // Goes to the next node
    head = head->next;
  }
  return record;
}

#ifndef TEST
int main() {
  node* list = malloc(sizeof(node));
  list->next = NULL; // create first empty element

  add(list, 1);
  add(list, 3);
  add(list, 2);
  printout(list);
  // Show list here
  add(list, 2);
  printout(list);
  // Show list here

  return 0;
}

#endif
