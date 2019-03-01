using namespace std;
typedef long long LL;
struct FastReader {
    inline int Int() {int ch,nag=0,x=0;while(!isdigit(ch=getchar()))nag=ch=='-';x=ch-'0';while(isdigit(ch=getchar()))x=x*10+ch-'0';return nag?-x:x;}
    inline LL Long() {LL ch,nag=0,x=0;while(!isdigit(ch=getchar()))nag=ch=='-';x=ch-'0';while(isdigit(ch=getchar()))x=x*10+ch-'0';return nag?-x:x;}
    inline LL Mod(LL P) {LL ch,nag=0,x=0;while(!isdigit(ch=getchar()))nag=ch=='-';x=(ch-'0')%P;while(isdigit(ch=getchar()))(x=x*10+ch-'0')%=P;return nag?-x:x;}
    inline long double Double() {LL a=Int(),b=0,c=1,ch;while(isdigit(ch=getchar()))b=b*10+ch-'0',ch*=10;return a+1.*b/c;}
    inline LL DoubleInt(LL bs=-1) {LL a=Int(),b=0,c=1,ch;while(isdigit(ch=getchar()))b=b*10+ch-'0',ch*=10;return bs==-1?a*c+b:a*bs+b;}
    inline char Alpha() {char ch;while(!isalpha(ch=getchar()));return ch;}
    inline char Char() {char ch; while( isspace(ch=getchar()));return ch;}
    inline char Digit() {char ch;while(!isdigit(ch=getchar()));return ch;}
    inline int CStr(char*c) {scanf("%s",c);return strlen(c);}
    inline int Str(string&s,int len=3000) {char buf[len];int l=CStr(buf);s=buf;return l;}
    inline LL operator()() { return Long(); }
    inline int operator()(char*c) { return CStr(c); }
    inline int operator()(string&s,int len=3000) { return Str(s,len); }
} read;
struct FastWriter {
    inline FastWriter& Int(LL x) {if(x<0){putchar('-');return Int(-x);}if(x/10)Int(x/10);putchar(x%10+'0');return *this;}
    inline FastWriter& Char(char x) {putchar(x);return *this;}
    inline FastWriter& Str(const char*x) {printf("%s",x);return *this;}
    inline FastWriter& StrE(const char*x) {puts(x);return *this;}
    inline FastWriter& Eoln() {putchar('\n');return *this;}
    inline FastWriter& operator()(int x) { return Int(x); }
    inline FastWriter& operator()(char x) { return Char(x); }
    inline FastWriter& operator()(LL x) { return Int(x); }
    inline FastWriter& operator()(const char*x) { return Str(x); }
} write;
