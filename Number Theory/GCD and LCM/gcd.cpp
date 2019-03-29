#include <iostream>
#include <algorithm>
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
                return GCD(a, a % b);
        }
}

int main()
{
        lli a,b;

        cout << "enter any two intergers" << endl;

        while(cin >> a >> b)
        {
                cout << "GCD of entered numbers is: " << GCD(a,b) << endl;
                
                cout << "enter any two intergers" << endl;
        }

        return 0;
}
