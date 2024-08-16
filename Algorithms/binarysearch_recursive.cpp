#include <bits/stdc++.h>

using namespace std;

int bs(int a[], int l, int r, int x, int mid = 0){
    if(l <= r){
        mid = (l + r)/2;
        if(a[mid] == x) return mid;

        if(a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;

        return bs(a, l, r, x);
    }
    return -1;
}

int main(){
    int a[] = {2, 2, 3, 4, 5, 5, 5, 7};
    cout << bs(a, 0, 7, 7);
}