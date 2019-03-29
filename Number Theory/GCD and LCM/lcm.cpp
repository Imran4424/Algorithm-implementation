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

lli lcmDriver(vector<int> numbers)
{

        int result = numbers[0];

        numbers.erase(numbers.begin());

        while(!numbers.empty())
        {
                int x = numbers.front();

                numbers.erase(numbers.begin());

                result = ((result * x) / GCD(result, x));
        }

        return result;
}


int main(int argc, char const *argv[])
{
        cout << "enter two int number" << endl;

        int a, b;

        while(cin >> a >> b)
        {
                cout << "LCM of entered numbers is: " << LCM(a, b) << endl;

                cout << "enter two int number" << endl;
        }
        
        return 0;
}