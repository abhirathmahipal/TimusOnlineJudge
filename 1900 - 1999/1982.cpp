#include <iostream>
#include <limits.h>

using namespace std;

int main ()
{
	int n, k;

	cin >> n >> k;
	int powerstation[n + 1];
	int graph[n + 1][n + 1];
	int vertices[n+1], processed[n+1];

	// Assuming no power station in any city
	for (int i = 0; i <= n; i++)
		powerstation[i] = 0, vertices[i] = INT_MAX, processed[i] = 0;

	for (int i = 0, temp = 0; i < k; i++)
	{
		cin >> temp;
		powerstation[temp] = 1;
	}

	// Getting input
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
		}

	}

	// Power station to power station routes are set to zero because in reality they 
	// aren't required therefore don't add to cost.

	for (int i = 1; i <=n; i++)
	{
		if (powerstation[i] == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				if (powerstation[j] == 1)
					graph[i][j] = 0;

				if (i == j)
					graph[i][j] = INT_MIN;

			}
		}
	}

		
	// We can now find out a MST
	vertices[1] = 0;

	for (int i = 1, temp = INT_MAX, iter = 0; i < n; i++)
	{

		// Finding vertex with min weight
		for (int j = 1; j <= n; j++)
		{
			if (vertices[j] < temp && processed[j] == 0)
				temp = vertices[j], iter = j;

		}

		processed[iter] = 1;

		// updating vertices array
		for (int j = 1; j <= n; j++)
		{
			if (processed[j] == 0)
				if (graph[iter][j] >= 0 && graph[iter][j] < vertices[j])
					vertices[j] = graph[iter][j];
		}

		temp = INT_MAX;

	}


	int u = 0;

	for (int i = 1; i <= n; i++)
		u += vertices[i];


	cout << u;

	return 0;
}
