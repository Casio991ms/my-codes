#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll arr[MAXN];
ll L[MAXN], R[MAXN];

void solve(ll caseno)
{
    ll n, i, l, r;
    vector<ll> ans;

    cin >> n;

    for(i = 0; i <= n; i++)
        arr[i] = 0;

    for(i = 1; i <= n; i++)
    {
        cin >> L[i] >> R[i];
        arr[L[i]]++;
        arr[R[i]+1]--;
    }

    for(i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
        if(arr[i] == n-1 && (i < L[i] || R[i] < i))
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}