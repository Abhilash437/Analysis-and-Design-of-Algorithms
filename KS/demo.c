#include<stdio.h>
#include<stdlib.h>

typedef struct table{
	int value,item,weight;
}T;

T *t;
int *a[20],optimal,subset[10],count;

int max(int a,int b){
	return a>b?a:b;
}

int knapsack(int i,int j){
	if(a[i][j]==-1){
		count++;
		if(j-t[i].weight<0)
			a[i][j] = knapsack(i-1,j);
		else
			a[i][j] = max(knapsack(i-1,j),knapsack(i-1,j-t[i].weight)+t[i].value);
	}
	return a[i][j];
}

int main(){
	int n;
	printf("Enter the number of items\n");
	scanf("%d",&n);

	t = (T *)malloc(sizeof(struct table)*(n+1));

	printf("Enter the item, weight and value\n");
	for(int i = 1;i<=n;i++)
		scanf("%d%d%d",&t[i].item,&t[i].weight,&t[i].value);
	printf("Enter the capacity\n");
	int W;
	scanf("%d",&W);
	for(int i = 0;i<=n;i++){
		int j;
		a[i] = (int *)malloc(sizeof(int)*(W+1));
		for(int j = 0;j<=W;j++){
			if(i==0||j==0)
			a[i][j] = 0;
		else
			a[i][j] = -1;
		}
		
		//printf("%d\n",a[i][j]);
	}
	optimal = knapsack(n,W);
	printf("Optimal value: %d\n",optimal);
	int RC = W;
	int i = n;
	int j = 0;
	while(RC!=0 && i>=1){
		if(a[i][RC]!=a[i-1][RC]){
			subset[j] = i;
			j++;
			RC = RC-t[i].weight;
		}
		i--;
	}
	printf("subset\n");
	for(i = 0;i<j;i++)
		printf("%d, ",subset[i]);
	printf("\n");
	printf("Count = %d\n",count);
}