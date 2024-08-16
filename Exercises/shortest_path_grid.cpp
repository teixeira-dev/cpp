#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>> grid{{1, 1, 1, 1},
                             {1, 1, 0, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0},
                             {1, 0, 0, 1}};

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 1}, 0});
    vis[0][1]++;

    int row, col, dist;
    while(!q.empty()){
        row = q.front().first.first;
        col = q.front().first.second;
        dist = q.front().second;
        q.pop();

        if(row == 4 && col == 0){
            cout << dist << endl;
            break;
        }

        for(auto it: {-1, 1}){
            if(row + it < n && row + it >= 0 && !vis[row + it][col] && grid[row + it][col]){
                vis[row + it][col]++;
                q.push({{row + it, col}, dist + 1});
            }
            if(col + it < m && col + it >= 0 && !vis[row][col + it] && grid[row][col + it]){
                vis[row][col + it]++;
                q.push({{row, col + it}, dist + 1});
            }
        }
        if(q.empty())
            cout << -1 << endl;
    }
}