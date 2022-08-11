#include<stdio.h>
#include<stdlib.h>


typedef struct table{
	int item,value,weight;
}T;

int optimal,subset[20];

int max(int a,int b){
	return a>b?a:b;
}

void knapsack(T *t,int n,int W){
	int *a[n+1];
	for(int i = 0;i<=n;i++)
		a[i] = (int *)malloc(sizeof(int)*(W+1));

	for(int i = 0;i<=n;i++){
		//printf("HI\n");
		for(int j = 0;j<=W;j++){
			if(i == 0||j == 0){
				a[i][j] = 0;
				//continue;
			}
			else if(j-t[i].weight<0)
				a[i][j] = a[i-1][j];
			else
				a[i][j] = max(a[i-1][j],t[i].value+a[i-1][j-t[i].weight]);
		}
	}
	//printf("HI\n");
	optimal = a[n][W];
	int RC = W;
	int i = n;
	int j = 0;
	while(RC!=0 && i>=1){
		//printf("HI\n");
		if(a[i][RC]!=a[i-1][RC]){
			subset[j] = i;
			j++;
			RC = RC - t[i].weight;
		}
		i--;
	}
	//printf("HI\n");
}


int main(){
	int n;
	printf("Enter the number of items\n");
		scanf("%d",&n);
	T *t = (T *)malloc(sizeof(struct table)*(n+1));
	printf("Enter item,value and weight\n");
	for(int i = 1;i<=n;i++)
		scanf("%d%d%d",&t[i].item,&t[i].weight,&t[i].value);
	printf("Enter knapsack capacity\n");
	int W;
	scanf("%d",&W);
	knapsack(t,n,W);
	printf("Optimal value: %d\n",optimal);
	printf("Subset\n");
	for(int i = 0;i<n;i++)
		printf("%d, ",subset[i]);
}