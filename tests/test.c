#include <stdio.h>
#include <linked_list.h>

int main(void) {
  LinkedList list = NULL;
  init_list(&list);
  append_to_list(list, 1);
  append_to_list(list, 2);
  append_to_list(list, 3);
  remove_from_list(list, 0);
  add_to_list(list, 2, 99);
  print_list(list);
}
