/**
	THIS PROGRAM USED DIFERENT SORTING ALGORITHMS(INSERTION,MERGE,QUICK,HEAP) TO
	SORT N RANDOMLY GENERATED INTEGERS AND THEN ANALYZE THEIR RUN TIME.
	
	Preared by:
				ARVY OLARCOS LLAVE
				ALLIANA ERMINO
				ELLA MAE POCHE   
	DESIGN AND ANALYSIS ALGORITHM, BSCS-2A
**/
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/**function print is used to print the elements of array
  *function sorting is used to call all the sorting algorithms
   and compute the Running Time of a specific Sorting Algorithm
  *function copy is used to copy the original order of the array
   from tempArr[] back to array
 **/
void print(int array[], int N, ofstream& myfile);
void sorting(int array[],int tempArr[], int N, ofstream& myfile);
void copy(int array[], int tempArr[], int N);

//FUNCTION FOR INSERTION SORT ALGORITHM
void insertion(int array[],int N);
//FUNCTIONS FOR MERGE SORT ALGORITHM
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
//FUNCTION FOR QUICK SORT ALGORITHM
void quicksort(int array[],int first,int last);
//FUNCTIONS FOR HEAP SORT ALGORITHM
void swap(int *a, int *b);
void heapify(int array[], int n, int i);
void heapsort(int array[],int N);

/////////////////////////////////////////////////
/////////////////MAIN FUNCTION///////////////////
/////////////////////////////////////////////////
int main(){
	
	int N;					//VARIABLE THAT WILL STORE THE SIZE OF ARRAY
    char selection;			/**THIS VARIABLE IS USED WHEN SELECTING TYPE OF 
							   PROGRAM THAT WILL GENERATE INTEGERS **/
	int MAXRANGE = 100000;  //MAXRANGE IS USED TO LIMIT THE RANGE OF PICKED RANDOM NUMBERS
	int X;

	ofstream myFile;		 	//DECLARATION FOR OUTPUT FILE
	myFile.open("README.txt"); //OPENING THE OUTPUT FILE
	
	cout<<"--THIS PROGRAM USED DIFERENT SORTING ALGORITHMS(INSERTION,MERGE,QUICK,HEAP) TO";
	cout<<"\nSORT RANDOMLY GENERATED INTEGERS AND THEN ANALYZE THEIR RUN TIME--\n";	
	/**
		*do while loop is used to ask the user choose how the program will generate the Integers 
		*that will be stored in the array. The loop will exit if the user input '3'.
		* '1' - to pick a random numbers and '2' to store sorted integer by asking the user to input a
		*positive integer and multiply it to (i+1) + N ,"i is the incrementing variable"  
	**/
    do {
        cout << "\n";
        cout << "Choose a program that will Generate the Integers\n\t[1]. Random\n\t[2]. Sorted\n\t[3]. End program" << endl;
        cout << "\nEnter selection: ", cin >> selection;
		
		//if statement to exit the loop
		if(selection == '3'){
            cout << "\n\nExiting program....";
           	cout<<"\n\nOpen \"README.txt\" to see the output.\n";
			myFile.close();	//closing the output file
            return 0;		
		}
		//if statement to exit the program when user inputs Invalid value 
		else if(selection != '1' && selection != '2'){
            cout<<"\nINVALID INPUT. SELECT FROM THE CHOICES\n";
            return 0;
        
		}
		//getting a value for N,size of array
	 	cout<<"Enter a value that will determine the number of integers in the Array: ";
		cin>>N;   

		//DECLARATION OF ARRAY
		int array[N];
		int tempArr[N];	//TEMPORARY ARRAY
		int temp;		//TEMPORARY VARIABLE THAT WILL HOLD THE RANDOM NUMBER
		
		//switch statement to get generate the values of array
		switch(selection){
	
			//case '1' is used to generate random numbers
			case '1':
				cout<<"\nGenerating inputs...\nSorting Array...\n";	
				for(int i=0; i<N; i ++){
	        		temp = (rand () % MAXRANGE) + 1;
					array[i] = temp;
					tempArr[i]= temp;
				}
				myFile<<"\n--The array elements by generating Random Numbers--\n";
	        	print(array, N, myFile);
				sorting(array, tempArr, N, myFile);
				break;
			//case '2' is used to generate sorted numbersby aking n input from the user
			case '2':
				cout << "Enter a positive Integer: ", cin>>X;
	        	if (X<1){
	            	cout << "\nINVALID INPUT...\n";
	            	return 0;
		        }
	        	cout<<"\nGenerating inputs...\nSorting Array...\n";
		        for(int i=0; i<N; i++){
	    	        array[i] = N + (i + 1) * X;
	        	    tempArr[i] = array[i];
	        	}
	        	myFile<<"\n**********************************************************************************";
	        	myFile<<"\n\n--The array elements by generating Sorted Integers in Increasing Order--\n";
	        	print(array, N, myFile);
				sorting(array, tempArr, N,myFile);
				break;
			}
	
	}while(selection!='3');
}
/////////////////////////////////////////////////
/////////////END OF MAIN PROGRAM/////////////////
/////////////////////////////////////////////////

