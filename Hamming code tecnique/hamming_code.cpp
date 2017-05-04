#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
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

int main()
{
    ///freopen("in.txt","rt",stdin);

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

    lli position;

    for(lli i=0; i<received.size(); i++)
    {
        if(hamming_code[i] != received[i])
        {
            position = i+1;

            break;
        }
    }

    ///need to edit the implementation

    cout<<"Received code: "<<received<<endl<<"Hamming  code: "<<hamming_code<<endl;

    cout<<"Error position: "<<position<<endl;

    return 0;
}
