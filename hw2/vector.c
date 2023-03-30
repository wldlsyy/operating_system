#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define VECTOR_INIT_SIZE 5

typedef struct vector{
    int *data; // pointer to an array of integers
    int size; // current total memory size
    int count; // current amount of data
} vector;

//Initialize
void vector_init(vector *v){
    v->count = 0;
    v->size = VECTOR_INIT_SIZE;
    v->data = (int*) malloc(sizeof(int) * v->size);

    return;
}

// Realloc memory for new data
int vector_resize(vector *v){
    int *new_data = realloc(v->data, sizeof(int) * (v->size + 10)); // realloc memory space for new data
    if (new_data == NULL){
        printf("Error: cannot allocate memory\n");
        return -1; // error
    }

    v->data = new_data;
    v->size += 10;
    
    return 0; // success
}

// Adding data to vector
int vector_add(vector *v, int data){
    if (v->size == v->count){ // if needed extra memory space is larger than current memory space
        vector_resize(v); // resize vector
    }
    
    v->data[v->count] = data;
    v->count++;

    return 0;
}


int main(int argc, char *argv[]){
    int n, i;
    int *data;
    vector v;

    vector_init(&v); // initialize vector

    printf("How many entries do you want to add?: ");
    scanf("%d", &n); // n -> count

    data = (int*) malloc(sizeof(int) * n);

    srand((unsigned int)time(NULL));
    for (i=0;i<n;i++){
        data[i] = rand()%100; // process random data
        vector_add(&v, data[i]);
    }

    // Print out the data in the vector
    printf("Vector data: ");
    for (i=0; i<v.count; i++){
        printf("%d ", v.data[i]);
    }
    printf("\n");

    free(data);
    free(v.data); // free memory

    return 0;
}