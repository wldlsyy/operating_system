#include <stdio.h>
#include <stdlib.h>

int main(){
    int *x;
    int i;

    x = (int*) malloc(10*sizeof(int)); // memory allocation
    
    for (i=0;i<10;i++){
        x[i] = i;
        printf("%d ", x[i]);
    }
    free(x); // forget to free!
    return 0;
}
