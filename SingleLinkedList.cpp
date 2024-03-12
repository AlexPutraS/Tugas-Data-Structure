#include <stdio.h>
#include <stdlib.h>

struct data {
	int age;
	struct data *next; //self reference
};

struct data *head = NULL;
struct data *tail = NULL;

struct data *create_node(int age){
//	alokasi memori secara dynamic menggunakan malloc
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->age = age;
	
	return node;
}

struct data *push_head(struct data *head, int age){
	struct data *node = create_node(age);
	node->next = head;
	head = node;
	return head;
}

struct data *push_tail(int age)
{
	struct data *node = create_node(age);

	tail -> next = node;
	tail = node;
}

struct data *push_tail(struct data *head, int age){
	struct data *node = create_node(age);
	struct data *temp = head; //variable pembantu untuk cek node terakhir
	
	//assign temp ke node terakhir
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next =node; //assign address baru ke node paling terakhir untuk simpan alamat ke node baru
	return head;
}


//struct data *push_mid
struct data *push_mid(struct data *head, int search_value, int new_value) {
    if (head == NULL) {
        printf("List is empty. Cannot insert based on search.\n");
        return head;  
    }

    struct data *temp = head;

    // Mencari nilai node yang sama dengan search_valuenya
    while (temp != NULL) {
        if (temp->age == search_value) {
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {  // kondisi ketika linkedlistnya kosong
        printf("Value %d not found in the list\n", search_value);
        return head;
    }

    //Insert setelah ketemu nodenya
    struct data *new_node = create_node(new_value);
    new_node->next = temp->next;
    temp->next = new_node;

    // kondisi ketika nilai tail dengan search_valuenya sama
    if (tail == temp) {
        tail = new_node;
    }

    return head;
}




struct data *pop_head(struct data *head){
	struct data *temp = head;
	//assign value baru di head untuk simpan alamat dari data kedua 
	head = head->next;
	
	free(temp);//free memory
	
	return head;
}

// hapus data paling terakhir
struct data *pop_tail(struct data *head){
	struct data *del = head; //akan menyimpan tempat yang akan kita delete
	struct data *temp = head; 
	
	while(del->next != NULL){
		temp = del;
		del = del->next;
	}
	temp->next = NULL;
	free(del);
	return head;
}

void print_linked_list(struct data *head){
	struct data *temp;
	temp = head;
	int count = 1;
	while(temp != NULL){
		printf("Data ke-%d : %d\n",count, temp->age);
		temp = temp->next;
		count++;
	}
//	printf("%d", head->age);
}

//struct data *pop_search(struct data *head, int age)
struct data *pop_search(struct data *head, int age) {
    if (head == NULL) {
        printf("List is empty. Cannot delete based on search.\n");
        return head;
    }

    struct data *temp = head;
    struct data *current = head; 

    // mencari node yang ingin di pop
    while (temp != NULL) {
        if (temp->age == age) {
            break;
        }
        current = temp;
        temp = temp->next;
    }

    if (temp == NULL) {  // Value not found
        printf("Value %d not found in the list\n", age);
        return head;
    }

    // kondisi ketika value head == searchnya(nilai yang ingin dihapus)
    if (current == head) {
        head = temp->next;
    } else {
        current->next = temp->next;
    }

    // kondisi ketika value tail == searchnya(nilai yang ingin dihapus)
    if (tail == temp) {
        tail = current;
    }

    free(temp);
    return head;
}

int main(){
	
	struct data *head;
	head = create_node(10);
	head = push_tail(head, 15); //push tail atau insert data di belakang
	head = push_head(head, 5); //push head atau insert data di depan
	head = push_head(head, 2);
	print_linked_list(head);
	
	printf("\n");
	
	head = push_mid(head, 5, 9);
	print_linked_list(head);
	
	printf("\n");
	
	head = pop_search(head, 9);
	print_linked_list(head);
	
	return 0;
}

