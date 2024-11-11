#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> Primes() {
        vector<int> primes;
        for (int i = 2; i <= 1000; i++) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) { primes.push_back(i); }
        }
        return primes;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = Primes();
        for (int i = 0; i < nums.size(); i++) {
            float bestSubtraction = 0;
            for (int j = 0; j < primes.size(); j++) {
                if (nums[i] - primes[j] <= (i == 0 ? 0 : nums[i - 1])) { break; }
                bestSubtraction = primes[j];
            }
            nums[i] -= bestSubtraction;
            if (i > 0 && nums[i] <= nums[i - 1]) { return false; }
        }
        return true;
    }
};
