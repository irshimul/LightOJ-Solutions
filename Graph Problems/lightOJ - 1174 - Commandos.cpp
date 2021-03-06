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
#define MEM(array, value) memset(array, value, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)



template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d, s;

int main()
{
    ios_base::sync_with_stdio(false);
    si(t);
    while(t--){

            sii(n, m);
            vector< vector<int> >ar(n, vector<int>(n, INF));
            for(int i=0; i<n; ++i)
                ar[i][i] = 0;

            while(m--){

                    sii(a, b);
                    ar[a][b] = 1;
                    ar[b][a] = 1;
            }

            sii(s, d);

            //Floyd Warshall
            for(int k=0; k<n; ++k)
                for(int i=0; i<n; ++i)
                    for(int j=0; j<n; ++j)
                        ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);


            int minTime = 0;
            for(int i=0; i<n; ++i)

                    if(ar[s][i] != INF  &&  ar[i][d] != INF)

                            minTime = max(minTime, ar[s][i] + ar[i][d]);

            printf("Case %d: %d\n", ++caseno, minTime);
    }
    return 0;
}
