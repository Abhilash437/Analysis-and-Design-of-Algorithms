#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void analysis(){
	FILE *f;
	int *a;
	srand(time(NULL));
	for(int i = 10;i<=100;i+=10){
		f = fopen("data.txt","a");
		a = (int *)malloc(sizeof(int)*i);
		for(int j = 0;j<i;j++){
			a[j] = rand()%100;
		}
		int count = 0;
		for(int j = 0;j<i-1;j++){
			int minind = j;
			for(int k = j+1;k<i;k++){
				count++;
				if(a[k] < a[minind])
					minind = k;
			}
			int temp = a[minind];
			a[minind] = a[j];
			a[j] = temp;
		}
		fprintf(f,"%d %d\n",i,count);
		fclose(f);
	}
}



int main(){
	analysis();
}