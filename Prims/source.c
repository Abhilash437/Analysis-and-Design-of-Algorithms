#include<stdio.h>
#include<stdlib.h>
int n;
int *a[30];

int prims(){
	int edges = 0,count = 0,cost = 0;
	int row,col;
	int selected[n];
	int min;
	for(int i = 0;i<n;i++)
		selected[i] = 0;
	selected[0] = 1;
	while(edges < n-1){
		row = 0;
		col = 0;
		min = 999;
		for(int i = 0;i<n;i++){
			if(selected[i]){

				for(int j = 0;j<n;j++){
					count++;
					if(selected[j]==0 && a[i][j])
						if(min > a[i][j]){
							min = a[i][j];
							row = i;
							col = j;
						}
				}
			}
		}
		printf("V%d ---- %d ---- V%d\n",row+1,a[row][col],col+1);
		cost += a[row][col];
		selected[col] = 1;
		edges++;
	}
	printf("Weight of MST: %d\n",cost);
	return count;
}


int main(){
	printf("Enter the number of vertices\n");
		scanf("%d",&n);
	for(int i = 0;i<n;i++)
		a[i] = (int *)malloc(sizeof(int)*n);
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("Count: %d\n",prims());
}