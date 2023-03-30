#include <stdio.h>
#include <stdlib.h>

int main(){
        int *data;
        int i;

        data = (int*) malloc(100*sizeof(int)); // memory allocation
        // allocate data
        for (i=0;i<100;i++){
                data[i] = i;
        }

        free(data[50]); // free memory using a pointer in the middle of the array
        return 0;
}