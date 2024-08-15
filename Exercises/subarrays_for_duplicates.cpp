#include <bits/stdc++.h>

using namespace std;

void unique_subarrays(vector<int> a, vector<int> b, int i = 0){
    for(auto it: b) cout << it << " ";
    cout << endl;
    for(int ind = i; ind < a.size(); ind++){
        if(ind > i && a[ind] == a[ind - 1]) continue;
        b.push_back(a[ind]);
        unique_subarrays(a, b, ind + 1);
        b.pop_back();
    }
}

int main(){
    /* This program prints every unique subarray from an array that
    contains duplicates using recursion. */
    
    vector<int> a{1, 2, 4, 4, 5, 5, 5};
    sort(a.begin(), a.end());
    vector<int> b;
    unique_subarrays(a, b);

}