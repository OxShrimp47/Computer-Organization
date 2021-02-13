/*
Name:Tommy Lee Truong
Last Edit:Sept 18 2019
Program Name: Pointers
*/
int main(){
	int x=0,y=0,*px=&x,*py=&y;
	int arr[10]={2,1,2,3,4,5,6,7,8,9};
	for (int i = 0; i<10; i++){
		printf("%d", *(arr+i));
	}
	printf("%d", *arr);
	printf("%d", arr[0]);
	return 0;
}
