#include <iostream>
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

lli LCM(lli a, lli b)
{
        return ((a * b) / GCD(a, b));
}


int main(int argc, char const *argv[])
{
        
        return 0;
}