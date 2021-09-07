#include <stdio.h>
#include <stdlib.h>

//Node for linked list
struct Node{
    int data;
    struct Node *next;
};

// print function:
//print out the value of each element
void print_list(struct Node *node){
    while (node != NULL){
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}


// insert function:
// insert a new element after some existing element.
void insert_node(struct Node** head_ref, int new_data){
    // create node and allocate it
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    // place data and the node inserted inserted in end so it points to NULL
    new_node->data  = new_data;
    new_node->next = NULL;

    //if the Linked List is empty, then make the new node as head
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node */
    last->next = new_node;
    return;
}

// delete function:
// delete a certain element
void delete_node(struct Node** head_ref, int key){
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}


int main() {
    // empty list
    struct Node* head = NULL;
    // Add elements in linked list
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    //print list
    printf("Elements in linked list:");
    print_list(head);

    //delete element
    delete_node(&head, 3);

    //print list
    printf("Elements in linked list after delete:");
    print_list(head);

    return 0;
}
