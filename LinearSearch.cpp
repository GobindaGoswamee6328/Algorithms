#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int printData(int *p, int n){
for(int i=0;i<n;i++){
        cout<<p[i]<<endl;
    }
}

int linearSearch(int *m, int n, int item){
    for(int i=0;i<n;i++){
        if(m[i]==item){
            return i;
        }
    }
    return -1;
}

int BinerySearch(int *array,int low,int high,int x)
{
    while(low<=high)
    {
        int  mid=low+(high-low)/2;
        if(array[mid]==x)
        {
           return mid;
        }else if(array[mid]<x)
        {
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

void BubbleSort(int *array,int size)
{
    for(int i=0;i<size;i++){
        int swapflag=0;
        for(int j=0; j<size-i-1; j++)
        {
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
                swapflag=1;
            }
        }
        if(!swapflag)
            break;

    }
}
void display(int *array,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}


int main(){

    int n=1000;

    int *a= new int[n];
    ifstream fin("1000.txt");

    for(int i=0;i<n;i++){
        fin>>a[i];
    }

    //printData(a,n);
    BubbleSort(a,1000);
    cout<<" bubble sort:"<<endl;
    display(a,1000);

    int item = 256;



    /*///////////////////////////*/

    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /*  ..........Change your algorithm...............*/

    int index = linearSearch(a,n,item);

    /*.....................Time taken by 1st Algorithm........................*/

    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        time_taken1 = time_taken1*1e-9;

    cout << "Data Size "<<n<< " Time taken by program is : " << fixed
         << time_taken1 << setprecision(20);
    cout << "sec" << endl;


    if(index==-1){
        cout<<"Not Found"<<endl;
    }else{
        cout<<item<<" Found in index="<<index<<endl;
    }
    auto start2 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /*  ..........Change your algorithm...............*/

    int result1=BinerySearch(a,0,1000-1,256);
    /*.....................Time taken by 1st Algorithm........................*/

    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 =chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
        time_taken2 = time_taken2*1e-9;

    cout << "Data Size "<<n<< " Time taken by program is : " << fixed
         << time_taken2 << setprecision(20);
    cout << "sec" << endl;

    //int result1=BinerySearch(a,0,1000-1,256);
    cout<<"Number at position:"<<result1<<endl;



return 0;
}

