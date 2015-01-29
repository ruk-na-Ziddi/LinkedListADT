#include "linkedlist.h"
#include "expr_assert.h"
#include <stdlib.h>

void test_createList_cretes_a_linked_list_and_sets_its_head_and_tail_to_NULL_and_count_to_0(){
	LinkedList list=createList();
	assertEqual((int)list.head, 0);
	assertEqual((int)list.tail, 0);
	assertEqual(list.count, 0);
}

void test_create_node_sets_given_data_as_nodes_data_and_its_next_to_NULL(){
	int data=5;
	Node_ptr node=create_node((void *)&data);
	assertEqual(*((int *)(*node).data), data);
	assertEqual((int)(*node).next, 0);
	free(node);
}

void test_add_to_list_adds_one_node_to_list_and_count_is_1(){
	int data=5;
	LinkedList list=createList();
	Node_ptr node=create_node((void *)&data);
	add_to_list(&list,node);
	assertEqual(*((int *)(*node).data), data);
	assertEqual(list.count,1);
	free(node);
}

void test_add_to_list_can_add_two_nodes_to_list_then_count_is_2(){
	int data=5;
	LinkedList list=createList();
	Node_ptr node1=create_node((void *)&data);
	Node_ptr node2=create_node((void *)&data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(*((int *)(*node1).data), data);
	assertEqual(*((int *)(*node2).data), data);
	assertEqual(list.count, 2);
	free(node1);
	free(node2);
}

void test_get_first_element_should_give_data_of_the_first_node_of_list(){
	int first_node_data=5,second_node_data=6;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(*((int *)get_first_element(list)), 5);
	free(node1);
	free(node2);
}

void test_get_last_element_should_give_data_of_the_last_node_of_list(){
	int first_node_data=5,second_node_data=6;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(*((int *)get_last_element(list)), 6);
	free(node1);
	free(node2);
}

void increment_by_one(void *data){
	*((int *)data)=*((int *)data) + 1;
}

void test_travese_should_increment_every_node_data_of_list_by_one(){
	int first_node_data=5,second_node_data=6;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	traverse(list, increment_by_one);
	assertEqual(first_node_data, 6);
	assertEqual(second_node_data, 7);
	free(node1);
	free(node2);
}