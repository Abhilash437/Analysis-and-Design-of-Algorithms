#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define X 10

int count;

int partition(int *a,int s,int e){
	int i = s+1,j = e, p = a[s];
	while(i<=j){
		count++;
		while(i<=e && a[i] < p){
			count++;
			i++;
		}
		count++;
		while(a[j]>p){
			count++;
			j--;
		}
		//count++;
		if(i<=j){
			//count++;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
			j--;
		}
		if(i==j && a[i] == p){
			count++;
			return j;
		}
	} 
	if(a[j]!=a[e]){
	int temp = a[s];
	a[s] = a[j];
	a[j]= a[s];
	}

	return j;
}

void quick(int *a,int s,int e){
	if(s<e){
		int l = partition(a,s,e);
		quick(a,s,l-1);
		quick(a,l+1,e);
	}
}
void analysis(int ch){
	FILE *f;
	srand(time(NULL));
	int *a,*b,*w;
	for(int i = 10;i<=100;i+=10){
		a = (int *)malloc(sizeof(int)*i);
		b = (int *)malloc(sizeof(int)*i);
		w = (int *)malloc(sizeof(int)*i);

		for(int j = 0;j<i;j++){
			b[j] = X;
			w[j] = j;
			a[j] = rand()%100;
		}
		count = 0;
		switch(ch){
			case 1:
				quick(b,0,i-1);
				f = fopen("best.txt","a");
				break;
			case 2:
				quick(w,0,i-1);
				f = fopen("worst.txt","a");
				break;
			case 3:
				quick(a,0,i-1);
				f = fopen("avg.txt","a");
				break;
		}
		fprintf(f, "%d %d\n",i,count );
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