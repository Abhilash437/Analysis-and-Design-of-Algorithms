#include<stdio.h>

int prims(int a[100][100],int n){
	int edges = 0,count = 0,cost = 0;
	int row,col,min,selected[100];
	for(int i = 0;i<n;i++)
		selected[i] = 0;
	selected[0] = 1;
	while(edges<n-1){
		row = 0;
		col = 0;
		min = 999;
		for(int i = 0;i<n;i++){
			count++;
			if(selected[i]){
				for(int j = 0;j<n;j++){
					//count++;
					if(selected[j]==0 && a[i][j]){
						count++;
						if(a[i][j]<min){
							min = a[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
		}
		printf("V%d ---- %d ---- V%d\n",row+1,a[row][col],col+1);
		selected[col]=1;
		cost+=a[row][col];
		edges++;
	}
	printf("Weight pf MST is: %d\n",cost);
	return count;
}


int main(){
	int n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);

	printf("Enter the weighted adjacency matrix\n");
	int a[100][100];
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
	int count = prims(a,n);
	printf("\nCount = %d\n",count);
}