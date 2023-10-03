#include "func.hpp"

void execStatic() {
    //std::cout << "Память для матриц выделяется статически" << std::endl;
    int n, m, l;
    //std::cout << "Введите размерности матриц (n m l): ";
    std::cin >> n >> m >> l;

    int A_static[100][100];
    int B_static[100][100];
    int result_static[100][100] = {0}; 

    //std::cout << "Введите матрицу A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A_static[i][j];
        }
    }

    //std::cout << "Введите матрицу B:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            std::cin >> B_static[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                result_static[i][j] += A_static[i][k] * B_static[k][j];
            }
        }
    }

    //std::cout << "Результат умножения матриц:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << result_static[i][j];
            if (j < l - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

void execDynamic() {
    int n, m, l;
    //std::cout << "Введите размерности матриц (n m l): ";
    std::cin >> n >> m >> l;

    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }

    int** B = new int*[m];
    for (int i = 0; i < m; i++) {
        B[i] = new int[l];
    }

    int** result = new int*[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[l];
    }

    //std::cout << "Введите матрицу A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }

   // std::cout << "Введите матрицу B:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            std::cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
            
        }
    }

    //std::cout << "Результат умножения матриц:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            std::cout << result[i][j];
            if (j < l - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < m; i++) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < n; i++) {
        delete[] result[i];
    }
    delete[] result;
}