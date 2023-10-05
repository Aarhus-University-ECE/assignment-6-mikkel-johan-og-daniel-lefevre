#pragma once

typedef struct node {
  int data;
  struct node *next;
} node;

void add(node *head, int x);
int size(node *l);
void printout(node *l);
int largest(node *l);
