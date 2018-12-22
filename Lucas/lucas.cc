/*************************************************************************
    > File Name: lucas.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月22日 星期六 15时54分10秒
 ************************************************************************/
typedef long long LL;
const int MAXN = 1e6+5;
using namespace std;

LL quick_mod(LL a, LL b, LL c)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans*a)%c;
        b>>=1;
        a = (a*a)%c;
    }
    return ans;
}
LL fac[MAXN];

void Get_Fac(LL m)///m!
{
    fac[0] = 1;
    for(int i=1; i<=m; i++)
        fac[i] = (fac[i-1]*i) % m;
}

LL Lucas(LL n, LL m, LL p)
{
    LL ans = 1;
    while(n && m)
    {
        LL a = n % p;
        LL b = m % p;
        if(a < b)
            return 0;
        ans = ( (ans*fac[a]%p) * (quick_mod(fac[b]*fac[a-b]%p,p-2,p)) ) % p;
        n /= p;
        m /= p;
    }
    return ans;
}
