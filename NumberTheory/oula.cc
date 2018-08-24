#include<bits/stdc++.h>
const int N = 1e5+1;
int prime[N],vis[N],phi[N],cnt;
void initPhi(int n)
{
	phi[1] = 1; //
	for(int i = 2; i <= n; ++i){
		if(!vis[i]){
			phi[i] = i-1; //性质1
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt; ++j){
			if(i*prime[j]>n) break;
			vis[i*prime[j]] = 1;
			if(i%prime[j]==0){ //性质2
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i]*phi[prime[j]]; //性质3
		}
	}
}

int main()
{
	int n;
	initPhi(1000);
	std::cin>>n;
	for(int i = 1; i <= n; ++i)
		printf("%d=%d\n",i,phi[i]);
	return 0;
}
