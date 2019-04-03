#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(vector<int> ar)
{
	for (int i = 0; i < ar.size(); ++i)
	{
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	cout << "enter the size of the array" << endl;

	int n;
	cin >> n;

	vector <int> numbers(n);

	for (int i = 0; i < numbers.size(); ++i)
	{
		int temp = rand() % 100;

		temp = (temp + i - 50);

		if (temp < 0)
		{
			temp = -temp;
		}

		numbers.push_back(temp);
	}

	int position = LinearSearch(numbers);

	return 0;
}