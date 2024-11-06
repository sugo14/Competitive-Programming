#include <bits/stdc++.h>
using namespace std;

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z');
}
int letterToNum(char c) {
    return c - 'A';
}
char numToLetter(int n) {
    return (n % 26) + 'A';
}

int main() {
    string header, msg, encoded;
    getline(cin, header);
    getline(cin, msg);

    string temp;
    for (int i = 0; i < msg.size(); i++) {
        if (isLetter(msg[i])) {
            temp.push_back(msg[i]);
        }
    }
    msg = temp;

    for (int i = 0; i < msg.size(); i++) {
        int j = i % header.size();
        encoded.push_back(numToLetter(letterToNum(msg[i]) + letterToNum(header[j])));
    }

    cout << encoded << endl;
}
