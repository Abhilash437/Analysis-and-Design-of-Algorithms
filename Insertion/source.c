#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;

void isort(int *a,int n){
	for(int i = 1;i<n;i++){
		int v = a[i];
		int k = i-1;
		
		while(k>=0 && a[k]>v){
			count++;
			a[k+1] = a[k];
			k--;
		}
		a[k+1] = v;
	}
}

void analysis(int ch){
	FILE *f;
	int *a,*b,*w;
	srand(time(NULL));
	for(int i = 10;i<=100;i+=10){
		a = (int *)malloc(sizeof(int)*i);
		b = (int *)malloc(sizeof(int)*i);
		w = (int *)malloc(sizeof(int)*i);

		for(int j = 0;j<i;j++){
			b[j] = j;
			w[j] = i-j;
			a[j] = rand()%100;
			//printf("b[%d] = %d, a[%d] = %d, w[%d] = %d\n",j,b[j],j,a[j],j,w[j]);
		}
		count = 0;
		switch(ch){
			case 1:
				isort(b,i);
				f = fopen("best.txt","a");
				break;
			case 2:
				isort(w,i);
				f = fopen("worst.txt","a");
				break;
			case 3:
				isort(a,i);
				f = fopen("avg.txt","a");
				break;
				
		}
		fprintf(f,"%d %d\n",i,count);
		fclose(f);
	}
}


int main(){
	int ch;
	while(1){
		printf("1.Best case\n2.Worst case\n3.Avg case\n");
			scanf("%d",&ch);
		switch(ch){
			case 1:
			case 2:
			case 3:
				analysis(ch);break;
			default: exit(1);
		}
	}
}