#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#define NUMPAGES 16384
#define PAGESIZE 4096 // 1 page = 4KB

/* measures the cost of accessing each page */
double tlb_measure(int num_pages, int num_trials){
    int i, j, jump;
    int *a;
    struct timespec startTime, endTime;
    long totalTime, perTime, avgTime;

    jump = PAGESIZE / sizeof(int); // distance to next page

    a = (int*) malloc(NUMPAGES * PAGESIZE);
    if (a == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (i = 0; i < NUMPAGES * jump; i += jump){
            a[i] = 0; // initialize array
    }

    printf("TLB measurement for %d pages in %d trials:\n", num_pages, num_trials);
    avgTime = 0;
    for (j = 0; j < num_trials ; j++){
        clock_gettime(CLOCK_MONOTONIC, &startTime); // start time
        for (i = 0; i < num_pages * jump; i += jump){
            a[i] += 1; // page access
            a[i] *= 2;
            a[i] *= 4;
            a[i] *= 8;
            a[i] *= 16;
            //printf("%d ", a[i]);
        }
        clock_gettime(CLOCK_MONOTONIC, &endTime); // end time
        totalTime = (endTime.tv_sec - startTime.tv_sec) * 1000000000 + (endTime.tv_nsec - startTime.tv_nsec); // 1 trial에 num_pages만큼 접근할 때 걸린 총 시간
        perTime = totalTime / num_pages; // 한 페이지 당 접근하는 데 걸린 시간
        printf("Time per access in %d pages: %ld ns\n", num_pages, perTime);

        if (j > num_trials / 2)
                avgTime += perTime;
    }

    //printf("%ld, %d", avgTime, num_trials);
    free(a);
    return avgTime / (num_trials / 2 -1);
}

int main(int argc, char *argv[]){
    int num_pages = atoi(argv[1]);
    int num_trials = atoi(argv[2]);
    long result;

    result = tlb_measure(num_pages, num_trials);
    printf("Average time per page access in %d trials: %ld ns\n", num_trials, result);
    return 0;
}
