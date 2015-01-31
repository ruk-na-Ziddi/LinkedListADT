typedef struct student Student;
typedef struct list LinkedList;
typedef struct node Node;
typedef Node* Node_ptr;

struct list{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node{
	void *data;
	Node_ptr next;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, void (*)(void *data));
void * getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **);
LinkedList * filter(LinkedList, int (*)(void *));