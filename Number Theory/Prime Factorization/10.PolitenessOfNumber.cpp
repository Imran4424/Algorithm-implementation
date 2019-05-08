#include <iostream>
using namespace std;

int Politeness(int num)
{
	int politeCount = 0;

	

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