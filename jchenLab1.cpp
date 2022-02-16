/*
justin Chen
DR. Williams
CSC 2710
1/31/2022
Location: csc2710/Lab1/jchenLab1.cpp
Implementation of basic algorithim its the first coding assignment
its to help get back into the flow of coding 
and getting to use different algorithims
*/

#include <iostream>
using namespace std;

/*
   seqsearch-- searches through the array to find a the vlaue
   n is the amount of elements in the array
   array is well the array
   x is the number you are trying to find
*/ 
void seqsearch(int n, int array[], int x)
{
   int loc= 0;
   int i = 0;
   int comp = 0;
   while ( loc == 0 && i < n)
   {
      comp++;
      if ( array[i] == x)
      {
         loc= i+1;
      }
      else
      {
         i++;
      }
   }
   if( loc != 0)
   {
      cout << "Number found in Location: " << loc;
      cout << endl;
      cout << comp << " Compares were made" << endl;
   }
   else
   {
      cout << "Number was not found "<< endl;
      cout << comp << " Compares were made" << endl;
   }
}       

/*
   exchangesort-- sorts the array from least to greatest value
   n is amount in the array
   array is the array
*/

void exchangesort(int n, int array[])
{
   int temp;
   for(int i=0; i < n-1; i++)
   {
      for(int j=i+1; j < n; j++)
      {
         if(array[j] < array[i])
         {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
         }
      }
   }
}

/*
   binsearch-- binary search where cut array in half then search either upper or
   lower depending of val needed to be found
   n = the amount in array
   array is array
   x is the value needed to find
*/

void binsearch(int n, int array[], int x)
{
   int loc, low, high, mid;
   low = 0;
   high = n;
   loc = 0;
   int comp = 0;
   while (low <= high && loc == 0)
   {
      mid = ((low+high)/2);
      comp++;
      if(x == array[mid])
      {
         loc = mid+1;
      }
      else if (x < array[mid])
      {
         high = mid -1;
      }
      else
      {
         low = mid+1;
      }
   }
   if (loc != 0)
   {
      cout << "Number was found at: " << loc << endl;
      cout << comp << " Compares were made" << endl;
   }
   else
   {
      cout << "Number was not found " << endl;
      cout << comp << " Compares were made" << endl;
   }
}

/*
   fib 1 is the recursive version where the function calles itself
   n is the fib number the user wants to see
   has a counter to count the amount of times 2 amounts have been added 
   together but might be wrong

*/

int fib(int n, int& comp)
{
   if (n <= 1)
   {
      return n;
   }
   else
   {
    comp++; 
    return fib(n-1, comp) + fib(n-2, comp);
   }
}
/*
    fib 2 is the fibanatchy the iterative approach
    has a counter to count the amount of times 2 values were
    added together
*/
int fib2(int n, int& comp)
{
   int i;
   int f[n];
   
   f[0] = 0;
   if (n > 0)
   {
      f[1]=1;
      for (i =2; i<=n; i++)
      {
         comp++;
         f[i] = f[i-1] + f[i-2];
      }
   }
   return f[n];
} 

/*
the main function doing all the functions
*/
int main()
{

   int sz;// used to get the size of the array
   cout << "Enter the size of the array: ";
   cin >> sz;
   int comp = 0;// counter amount for fib1
   int array[sz];// the array being used
   int comp2 = 0;// counter for fib 2
   for(int i=0; i< sz; i++)//fill the array with random numbers
   {
      array[i]= rand()%100;
   }
  
   int x; //number user is trying to find in array
   cout << "We are using the sequential search what number do you want to find: ";
   cin >> x;
   cout << endl;
   seqsearch(sz, array, x);   //seq search being called
   exchangesort(sz, array);   // array gets sorted

   cout << "the Array has been sorted" << endl;

   cout << "We are using binary search, What number do you want to find: ";
   cin >> x;
   cout << endl;
   binsearch(sz, array, x);// binary search called
   
   //Fib getting called
   cout << "We are using the recursive fib function, What nth term do you want to find: ";
   cin >> x;
   cout << endl;
   cout << "the " << x << " term in fib is: " << fib(x, comp) << endl;
   cout << comp << " Amount of times 2 values were added" << endl;
 
   
   //fib 2 getting called  
   cout << "We are using the iterative fib function, What nth term do you want to find: ";
   cin >> x;
   cout << endl;
   cout << "the " << x << " term in the fib is: " << fib2(x, comp2) << endl;
   cout << comp2 << " Amount of times 2 values were added" << endl;
 
   return 0;
}
