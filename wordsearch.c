/*
Name:Tommy Lee Truong
Last Edit:Nov 6 2019
Program Name: Word Search
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
void intialCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found);
void HCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found);
void VCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found);
void DCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found);
// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i=0; i<50; i++){
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i=0; i<49; i++){
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i=0; i<50; i++){
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");

    return 0;
}

void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%c",*(*(arr+i)+j));
		}
		printf("\n");
	}
		
	
	return ;

}

void searchPuzzle(char** arr, int n, char** list, int listSize){
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here

	char** found = (char**)malloc(n*sizeof(char*));
	for (int x=0; x<n; x++){
		*(found+x) = (char*)malloc(n*sizeof(char));
	}
	int i =0, j=0, k=0, l=0, h=0;
	intialCheck(arr,n,list,listSize,i,j,k,l,h,found);

	return ;

}
void intialCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found){
//converts to lowercase
	if(i==n||k==listSize){
		

		return;
		
	}
	//looks for starting letter

	if(*(*(arr+i)+j)==*(*(list +k)+l)){
		//*(found+h)=(*(arr+i)+j);
		h++;
		l++;
		if(*(*(arr+i)+(j+1))==*(*(list +k)+l)-32&&strlen(*(list+k))<(n-j)){
			j++;
			HCheck(arr,n,list,listSize,i,j,k,l,h,found);
		}
		if(*(*(arr+(i+1))+j)==*(*(list +k)+l)-32&&strlen(*(list+k))<(n-i)){
			i++;
			VCheck(arr,n,list,listSize,i,j,k,l,h,found);
		}
		if(*(*(arr+(i+1))+(j+1))==*(*(list +k)+l)-32&&strlen(*(list+k))<(n-j)){
			i++;
			j++;
			DCheck(arr,n,list,listSize,i,j,k,l,h,found);
		}
		/**(found+h)=(*(arr+i)+j);
		h++;
		l=0;
		i=0;
		j=0;
		k++;
*/
		intialCheck(arr,n,list,listSize,i,j,k,l,0,found);
	}
	else{
		j++;
		if (j=n){
			j=0;
			i++;
		}
		intialCheck(arr,n,list,listSize,i,j,k,l,h,found);
	}
return ;
}
void HCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found){
//searches word horizontally

	if(l==strlen(*(list+k))){
	printf("Word found:%s\n",*(list+k));
		while (h != 0){
			*(*(arr+i)+j)=*(*(arr+i)+j)+32;
			j--;
			h--;
		}
		k++;

		intialCheck(arr,n,list,listSize,0,0,k,0,0,found);	
	}
	if(*(*(arr+i)+j)==*(*(list +k)+l)-32){
	printPuzzle( arr,  n);
		//*(found+h)=(*(arr+i)+j);
		h++;
		l++;
		j++;
		HCheck(arr,n,list,listSize,i,j,k,l,h,found);
	}
	else{
		
		l=l-h;
		j=j-h;
		j++;
		if (j=n){
			j=0;
			i++;
		}
		intialCheck(arr,n,list,listSize,i,j,k,l,0,found);
	}
}
void VCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l,int h,char **found){
//searches word vertically
	if(l==strlen(*(list+k))){
	printf("Word found:%s\n",*(list+k));
		while (h != 0){
			*(*(arr+i)+j)=*(*(arr+i)+j)+32;
			i--;
			h--;
		}
		k++;

		intialCheck(arr,n,list,listSize,0,0,k,0,0,found);	
	}
	if(*(*(arr+i)+j)==*(*(list +k)+l)-32){
		h++;
		l++;
		i++;
		VCheck(arr,n,list,listSize,i,j,k,l,h,found);
	}
	else{
		
		l=l-h;
		i=i-h;
		j++;
		if (j=n){
			j=0;
			i++;
		}
		intialCheck(arr,n,list,listSize,i,j,k,l,0,found);
	}
}
void DCheck(char** arr, int n, char** list, int listSize,int i,int j,int k,int l, int h,char **found){
//searches word diagonally
if(l==strlen(*(list+k))){
	printf("Word found:%s\n",*(list+k));
		while (h != 0){
			*(*(arr+i)+j)=*(*(arr+i)+j)+32;
			i--;
			h--;
		}
		k++;

		intialCheck(arr,n,list,listSize,0,0,k,0,0,found);	
	}
	if(*(*(arr+i)+j)==*(*(list +k)+l)-32){
		h++;
		l++;
		i++;
		j++;
		VCheck(arr,n,list,listSize,i,j,k,l,h,found);
	}
	else{
		
		l=l-h;
		i=i-h;
		j=j-h;
		j++;
		if (j=n){
			j=0;
			i++;
		}
		intialCheck(arr,n,list,listSize,i,j,k,l,0,found);
	}
}
