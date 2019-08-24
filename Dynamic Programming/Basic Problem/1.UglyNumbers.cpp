#include <iostream>
using namespace std;

int MaxDivide(int x, int y)
{
	while(x % y == 0)
	{
		x = x / y; 
	}

	return x;
}

bool IsUgly(int num)
{
	num = MaxDivide(num, 2);
	num = MaxDivide(num, 3);
	num = MaxDivide(num, 5);

	if (1 == num)
	{
		return true;
	}

	return false;
}

void GetNthUgly(int n)
{
	int i = 1, count = 1;

	cout << i++ << " ";

	for (; count < n; ++i)
	{
		if (IsUgly(i))
		{
			cout << i << " ";

			count++;
		}
	}

}

int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	int n;
	cin >> n;

	GetNthUgly(n);



	return 0;
}