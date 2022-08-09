#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

int maxmin(int *a,int s,int e){
	if(s == e)
		return a[s];
	int t1 = maxmin(a,s,(s+e)/2);
	int t2 = maxmin(a,((s+e)/2)+1,e);
	count++;
	if(t1<t2)
		return t2;
	else
		return t1;
}
void analysis(){
	FILE *f;
	int *a;
	for(int i = 10;i<=100;i+=10){
		a = (int *)malloc(sizeof(int)*i);
		for(int j = 0;j<i;j++){
			a[j] = rand()%100;
		}
		count = 0;
		f = fopen("data.txt","a");
		int temp = maxmin(a,0,i-1);
		fprintf(f, "%d %d\n",i,count );
		fclose(f);
	}
}

int main(){
	int ch;
	analysis();
}