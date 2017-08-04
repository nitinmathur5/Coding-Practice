#include <stdio.h>

void cutthesticks(int n, int *a) {
    int i, aStick=n;
    int *ptr = a;
    printf("%d\n", aStick);
    while (aStick != 1) {
        int smallest_stick = 0xFFFF;
        int highest_stick = 0;
        for (i=0;i<(n-1);i++) {
            if((a[i] < a[i+1]) && smallest_stick > a[i])
                smallest_stick = a[i];
            else {  //i.e. a(i+1) > a(i)
                if(smallest_stick > a[i+1])
                    smallest_stick = a[i+1];
            }
            if((a[i] < a[i+1]) && highest_stick < a[i+1])
                highest_stick = a[i+1];
        }
        //printf("smallest stick = %d\n", smallest_stick);
        //printf("highest  stick = %d\n", highest_stick);

        aStick = 0;
        for(i=0;i<n;i++){
            //cut, and form a new array
            if(a[i] - smallest_stick > 0) {
                ptr[aStick] = (a[i] -= smallest_stick);
                //printf ("%d ", ptr[i]);
                aStick++;
            }
        }
        if (aStick != 0)
            printf("%d\n", aStick);
        //now copy the new array into a[] and set n to aStick
        for(i=0; i<aStick;i++) {
            a[i] = ptr[i];
            //printf("%d ,", a[i]);
        }
        n=aStick;
    }
}

int main() {
    int n;
    n = 8;
    //scanf("%d",&n);
    //int arr[n];
    //int arr[6] = {5, 4, 4, 2, 2, 8};
    int arr[8] = {1, 13, 3, 8, 14, 9, 4, 4};
    /*
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }

    */

    cutthesticks(n, arr);
    return 0;
}
