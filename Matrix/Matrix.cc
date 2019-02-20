# include<cstdio>
# include<cstring>
using namespace std;
const int MAXN = 105, mod = 1e9+7;
typedef long long LL;
struct Matrix//矩阵的类
{
    LL a[MAXN][MAXN];

    void init()           //将其初始化为单位矩阵
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < MAXN; i++)
            a[i][i] = 1;
    }
};

Matrix mul(Matrix x, Matrix y) {
    Matrix ret;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            ret.a[i][j] = 0;
            for (int k = 0; k < MAXN; k++) {
                ret.a[i][j] += x.a[i][k] * y.a[k][j] % mod;
                ret.a[i][j] %= mod;
            }
        }
    }
    return ret;
}

Matrix pow(Matrix a,LL n)    //(a^n)%mod  //矩阵快速幂
{
    Matrix ans;
    ans.init();
    while (n > 0) {
        if (n & 1)//n&1
            ans = mul(ans, a);
        n >>= 1;
        a = mul(a, a);
    }
    return ans;
}

Matrix add(Matrix x,Matrix y)  //(a+b)%mod  //矩阵加法
{
    int i, j, k;
    Matrix ans;
    for (i = 0; i < MAXN; i++)
        for (j = 0; j < MAXN; j++) {
            ans.a[i][j] = x.a[i][j] + y.a[i][j];
            ans.a[i][j] %= mod;
        }
    return ans;
}

Matrix sum(Matrix a,int n)  //(a+a^2+a^3....+a^n)%mod// 矩阵的幂和
{
    int m;
    Matrix ans, pre;
    if (n == 1)
        return a;
    m = n / 2;
    pre = sum(a, m);                      //[1,n/2]
    ans = add(pre, mul(pre, pow(a, m)));   //ans=[1,n/2]+a^(n/2)*[1,n/2]
    if (n & 1)
        ans = add(ans, pow(a, n));          //ans=ans+a^n
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    Matrix ans,A;
    return 0;
}

