#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][ j - 1]);
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    int l = L[m][n];
    cout << "Length of LCS of " << X << " and " << Y << ": " << l << endl;
    char lcs[l + 1];
    lcs[l] = '\0';
    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[l - 1] = X[i - 1];
            i--;
            j--;
            l--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "LCS: " << lcs << endl;
}
int main() {
    char X[] = "BHDAFG";
    char Y[] = "ABCDEFH";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
    return 0;
}
