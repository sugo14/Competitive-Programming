#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isLower(char c) { return c >= 'a' && c <= 'z'; }
    bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
    bool isDigit(char c) { return c >= '0' && c <= '9'; }
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> s;
        s.push(map<string, int>());
        for (int i = 0; i < formula.size(); i++) {
            char c = formula[i];
            if (c == '(') {
                s.push(map<string, int>());
            }
            else if (c == ')') {
                // get number after
                int n = 0;
                while (i + 1 < formula.size() && isDigit(formula[i + 1])) {
                    n *= 10;
                    n += formula[i + 1] - '0';
                    i++;
                }
                if (n == 0) { n = 1; }
                cout << "number found: " << n << ", state: ";
                for (pair<string, int> p : s.top()) {
                    cout << p.first << " " << p.second <<  ", ";
                }
                cout << endl;
                // multiply
                map<string, int> temp = s.top();
                for (auto& p : temp) {
                    p.second *= n;
                }
                // remove from top of stack
                s.pop();
                for (pair<string, int> p : temp) {
                    s.top()[p.first] += p.second;
                }
            }
            else {
                // get element
                string currElement = "";
                currElement.push_back(c);
                while (i + 1 < formula.size() && isLower(formula[i + 1])) {
                    currElement.push_back(formula[i + 1]);
                    i++;
                }
                // get number
                int currNumber = 0;
                while (i + 1 < formula.size() && isDigit(formula[i + 1])) {
                    currNumber *= 10;
                    currNumber += formula[i + 1] - '0';
                    i++;
                }
                if (currNumber == 0) { currNumber = 1; }
                // add to top of stack
                s.top()[currElement] += currNumber;
            }
        }
        // create string
        string ans = "";
        for (pair<string, int> p : s.top()) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string formula = "K4(ON(SO3)2)2";
    cout << s.countOfAtoms(formula) << endl;
    return 0;
}
