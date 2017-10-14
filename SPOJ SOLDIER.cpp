/*#include <bits/stdc++.h>
using namespace std;
bool items[7];
int n,t,arr[102],p[102],q[102],memo[102][2000],lastQ[102],lastP[102];
set<int> check;
int dp(int i,int m){
    if(m < 0)
        return 0;
    if(i==n)
        return 1e6;
    int &ret = memo[i][m];
    if(ret != -1)
        return ret;
    ret = 1e6;
    if(items[arr[i]]){
            if(q[i] > lastQ[arr[i]] || (q[i] == lastQ[arr[i]] && lastP[arr[i]] > p[i])){
                lastQ[arr[i]] = q[i];
                int tmp = lastP[arr[i]];
                lastP[arr[i]] = p[i];
                ret = min(q[i] , dp(i+1,m+tmp-p[i]));
            }
            else
                ret = min(ret , dp(i+1,m));
        }
    else{
        lastQ[arr[i]] = q[i];
        lastP[arr[i]] = p[i];
        items[arr[i]] = 1;
        ret = min(q[i] , dp(i+1,m-p[i]));
        items[arr[i]] = 0;
        ret = min(ret,dp(i+1,m));
    }


    return ret;
}
int main()
{
   cin >> n >> t;
   for(int i=0; i<n; i++)
   {
       cin >> arr[i] >> p[i] >> q[i];
       check.insert(arr[i]);
   }
   if(check.size() != 6)
   {
       cout << 0;
       return 0;
   }
   memset(memo,-1,sizeof memo);
   cout << dp(0,t);
}
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;

int dp[7][1001];
vector< pii > G[7];

int solve(int item, int money) {
	if(money < 0) return 0;
	if(item > 6) return 0x3f3f3f3f;
	if(dp[item][money]!=-1) return dp[item][money];
	int& ret = dp[item][money];
	ret = 0;
	for(unsigned i = 0; i < G[item].size(); i++)
		if(money >= G[item][i].first)
			ret = max(ret, min(G[item][i].second, solve(item+1, money - G[item][i].first)));
	return ret;
}

int main() {
	int n, t, i, p, q, r;
	scanf("%d%d", &n, &t);
	memset(dp, -1, sizeof dp);
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &p, &q, &r);
		G[p].push_back(pii(q, r));
	}
	printf("%d\n", solve(1, t));
	return 0;
}
