/*
	By using enhance merge sort
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int Merge(vector <int> roksana, vector <int> auxilary, int left, int mid, int right)
{
	int i, j, k, inversionCount = 0;

	
}

int MergeSort(vector<int> roksana, vector <int> auxilary, int left, int right)
{
	int mid, inversionCount = 0;

	if (right > left)
	{
		mid = (left + right) / 2;

		inversionCount += MergeSort(roksana, auxilary, left, mid); // left sub array
		inversionCount += MergeSort(roksana, auxilary, mid+1, right); // right sub array

		/* merging two parts*/


	}

	return inversionCount;
}

int MergeSortHandler(vector <int> roksana)
{
	vector <int> auxilary(roksana.size());

	return MergeSort(roksana, auxilary, 0, roksana.size()-1);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}