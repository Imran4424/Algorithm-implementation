#include <iostream>
#include <vector>
using namespace std;


typedef long long int lli;


lli GCD(lli a, lli b)
{
        if(a == 0 || b == 0)
        {
                return 0;
        }

        if(a < b)
        {
                swap(a, b);
        }

        if(a % b == 0)
        {
                return b;
        }
        else
        {
                return GCD(b, a % b);
        }
}

lli gcdDriver(vector<int> numbers)
{
	int a = numbers[0];
	int b = numbers[1];

	int result = GCD(a, b);

	numbers.erase(numbers.begin(), numbers.begin() + 1);

	while(!numbers.empty())
	{
		int x = numbers.front();

		numbers.erase(0);

		result = GCD(result, x);
	}

	return result;
}


int main(int argc, char const *argv[])
{
	vector <int> numbers;

	cout << "enter the int numbers" << endl;
	int num;

	while(cin >> num)
	{
		if (0 == num)
		{
			break;
		}

		numbers.push_back(num);
	}



	return 0;
}