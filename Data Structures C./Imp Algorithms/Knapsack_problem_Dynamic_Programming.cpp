#include <iostream>
#include <vector>
using namespace std;

void solveKnapsack(vector<vector<int>>& v, int m, int n, vector<int>& profits, vector<int>& weights) {
    int w, i;
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= m; w++) {
            if (weights[i] > w)
                v[i][w] = v[i - 1][w];
            else
                v[i][w] = max(v[i - 1][w], v[i - 1][w - weights[i]] + profits[i]);
        }
    }
    int maxProfit = v[n][m];
    cout << "The maximum profit obtained is " << maxProfit << endl;

    int temp = maxProfit, j;
    i = n;
    w = m;
    cout<<"Selected items: "<<endl;
    while (temp > 0 && i > 0 && w > 0) {
        if (v[i][w] != v[i - 1][w]) {
          cout << "Item:  "<<i << ", ";
          temp -= profits[i];
          w -= weights[i];
        }
        i--;
    }
}

int main() {
    int m, n, i;
    cout << "Enter the number of items" << endl;
    cin >> n;
    cout << "Enter the capacity of knapsack" << endl;
    cin >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    vector<int> profits(n + 1);
    vector<int> weights(n + 1);
    cout << "Enter the profit values: " << endl;
    for (i = 1; i <= n; i++)
        cin >> profits[i];
    cout << "Enter the weights of items: " << endl;
    for (i = 1; i <= n; i++)
        cin >> weights[i];
    solveKnapsack(v, m, n, profits, weights);
    return 0;
}
