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

vector<int> romanSort(vector<int> A) {
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
    vector<int> B;

    for (int i = 0; i < (int)A.size(); i++) {
        C[A[i]]++;
    }

    for (int i = 0; i < range; i++) {
        while (C[i] > 0) {
            B.push_back(i + min);
            C[i]--;
        }
    }

    return B;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uporaba: vaja1 <opcija> <vhodna_datoteka>" << endl;
        return 1;
    }

    string opcija = argv[1];
    string imeDatoteke = argv[2];

    ifstream vhod(imeDatoteke);
    if (!vhod) {
        cout << "Napaka pri odpiranju vhodne datoteke." << endl;
        return 1;
    }

    vector<int> A;
    int x;

    while (vhod >> x) {
        A.push_back(x);
    }

    vhod.close();

    vector<int> rezultat;

    if (opcija == "0") {
        rezultat = countingSort(A);
    } else if (opcija == "1") {
        rezultat = romanSort(A);
    } else {
        cout << "Napacna opcija. Uporabi 0 ali 1." << endl;
        return 1;
    }

    ofstream izhod("out.txt");
    if (!izhod) {
        cout << "Napaka pri pisanju v out.txt." << endl;
        return 1;
    }

    for (int i = 0; i < (int)rezultat.size(); i++) {
        izhod << rezultat[i];
        if (i != (int)rezultat.size() - 1) {
            izhod << " ";
        }
    }

    izhod.close();

    return 0;
}