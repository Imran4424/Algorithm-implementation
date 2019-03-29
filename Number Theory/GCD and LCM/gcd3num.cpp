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
                return GCD(b, a % b);
        }
}


int main()
{
        lli a, b, c;

        cout << "enter any two intergers" << endl;


        while(cin >> a >> b >> c)
        {
                lli intermediate = gcd(a, b);

                cout << "GCD of entered number are:" << GCD(c, intermediate) << endl;

                cout << "enter any two intergers" << endl;
        }

        return 0;
}
