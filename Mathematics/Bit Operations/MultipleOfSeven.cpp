#include <iostream>
using namespace std;

int MultipleOfSeven(int num)
{
	return ((num << 3) - num);
}


int main(int argc, char const *argv[])
{
	int num;

	cin >> num;

	cout << "Multiple of seven of " << num << " is: " << MultipleOfSeven(num) << endl;

	return 0;
}