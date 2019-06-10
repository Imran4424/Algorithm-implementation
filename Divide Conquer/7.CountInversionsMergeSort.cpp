/*
	By using enhance merge sort
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int Merge(vector <int> &roksana, int left, int mid, int right)
{
	int i, j, k, inversionCount = 0;

	vector <int> auxilary;

	i = left; // i is index for left sub array
	j = mid + 1;  // j is index for right sub array
	// k = left; // k is index for merged sub array

	while((i <= mid) && (j <= right))
	{
		if (roksana[i] <= roksana[j])
		{
			// auxilary[k++] = roksana[i++];
			auxilary.push_back(roksana[i++]);
		}
		else
		{
			// auxilary[k++] = roksana[j++];
			auxilary.push_back(roksana[j++]);


			inversionCount += (mid - i + 1);
		}
	}

	while(i <= mid)
	{
		// auxilary[k++] = roksana[i++];
		auxilary.push_back(roksana[i++]);
	}

	while(j <= right)
	{
		// auxilary[k++] = roksana[j++];
		auxilary.push_back(roksana[j++]);
	}

	/* copying back the merged elements to original array */

	for (i = left; i <= right; ++i)
	{
		roksana[i] = auxilary[i];
	}

	return inversionCount;
}

int MergeSort(vector<int> &roksana, int left, int right)
{
	int mid, inversionCount = 0;

	if (right > left)
	{
		mid = (left + right) / 2;

		inversionCount += MergeSort(roksana, left, mid); // left sub array
		inversionCount += MergeSort(roksana, mid+1, right); // right sub array

		/* merging two parts*/

		inversionCount += Merge(roksana, auxilary, left, mid, right);
	}

	return inversionCount;
}



int main(int argc, char const *argv[])
{
	vector <int> roksana{13, 1, 3, 19, 11, 3, 4, 1, 10, 8}; // 23
	// vector <int> roksana{1, 20, 6, 4, 5}; // 5

	cout << "Number of inversions are: " << MergeSort(roksana, 0, roksana.size() - 1) << endl;

	return 0;
}