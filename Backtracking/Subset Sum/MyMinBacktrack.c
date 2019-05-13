#include <stdio.h>
#include <stdbool.h>


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