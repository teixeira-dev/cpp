#include <bits/stdc++.h>

using namespace std;

int lower_bound(vector<int> a, int l, int r, int x){
    int mid, ans = r + 1;
    while(l <= r){
        mid = (l + r)/2;
        if(a[mid] >= x){
            ans = mid;
            r = mid - 1;
        }else
            l = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> a{1, 3, 3, 3, 3, 3, 5, 5, 6, 6, 6};
    cout << lower_bound(a, 0, 10, 3);
}