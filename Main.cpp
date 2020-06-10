#include<iostream>

#include<time.h>

#include<stdio.h>

#include<stdlib.h>

#include<cstring>

#include <vector>

#include <algorithm> 

using namespace std;

#define ArraySize 5000

void merge(int arr[], int l, int m, int r) 

{ 

    int i, j, k; 

    int n1 = m - l + 1; 

	int n2 =  r - m; 
     
    int *L=new int[n1];

	int*R=new int[n2]; 
  
    for (i = 0; i < n1; i++) 

        L[i] = arr[l + i];

    for (j = 0; j < n2; j++) 

        R[j] = arr[m + 1+ j]; 
  
    i = 0; 

    j = 0; 

    k = l; 

    while (i < n1 && j < n2) 

    { 

        if (L[i] <= R[j]) 

        { 

            arr[k] = L[i]; 

            i++; 

        } 

        else

        { 
            arr[k] = R[j]; 

            j++;

        } 

        k++;

    } 
  
    while (i < n1)

    { 
        arr[k] = L[i]; 

        i++;

        k++;

    } 
  
    while (j < n2)

    { 

        arr[k] = R[j]; 

        j++;

        k++;

    } 

} 
 
void mergeSort(int arr[], int l, int r) 

{ 

    if (l < r) 

    { 
       
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 

        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 

    } 

} 

void countSort(int* array, int size) {

    int* output = new int[size + 1];

    int Max = max(array[0], array[size]);

    int* count=new int[Max + 1];     //create count array (max+1 number of elements)

    for (int i = 0; i <= Max; i++)

        count[i] = 0;     //initialize count array to all zero

    for (int i = 1; i <= size; i++)

        count[array[i]]++;     //increase number count in count array.

    for (int i = 1; i <= Max; i++)

        count[i] += count[i - 1];     //find cumulative frequency

    for (int i = size; i >= 1; i--)

	{

        output[count[array[i]]] = array[i];

        count[array[i]] -= 1; //decrease count for same numbers

    }

    for (int i = 1; i <= size; i++) 
	
	{

        array[i] = output[i]; //store output array to main array

    }

}

void swap(int *xp, int *yp)  

{  
    int temp = *xp;  

	*xp = *yp;  

    *yp = temp; 

} 

void selectionSort(int arr[], int n)  

{  
    
	int i, j, min_idx;  
  
     for (i = 0; i < n-1; i++)  

    {  
        min_idx = i;  

        for (j = i+1; j < n; j++)

        if (arr[j] < arr[min_idx])  

            min_idx = j;  
     
        swap(&arr[min_idx], &arr[i]);  

    }  

}  
   
   
void Swap(int* a, int* b)  

{  

    int t = *a;

    *a = *b;

    *b = t;  

}  
  
int partition (int arr[], int low, int high) 

{  

    int pivot = arr[high]; // pivot

    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  

    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)

        {  
            i++; // increment index of smaller element  

            Swap(&arr[i], &arr[j]);  

        }  

    }  

    Swap(&arr[i + 1], &arr[high]);  

    return (i + 1);  

}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  

{  

    if (low < high) 

    {

        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  

        quickSort(arr, pi + 1, high);  

    }  

}  
  
  void insertionSort(int arr[], int n)  

{  
   
	 int i, key, j;  

    for (i = 1; i < n; i++) 

    {  

        key = arr[i];  

        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 

        {  

            arr[j + 1] = arr[j];

            j = j - 1;

        }  

        arr[j + 1] = key;

    }  

}  
  
  void heapify(int arr[], int n, int i) 

{ 

    int largest = i; // Initialize largest as root

    int l = 2*i + 1; // left = 2*i + 1 

    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 

    if (l < n && arr[l] > arr[largest]) 

      largest = l; 
  
    // If right child is larger than largest so far 

    if (r < n && arr[r] > arr[largest]) 

        largest = r; 
  
    // If largest is not root 

    if (largest != i) 

    { 

        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 

        heapify(arr, n, largest); 

    }

} 
  
// main function to do heap sort 

void heapSort(int arr[], int n) 

