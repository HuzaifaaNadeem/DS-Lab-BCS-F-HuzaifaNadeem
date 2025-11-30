#include <iostream>
#include <string>
using namespace std;

int* rabinKarp(const string &text,const string &pattern,int &matchCount,int &falsePositives){
    int n=text.length(),m=pattern.length();
    const int base=256,mod=101;
    matchCount=0; falsePositives=0;
    int capacity=5;
    int* matches=new int[capacity];

    long long patternHash=0,textHash=0,h=1;
    for(int i=0;i<m-1;i++) h=(h*base)%mod;

    for(int i=0;i<m;i++){
        patternHash=(base*patternHash+pattern[i])%mod;
        textHash=(base*textHash+text[i])%mod;
    }

    for(int i=0;i<=n-m;i++){
        if(patternHash==textHash){
            bool ok=true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){ ok=false; break; }
            }
            if(ok){
                if(matchCount==capacity){
                    capacity*=2;
                    int* newArr=new int[capacity];
                    for(int k=0;k<matchCount;k++) newArr[k]=matches[k];
                    delete[] matches;
                    matches=newArr;
                }
                matches[matchCount++]=i;
            } else {
                falsePositives++;
                cout<<"False positive hash match at index "<<i<<endl;
            }
        }
        if(i<n-m){
            textHash=(base*(textHash-text[i]*h)+text[i+m])%mod;
            if(textHash<0) textHash+=mod;
        }
    }
    return matches;
}

int main(){
    string text="Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern="Algorithms";
    int matchCount=0,falsePositives=0;

    int* result=rabinKarp(text,pattern,matchCount,falsePositives);

    cout<<"Matches found at positions: ";
    for(int i=0;i<matchCount;i++) cout<<result[i]<<" ";
    cout<<endl;
    cout<<"False positives due to hash collision: "<<falsePositives<<endl;

    delete[] result;
    return 0;
}
