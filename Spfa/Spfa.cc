/* @ openjude Till the Cows Come Home
 *   2018-08-03 00:18:35
 * */
#include<bits/stdc++.h>

using namespace std;

const int inf = 1<<30;
typedef pair<int,int> p;
struct edge{
	int v,w;
};
vector<edge> e[1001];
int dis[1001],T,N,x,y,w;
void spfa()
{
	priority_queue< p,vector<p>,greater<p> > pq;
	dis[0] = 0;
	pq.push(p(0,0));
	while(!pq.empty()){
		p cur = pq.top();
		pq.pop();
		int dist = cur.first, u = cur.second;
		if(dist > dis[u])
			continue;
		for(int v = 0; v < e[u].size(); ++v){
			edge nxt = e[u][v];
			if(dis[nxt.v] > nxt.w + dis[u]){
				dis[nxt.v] = nxt.w + dis[u];
				pq.push(p(dis[nxt.v],nxt.v));
			}
		}
	}
}

int main()
{	
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&T,&N);
	fill(dis,dis+N,inf);
	for(int i = 0; i < T; ++i){
		scanf("%d%d%d",&x,&y,&w);
		x--,y--;
		e[x].push_back((edge){y,w});
		e[y].push_back((edge){x,w});
	}
	spfa();
	printf("%d\n",dis[N-1]);
	return 0;
}
