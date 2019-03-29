#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

lli gcd(lli a,lli b)
{
        if(a < b)
        {
                swap(a,b);
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

    

    while(cin>>a>>b)
    {
	   cout<<gcd(a,b)<<endl;
    }

    return 0;
}
