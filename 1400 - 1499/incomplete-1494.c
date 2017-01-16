#include <stdio.h>

int main() {

    int balls;
    scanf("%d", &balls);
    int order[balls + 1];
    int previous = balls + 1;
    
    // just checking if the ball picked up is less
    // than the previous one. We can immediately 
    // break if even one order is messed up
    for(int i = 1; i <= balls; i++)
    {
        scanf("%d", &order[i]);
        if(order[i] + 1 != previous) {
            printf("Cheater");
            return 0;
        }
        previous = order[i];
    }

    printf("Not a proof");

    return 0;
}
