#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> a[6];
    a[0] = {{1, 4}, {2, 4}};
    a[1] = {{0, 4}, {2, 2}};
    a[2] = {{0, 4}, {1, 2}, {3, 3}, {5, 6}, {4, 1}};
    a[3] = {{2, 3}, {5, 2}};
    a[4] = {{2, 1}, {5, 3}};
    a[5] = {{3, 2}, {2, 6}, {4, 3}};

    int dist[6];
    fill(begin(dist), end(dist), INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[0], 0});
    
    int front, dis;
    while(!pq.empty()){
        front = pq.top().second;
        dis = pq.top().first;
        pq.pop();
        if(dist[front] != dis) continue;
        for(auto it: a[front]){
            if(dis + it.second < dist[it.first]){
                dist[it.first] = dis + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    for(int i = 0; i < 6; i++)
        cout << i << ": > " << dist[i] << endl;
}