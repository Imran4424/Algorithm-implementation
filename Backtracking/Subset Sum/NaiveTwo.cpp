#include <stdio.h>
#include <vector>
using namespace std;

bool status = false;

vector<int> SubsetSum(int input[], int n, int sum, vector <int> solve)
{
	if (0 == sum)
	{
		status = true;

		return solve;
	}

	if(0 == n && sum != 0)
	{
		status = false;

		return solve;
	}

	if (input[n-1] > sum)
	{
		return SubsetSum(input, n-1, sum, solve);
	}

	solve.push_back(input[n-1]);

	return (SubsetSum(input, n-1, sum, solve) || SubsetSum(input, n-1, sum - input[n-1]), solve);
}

int main(int argc, char const *argv[])
{
	int size, target;

	scanf("%d %d", &size, &target);

	int input[size];

	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &input[i]);
	}

	vector <int> solve;

	solve = SubsetSum(input, size, target, solve);

	if(status)
	{
		// printf("Solution exists\n");

		for (int i = 0; i < solve.size(); ++i)
		{
			printf("%d ", solve[i]);
		}

		printf("\n");
	}
	else
	{
		printf("Solution doesn't exists\n");
	}
	
	return 0;
}