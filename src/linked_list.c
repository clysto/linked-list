#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

void init_list(LinkedList *list) {
  *list = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
  (*list)->next = NULL;
}

void append_to_list(LinkedList list, int value) {
  struct LinkedListNode *p = list;
  while (p->next) {
    p = p->next;
  }
  p->next = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
  p->next->value = value;
  p->next->next = NULL;
}

void print_list(LinkedList list) {
  struct LinkedListNode *p = list->next;
  printf("[ ");
  while (p) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("]\n");
}

void remove_from_list(LinkedList list, int index) {
  struct LinkedListNode *p = list;
  while (index && p->next) {
    p = p->next;
    index--;
  }
  if (!p->next)
    return;
  struct LinkedListNode *q = p->next;
  p->next = p->next->next;
  free(q);
}

void add_to_list(LinkedList list, int index, int value) {
  struct LinkedListNode *p = list;
  while (index && p->next) {
    p = p->next;
    index--;
  }
  if (index)
    return;
  struct LinkedListNode *q = p->next;
  p->next = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
  p->next->value = value;
  p->next->next = q;
}
