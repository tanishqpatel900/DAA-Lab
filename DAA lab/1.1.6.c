#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999 //tanishq patel prn-26070521506

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	
	// write your code here
int distance[MAX];
	int pred[MAX];
	int visited[MAX];
	int count,mindistance,nextnode,i,j;
	for(i=1;i<=n;i++){
		distance[i]=INFINITY;
		pred[i]=0;
		visited[i]=0;
	}
	distance[startnode]=0;
	for(count=1;count<=n;count++){
		mindistance=INFINITY;
		nextnode=-1;
		for(i=1;i<=n;i++){
			if(distance[i]<mindistance && !visited[i]){
				mindistance=distance[i];
				nextnode=i;
			}
		}
		if(nextnode==-1){
			break;
		}
		visited[nextnode]=1;
		for(i=1;i<=n;i++){
			if(!visited[i] && G[nextnode][i]>0 && G[nextnode][i]!=INFINITY){
				if(mindistance+G[nextnode][i]<distance[i]){
} 