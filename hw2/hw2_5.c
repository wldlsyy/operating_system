#include <stdio.h>
#include <stdlib.h>

int main(){
        int *data;

        data = (int*) malloc(100*sizeof(int)); // memory allocation
        data[100] = 0;

        free(data); // free memory
        return 0;
}