{ 
    // Build heap (rearrange array) 

	for (int i = n / 2 - 1; i >= 0; i--) 

        heapify(arr, n, i); 
  
    // One by one extract an element from heap

    for (int i=n-1; i>=0; i--) 

    { 
        // Move current root to end 

        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 

        heapify(arr, i, 0); 

	}

} 


void main()

{

int A[ArraySize];


srand(time(NULL));

for(int i=0;i<ArraySize;i++)

{

float x=rand()%100+1;

A[i]=x;


}


for (int i = 0; i < ArraySize; i++)
    {
        float x = rand() % 100 + (float)(rand() % 100) / 100.0;

        A[i];
    }

cout<<endl<<endl;

clock_t begin = clock();

mergeSort(A,0,ArraySize-1);

clock_t end = clock();

	int x;

	int y;

	cout<<"______________________________________________________"<<endl;

	cout<<"Plz choose your way 1 or 2 (1 for int & 2 for float) :"<<endl;

	cin>>y;

	if(y==1){

		cout<<"\t"<<"Int menu :"<<endl;

		cout<<".........................."<<endl;

	cout<<"Plz enter your choice : "<<endl;

	cout<<endl;

	cout<<"__________________________________"<<endl;

	cout<<"Enter num 1 for mergeSort : "<<endl<<endl; 

	cout<<"Enter num 2 for countSort : "<<endl<<endl; 

	cout<<"Enter num 3 for selectionSort : "<<endl<<endl; 

	cout<<"Enter num 4 for quickSort : "<<endl<<endl; 

	cout<<"Enter num 5 for insertionSort : "<<endl<<endl; 

	cout<<"Enter num 6 for heapSort : "<<endl<<endl; 


	cin>>x;

	while(x>=1&&x<=6){

		if(x==1){

			clock_t Tegin=clock();

			mergeSort( A,0,ArraySize-1);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;

		}

		if(x==2){

			clock_t begin=clock();

			countSort(A,ArraySize-1);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;

		}

		if(x==3){

			clock_t begin=clock();

			selectionSort(A,ArraySize);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;
		}

		if(x==4){

			
			clock_t begin=clock();

			quickSort(A,0,ArraySize-1);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;


		}

		if(x==5){

			
			clock_t begin=clock();

			insertionSort(A,ArraySize);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;
		}

		if(x==6){

			
			clock_t begin=clock();

			heapSort(A,ArraySize);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;

		}

		
		cin>>x;

	}

	}
	else if(y==2){

				cout<<"\t"<<"Float menu :"<<endl;

				cout<<".................."<<endl;

	cout<<"Plz enter your choice : "<<endl;


	cout<<endl;

	cout<<"__________________________________"<<endl;

	cout<<"Enter num 1 for mergeSort : "<<endl<<endl; 

	cout<<"Enter num 2 for selectionSort : "<<endl<<endl; 

	cout<<"Enter num 3 for quickSort : "<<endl<<endl; 

	cout<<"Enter num 4 for insertionSort : "<<endl<<endl; 

	cout<<"Enter num 5 for heapSort : "<<endl<<endl; 


	cin>>x;


	
	while(x>=1&&x<=5){

		if(x==1){

			clock_t begin=clock();

			mergeSort( A,0,ArraySize-1);

			clock_t end =clock();

			float answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;

		
		}


		if(x==2){

			clock_t begin=clock();

			selectionSort(A,ArraySize);

			clock_t end =clock();

			int answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;
		}

		if(x==3){

			
			clock_t begin=clock();

			quickSort(A,0,ArraySize-1);

			clock_t end =clock();

			float answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;


		}

		if(x==4){

			
			clock_t begin=clock();

			insertionSort(A,ArraySize);

			clock_t end =clock();

			float answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;
		}

		if(x==5){

			
			clock_t begin=clock();

			heapSort(A,ArraySize);

			clock_t end =clock();

			float answer = end - begin;

			float SAnswer = (float)answer/CLOCKS_PER_SEC;

			cout<< "The time is :";

			cout<<SAnswer<<endl;

		}

		
		cin>>x;

	}

	}

	else cout<<"error";

	system("pause");

}