/*
Name: Justin Chen, Name, Name
Class: csc-2710
Date: 3/4/2022
Program 2 creating a bunch of sorting algo.


Things to work on
1. get the counters for mergesort,heapsort, and quicksort
2. get the times set for the sorts.
3. fix selection sort.
*/

#include<iostream>
using namespace std;
int p = 10; //global to show first 10 val in array
 
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void displayArray(int arr[], int size)//function for displaying the array
{
 int i;
 for(i = 0; i<size; i++)
   cout<<arr[i]<<" ";

 cout << endl;
}
//end if displaying function 

void selectionSort(int arr[], int size, int cnt) //not working right now
{
   int i, j, imin;
   for(i = 0; i<size-1; i++) 
   {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(arr[j] < arr[imin])
         {
            cnt++;
            imin = j;
         }//placing in correct position
         swap(arr[i], arr[imin]);
   }
    cout << "the array is now sorted" << endl;
    cout << "this is the amount of swaps used: " << cnt << endl;
    displayArray(arr, p);
}

void exchangeSort(int arr[], int n, int cnt)
{
   int temp;
   for(int i=0; i < n-1; i++)
   {
      for(int j=i+1; j < n; j++)
      { 
        if(arr[j] < arr[i])
        {
            cnt++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
      }
   }
    cout << "the array is now sorted" << endl;
    cout << "this is the amount of swaps used: " << cnt << endl;
    displayArray(arr, p);
}

void bubbleSort(int arr[], int n, int cnt) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++)
    {    
        cnt++; 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]);
    }         
    cout << "the array is now sorted" << endl;
    cout << "this is the amount of compares used: " << cnt << endl;
    displayArray(arr, p);
} 

void insertionSort(int arr[], int n, int cnt)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        cnt++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            cnt++;
        }
        arr[j + 1] = key;
    }
    
    cout << "the array is now sorted" << endl;
    cout << "this is the amount of compares used: " << cnt << endl;
    displayArray(arr, p);
}


void merge(int *arr, int low, int high, int mid)//function for sorting each part of the array
{
 int i, j, k , c[100];
 i =low;
 k = low;
 j = mid + 1;
 while(i <= mid && j <= high)
 {
   if(arr[i]<arr[j])
   {
     c[k] = arr[i];
     k++;
     i++;
   }
   else
   {
     c[k] = arr[j];
     k++;
     j++;
   }
 }
 while(i <= mid)
 { 
  c[k] = arr[i];
  k++;
  i++;
 }
 while(j <= high)
 {
  c[k] = arr[j]; 
  k++;
  j++;
 }
 for(i = low; i<k; i++)
 {
  arr[i] = c[i];
 }
}
//end of merge sort function

void mergeSort(int *arr, int low, int high)//fuction for dividing the array into parts
//this function calls in the sort function after it has been divided 
{
 int mid;
 if(low<high)
 {
  //divides the array at mid and sort independently using merge sort
  mid = (low+high)/2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  //merge or conquer sorted arrays
  merge(arr, low, high, mid);
 }
}
//end of dividing function

int partition(int arr[], int low, int high)//partition function
{
 int pivot = arr[high];
 int i = (low - 1);
 
 for(int j = low; j <= high- 1; j++)
 {
   if(arr[j] <= pivot)//if current element is smaller than pivot, increment low element
   //swap elements at i and j
   {
     i++;//increments index of smaller element
     swap(&arr[i], &arr[j]);
   }
 }
 swap(&arr[i + 1], &arr[high]);
 return(i + 1);
}
//end of partition function

void quickSort(int arr[], int low, int high)//quick sort function
{
 if(low<high)
 {
  //partition the array
  int pivot = partition(arr, low, high);
  
  //sort the sub arrays independently
  quickSort(arr, low, pivot - 1);
  quickSort(arr, pivot + 1, high);
 }
}
//end of quick sort function



void heapify(int arr[], int n, int root)//function to heapify the tree
{
 int largest = root; //root is the largest element
 int l = 2*root + 1; //left = 2*root + 1
 int r = 2*root + 2; //right = 2*root + 2

 if(l < n && arr[l] > arr[largest])//if left child is larger than root
  largest = l;
 
 if(r < n && arr[r] > arr[largest])//If right child is larger than largest
  largest = r;

 if(largest != root)//if largest is not root
 {
  swap(arr[root], arr[largest]);//swap root and largest
 
  heapify(arr, n, largest);//Heapify sub-tree using recursion
 }
}
//End of heapify function

