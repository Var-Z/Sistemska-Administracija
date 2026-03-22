#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> countingSort(vector<int> A) {
    if (A.empty()) return A;

    int min = A[0];
    int max = A[0];

    for (int i = 1; i < (int)A.size(); i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }

    for (int i = 0; i < (int)A.size(); i++) {
        A[i] = A[i] - min;
    }

    int range = max - min + 1;

    vector<int> C(range, 0);
    vector<int> B(A.size());

    for (int i = 0; i < (int)A.size(); i++) {
        C[A[i]]++;
    }

    for (int i = 1; i < range; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = (int)A.size() - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }

    for (int i = 0; i < (int)B.size(); i++) {
        B[i] = B[i] + min;
    }

    return B;
}

vector<int> romanSort(vector<int> A) {}

int main(){
    return 0;
}