#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<cstring>
using namespace std;
const int inf = 1<<30;
int G[301][301],Layer[301],n,m;
bool vis[301];

bool CountLayer()
{
	int layer = 0; deque<int> q;
	memset(Layer,0xff,sizeof Layer); //init with -1
	Layer[1] = 0; q.push_back(1);
	while(!q.empty())
	{
		int v = q.front();
		q.pop_front();
		for(int j = 1; j <= m; ++j){
			if(G[v][j] > 0 && Layer[j] == -1){
			// Layer[j] = -1说明j还没有访问过
				Layer[j] = Layer[v] + 1;
				if(j == m) //分层到汇点即可
					return true;
				else
					q.push_back(j);
			}
		}
	}
	return false;
}

int Dinic()
{
	int nMaxFlow = 0;
	deque<int> q; // dfs用的栈
	while(CountLayer()) //只要能分层
	{
		q.push_back(1); // 源点入栈
		memset(vis,0,sizeof vis);
		while(!q.empty())
		{
			int nd = q.back();
			if(nd == m){ // nd 是汇点
				//在栈中寻找容量最小边
				int nMinC = inf;
				int nMinC_vs;//容量最小边起点
				for(int i = 1; i < q.size(); ++i){
					int vs = q[i-1];
					int ve = q[i];
					if(G[vs][ve] > 0){
						if(nMinC > G[vs][ve]){
							nMinC = G[vs][ve];
							nMinC_vs = vs;
						}
					}
				}
				//增广，改图
				nMaxFlow += nMinC;
				for(int i = 1; i < q.size(); ++i){
					int vs = q[i-1];
					int ve = q[i];
					G[vs][ve] -= nMinC;
					G[ve][vs] += nMinC;
				}
				//退栈到nMinC_vs成为栈顶，以便继续dfs
				while(!q.empty() && q.back() != nMinC_vs){
					vis[q.back()] = 0;
					q.pop_back();
				}
			}
			else{ //nd不是汇点
				int i;
				for(i = 1; i <= m; ++i){
					if(G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 && !vis[i]){
						//只往下一层的没有走过的节点走
						vis[i] = 1;
						q.push_back(i);
						break;
					}
				}
				if(i > m) //找不到下一个点
					q.pop_back(); //回溯
			}
		}
	}

	return nMaxFlow;
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n>>m)
	{
		int s,e,c;
		memset(G,0,sizeof G);
		for(int i = 0 ; i < n; ++i){
			cin>>s>>e>>c;
			G[s][e] += c;
		}
		cout<<Dinic()<<endl;
	}

	return 0;
}
