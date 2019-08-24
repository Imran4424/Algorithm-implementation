#include <iostream>
using namespace std;

bool IsUgly(int num)
{

}

void GetNthUgly(int n)
{
	int i = 1, count = 1;

	cout << i << " ";

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