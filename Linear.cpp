#include<bits/stdc++.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void generate_data(int n)
{
    int *m=new int[n];
    for(int i=0;i<n;i++)
    {
        //int a=rand();
        m[i]=rand();
        //cout<<a<< " "<<a%100<<endl;
        //cout<<a%100+1<<" ";
    }
}

int LinearSearch(int *array,int n,int x)
{
    for(int i=0;i<n;i++)
        if(array[i]==x)
    {
        return i;
    }
    return -1;
}

void printData(int *p,int n)
{
    ofstream fout("100.txt");
    for(int i=0;i<n;i++)
    {
        fout<<p[i]<<" ";
    }
}


int main()
{

    int n=100;
   srand(time(0));
//   int *a=generate_data(n);
   int *a=new int[n];
   ifstream fin("1000.txt");

   for(int i=0;i<n;i++)
   {
       fin>>a[i];
   }
   //printData(a,n);
   int item=2500;

   int index=LinearSearch(a,n,item);
   if(index==-1)
   {
       cout<<"not fount"<<endl;
   }
   else{
    cout<<item<<"found in index:"<<index<<endl;
   }
   /* int *A=new int[100];
    srand(time(0));

    //freopen("100-int.txt","w",stdout);


    //srand(time(0));
     freopen("100-int.txt","r",stdin);
    int a[100];
    for(int i=0;i<100;i++)
    {
        cin>>a[i];

    }

    for(int i=0;i<100;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;


    /*cout<<"random number :"<<endl;

    for(int i=0;i<100;i++)
    {
        //int a=rand();
        A[i]=rand()%50;
        //cout<<a<< " "<<a%100<<endl;
        //cout<<a%100+1<<" ";
    }*/
   // display(A,100);
   //display(A,100);
    //BubbleSort(A,100);
    //cout<<"random number after bubble sort:"<<endl;
   // display(A,100);
    //int result2=LinearSearch(A,100-1,50);
    //cout<<"Number at position:"<<result2<<endl;
   /* linearSearch(A,50);

    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /*  ..........Change your algorithm...............*/
    //int *m = bubbleSort(A,n);
    /* .......................................  */
  // LinearSearch(A,50);

    /*.....................Time taken by 1st Algorithm........................*/
    /*auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        time_taken1 *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken1 << setprecision(9);
    cout << " sec" << endl;*/


    return 0;
}
