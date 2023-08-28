#include <iostream>
#include <vector>

using namespace std;

void rankSort(vector<int> &arr) {
    int n = arr.size();
    vector<int> rank(n, 0);
    vector<int> sortedArr(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] < arr[i] || (arr[j] == arr[i] && j < i)) {
                rank[i]++;
            }
        }
        sortedArr[rank[i]] = arr[i];
    }

    arr = sortedArr;
}

int main() {
    vector<int> arr = {64, 11, 25, 11, 22, 11, 90};
    
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rankSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
