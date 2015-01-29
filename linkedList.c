#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList(void){
	LinkedList list={NULL,NULL,0};
	return list;
}

Node * create_node(void *data){
	Node_ptr node=malloc(sizeof(Node));
	(*node).data=data;
	(*node).next=NULL;
	return node;
}

int add_to_list(LinkedList *list,Node *node){
	if((*list).head==NULL) (*list).head=node;
	if((*list).tail!=NULL) (*(*list).tail).next=node;
	(*list).tail=node;
	(*list).count++;
	return 0;
}

void *get_first_element(LinkedList list){
	return list.head->data;
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}

void traverse(LinkedList list, void (*fn)(void *data)){
	Node_ptr walker=list.head;
	while(walker!=NULL){
		fn((*walker).data);
		walker=(*walker).next;
	}
}