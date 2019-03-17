#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;

	//getline(cin, s);

	cin >> s;

	for(int i = 0; i < s.size(); i++)
	{
		cout << s[i];

		for(int j = 0; j < s.size(); j++)
		{

			if(i == j)
			{
				continue; 
			}

			cout << s[j];

			for(int k = 0; k < s.size(); k++)
			{
				if(i == k || j == k)
				{
					continue;
				}

				cout << s[k];
			}
		}

		cout << endl;
	}


	return 0;
}