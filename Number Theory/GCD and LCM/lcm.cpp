#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int lli;

lli GCD(lli a,lli b)
{
    if(a<b)
    {
        swap(a,b);
    }

    if(a%b == 0)
    {
        return b;
    }
    else
    {
        return GCD(a,a%b);
    }
}

lli LCM(lli a,lli b,lli c,lli g)
{
    lli l = ((a*b*c)/pow(g,2));

    return l;
}

int main()
{
    lli a,b,c;

    while(cin>>a>>b>>c)
    {
        lli temp = GCD(a,b);
        ///cout<<temp<<endl;
        lli g = (c,temp);
        ///cout<<g<<endl;

        cout<<g<<" "<<LCM(a,b,c,g)<<endl;
    }

    return 0;
}
