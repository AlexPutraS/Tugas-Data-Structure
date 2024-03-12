#include <stdio.h>
#include <stdlib.h>

struct data{
	int age;
	struct data *next;
	struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;

struct data *create_node(int age){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->prev = NULL;
	node->age = age;
	
	return node;
}

void push_head(int age){
	struct data *node = create_node(age);
	node->next = head;
	head->prev = node;
	head = node;
}

void push_tail(int age){
	struct data *node = create_node(age);
	node->prev = tail;
	tail->next = node;
	
	tail = node;
}

void push_mid(int age, int insertafter) {
    
    if (head == NULL || insertafter == -1) {
        push_head(age);
        return;
    }

    struct data *temp = head;
    while (temp != NULL && temp->age != insertafter) {
        temp = temp->next;
    }

    
    if (temp == NULL) {
        push_tail(age);
        return;
    }

    
    struct data *node = create_node(age);

    
    node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = node;
    }
    node->prev = temp;
    temp->next = node;

    
    if (tail == temp) {
        tail = node;
    }
}

void pop_head(){
	struct data *temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
}

void pop_tail(){
	struct data *temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	
	free(temp);
}

void pop_search(int age){
	 struct data *temp = head;

    // Search for the node to remove
    while (temp != NULL && temp->age != age) {
        temp = temp->next;
    }

    if (temp == NULL) {
        // Node not found, do nothing
        return;
    }

    // Handle removal of head or tail nodes efficiently
    if (temp == head) {
        pop_head();
        return;
    }

    if (temp == tail) {
        pop_tail();
        return;
    }

    // Remove the node from the middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void print_linked_list(){
	struct data *temp = head;
	int count = 1;
	
	while(temp != NULL){
		printf("Data ke-%d : %d\n", count, temp->age);
		temp = temp->next;
		count++;
	}
}

int main(){
	
	head = create_node(2);;
	tail = create_node(5);
	
	head->next = tail;
	tail->prev = head;
	
	//push depan
	push_head(1);
	push_head(8);
	//push belakang
	push_tail(10);
	push_tail(19);

	//push depan
	pop_head();
	
	print_linked_list();
	
	printf("\n");
	
	//push tengah
	push_mid(3, 5);
	push_mid(7, 8);
	print_linked_list();
	
	printf("\n");
	
	//pop search
	pop_search(19);
	print_linked_list();
	
	return 0;
}
