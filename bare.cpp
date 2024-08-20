#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> change, int m, vector<int> arr) {
    int l = 0, r = n+1;
    while (l < r) {
        int mid = (l + r) / 2;
        map<int,int> last_pos;
        for (int i = 0; i < mid; i++) {
            if (change[i]) last_pos[change[i] - 1] = i;
        }
        vector<pair<int,int>> q;
        for (auto it : last_pos) {
            q.push_back({it.second, it.first});
        }
        sort(q.begin(), q.end());
        bool success = mid > 0;
        for (int i = 0; i < mid;i++) {
            if (i != q.back().first) {
                if (arr[q.back().second] > 0) arr[q.back().second]--;
                else {
                    q.pop_back();
                }
            }
            else {
                if (arr[q.back().second] > 0) {
                    success = false;
                    break;
                }
                else {
                    q.pop_back();
                }
            }
        }    
        if (success) r = mid;
        else {
            if (l == n) return -1;
            l = mid + 1;    
        }
    }
    return l;
}

int main() {
    
}