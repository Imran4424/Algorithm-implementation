#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SubSetSum(vector<int> input, int target)
{
	sort(input.begin(), input.end());

	int i=0;

	while(input[i] <= target)
	{
		i++;
	}

	input.resize(i);

}

int main(int argc, char const *argv[])
{
	vector <int> input;

	int size, target;
	cin >> size >> target;

	for(int i=0; i< size; ++i)
	{
		int temp;
		cin >> temp;

		input.push_back(temp);
	}




	return 0;
}