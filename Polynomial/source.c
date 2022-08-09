#include<stdio.h>
#include<stdlib.h>

void analysis(){

	FILE *f;
	int *a;
	for(int i = 10;i<=100;i+=10){
		f = fopen("data.txt","a");
		a = (int *)malloc(sizeof(int)*i);
		for(int j = 0;j<i;j++)
			a[j] = j;
		int poly = a[0];
		int px = 1;
		int count = 0;
		for(int j =1;j<i;j++){
			int px = px*10;
			poly += a[j]*px;
			count++;
		}
		fprintf(f,"%d %d\n",i,count);
		fclose(f);
	}

}

int main(){
	analysis();
}