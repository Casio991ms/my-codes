#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 200005

LL a[MAXN], b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    
    ans = 0;
    for(i = n-1; i >= 0; i--)
    {
        a[i] += ans;

        ans += (a[i] + b[i] - 1)/b[i]*b[i] - a[i];
    }

    cout << ans << "\n";
}