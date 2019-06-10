#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int CountInversions(vector <int> arr)
{
	int inversionCount = 0;

	for (int i = 0; i < arr.size() - 1; ++i)
	{
		for (int j = i+1; j < arr.size(); ++j)
		{
			if (arr[i] > arr[j])
			{
				inversionCount++;
			}
		}
	}

	return inversionCount;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}