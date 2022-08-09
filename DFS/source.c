#include<stdio.h>
#include<stdlib.h>

int count;
int bop;
int cyclic;
int V[100];

void cycles(int v,int *a[100],int n){
	for(int i = 0;i<n;i++){
		if(a[v][i] == 1 && V[i]!=0 && V[v] - V[i]!=1){
			cyclic++;
			printf("Backedge from %d to %d\n",v,i);
		}
	}
}
void dfs(int v,int *a[100],int n){

	count++;
	V[v] = count;
	
	printf("%d\n",v);
	//cycles(v,a,n);
	// for(int i=0;i<n;i++){
	// 	if(a[v][i] == 1 && V[i]!=0 && V[v]-V[i]!=1){
	// 		cyclic++;
	// 		printf("Backedge from %d to %d\n",v,i);
	// 	}
	// }
	for(int i = 0;i<n;i++){
		bop++;
		if(a[v][i] == 1){
			bop++;
			if(V[i] == 0)
				dfs(i,a,n);
			else if(V[v]>V[i] || ){
				cyclic++;
			}
		}
	}

}

void DFS(int *a[100],int n){
	count = 0;
	for(int i = 0;i<n;i++)
		V[i] = 0;
	bop = 0;
	count = 0;
	cyclic = 0;
	int connected = -1;
	for(int i = 0;i<n;i++)
		if(V[i] == 0){
			printf("DFS tree: %d\n",connected+2);
			dfs(i,a,n);
			connected++;
		}
	if(cyclic>0)
		printf("Graph has cycles\n");
}


int main(){
	int v;
	printf("Enter the number of vertices in the graph\n");
		scanf("%d",&v);
	int *a[v];
	for(int i = 0;i<v;i++)
		a[i] = (int *)malloc(sizeof(int)*v);
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<v;i++)
		for(int j = 0;j<v;j++)
			scanf("%d",&a[i][j]);
	DFS(a,v);
}