#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> largestK;
    vector<int>& _nums;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) : _nums(nums), _k(k) {
        for (int num : nums) { add(num); }
    }
    
    int add(int val) {
        if (largestK.size() < _k) { largestK.push(val); }
        else if (val > largestK.top()) {
            largestK.pop();
            largestK.push(val);
        }
        return largestK.top();
    }
};
