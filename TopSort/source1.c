#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count,bop,cyclic,V[100],top[100];

void cycle(int v,int *a[100],int n){
	for(int i = 0;i<n;i++)
		if(a[v][i] == 1 && V[i]!=0)
		{
			printf("Cycle exists hence no solution\n");
			exit(1);
		}
}

void dfs(int v,int *a[100],int n){
	V[v] = -9;
	cycle(v,a,n);
	for(int i = 0;i<n;i++)
		if(a[v][i] == 1)
			if(V[i] == 0){
				dfs(i,a,n);
			}
	count++;
	V[v] = count;
	top[count-1] = v;
}

void DFS(int *a[100],int n){
	for(int i = 0;i<n;i++)
		V[i] = 0;

	count = 0;
	for(int i = 0;i<n;i++)
		if(V[i] == 0)
			dfs(i,a,n);
}

int main(){
	int v;
	printf("Enter the number of vertices\n");
		scanf("%d",&v);
	int *a[v];
	for(int i = 0;i<v;i++)
		a[i] = (int *)malloc(sizeof(int)*i);
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<v;i++)
		for(int j = 0;j<v;j++)
			scanf("%d",&a[i][j]);
	DFS(a,v);
	printf("Topological sorting\n");
	for(int i = v-1;i>=0;i--)
		printf("%d ",top[i]);
}