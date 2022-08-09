#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int delcount;

void Hdel(int *a,int n){
	int size = n;
	for(int i = 0;i<size-1;i++){
		int temp = a[1];
		a[1] = a[n];
		a[n] = temp;
		n--;
		int k = 1;
		int v = a[k];
		int heap = 0;
		while(!heap && 2*k<=n){
			int j = 2*k;
			if(j<n){
				count++;
				//delcount++;
				if(a[j+1]>a[j])
					j++;
			}
			count++;
			//delcount++;
			if(v>=a[j])
				heap = 1;
			else{
				a[k] = a[j];
				k = j;
			}
		}
		a[k] = v;
	}
}
void Hin(int *a,int n){
	for(int i = n/2;i>=1;i--){
		int v = a[i];
		int k = i;
		int heap = 0;
		printf("Hi\n");
		while(!heap && 2*k<=n){
			int j = 2*k;
			if(j<n){
				count++;
				//delcount++;
				if(a[j+1]>a[j])
				{
					j++;
				}
			}
			count++;
			//delcount++;
			if(v>=a[j])
				heap = 1;
			else{
				a[k] = a[j];
				k = j;
			}
		}
		a[k] = v;
	}
}

void analysis(int ch){
	FILE *f;
	int *w,*b;
	for(int i = 10;i<=100;i+=10){
		b = (int *)malloc(sizeof(int)*(i+1));
		w = (int *)malloc(sizeof(int)*(i+1));
		for(int j = 1;j<i;j++){
			b[j] = i-j;
			w[j] = j;
		}
		count = 0;
		//printf("Hi\n");
		switch(ch){
			case 1:
				Hin(b,i-1);
				f = fopen("conb.txt","a");
				break;
			case 2:
				Hin(w,i-1);
				f = fopen("conw.txt","a");
				break;
			case 3:
				//Hin(b,i-1);
				Hdel(b,i-1);
				f = fopen("del.txt","a");
				break;
		}
		fprintf(f,"%d %d\n",i-1,count);
		fclose(f);
	}
}

int main(){
	int ch;
	while(1){
		printf("1.Best case construction\n2.Worst case construction\n3.Heap sort\n");
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