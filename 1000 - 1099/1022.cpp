// This can be solved using Topological Sort

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;


int main ()
{

	
	int num;
	scanf("%d", &num);
	int info[num + 1][num + 1];
	int pointcount[num + 1];
	bool alreadypushed[num + 1];

	
	// Setting relationship to none
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			info[i][j] = 0;

	for (int i = 1; i <= num; i++)
	{
		alreadypushed[i] = false;
		pointcount[i] = 0;
	}


	// Getting input and storing it in an adjacency matrix
	for (int i = 1, temp = 1; i <= num; i++)
	{
		cin >> temp;
		while (temp != 0)
		{
			info[i][temp] = 1;
			pointcount[temp]++;
			cin >> temp;
		}

	}

	stack <int> topologicalsort;

	
	int temp, counter = 0;
	while (counter < num)
	{
		for (int i = 1; i <= num; i++)
			if (pointcount[i] == 0 && alreadypushed[i] == false)
			{ 
				topologicalsort.push(i);
				alreadypushed[i] = true;
			}

		while (topologicalsort.size() != 0)
		{
			temp = topologicalsort.top();
			cout << temp << " ";
			// Reducing inbound links by 1 after removing a vertex
			for (int i = 1; i <= num; i++)
			{
				if (info[temp][i] == 1)
					pointcount[i]--;
			}
			topologicalsort.pop();
			counter++;
		}

	}

	



	return 0;
}

