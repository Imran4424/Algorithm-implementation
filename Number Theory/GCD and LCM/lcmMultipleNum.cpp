#include <iostream>
#include <vector>
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


int main(int argc, char const *argv[])
{
        vector <int> numbers;

        cout << "enter the int numbers, 0 is the ending number" << endl;

        int num;

        while(cin >> num)
        {
                if (0 == num)
                {
                        break;
                }

                numbers.push_back(num);
        }

        cout << "GCD of entered number is: " << gcdDriver(numbers) << endl;


        return 0;
}