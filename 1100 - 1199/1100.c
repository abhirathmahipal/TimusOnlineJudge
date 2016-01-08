#include <stdio.h>

int main (void) {

	int teams;
	scanf("%d", &teams);

	int m[teams], id[teams];
	
	for (int i = 0; i < teams; i++) {
		scanf("%d %d", &id[i], &m[i]);
		
	}

	// It is better to just display it rather than sorting it
	// we know that values that are to be sorted are only between 
	// 0 and 100. This way we need to make only 101 iterations.
	

	for (int i = 100; i != -1; i--) {
		
		for (int j = 0; j < teams; j++) {

			if (m[j] == i)
				printf("%d %d\n", id[j], m[j]);

		}


	}
	
}