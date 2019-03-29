#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "enter the ending range from 1 to n" << endl;

	int num, count;

	cin >> num;

	for (int i = 1; i <= num; ++i)
	{
		bool status = true;

		int inTest = i;

		while(inTest)
		{
			int digit = inTest % 10;

			if (3 == digit)
			{
				status = false;
				break;
			}

			inTest = inTest / 10;
		}

		if (status)
		{
			count++;
		}
	}


	cout << "Number of numbers which doesn't contain 3 in decimal form: " << count << endl;

	return 0;
}