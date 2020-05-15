/*
 * https://github.com/stefdasca/CompetitiveProgramming/blob/master/Infoarena/pitici3.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , d , all ;
pi a [2009] ;
int dp [2009][2009] ;
bool cmp ( pi x , pi y ) {
	return ( x .fi + x .se ) < ( y .fi + y .se ) ; 
}
int main () {
	ifstream fin ( "pitici3.in" ) ;
	ofstream fout( "pitici3.out") ; 
	fin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ) fin >> a [i] .fi >> a [i] .se , all += a[i] .fi ;
	fin >> d ;
	sort ( a + 1 , a + n + 1 , cmp ) ;
	int ans = 0 ; 
	for ( int i = 0 ; i <= n ; i ++ ) {
		for ( int j = 0 ; j <= n ; j ++ ) {
			dp [i][j] = -1e9 ; 
		}
	}
	for ( int i = 0 ; i <= n ; i ++ ) {
		dp [i][0] = all ; 
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= i ; j ++ ) {
			dp [i][j] = dp [i-1][j] ;
		       	if ( dp [i-1][j-1] + a [i] .se >= d ) {
				dp [i][j] = max ( dp [i][j] , dp [i-1][j-1] - a[i] .fi ) ;
				ans = max ( ans , j ) ; 
			}
		}
	}
	fout << ans << endl ; 
}
