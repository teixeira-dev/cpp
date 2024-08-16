#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> a[6];
    a[1] = {{2, 2}, {4, 1}};
    a[2] = {{1, 2}, {3, 4}, {5, 5}};
    a[3] = {{4, 3}, {2, 4}, {5, 1}};
    a[4] = {{1, 1}, {3, 3}};
    a[5] = {{2, 5}, {3, 1}};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    int dist[6];
    int path[5] = {0};

    fill(begin(dist), end(dist), INT_MAX);

    dist[1] = 0;
    pq.push({dist[1], 1});

    int dis, front;
    while(!pq.empty()){
        front = pq.top().second;
        dis = pq.top().first;
        pq.pop();

        if(dist[front] != dis) continue;
        for(auto it: a[front]){
            if(dis + it.second < dist[it.first]){
                path[it.first] = front;
                dist[it.first] = dis + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    int first = 5;
    
    do{
        cout << first << " ";
        first = path[first];
    }while(first != 0);

}