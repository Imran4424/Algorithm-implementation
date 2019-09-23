#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

// simple implementation of euclid rule

lli GCD(lli a, lli b)
{
        if (0 == b)
        {
                return a;
        }

        return GCD(b, a % b); // this one take one more call if a <  b to swap

}

int main()
{
        lli a, b;

        cout << "enter any two intergers" << endl;

        while(cin >> a >> b)
        {
                cout << "GCD of entered numbers is: " << GCD(a,b) << endl;
                
                cout << "enter any two intergers" << endl;
        }

        return 0;
}
