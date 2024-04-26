// https://vjudge.net/problem/CSES-1666

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

vector<vector<ll>> adj;
vector<bool> visited;
vector<vector<ll>> comps;


void DFS(ll u, vector<ll> &comp) {
    visited[u] = true;
    comp.push_back(u);
    for (ll v: adj[u]) {
        if (!visited[v])
            DFS(v, comp);
    }
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    adj.resize(n + 1, vector<ll>());
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<ll> comp;
            DFS(i, comp);
            comps.push_back(comp);
        }
    }

    cout << comps.size() - 1 << '\n';

    for (int i = 0; i < comps.size() - 1; ++i) {
        cout << comps[i][0] << " " << comps[i + 1][0] << '\n';
    }

    return 0;
}
