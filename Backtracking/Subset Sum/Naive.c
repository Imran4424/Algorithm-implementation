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

	if (/* condition */)
	{
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int size, target;

	scanf("%d %d", &size, &target)

	int input[size];

	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &input[i]);
	}

	bool status = SubsetSum(input, size, target);
	
	return 0;
}