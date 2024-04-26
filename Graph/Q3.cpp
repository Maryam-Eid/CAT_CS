// https://vjudge.net/problem/UVA-10608


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

typedef long long ll;

void DFS(ll u, ll &count) {
    visited[u] = true;
    count++;
    for (ll v: adj[u]) {
        if (!visited[v])
            DFS(v, count);
    }
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);

        for (int i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll ma = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                ll count = 0;
                DFS(i, count);
                ma = max(ma, count);
            }
        }

        cout << ma << '\n';
    }

    return 0;
}
