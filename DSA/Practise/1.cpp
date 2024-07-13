#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void compute_f_and_g(int n, int m, int k, vector<int>& permutation) {
    vector<int> f(n); // f[i] stores the value of f(i)
    vector<int> g(n); // g[i] stores the value of g(i)

    // Sort permutation in descending order
    sort(permutation.begin(), permutation.end(), greater<int>());

    for (int i = 0; i < n; ++i) {
        f[i] = permutation[i]; // f(i) is the ith element in sorted permutation

        if (permutation[i] >= k) {
            g[i] = 0; // g(i) is 0 if permutation[i] >= k
        } else {
            g[i] = m; // g(i) is m if permutation[i] < k

            // Calculate sum of all g(j) where j < i and permutation[j] <= m
            for (int j = 0; j < i; ++j) {
                if (permutation[j] <= m) {
                    g[i] += g[j];
                }
            }
        }
    }

    // Output results for this test case
    for (int i = 0; i < n; ++i) {
        cout << f[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << g[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int t; // number of test cases
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> permutation(n);
        for (int i = 0; i < n; ++i) {
            cin >> permutation[i];
        }

        compute_f_and_g(n, m, k, permutation);
    }

    return 0;
}