void heapSort(int arr[], int n)//function implimenting Heap sort
{
 for(int i = n/2 -1; i >= 0; i--)//build heap
 heapify(arr, n, i);
 
 for(int i = n-1; i >= 0; i--)//extracting elements from heap one by one
 {
   swap(arr[0], arr[i]);
 
   heapify(arr, i, 0);
 }
}
//End of Heap sort function

int main()
{
    int n = 100;
    int array1[n]; // almost sorted
    int array2[n]; // randomly sorted
    int array3[n]; // revere sorted
    int array4[n]; // duplications

    for(int i=0; i< n; i++)//puting values in array1
    {
        array1[i] = i+1;
    }

    for(int i=0; i<n; i++) //putting values in array2
    {
        array2[i] = rand()%1000;
    }

    int z= 0;
    for(int i=100; i>0; i--) //putting values in array3
    {
        array3[z] = i;
        z++;
    }
    
    for(int i=0; i<n; i++) //putting values in array4
    {
        array4[i] = rand()%15;
    }
    
    int x;
    cout << "the sorting algorthims are:" << endl;
    cout << "1 for selection sort" << endl;
    cout << "2 for exchange sort" << endl;
    cout << "3 for bubble sort" << endl;
    cout << "4 for insertion sort" << endl;
    cout << "5 for merge sort" << endl;
    cout << "6 for quicksort" << endl;
    cout << "7 for heapsort" << endl;
    cout << "which sort do you want: ";
    cin >> x;

    int cnt = 0; //counter for array
    
    if(x==1)// selection sort
    {
        cout << "Almost sorted array:" << endl;
        selectionSort(array1, n, cnt);
        cout << "Randomly sorted array:" << endl;
        selectionSort(array2, n, cnt);
        cout << "Reverse sorted array:" << endl;
        selectionSort(array3, n, cnt);
        cout << "Duplicate sorted array:" << endl;
        selectionSort(array4, n, cnt);
    }
    else if(x == 2)// exchange sort
    {
        cout << "Almost sorted array:" << endl;
        exchangeSort(array1, n, cnt);
        cout << "Randomly sorted array:" << endl;
        exchangeSort(array2, n, cnt);
        cout << "Reverse sorted array:" << endl;
        exchangeSort(array3, n, cnt);
        cout << "Duplicate sorted array:" << endl;
        exchangeSort(array4, n, cnt);
    }
    else if(x == 3) // bubble sort
    {
        cout << "Almost sorted array:" << endl;
        bubbleSort(array1, n, cnt);
        cout << "Randomly sorted array:" << endl;
        bubbleSort(array2, n, cnt);
        cout << "Reverse sorted array:" << endl;
        bubbleSort(array3, n, cnt);
        cout << "Duplicate sorted array:" << endl;
        bubbleSort(array4, n, cnt);
    }
    else if(x == 4) // insertion sort
    {
        cout << "Almost sorted array:" << endl;
        insertionSort(array1, n, cnt);
        cout << "Randomly sorted array:" << endl;
        insertionSort(array2, n, cnt);
        cout << "Reverse sorted array:" << endl;
        insertionSort(array3, n, cnt);
        cout << "Duplicate sorted array:" << endl;
        insertionSort(array4, n, cnt);
    }
    else if(x == 5) // mergesort
    {
        cout << "Almost sorted array:" << endl;
        mergeSort(array1, 0, n-1);
        cout << "Randomly sorted array:" << endl;
        mergeSort(array2, 0, n-1);
        cout << "Reverse sorted array:" << endl;
        mergeSort(array3, 0, n-1);
        cout << "Duplicate sorted array:" << endl;
        mergeSort(array4, 0, n-1);
    }
    else if(x == 6) //quicksort
    {
        cout << "Almost sorted array:" << endl;
        quickSort(array1, 0, n-1);
        cout << "Randomly sorted array:" << endl;
        quickSort(array2, 0, n-1);
        cout << "Reverse sorted array:" << endl;
        quickSort(array3, 0, n-1);
        cout << "Duplicate sorted array:" << endl;
        quickSort(array4, 0, n-1);
    }
    else if(x == 7) //heapsort
    {
        cout << "Almost sorted array:" << endl;
        heapSort(array1, n);
        cout << "Randomly sorted array:" << endl;
        heapSort(array2,n);
        cout << "Reverse sorted array:" << endl;
        heapSort(array3, n);
        cout << "Duplicate sorted array:" << endl;
        heapSort(array4, n);
    }
    return 0;
}

