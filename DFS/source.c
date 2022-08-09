#include<stdio.h>
#include<stdlib.h>

#define initial 1
#define visited 2
#define finished 3

#define MAX 100

int state[MAX];
int V[MAX];
int count;
int cycles;

void DFS(int a[100][100],int v,int n){
	int i;
	state[v] = visited;
	count++;
	V[v] = count;
	printf("%d - %d\n",v,count);
	for(i = 0;i<n;i++){
		if(a[v][i] == 1){
			if(state[i] == initial)
				DFS(a,i,n);
			else if(state[i] == finished){
				printf("There exists a back edge from %d to %d\n",v,i);
				cycles++;
			}
		}
	}
	state[v] = finished;

}

void dfs(int a[100][100],int n){
	for(int i = 0;i<n;i++){
		V[i] = 0;
		state[i] = initial;
	}
	count = 0;
	cycles = 0;
	//DFS(a,0,n);

	for(int i = 0;i<n;i++){
		if(state[i] == initial){
			//printf("%d\n",i);
			DFS(a,i,n);
		}
	}
	if(cycles>0)
		printf("There exists cycles in the graph\n");
	else
		printf("Graph is acyclic\n");
}

int main(){
	int n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	int a[100][100];
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
	dfs(a,n);
}