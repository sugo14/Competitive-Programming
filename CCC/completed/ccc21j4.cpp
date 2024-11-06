#include <bits/stdc++.h>
using namespace std;

string bookshelf;
int swaps = 0;
int lastLIndex, lastMIndex;
int lInS, mInS, sInL, mInL, sInM, lInM;

void count() {
    int l = 0, m = 0, s = 0;
    for (char c : bookshelf) {
        if (c == 'L') { l++; }
        if (c == 'M') { m++; }
        if (c == 'S') { s++; }
    }
    lastLIndex = l - 1;
    lastMIndex = lastLIndex + m;
    for (int i = 0; i < bookshelf.size(); i++) {
        char c = bookshelf[i];
        if (i > lastMIndex) {
            if (c == 'L') { lInS++; }
            if (c == 'M') { mInS++; }
        }
        else if (i <= lastLIndex) {
            if (c == 'S') { sInL++; }
            if (c == 'M') { mInL++; }
        }
        else {
            if (c == 'S') { sInM++; }
            if (c == 'L') { lInM++; }
        }
    }
}

int main() {
    cin >> bookshelf;
    count();
    while (lInS + mInS + sInL + mInL + sInM + lInM > 0) {
        /* optimal swaps */
        if (lInS > 0 && sInL > 0) {
            swaps++;
            lInS--, sInL--;
        }
        else if (mInS > 0 && sInM > 0) {
            swaps++;
            mInS--, sInM--;
        }
        else if (mInL > 0 && lInM > 0) {
            swaps++;
            mInL--, lInM--;
        }
        /* less optimal swaps */
        else if (sInL > 0 && mInS > 0) {
            swaps++;
            mInS--, sInL--, mInL++;
        }
        else if (sInM > 0 && lInS > 0) {
            swaps++;
            lInS--, sInM--, lInM++;
        }
        else if (lInM > 0 && sInL > 0) {
            swaps++;
            lInM--, sInL--, sInM++;
        }
        else if (lInS > 0 && mInL > 0) {
            swaps++;
            lInS--, mInL--, mInS++;
        }
        else if (mInL > 0 && sInM > 0) {
            swaps++;
            mInL--, sInM--, sInL++;
        }
    }
    cout << swaps << endl;
}
