#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define all1(x) x.begin(), x.end()
#define all2(x) x.rbegin(), x.rend()
#define pairs pair<int, int>
#define debug(v)                             \
    for (long long i = 0; i < v.size(); i++) \
        cout << v[i] << " ";                 \
    cout << endl;
#define debugP(v)                            \
    for (long long i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << endl;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define int long long

#define pi 3.14159265358979323846
#define endli "\n";

void init()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

bool prime[10000002];
vector<int> primess;
void func()
{
    memset(prime, true, sizeof(prime));
    int n = 1000000;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i < n; i += p)
                prime[i] = false;
    for (int i = 0; i < 1000000; i++)
    {
        if (prime[i])
            primess.pb(i);
    }
}

// Sieve

vector<int> sieveN(int n)
{
    vector<int> ans;

    while (n % 2 == 0)
    {
        ans.pb(2);
        n /= 2;
    }

    for (int i = 3; i < sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            ans.pb(i);
            n /= i;
        }
    }

    if (n > 2)
        ans.pb(n);

    return ans;
}

int ceil_div(int a, int b)
{
    return (a + b % 2 == 0 ? (a + b) / 2 : ((a + b) + 1) / 2);
}

int checkR(vector<int> &arr, int k) 
{
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] < k) l = mid + 1; // reducing left search space
        else r = mid - 1;
    }

    return l;
}

int checkL(vector<int> &arr, int k)
{
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] >= k) r = mid - 1; // reducing right search space
        else l = mid + 1;
    }

    return r;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> cities(n), towers(k);
    
    forn(i, n) cin >> cities[i];
    forn(i, k) cin >> towers[i];

    int miniAns = 0;

    for (int i = 0; i < n; i++)
    {
        int towersL = checkL(towers, cities[i]);
        int towersR = checkR(towers, cities[i]);

        int currMin = min(abs(cities[i] - towers[towersL]), abs(cities[i] - towers[towersR]));
        miniAns = max(miniAns, currMin);
    }

    cout << miniAns << endli;
}

signed main()
{
    fast
    init();
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}