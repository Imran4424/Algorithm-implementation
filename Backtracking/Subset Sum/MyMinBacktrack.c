#include <stdio.h>
#include <stdbool.h>

bool secondRoute;
int startIndex;

int partitioning(int ar[], int start, int end)
{

	int pivot = ar[end];

	int pIndex = start;

	for (int i = start; i < end; ++i)
	{
		if (ar[i] <= pivot)
		{
			int temp = ar[i];
			ar[i] = ar[pIndex];
			ar[pIndex] = temp;

			pIndex++;
		}
	}

	int temp = ar[end];
	ar[end] = ar[pIndex];
	ar[pIndex] = temp;


	return pIndex;
}


void quick_sort(int ar[], int start,int end) // end will be size - 1
{
	if (start < end)
	{
		int pIndex = partitioning(ar,start,end);

		quick_sort(ar,start,pIndex-1);
		quick_sort(ar,pIndex+1,end);
	}
}

bool SubSetSolve(int input[], int size, int index, int sum, int target)
{
	sum = sum + input[index];

	if(sum == target)
	{
		return true;
	}

	while(sum > target)
	{

	}

	if(sum == target)
	{
		return true;
	}


}

bool SubsetSum(int input[], int size, int target)
{
	quick_sort(input, 0, size-1);

	int x = 0;

	while(input[x] <= target)
	{
		x++;
	}

	size = x;
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