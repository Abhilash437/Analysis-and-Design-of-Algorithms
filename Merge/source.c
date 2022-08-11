#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int count;
void split(int *a,int *left,int *right,int l,int m,int r){
	for(int i = 0;i<=m-l;i++)
		left[i] = a[2*i];
	for(int i = 0;i<r-m;i++)
		right[i] = a[2*i+1];
}

void join(int *a,int *left,int *right,int l,int m,int r){
	int i,j;
	for(i = 0;i<=m-l;i++)
		a[i] = left[i];
	for(j = 0;j<=r-m;j++)
		a[i+j] = right[j];
}

void generateworstcase(int *a,int l,int r){
	if(l<r){
		int m = l+(r-l)/2;
		int left[m-l+1];
		int right[r-m];
		split(a,left,right,l,m,r);
		generateworstcase(a,l,m);
		generateworstcase(a,m+1,r);
		join(a,left,right,l,m,r);
	}
}

void merge(int *a,int l,int m,int r){
	int i = l;
	int j = m+1;
	int k = 0;
	int b[101];
	while(i<=m && j<=r){
		count++;
		if(a[i]<a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i<=m){
		b[k++] = a[i++];
	}
	while(j<=r){
		b[k++] = a[j++];
	}
}

void msort(int *a,int l,int r){
	if(l<r){
		int m = (l+r)/2;
		msort(a,l,m);
		msort(a,m+1,r);
		merge(a,l,m,r);
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
			w[j] = j;
			a[j] = rand()%100;
		}
		count = 0;
		switch(ch){
			case 1:
				msort(b,0,i-1);
				f = fopen("best.txt","a");
				break;
			case 2:
				generateworstcase(w,0,i-1);
				msort(w,0,i-1);
				f = fopen("worst.txt","a");
				break;
			case 3:
				msort(a,0,i-1);
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
		printf("1. Best case\n2. Worst case\n3. Avg case\n");
			scanf("%d",&ch);
		switch(ch){
			case 1:
			case 2:
			case 3:
				analysis(ch);break;
			default:exit(1);
		}
	}
}