#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Linked list node
typedef struct Node{ 
    int data; // data to be inserted
    struct Node *next; // address that points to the next node
} Node;

// Linked list initialization
void llist_init(Node **head){
    *head = NULL;
}

// Add new data to linked list
void llist_add(Node **head, int data){
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;

    if (*head == NULL){
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current -> next != NULL){
        current = current -> next;
    }
    current -> next = new_node;
}

// Free memory for linked list
void llist_free(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    int n, i;
    int *data;
    Node *head;

    llist_init(&head); // initialize linked list

    printf("How many entries do you want to add?: ");
    scanf("%d", &n); // n -> count

    data = (int*) malloc(sizeof(int) * n);

    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++) {
        data[i] = rand() % 100; // process random data
        llist_add(&head, data[i]);
    }

    // Print out the data in the linked list
    printf("Linked list data: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    free(data);
    llist_free(&head); // free memory

    return 0;
}