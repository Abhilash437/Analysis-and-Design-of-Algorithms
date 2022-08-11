#include<stdio.h>
#include<stdlib.h>

#define initial 1
#define visited 2
#define finished 3

#define MAX 100

int state[MAX];
int V[MAX];
int count;
int bop;
int cycles;
int connected;

void DFS(int a[100][100],int v,int n){
	count++;
	V[v] = count;
	state[v] = visited;
	for(int i = 0;i<n;i++){
		bop++;
		if(a[v][i]==1){
			//bop++;
			if(state[i]==initial)
				DFS(a,i,n);
			else if(state[i] == finished){
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
	cycles = 0;
	bop = 0;
	count  = 0;
	connected = -1;
	for(int i = 0;i<n;i++){
		if(state[i] == initial){
			DFS(a,i,n);
			connected++;
		}
	}
	if(connected>0)
		printf("Disconnected graph\n");
	else
		printf("connected graph\n");
	if(cycles>0)
		printf("Cyclic graph\n");
	else
		printf("Acyclic graph\n");
}

int main(){
	int n;
	printf("Enter number of vertices\n");
		scanf("%d",&n);
	int a[100][100];
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
	dfs(a,n);
	printf("BOP = %d\n",bop);
}