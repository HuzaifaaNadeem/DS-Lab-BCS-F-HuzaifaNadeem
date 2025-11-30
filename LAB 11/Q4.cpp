#include <iostream>
#include <string>
using namespace std;

void buildLPS(const string &pat, int *lps) {
    int m = pat.length();
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int* kmp(const string &text, const string &pat, int &matchCount) {
    int n = text.length();
    int m = pat.length();

    int *lps = new int[m];
    buildLPS(pat, lps);

    cout << "LPS Array: ";
    for(int i = 0; i < m; i++) cout << lps[i] << " ";
    cout << endl;

    int cap = 5;
    int *matches = new int[cap];
    matchCount = 0;

    int i = 0, j = 0;
    while(i < n) {
        if(text[i] == pat[j]) {
            i++; j++;
        }

        if(j == m) {
            if(matchCount == cap) {
                cap *= 2;
                int *newArr = new int[cap];
                for(int k = 0; k < matchCount; k++) newArr[k] = matches[k];
                delete[] matches;
                matches = newArr;
            }
            matches[matchCount++] = i - j;
            j = lps[j - 1];
        }
        else if(i < n && text[i] != pat[j]) {
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }

    delete[] lps;
    return matches;
}

int main() {
    string text = "ababababc";
    string pat = "abab";

    int count = 0;
    int *result = kmp(text, pat, count);

    cout << "Matches found at positions: ";
    for(int i = 0; i < count; i++) cout << result[i] << " ";
    cout << endl;

    delete[] result;
    return 0;
}
