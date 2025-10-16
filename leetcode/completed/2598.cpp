#include <bits/stdc++.h>
using namespace std;

int acc[100001];

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        fill(acc, acc + value, 0);
        int minIdx = 0;

        for (int i = 0; i < nums.size(); i++) { acc[(nums[i] % value + value) % value]++; }
        for (int i = 0; i < value; i++) { minIdx = (acc[i] < acc[minIdx]) ? i : minIdx; }
        return value * acc[minIdx] + minIdx;
    }
};
