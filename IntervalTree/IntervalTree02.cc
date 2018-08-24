/* @POJ 3264
 * 给定q个数A1,A2,...AQ,
 * 多次求任一区间Ai-Aj中最大数和最小数的差
 * */
#include<bits/stdc++.h>
const int N = 5e5+1,inf = 0xffffff0;
int minV = -inf, maxV = inf;
struct node{
	int L,R;
	int minV,maxV;
	int mid(){
		return (L+R)>>1;
	}
}tree[N<<2];

void Build(int root,int L,int R)
{
	tree[root].L = L;
	tree[root].R = R;
	tree[root].minV = inf;
	tree[root],maxV = -inf;
	if(L!=R){
		Build(2*root+1,L,(L+R)/2);
		Build(2*root+2,(L+R)/2+1,R);
	}
}

//insert i'th num = v into the interval tree
void Insert(int root,int i,int v)
{
	if(tree[root].L == tree[root].R){
		tree[root].minV = tree[root].maxV = v;
		return;
	}
	tree[root].minV = std::min(tree[root].minV,v);
	tree[root].maxV = std::max(tree[root].maxV,v);
	if(i <= tree[root].mid())
		Insert(2*root+1,i,v);
	else
		Insert(2*root+2,i,v);
}

void query(int root,int s,int e)
{
	if(tree[root].minV >= minV && tree[root].maxV <= maxV)
		return;
	if(tree[root].L == s && tree[root].R == e){
		minV = std::min(minV,tree[root].minV);
		maxV = std::max(maxV,tree[root].maxV);
		return;
	}
	if(e <= tree[root].mid())
		query(2*root+1,s,e);
	else if(s > tree[root].mid())
		query(2*root+2,s,e);
	else{
		query(2*root+1,s,tree[root].mid());
		query(2*root+2,tree[root].mid()+1,e);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,q,h,s,e;
	scanf("%d%d",&n,&q);
	Build(0,1,n);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&h);
		Insert(0,i,h);
	}
	for(int i = 0; i < q; ++i){
		scanf("%d%d",&s,&e);
		minV = inf;
		maxV = -inf;
		query(0,s,e);
		printf("%d\n",maxV-minV);
	}
	return 0;
}
