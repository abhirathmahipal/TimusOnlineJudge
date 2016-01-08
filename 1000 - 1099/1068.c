#include <stdio.h>

int main (void) {

	int input, sum = 0;
	scanf("%d", &input);

	// if number is greater than 1
	if (input > 1) {

		while (input != 0) {
			sum += input;
			input--;
		}

		printf("%d", sum);
		return 0;
	}

	// if the number is less than 1
	else if (input < 1) {

		while (input != 2) {
			sum += input;
			input++;
		}

		printf("%d", sum);
		return 0;

	}
	// If it's one, just print 1
	printf("%d", input);

	return 0;

}