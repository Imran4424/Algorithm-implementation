#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int lli;

vector <lli> test(10, -1);

int main(int argc, char const *argv[])
{
	for (int i = 0; i < test.size(); ++i)
	{
		cout << test[0] << " ";
	}
	return 0;
}