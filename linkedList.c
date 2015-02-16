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

void * getElementAt(LinkedList list, int index){
	Node_ptr walker=list.head;
	int i=0;
	if(index>=list.count) return NULL;
	while(i!=index){
		walker=(*walker).next;
		++i;
	}
	return (*walker).data;
}

int indexOf(LinkedList list, void *data){
	Node_ptr walker=list.head;
	int i=0;
	while(walker!=0){
		if((*walker).data==data) return i;
		walker=(*walker).next;
		++i;
	}
	return -1;
}

void * getNodeAt(LinkedList list, int index){
	Node_ptr walker=list.head;
	int i=0;
	if(index>=list.count) return NULL;
	while(i!=index){
		walker=(*walker).next;
		++i;
	}
	return walker;
}

void * deleteElementAt(LinkedList *list, int index){
	Node_ptr walker=list->head,runner;
	int i=0;
	if(index==0 && list->count>1){
		runner=walker;
		list->head=list->head->next;
		list->count--;
		return runner->data;
	}
	if(index==0 && list->count==1){
		runner=walker;
		list->head=NULL;
		list->tail=NULL;
		list->count--;
		return runner->data;
	}
	if(index==list->count-1){
		runner=list->tail;
		if(list->count>1) list->tail=getNodeAt(*list, list->count-2);
		if(list->count==1){
			list->head=NULL;
			list->tail=NULL;
		}
		list->count--;
		return runner->data;
	}
	while(walker!=0){
		if(i==index-1){
			runner=walker->next;
			walker->next=walker->next->next;
			list->count--;
			return runner->data;
		}
		walker=walker->next;
		++i;
	}
	return NULL;
}

int asArray(LinkedList list, void **array){
	int i;
	Node_ptr walker=list.head;
	for (i=0;i<list.count;i++){
		array[i]=walker->data;
		walker=walker->next;
	}
	return list.count;
}

LinkedList * filter(LinkedList list, int (*fn)(void *data)){
	int i;
	LinkedList *filteredList=calloc(sizeof(LinkedList),1);
	Node* walker = list.head;
	for(i=0;i<list.count;++i){
		if(fn(walker->data)) add_to_list(filteredList, walker);
		walker=walker->next;
	}
	return filteredList;
}