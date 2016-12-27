#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    int n[140001];
    int m, temp = 0;
    
    scanf("%d", &m);

    int counter = 1;
    while(temp != -1) {
        scanf("%d", &temp);
        n[counter++] = temp;                
    }


    // could have done faster using dynamic programming but
    // this sufficed given the small size of input

    for (int i = 1; i < counter - m; i++) {
        int j = i; int highest = INT_MIN;

        for (int k = 0; k < m; k++) {
            if (n[j + k] > highest)
                highest = n[j + k];            
        }

        printf("%d\n", highest);
    }


    return 0;
}
