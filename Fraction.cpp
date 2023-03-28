
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct
   {
    int value;
    int weight;
    float d;
   } Item;


void input(Item items[],int sizeOfItems)
{
   cout << "Enter total "<< sizeOfItems <<" item's values and weight" <<
   endl;

   for(int i = 0; i < sizeOfItems; i++)
    {
      cout << "Enter "<< i+1 << " Value ";
      cin >> items[i].value;

      cout << "Enter "<< i+1 << " Weight ";
      cin >> items[i].weight;
    }
}


void display(Item items[], int sizeOfItems)
{
   int i;
   cout << "values: ";

   for(i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].value << "\t";
   }

   cout << endl << "weight: ";

   for (i = 0; i < sizeOfItems; i++)
   {
      cout << items[i].weight << "\t";
   }
   cout << endl;
}


bool compare(Item i1, Item i2)
{
   return (i1.d > i2.d);
}


float knapsack(Item items[], int sizeOfItems, int Weight)
{
   int i, j;
   float totalValue = 0, totalWeight = 0;

   for (i = 0; i < sizeOfItems; i++)
   {
      items[i].d = (float)items[i].value / items[i].weight;
   }

   sort(items, items+sizeOfItems, compare);

   for(i=0; i<sizeOfItems; i++)

    {
      if(totalWeight + items[i].weight<= Weight)

       {
         totalValue += items[i].value ;
         totalWeight += items[i].weight;
       }

    else
       {
         int wt = Weight-totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
       }
    }

   cout << "Total weight: " << totalWeight <<endl;
   return totalValue;
}


int main()
 {
   int Weight;
   Item items[4];
   input(items, 4);
   cout << "Entered data \n";
   display(items,4);
   cout<< "Enter Knapsack weight \n";
   cin >> Weight;
   float maxValue = knapsack(items, 4, Weight);
   cout << "Max value for "<< Weight <<" weight is "<< maxValue;
}
