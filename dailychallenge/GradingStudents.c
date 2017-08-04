#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int grades_size, int* grades, int *result_size){
    // Complete this function
    for (int i=0; i<grades_size; i++) {
        if(grades[i] >= 38) {
            int p = (((grades[i]/5)*5+5) - grades[i]);
            if(p < 3) {
                grades[i]+=p;
            }
        }
    }
    *result_size = grades_size;
    return grades;
}

int main() {
    int n;
    n = 4;
    int grades[4] = {73,67,38,33};
    //scanf("%d", &n);
    //int *grades = malloc(sizeof(int) * n);

    /*for(int grades_i = 0; grades_i < n; grades_i++){
       scanf("%d",&grades[grades_i]);
    }*/

    int result_size = n;
    int* result = solve(n, grades, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf("\n");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}
