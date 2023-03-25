#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void Swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int A[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        if(A[j]<A[min])
        min=j;
        Swap(&A[min],&A[i]);
    }
}
void merge(int *Array, int left,int mid, int right){
    int Size1=mid-left+1;
    int Size2=right-mid;

    int Array1[Size1];
    int Array2[Size2];

    for(int i=0;i<Size1;i++){
        Array1[i]=Array[left+i];
    }
    for(int i=0;i<Size2;i++){
        Array2[i]=Array[mid+1+i];
    }

    int i=0,j=0,k=left;

    while(i<Size1 && j<Size2){
        if(Array1[i]<Array2[j]){
            Array[k]=Array1[i];
            k++, i++;
        }
        else{
            Array[k]=Array2[j];
            k++, j++;
        }
    }
    while(i<Size1){
        Array[k]=Array1[i];
        k++, i++;
    }
    while(i<Size2){
        Array[k]=Array2[j];
        k++, j++;
    }
}

int MergeSort(int *Array,int left,int right){
    if(left<right){
        int mid=(left+right)/2;

        MergeSort(Array,left,mid);
        MergeSort(Array,mid+1,right);

        merge(Array,left,mid,right);
    }
}
int main()
{
    int k=100000;

    int *a = new int[k];

    freopen("in.txt","r",stdin);
    for(int i=0; i<k; i++)
    {
        cin>>a[i];
    }


    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /*  ..........Change your algorithm...............*/
    selectionSort(a,k);
    /* .......................................  */


    /*.....................Time taken by 1st Algorithm........................*/
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        time_taken1 *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken1 << setprecision(9);
    cout << " sec" << endl;

    /*.....................End of Time taken by 1st Algorithm........................*/

    auto start2 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /*  ..........Change your algorithm...............*/
    MergeSort(a,0,k);
    /* .......................................  */


    /*.....................Time taken by 2nd Algorithm........................*/
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 =chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
        time_taken2 *= 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken2 << setprecision(9);
    cout << " sec" << endl;

    /*.....................End of Time taken by 2nd Algorithm........................*/


    return 0;
}



