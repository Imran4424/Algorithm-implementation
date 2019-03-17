#include <iostream>
using namespace std;

void Permutation(string s, int start, int stop)
{
	if (start == stop)
	{
		cout << s << endl;
	}
	else
	{
		for (int i = start; i <= stop; ++i)
		{
			swap(s[start], s[i]);

			Permutation(s, start+1, stop);

			swap(s[start], s[i]); // backtrack
		}
	}
}

int main(int argc, char const *argv[])
{
	string s;

	//getline(cin, s);

	cin >> s;

	
	Permutation(s, 0, s.size());

	return 0;
}