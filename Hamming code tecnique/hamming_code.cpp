#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <sstream>
using namespace std;

typedef long long int lli;

bool checking(lli x)
{
    for(lli i=0; i<=15; i++)
    {
        if(pow(2,i) == x)
        {
            return true;
        }
    }

    return false;
}

lli BinToDec(lli n)
{
    lli factor = 1;
    lli total = 0;

    while (n != 0)
    {
        total += (n%10) * factor;
        n /= 10;
        factor *= 2;
    }

    return total;
}

int main()
{
    freopen("in.txt","rt",stdin);

    string data,received;
    cout<<"Data: ";
    cin>>data;
    cout<<endl;

    cout<<"Received: ";
    cin>>received;
    cout<<endl;

    string hamming_code;

    lli k = 0;



    reverse(data.begin(),data.end()); /// here given data string is revered, so i reversed it again for simplicity
    ///  for your case if it is not then don't reverse it



    for(lli i=0; k<data.size(); i++)
    {
        bool flag = checking(i+1);

        if(flag)
        {
            hamming_code.insert(i,1,'*');


        }
        else
        {

            hamming_code.insert(i,1,data[k]);

            k++;
        }
    }

    cout<<hamming_code<<endl;




    for(lli i=1; i<=hamming_code.size(); i *= 2)
    {
        lli parity_bit = 0;


        for(lli j=i; j<=hamming_code.size(); j = j+(2*i))
        {
            lli temp = i;
            lli point = j;

            while(temp--  && point <= hamming_code.size())
            {

                if(hamming_code[point-1] == '1')
                {

                    parity_bit++;


                }


                point++;


            }


        }


        if(parity_bit%2 == 0)
        {
            hamming_code[i-1] = '0';
        }
        else
        {
            hamming_code[i-1] = '1';
        }
    }

    reverse(received.begin(),received.end()); /// here given received string is revered, so i reversed it again for simplicity
    ///  for your case if it is not then don't reverse it

    string position = "00000000000";


    lli pos = 0;

    for(lli i=1; i<=received.size(); i *= 2)
    {
        lli parity_bit = 0;


        for(lli j=i; j<=received.size(); j = j+(2*i))
        {
            lli temp = i;
            lli point = j;

            while(temp--  && point <= received.size())
            {

                if(received[point-1] == '1')
                {
                    parity_bit++;


                }


                point++;


            }


        }


        if(parity_bit%2 == 0)
        {
            position[pos] = '0';
            pos++;


        }
        else
        {
            position[pos] = '1';
            pos++;


        }
    }

    reverse(position.begin(),position.end());

    stringstream ss;
    lli error_position;

    ss<<position;
    ss>>error_position;

    cout<<received<<endl<<hamming_code<<endl;

    cout<<"Error position in binary : "<<error_position<<endl;

    error_position = BinToDec(error_position);

    cout<<"Error position in decimal : "<<error_position<<endl;

    return 0;
}
