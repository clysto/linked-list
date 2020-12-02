struct LinkedListNode {
  int value;
  struct LinkedListNode *next;
};

typedef struct LinkedListNode *LinkedList;

void init_list(LinkedList *list);

void append_to_list(LinkedList list, int value);

void print_list(LinkedList list);

void remove_from_list(LinkedList list, int index);

void add_to_list(LinkedList list, int index, int value);
