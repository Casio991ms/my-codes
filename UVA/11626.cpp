#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define ff first
#define ss second

ll n;
vector<pii> v;

bool cmp(pii a, pii b)
{
    return a.ff < b.ff || (a.ff == b.ff && a.ss < b.ss);
}

bool clockWise(pii a, pii b, pii c)
{
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) <= 0;
}

bool antiClockWise(pii a, pii b, pii c)
{
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) >= 0;
}

void convex_hull()
{
    if(v.size() == 1)
        return;

    sort(v.begin(), v.end(), cmp);

    pii p1 = v[0], p2 = v.back();

    vector<pii> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for (ll i = 1; i < (ll)v.size(); i++)
    {
        if (i == v.size() - 1 || clockWise(p1, v[i], p2))
        {
            while (up.size() >= 2 && !clockWise(up[up.size()-2], up[up.size()-1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || antiClockWise(p1, v[i], p2))
        {
            while(down.size() >= 2 && !antiClockWise(down[down.size()-2], down[down.size()-1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }

    v.clear();
    for (ll i = 0; i < (ll)down.size(); i++)
        v.push_back(down[i]);
    for (ll i = up.size() - 2; i > 0; i--)
        v.push_back(up[i]);
}

int main()
{
    ll t, i, x, y;
    string c;

    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> x >> y >> c;
            if(c == "Y")
                v.push_back({x, y});
        }

        convex_hull();

        cout << v.size() << "\n";
        for(auto u : v)
            cout << u.ff << " " << u.ss << "\n";
    }
}
