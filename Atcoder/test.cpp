#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    string s = "BGGRR";

    do
    {
        cnt = 0;
        cnt += (s.substr(0, 2) == "RG");
        cnt += (s.substr(1, 2) == "RG");
        cnt += (s.substr(2, 2) == "RG");
        cnt += (s.substr(3, 2) == "RG");

        cout << s << "\t" << cnt << "\n";

    }while(next_permutation(s.begin(), s.end()));
}