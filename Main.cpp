#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define AL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define RPP(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

static auto __fast_io = [](){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return nullptr;}();

static constexpr int DX4[4] = {1, -1, 0, 0};
static constexpr int DY4[4] = {0, 0, 1, -1};
static constexpr int DX8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
static constexpr int DY8[8] = {1, 0, -1, 1, -1, 1, 0, -1};

ll GDC(ll a, ll b) { return b == 0 ? a : GDC(b, a % b); }
ll LCM(ll a, ll b) { return a / GDC(a,b) * b; }
ll MP(ll a, ll e, ll m) {
    ll r = 1;
    a %= m;
    while (e) {
        if (e & 1) r = (__int128)r * a % m;
        a = (__int128)a * a % m;
        e >>= 1;
    }
    return r;
}

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int _n): n(_n), p(n, -1), r(n, 0) { iota(AL(p), 0); }
    int FF(int x) { return p[x] == x ? x : p[x] = FF(p[x]); }
    bool UU(int a, int b) {
        a = FF(a); b = FF(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

struct FEN {
    int n;
    vector<ll> f;
    FEN(int _n): n(_n), f(n+1, 0) {}
    void UU(int i, ll v) {
        for (; i <= n; i += i & -i) f[i] += v;
    }
    ll QQ(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    ll RQ(int l, int r) { return QQ(r) - QQ(l-1); }
};

struct SEG {
    int n;
    vector<ll> st;
    SEG(int _n): n(_n), st(4*n, 0) {}
    void UU(int p, ll v) { UU(1, 0, n-1, p, v); }
    ll QQ(int l, int r) { return QQ(1, 0, n-1, l, r); }
private:
    void UU(int node, int L, int R, int p, ll v) {
        if (L == R) { st[node] = v; return; }
        int mid = (L+R)/2;
        if (p <= mid) UU(2*node, L, mid, p, v);
        else UU(2*node+1, mid+1, R, p, v);
        st[node] = st[2*node] + st[2*node+1];
    }
    ll QQ(int node, int L, int R, int i, int j) {
        if (j < L || R < i) return 0;
        if (i <= L && R <= j) return st[node];
        int mid = (L+R)/2;
        return QQ(2*node, L, mid, i, j)+ QQ(2*node+1, mid+1, R, i, j);
    }
};

void solve() {
    int n;
    cin >> n;
    string ans;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
