#include <stdio.h>
#include <math.h>

// A lot of people had problems when they took pi as 3.14. They suggested to take it as 3.14159

int main (void) {

	// 	Getting input
	int nailcount;
	double radius;
	scanf("%d %lf", &nailcount, &radius);
	
	// Getting the coordinates of the nails
	double xcoor[nailcount + 1], ycoor[nailcount + 1], length = 0, temp;
	
	for (int i = 0; i < nailcount; i++)
		scanf("%lf %lf", &xcoor[i], &ycoor[i]);

	xcoor[nailcount] = xcoor[0];
	ycoor[nailcount] = ycoor[0];

	// If there's only one nail , the lenght of the rope is equal to the circumference of the circle
	// Finding distance between nail 1 and nail 2. Same for the others as well

	for (int i = 0; i < nailcount; i++) {
	
		temp = sqrt(((xcoor[i] - xcoor[i + 1]) * (xcoor[i] - xcoor[i + 1])) + ((ycoor[i] - ycoor[i + 1]) * (ycoor[i] - ycoor[i + 1])));
		length += temp;
	}	
	
	// Draw samples in a book. The left over length after considering the distance between the vertices is the circumference of a circle.
	// Since they all have the same radius, we needn't find the angle between them. 
	// Drawing it will give you a clear idea, you can also check for mathematical proof online.
	length += (3.141592 * radius * 2);
	printf("%.02lf", length);

	return 0;
}

