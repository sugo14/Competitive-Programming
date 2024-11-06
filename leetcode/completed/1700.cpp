#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> students2 = deque<int>(students.begin(), students.end());
        int x = 0;
        for (int i = 0; i < sandwiches.size(); i++) {
            while (true) {
                if (students2.front() == sandwiches[i]) {
                    students2.pop_front();
                    x = 0;
                    break;
                }
                else {
                    int temp = students2.front();
                    students2.pop_front();
                    students2.push_back(temp);
                    x++;
                }
                if (x >= students2.size()) {
                    return students2.size();
                }
            }
        }
        return students2.size();
    }
};
