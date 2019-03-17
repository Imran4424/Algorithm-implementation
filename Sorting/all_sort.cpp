#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
#include <cstdio>
using namespace std;

struct timeval stop, start;

void bubble_sort(int a[],int n)
{
    gettimeofday(&start, NULL);

    int i,j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j+1],a[j]);
            }
        }
    }

    gettimeofday(&stop, NULL);
    printf("took %lu\n", stop.tv_usec - start.tv_usec);
}

void insertion_sort(int a[],int n)
{
    gettimeofday(&start, NULL);

    int i,j;

    for(i=1; i<n; i++)
    {
        for(j=i; j>0; j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
            else
            {
                break;
            }
        }
    }

    gettimeofday(&stop, NULL);
    printf("took %lu\n", stop.tv_usec - start.tv_usec);

}

void selection_sort(int a[],int n)
{
    gettimeofday(&start, NULL);

    int i,j,min;

    for(i=0; i<n-1; i++)
    {
        min = i;

        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }

        swap(a[i],a[min]);
    }

    gettimeofday(&stop, NULL);
    printf("took %lu\n", stop.tv_usec - start.tv_usec);
}


void merge(int left[],int ln,int right[],int rn,int a[])
{
    int i=0,k=0,j=0;

    while(i<ln && j<rn)
    {
        if(left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<ln)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j<rn)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int n)
{


    if(n>1)
    {
        int mid = n/2;

        int left[mid];
        int right[n-mid];
        int i;

        for(i=0; i<mid; i++)
        {
            left[i] = a[i];
        }

        for(i=mid; i<n; i++)
        {
            right[i-mid] = a[i];
        }

        merge_sort(left,mid);
        merge_sort(right,(n-mid));

        merge(left,mid,right,(n-mid),a);
    }

}

int partition(int a[],int start,int endd)
{
    int pivot = a[endd];
    int i,pin;

    pin = start;

    /*

    Here,look at "i = start" statement. If we change it to "i = start+1" then,

    we get get a less number of pin if the first element of the array is less than pivot

    look at the for loop and if block carefully
    */

    for(i=start; i<endd; i++)
    {
        if(a[i] <= pivot)
        {
            swap(a[i],a[pin]);

            pin++;
        }

    }
    swap(a[pin],a[endd]);

    return pin;
}

void quick_sort(int a[],int start,int endd)
{

    if(start<endd)
    {
        int hook = partition(a,start,endd);

        quick_sort(a,start,hook-1);
        quick_sort(a,hook+1,endd);
    }
}


int main()
{
    int n,i;

    cout<<"Input the array size"<<endl;
    cin>>n;

    int ab[n];

    for(i=0; i<n; i++)
    {
        ab[i] = rand()%100+1;
    }


    bubble_sort(ab,n-1);
    insertion_sort(ab,n);
    selection_sort(ab,n);

    gettimeofday(&start, NULL);
    merge_sort(ab,n);
    gettimeofday(&stop, NULL);
    printf("took %lu\n", stop.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    quick_sort(ab,0,n-1);
    gettimeofday(&stop, NULL);
    printf("took %lu\n", stop.tv_usec - start.tv_usec);


    /*
    for(i=0; i<n; i++)
    {
        cout<<ab[i]<<" ";
    }

    cout<<enddl; */

    return 0;

}
