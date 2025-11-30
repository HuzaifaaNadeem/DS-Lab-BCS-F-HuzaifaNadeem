#include <iostream>
#include <string>
using namespace std;

void buildBadChar(const string& pat, int badChar[]) {
    for(int i=0;i<256;i++) badChar[i] = -1;
    for(int i=0;i<pat.length();i++) badChar[(unsigned char)pat[i]] = i;
}

void buildGoodSuffix(const string& pat,int* goodSuffix) {
    int m = pat.length();
    int* suffix = new int[m];
    for(int i=0;i<m;i++) suffix[i] = -1;
    suffix[m-1] = m;

    int f = 0, g = m-1;
    for(int i=m-2;i>=0;i--) {
        if(i > g && suffix[i + m - 1 - f] < i - g) suffix[i] = suffix[i + m - 1 - f];
        else {
            if(i < g) g = i;
            f = i;
            while(g>=0 && pat[g] == pat[g + m - 1 - f]) g--;
            suffix[i] = f - g;
        }
    }

    for(int i=0;i<m;i++) goodSuffix[i] = m;
    int j = 0;
    for(int i=m-1;i>=-1;i--) {
        if(i==-1 || suffix[i]==i+1) {
            for(; j<m-1-i; j++)
                if(goodSuffix[j] == m) goodSuffix[j] = m-1-i;
        }
    }
    for(int i=0;i<=m-2;i++) goodSuffix[m-1 - suffix[i]] = m-1 - i;

    delete[] suffix;
}

int* boyerMoore(const string& text,const string& pat,int& matchCount){
    int n = text.length(), m = pat.length();
    matchCount = 0;

    int* badShift = new int[256];
    buildBadChar(pat,badShift);

    int* goodShift = new int[m];
    buildGoodSuffix(pat,goodShift);

    int cap = 5;
    int* matches = new int[cap];

    int s = 0;
    while(s <= n - m){
        int j = m - 1;
        while(j >= 0 && pat[j] == text[s+j]) j--;

        if(j < 0){
            if(matchCount == cap){
                cap *= 2;
                int* newArr = new int[cap];
                for(int k=0;k<matchCount;k++) newArr[k] = matches[k];
                delete[] matches;
                matches = newArr;
            }
            matches[matchCount++] = s;
            s += goodShift[0];
        } 
        else {
            int bad = j - badShift[(unsigned char)text[s+j]];
            int good = goodShift[j];
            s += (bad > good ? bad : good);
        }
    }

    delete[] badShift;
    delete[] goodShift;
    return matches;
}

int main(){
    string dna = "ACGTACGTGACG";
    string pat = "ACG";

    int matchCount = 0;
    int* result = boyerMoore(dna,pat,matchCount);

    cout<<"Matches at positions: ";
    for(int i=0;i<matchCount;i++) cout<<result[i]<<" ";
    cout<<endl;

    delete[] result;
    return 0;
}
