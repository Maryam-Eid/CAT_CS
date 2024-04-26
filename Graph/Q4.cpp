// https://vjudge.net/problem/CodeForces-292B

// bus: exactly two nodes with degree 1 & all other nodes have degree 2.
// ring: all nodes have degree 2
// star: if one node has degree n−1 and all other nodes have degree 1
// unknown: none of the above

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> degree;

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    degree.assign(n + 1, 0);


    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    ll d1 = 0, d2 = 0, dn = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) d1++;
        if (degree[i] == 2) d2++;
        if (degree[i] == n - 1) dn++;
    }

    if (d1 == 2 && d2 == n - 2) {
        cout << "bus topology" << '\n';
        return 0;
    }

    if (d2 == n) {
        cout << "ring topology" << '\n';
        return 0;
    }

    if (d1 == n - 1 && dn == 1) {
        cout << "star topology" << '\n';
        return 0;
    }

    cout << "unknown topology" << '\n';


    return 0;
}
