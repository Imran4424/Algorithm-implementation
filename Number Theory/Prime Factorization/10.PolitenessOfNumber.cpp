#include <iostream>
using namespace std;

int Politeness(int num)
{
	int politeCount = 0;

	for(int i=1; i <= (num/2); i++)
	{
		int currentSum = 0;

		for(int j=i; j<= (num/2)+1; j++)
		{
			currentSum += j;

			if (currentSum == num)
			{
				politeCount++;
				break;
			}
			else if(currentSum > num)
			{
				break;
			}

		}
	}

	return politeCount;
}



int main(int argc, char const *argv[])
{
	int num;

	cout << "enter any positive integer" << endl;

	while(cin >> num)
	{
		cout << "Politeness of " << num << " is: " << Politeness(num) << endl;
		
		cout << "enter any positive integer" << endl;
	}

	return 0;
}