/*
Name:Tommy Lee Truong and Professor Chi Yan Leung
Last Edit:Sept 18 2019
Program Name: Copy Array
*/
#include<stdio.h>
#include<string.h>

void printArr(int *a, int size){
	//Your code here
	printf("printArr:");
	for(int i =0; i<size;i++){
	     printf(" %d",a[i]);
	}
	printf("\n");
}

int* arrCopy(int *a, int size){
	//Your code here
	return a;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter size of array:\n");
    scanf("%d",&n);

    //Dynamically create an int array of n items
    //Your code here
    int temp[n];
    for(i=0; i<n; i++){
	printf("Enter array content# %d: ",++i);
	scanf("%d",&temp[--i]);
    }
    arr = &temp[0];

    //Ask user to input content of array
	//Your code here
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}
