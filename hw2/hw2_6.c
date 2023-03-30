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

        free(data); // free memory
        
        for (i=0;i<100;i++){
                printf("%d ", data[i]); // print one element after freeing
        }
        printf("\n");
        return 0;
}
