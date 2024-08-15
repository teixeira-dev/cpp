#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a[10];
    a[1] = {2, 6};
    a[2] = {1, 3, 4};
    a[3] = {2};
    a[4] = {2, 5};
    a[5] = {4, 8};
    a[6] = {1, 7, 9};
    a[7] = {6, 8};
    a[8] = {7, 5};
    a[9] = {6};

    int vis[10] = {0};
    int level[10] = {0};

    queue<int> q;
    q.push(1);
    vis[1]++;
    
    int front, current;
    current = 0;
    string s = "";
    while(!q.empty()){

        front = q.front();
        q.pop();

        if(level[front] != current){
            current = level[front];
            cout << endl;
            s = "";
        }

        cout << s << front;
        s = " ";

        for(auto it: a[front]){
            if(vis[it]) continue;
            vis[it]++;
            level[it] = current + 1;
            q.push(it);
        }
    }
}