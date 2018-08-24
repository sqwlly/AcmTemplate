/* @POJ 3468
 * 询问区间[a,b]的和
 * 区间[a,b]增加或减少一个数值
 **/
#include<bits/stdc++.h>

typedef long long LL;
const int N = 1e5+1;
struct node{
	int L, R;
	LL nSum, Inc;
	node *left, *right;
};
node Tree[N<<1];
int nCount = 0;

int mid(node *root)
{
	return (root->L + root->R)>>1;
}

void build(node *root,int L,int R)
{
	root->L = L;
	root->R = R;
	root->nSum = 0;
	root->Inc = 0;
	if(L==R) return;
	nCount++;
	root->left = Tree + nCount;
	nCount++;
	root->right = Tree + nCount;
	build(root->left,L,(L+R)>>1);
	build(root->right,((L+R)>>1)+1,R);
}

void Insert(node *root,int i,int v)
{
	if(root->L == i && root->R == i){
		root->nSum = v;
		return;
	}
	root->nSum += v;
	if(i <= mid(root))
		Insert(root->left,i,v);
	else
		Insert(root->right,i,v);
}

void add(node *root,int a,int b,LL c)
{
	if(root->L == a&& root->R == b){
		root->Inc += c;
		return;
	}
	root->nSum += c*(b-a+1);
	if(b <= (root->L+root->R)/2)
		add(root->left,a,b,c);
	else if(a >= (root->L+root->R)/2+1)
		add(root->right,a,b,c);
	else{
		add(root->left,a,(root->L+root->R)/2,c);
		add(root->right,(root->L+root->R)/2+1,b,c);
	}
}

LL query(node *root,int a,int b)
{
	if(root->L == a && root->R ==b)
		return root->nSum + (root->R - root->L + 1) * root->Inc;
	root->nSum += (root->R - root->L + 1) * root->Inc;
	add(root->left,root->L,mid(root),root->Inc);
	add(root->right,mid(root)+1,root->R,root->Inc);
	root->Inc = 0;
	if(b <= mid(root))
		return query(root->left,a,b);
	else if(a >= mid(root)+1)
		return query(root->right,a,b);
	else
		return query(root->left,a,mid(root)) + query(root->right,mid(root)+1,b);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,a,b,c;
	char cmd[10];
	scanf("%d%d",&n,&q);
	nCount = 0;
	build(Tree,1,n);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a);
		Insert(Tree,i,a);
	}
	for(int i = 0; i < q; ++i){
		scanf("%s",cmd);
		if(cmd[0]=='C'){
			scanf("%d%d%d",&a,&b,&c);
			add(Tree,a,b,c);
		}else{
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(Tree,a,b));
		}
	}
	return 0;
}
