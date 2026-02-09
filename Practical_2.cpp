#include <iostream>
using namespace std;

int main() {
    int r = 2, c = 3;
    int A[2][3] = {{1,2,3}, {4,5,6}};
    int B[2][3] = {{5,6,3}, {7,8,9}};
    int Add[2][3],Sub[2][3],TranA[3][2],TranB[3][2];

    // Matrix Addition
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            Add[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Addition of matrices:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        cout << Add[i][j] << ' ';
        }
        cout << endl;
    }

    // Matrix Subtraction
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            Sub[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "\nSubtraction of matrices:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << Sub[i][j] << ' ';
        }
        cout << endl;
    }

    // Transpose of Martix A
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            TranA[j][i] = A[i][j];
        }
    }

    cout << "\nTranspose of Matrix A:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++){
             cout << TranA[i][j] << ' ';
        }
        cout << endl;
    }

    // Transpose of Matrix B
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            TranB[j][i] = B[i][j];
        }
    }

    cout << "\nTranspose of Matrix B:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++){
             cout << TranB[i][j] << ' ';
        }
        cout << endl;
    }

    // Scalar multiplication Of Matrix A
    cout << "\nScalar multiplication of A :\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
             cout << A[i][j] * 2 << ' ';
        }
        cout << endl;
    }

    cout << "\nScalar multiplication of B :\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
             cout << B[i][j] * 3 << ' ';
        }
        cout << endl;
    }

    return 0;
}
