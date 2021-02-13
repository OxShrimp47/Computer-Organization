/*
Name:Tommy Lee Truong
Last Edit:Nov 14 2018
Program Name: Swap
*/
void swap (int *px, int *py) {
 	int *temp;
	*temp = *px;
	*px = *py;
	*py = *temp;
}
void proc(int *px, int *py){
	px=NULL;
	py=NULL;
}
int main(){
	int x,y;
	proc(&x,&y)
	swap(&x,&y);
	return 0;
}
