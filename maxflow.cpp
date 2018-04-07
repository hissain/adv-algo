#include <stdio.h>
#define SZ 100

int residue[SZ][SZ], flow[SZ][SZ];
int S, T, N, E, u, v, c;
int visited[SZ];

inline int min(int a, int b){return a < b ? a : b;}
int dfs(int u, int rescap){

	if (u == T){return rescap;}
	visited[u] = 1;
	for(register int v = 0; v < N; v++){
		if (visited[v] == 0 && residue[u][v]){
			int r = dfs(v, min(residue[u][v], rescap));
			if(r) {
				flow[u][v] += r;
				residue[u][v] -= r;
				residue[v][u] += r;
				visited[u] = 0;
				return r;
			}
		}
	}
	visited[u] = 0;
	return 0;
}

int main(){

	freopen("maxflow.txt", "rt", stdin);
	scanf("%d %d", &N, &E);
	for(register int i = 0; i < E; i++){
		scanf("%d %d %d", &u, &v, &c);
		residue[u][v] = c;
	}

	S = 0;
	T = N - 1;

	int total = 0;
	int f = 0;
	do{
		f = dfs(S, 1<<30);
		total += f;
	}while(f);
	printf("max flow: %d\n", total);	
	
	return 0;
}

