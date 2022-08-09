#include<stdio.h>
#include<stdlib.h>

int match(int t[],int p[],int i){
	int count = 0;
	for(int j = 0;j<=100;j++){
		int k = 0;
		count++;
		while(k<i && t[j+k] == p[k]){
			count++;
			k++;
		}
		if(k==i)
			break;
	}
	return count;
}


void analysis(int ch){
	FILE *f;
	int *b,*w,*a,t[100];
	for(int j = 0;j<=100;j++)
			t[j] = 0;
	for(int i=2;i<10;i++){
		b = (int *)malloc(sizeof(int)*i);
		a = (int *)malloc(sizeof(int)*i);
		w = (int *)malloc(sizeof(int)*i);
		printf("hi\n");
		

		for(int j = 0;j<i;j++){
			b[j] = 0;
			if(j!=i-1)
				w[j] = 0;
			else
				w[j] = 1;
			a[j] = j%2;
		}
		int count = 0;
		switch(ch){
			case 1:
				f = fopen("best.txt","a");
				count = match(t,b,i);
				break;
			case 2:
				f = fopen("worst.txt","a");
				count = match(t,w,i);
				break;
			case 3:
				f = fopen("avg.txt","a");
				count = match(t,a,i);
				break;
		}

		fprintf(f, "%d %d\n",i,count );
		fclose(f);
	}
}


int main(){
	int ch;
	while(1){
		printf("1.Best case\n2.Worst case\n3.Average case\n");
			scanf("%d",&ch);
		switch(ch){
			case 1:
			case 2:
			case 3: analysis(ch);break;
			default:exit(1);
		}
	}
}