#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define initial 1
#define visited 2
#define finished 3

int state[100];
int count,bop,cyclic,V[100],top[100];


void dfs(int v,int *a[100],int n){
	V[v] = -9;
	state[v] = visited;
	//cycle(v,a,n);
	for(int i = 0;i<n;i++)
		if(a[v][i] == 1){
			if(state[i]==initial){
				dfs(i,a,n);
			}else if(state[i] == visited){
				printf("Cycles exists hence no solution\n");
				exit(1);
			}
		}
	count++;
	V[v] = count;
	state[v] = finished;
	top[count-1] = v;
}

void DFS(int *a[100],int n){
	for(int i = 0;i<n;i++){
		state[i] = initial;
		V[i] = 0;
	}

	count = 0;
	for(int i = 0;i<n;i++)
		if(state[i]==initial)
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