// https://vjudge.net/problem/CSES-1192

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void DFS(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#')
        return;

    grid[x][y] = '#';
    DFS(grid, x + 1, y);
    DFS(grid, x - 1, y);
    DFS(grid, x, y + 1);
    DFS(grid, x, y - 1);
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    ll r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                DFS(grid, i, j);
                r++;
            }
        }
    }

    cout << r << '\n';


    return 0;
}
