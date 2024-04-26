// https://vjudge.net/problem/SPOJ-PT07Y

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void DFS(vector<vector<ll>> &adj, vector<bool> &visited, ll u) {
    visited[u] = true;
    for (ll v: adj[u]) {
        if (!visited[v])
            DFS(adj, visited, v);
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

    if (m != n - 1) {
        cout << "NO";
        return 0;
    }


    vector<vector<ll>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    ll connected = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            connected++;
            DFS(adj, visited, i);
        }
    }

    if (connected == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
