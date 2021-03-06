#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ll long long
#define FOR(i, k, n) for(int i=(int) k ; i<(int)n; ++i)
#define REP(i, n) for(int i=0; i<n; ++i)
#define MEM(array) memset(array, -1, sizeof(array))
#define CLR(array) memset(array, 0, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define TIME(a) printf("Time %d\n", clock() - a)



template <class T> inline T imax(T &a,T b){if(b>a) a=b;}
template <class T> inline T imin(T &a,T b){if(b<a) a=b;}

const int MAX = 1e5 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, m, caseno = 0, a, b, c, d, p, q, n;
//string s;
char s[MAX];
int ar[MAX];
int bit[MAX];

void update(int idx, int val)
{
  while(idx <= n){
    bit[idx] ^= val;
    idx += idx & -idx;
  }
}

int sum(int idx)
{
  int ret = 0;
  while(idx > 0){
    ret ^= bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    si(t);
    while(t--){
      scanf("%s", s);
      n = strlen(s);
      REP(i, n) ar[i] = s[i] - '0';

      si(q);
      CLR(bit);
      printf("Case %d:\n", ++caseno);

      while(q--){
        char pic;
        getchar();
        scanf("%c", &pic);;
        if(pic == 'I'){
          sii(a, b);
          update(a, 1);
          update(b+1, 1);
        }
        else{
          si(a);
          printf("%d\n", ar[a-1] ^ (sum(a) & 1));
        }
      }
    }

    return 0;
}
