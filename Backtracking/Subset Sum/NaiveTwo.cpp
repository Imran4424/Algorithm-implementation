#include <stdio.h>
#include <vector>
using namespace std;

// bool status = false;

vector<int> solve;

bool SubsetSum(int input[], int n, int sum, vector <int> result)
{
	if (0 == sum)
	{
		solve = result;

		return true;
	}

	if(0 == n && sum != 0)
	{
		return false;
	}

	if (input[n-1] > sum)
	{
		return SubsetSum(input, n-1, sum, solve);
	}

	result.push_back(input[n-1]);
	

	if(SubsetSum(input, n-1, sum, result) || SubsetSum(input, n-1, sum - input[n-1], result))
	{
		//solve = result;

		return true;
	}

	return false;
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

	vector <int> result;

	bool status = SubsetSum(input, size, target, result);

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

/*
	not working
*/