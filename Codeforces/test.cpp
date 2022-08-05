#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e5+7;
const LL INF = 1e18+7;
PII tr[4*N];

void update(int u, int st, int en, int idx, int val, int id) {
    if (st==en)     tr[u] = {val, id};
    else {
        int mid = (st+en)/2;
        if (idx<=mid)   update(2*u, st, mid, idx, val, id);
        else            update(2*u+1, mid+1, en, idx, val, id);
        tr[u] = max(tr[2*u], tr[2*u+1]);
    }
}

PII query(int u, int st, int en, int l, int r)
{
    if (en<l || r<st)   return {0, 0};
    else if (l<=st && en<=r)    return tr[u];
    else {
        int mid = (st+en)/2;
        return max(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}

LL h[N];
map<LL, int> id;

int dp[N], prv[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin>>n>>d;

    for (int i=1; i<=n; i++) {
        cin>>h[i];
        id[h[i]] = 0;
    }

    int cnt = 0;
    for (auto &pr: id)   pr.second = ++cnt;
    id[-INF] = 0;
    id[INF] = 1 + cnt;

    for (int i=1; i<=n; i++) {
        int k = id[h[i]];
        int l = (--id.upper_bound(h[i]-d))->second;
        int r = id.lower_bound(h[i]+d)->second;

        PII pr = {0, 0};
        if (l>0)  pr = max(pr, query(1,1,n,1,l));
        if (r<=n) pr = max(pr, query(1,1,n,r,n));

        dp[i] = 1 + pr.first;
        prv[i] = pr.second;

        update(1,1,n,k,dp[i],i);

//        cout<<"---->"<<k<<" "<<l<<" "<<r<<endl;
//        cout<<i<<" "<<dp[i]<<" "<<prv[i]<<endl;
    }

    int ans = 0, id = -1;
    for (int i=1; i<=n; i++)
        if (dp[i] > ans)
            ans = dp[i], id = i;

    vector<int> v;
    while (id)  v.push_back(id), id = prv[id];
    reverse(v.begin(), v.end());

    cout<<ans<<endl;
    for (auto i: v) cout<<i<<" ";
}
