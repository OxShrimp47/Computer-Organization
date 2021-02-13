/*
Name:Tommy Lee Truong
Last Edit:Sept 11 2019
Program Name: Averages
*/
#include <stdio.h>
int main(){	
	int c = 1;
	int cntn=0;
	int cntp=0;
	int sumn=0;
	int sump=0;
	int avgp;
	int avgn;
	while (c != 0){
		printf("Please enter an integer:");
		scanf("%d",&c);
		if (c>0){
			sump=sump + c;
			cntp++;
		}
		else if (c<0){
			sumn= sumn + c;
			cntn++;		
		}
	}
	
	if (cntp != 0){
		avgp= (sump)/(cntp);
	
		printf("Positive average:%d\n",avgp);
	}
	if (cntn != 0){
		avgn= (sumn)/(cntn);
		printf("Negative average:%d\n",avgn);
	}

	return 0;
}
	
	
