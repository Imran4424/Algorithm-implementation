#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	cout << "enter any number" << endl;
	cout << "enter zero to exit" << endl;

	int count = 0;
	double avg = 0;

	double num;
	cin >> num; 

	while(num)
	{
		count++;

		avg = (((count-1) * avg) + num ) / count;

		cout << "Current average: " << avg << endl;

		cout << "enter any number" << endl;
		cout << "enter zero to exit" << endl;

		cin >> num;
	}

	return 0;
}