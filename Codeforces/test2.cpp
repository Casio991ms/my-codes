#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll a[MAXN];
vector<ll> adj[MAXN];

void call(ll node, ll pr)
{
	
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, x, y;

    cin >> n; 

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i < n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}