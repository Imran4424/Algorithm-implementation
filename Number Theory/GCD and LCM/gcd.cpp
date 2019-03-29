#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b)
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
                return gcd(a, a % b);
        }
}

int main()
{
        lli a,b;

        cout << "enter any two intergers" << endl;

        while(cin>>a>>b)
        {
                cout << "GCD of entered numbers is: " << gcd(a,b) << endl;
        }

        return 0;
}
