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
// void print (void *data){
// 	printf("list--> %d\n",data );
// }
void test_add_to_list_adds_one_node_to_list_and_count_is_1(){
	int data=5;
	LinkedList list=createList();
	Node_ptr node=create_node((void *)&data);
	add_to_list(&list,node);
	assertEqual(*((int *)(*node).data), data);
	assertEqual(*((int *)(list.head->data)), 5);
	assertEqual(*((int *)(list.tail->data)), 5);
	// traverse(list, print);
	assertEqual(list.count,1);
	free(node);
}

void test_add_to_list_can_add_two_nodes_to_list_then_count_is_2(){
	int data=5,data1=6;
	LinkedList list=createList();
	Node_ptr node1=create_node((void *)&data);
	Node_ptr node2=create_node((void *)&data1);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(*((int *)(*node1).data), data);
	assertEqual(*((int *)(*node2).data), data1);
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

void test_getElementAt_should_give_the_data_for_given_index(){
	int first_node_data=5,second_node_data=6;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(*((int *)getElementAt(list, 1)), 6);
	free(node1);
	free(node2);
}

void test_getElementAt_should_give_the_data_for_given_index_indexis_2(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(*((int *)getElementAt(list, 2)), 7);
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_should_give_null_when_index_is_bigger_than_count(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual((int)getElementAt(list, 4), 0);
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_should_give_null_when_index_is_equal_to_count(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual((int)getElementAt(list, 3), 0);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_should_give_2_when_given_data_is_3rd_node_data(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(indexOf(list, &third_node_data), 2);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_should_give_negtive_1_when_given_data_is_not_found(){
	int first_node_data=5,second_node_data=6,third_node_data=7,number=10;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(indexOf(list, &number), -1);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_delete_the_node_at_given_index(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(*((int *)deleteElementAt(&list, 1)), second_node_data);
	assertEqual(indexOf(list, &third_node_data), 1);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_delete_the_first_node(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(*((int *)deleteElementAt(&list, 0)), first_node_data);
	assertEqual(indexOf(list, &second_node_data), 0);
	assertEqual(indexOf(list, &third_node_data), 1);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementA_should_delete_the_first_node(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(*((int *)deleteElementAt(&list, 2)), third_node_data);
	assertEqual(indexOf(list, &second_node_data), 1);
	assertEqual(indexOf(list, &first_node_data), 0);
	assertEqual(*((int *)list.tail->data), second_node_data);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElement_should_delete_the_only_node(){
	int first_node_data=5;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	add_to_list(&list, node1);
	assertEqual(*((int *)deleteElementAt(&list, 0)), first_node_data);
	assertEqual(indexOf(list, &first_node_data), -1);
	assertEqual((int)list.tail, 0);
	assertEqual((int)list.head, 0);
	free(node1);
}

void test_deleteElementA_should_delete_the_second_node_when_only_two_nodes_are_there(){
	int first_node_data=5,second_node_data=6;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assertEqual(*((int *)deleteElementAt(&list, 1)), second_node_data);
	assertEqual(indexOf(list, &first_node_data), 0);
	assertEqual(*((int *)list.tail->data), first_node_data);
	assertEqual(*((int *)list.head->data), first_node_data);
	free(node1);
	free(node2);
}

void test_asArray_puts_all_node_datas_in_an_array(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	int *array[3];
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	assertEqual(asArray(list, (void **)array), 3);
	assertEqual(*(array[0]), first_node_data);
	assertEqual(*(array[1]), second_node_data);
	assertEqual(*(array[2]), third_node_data);
	free(node1);
	free(node2);
	free(node3);
}

int greter_than_4(void *data){
	return *(int*)data > 4;
}

void test_filter_puts_only_greter_than_4_node_data_in_filtered_list(){
	int first_node_data=5,second_node_data=6,third_node_data=7;
	LinkedList *filteredList;
	LinkedList list = createList();
	Node_ptr node1=create_node((void *)&first_node_data);
	Node_ptr node2=create_node((void *)&second_node_data);
	Node_ptr node3=create_node((void *)&third_node_data);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	filteredList=filter(list, greter_than_4);
	assertEqual(*((int *)filteredList->head->data), first_node_data);
	assertEqual(*((int *)filteredList->tail->data), third_node_data);
	assertEqual(indexOf(*filteredList, &second_node_data), 1);
	free(filteredList);
	free(node1);
	free(node2);
	free(node3);
}