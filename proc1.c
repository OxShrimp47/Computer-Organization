/* 
Name:Tommy Lee Truong
Last Edit:Oct 28 2019
Program Name: Procedure
include<stdio.h>
*/

int Sum(int x, int y){
	int s = x+y;
	return s;
}
int main(){
	int m = 10;
	int n = 5;
	int s = Sum(m,n);
	printf("%d\n", s);
	return 0;
}