// function to print the elements of the array
void print(int array[], int N, ofstream& myFile){
	
    for(int i = 0; i < N; i++){
		myFile <<array[i]<<", ";
	  // 	myFile<<endl;
    }
}
//functions to copy the original order of array from temporary array 
void copy(int array[], int tempArr[], int N){
	for(int i=0; i<N; i++){
		array[i] = tempArr[i];
	}
}

// function for calling sortING algorithms fnctions and computing running time
void sorting(int array[],int tempArr[], int N, ofstream&myFile){
    clock_t start, end;
    double cpu_time_used;

        //TO PERFORM INSERTION SORT
        start = clock(); 
        insertion(array,N); 
        end = clock(); 
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //meaures the time taken by the processor
        myFile<< "\n\n---Insertion Sort---" << endl;
        print(array, N, myFile);     
		myFile<<"\n\tTime taken is "<<cpu_time_used<<endl;
        cout<<"\nTime taken in Insertion sort is "<<cpu_time_used<<endl;

		//TO PERFORM MERGE SORT
		copy(array, tempArr,N);        
		start = clock(); 
		mergeSort(array, 0, N - 1);        
		end = clock(); 
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //meaures the time taken by the processor
        myFile<< "\n\n---Merge Sort---" << endl;
        print(array, N, myFile);      
		myFile<<"\n\tTime taken is "<<cpu_time_used<<endl;
        cout<<"Time taken in Merge sort is "<<cpu_time_used<<endl;

		//TO PERFORM QUICK SORT 		
		copy(array, tempArr,N);        
		start = clock();
		quicksort(array,0,N-1);
		end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;//meaures the time taken by the processor
        myFile<< "\n\n---Quick Sort---" << endl;
        print(array, N, myFile);     
		myFile<<"\n\tTime taken is "<<cpu_time_used<<endl;
        cout<<"Time taken in Quick sort is "<<cpu_time_used<<endl;

		//TO PERFORM HEAP SORT
		copy(array, tempArr,N);        
		start = clock();		
		heapsort(array,N);
		end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;//meaures the time taken by the processor
        myFile<< "\n\n---Heap Sort---" << endl;
        print(array, N, myFile);     
		myFile<<"\n\tTime taken is "<<cpu_time_used<<endl;
        cout<<"Time taken in Heap sort is "<<cpu_time_used<<endl;		
}

void insertion(int array[],int N){
	// Implementation of insertion sort algorithm
	int temp,j;
   	for(int i=1;i<N;i++){
      		temp=array[i];
      		j=i-1;

      		while((temp<array[j]) && (j>=0)){
		         array[j+1]=array[j];
         		 j=j-1;
      		}
	array[j+1]=temp;
   }
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        /* create temp arrays */
        int L[n1], R[n2];
        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                        arr[k] = L[i];
                        i++;
                }
                else{
                        arr[k] = R[j];
                        j++;
                }
        k++;
        }
        /* Copy the remaining elements of L[], if there are any */
        while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
        }
        /* Copy the remaining elements of R[], if there are any */
        while (j < n2){
                arr[k] = R[j];
                j++;
                k++;
        }
}

void mergeSort(int arr[], int l, int r)
{
        if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void quicksort(int array[],int first,int last){
	int i, j, pivot, temp;

   	if(first<last){
      		pivot=first;
      		i=first;
      		j=last;

      		while(i<j){
         		while(array[i]<=array[pivot]&&i<last)
            			i++;
         		while(array[j]>array[pivot])
            			j--;
         		if(i<j){
            			temp=array[i];
            			array[i]=array[j];
            			array[j]=temp;
         		}
      		}

      	temp=array[pivot];
      	array[pivot]=array[j];
      	array[j]=temp;
      	quicksort(array,first,j-1);
      	quicksort(array,j+1,last);
   	}
}

// Function to swap the the position of two elements
void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

void heapify(int array[], int n, int i){
        // Find largest among root, left child and right child
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && array[left] > array[largest])
                largest = left;

        if (right < n && array[right] > array[largest])
                largest = right;

// Swap and continue heapifying if root is not largest
        if (largest != i) {
                swap(&array[i], &array[largest]);
                heapify(array, n, largest);
        }
}

// Main function to do heapsort
void heapsort(int array[],int N){
        // Build max heap
        for(int i=N/2-1; i>=0; i--)
                heapify(array,N,i);

        // Heap sort
        for(int i=N-1; i>=0; i--){
                swap(&array[0], &array[i]);

                // Heapify root element to get highest element at root again
                heapify(array,i,0);
        }
}

