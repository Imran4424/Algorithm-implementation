#include <stdio.h>
#include <stdbool.h>

bool SubsetSum(int input[], int n, int sum)
{
	if (0 == sum)
	{
		return true;
	}

	if(0 == n && sum != 0)
	{
		return false;
	}

	if (input[n-1] > sum)
	{
		return SubsetSum(input, n-1, sum);
	}

	return (SubsetSum(input, n-1, sum) || SubsetSum(input, n-1, sum - input[n-1]));
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

	bool status = SubsetSum(input, size, target);

	if(status)
	{
		printf("Solution exists\n");
	}
	else
	{
		printf("Solution doesn't exists\n");
	}
	
	return 0;
}