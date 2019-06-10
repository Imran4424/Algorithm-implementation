/*
	By using enhance merge sort
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;


int MergeSort(vector<int> roksana, int left, int right)
{
	int mid, inversionCount = 0;

	if (right > left)
	{
		mid = (left + right) / 2;

		inversionCount += MergeSort(roksana, left, mid); // left sub array
		inversionCount += MergeSort(roksana, mid+1, right); // right sub array

		/* merging two parts*/


	}

	return inversionCount;
}

int MergeSortHandler(vector <int> roksana)
{
	vector <int> auxilary(roksana.size());
}

int main(int argc, char const *argv[])
{
	
	return 0;
}