#include <iostream>
#include <string>
using namespace std;

int* bruteForceSearch(const string &text, const string &pattern, int &matchCount, int &comparisons) {
    int n = text.length();
    int m = pattern.length();

    matchCount = 0;
    comparisons = 0;

    int capacity = 5;
    int* indices = new int[capacity];

    for (int i = 0; i <= n - m; i++) {
        bool match = true;

        for (int j = 0; j < m; j++) {
            comparisons++;

            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            if (matchCount == capacity) {
                capacity *= 2;
                int *newArr = new int[capacity];

                for (int k = 0; k < matchCount; k++) {
                    newArr[k] = indices[k];
                }

                delete[] indices;
                indices = newArr;
            }

            indices[matchCount++] = i;
        }
    }

    return indices;
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    int matchCount = 0;
    int comparisons = 0;

    int *result = bruteForceSearch(text, pattern, matchCount, comparisons);

    cout << "Matches at indices: ";
    for (int i = 0; i < matchCount; i++) {
        cout << result[i] << " ";
    }

    cout << endl;
    cout << "Total Comparisons: " << comparisons << endl;

    delete[] result;

    return 0;
}
