/*
Name:Tommy Lee Truong
Last Edit:Sept 11 2019
Program Name: Punishment
*/
#include <stdio.h>
int main(){
	int line;
	int typo;
	printf("Enter the number of lines for the punishment:");
	scanf("%d", &line);
	if (line <1){
		printf("You entered an incorrect value for the number of lines!\n");
	}
	else{
		printf("Enter the line for which we want to make a typo:");
		scanf("%d", &typo);
		if(typo < 1 || typo > line){
			printf("You entered an incorrect value for the line typo!\n");
		}
		else{
			for(int x = 0; x < line; x++){
				if(x+1 == typo){
					printf("C programming language is the bet!\n");
				}
				else{
					printf("C programming language is the best!\n");
				}
				
			} 
		}
	}
	return 0;
}
