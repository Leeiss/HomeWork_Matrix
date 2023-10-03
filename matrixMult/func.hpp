#pragma once
#include <iostream>

/*
Реализовать умножение двух матриц типа int
A[n][m]
B[m][l]
result[n][l]

Стандартный ввод cin

Стандартный вывод cout. В выводе результирующая матрица (result) должна быть представлена в виде строк и столбцов 
=============================================================================
В воде сначала идут 3 размерности n m l соответствующие 
A[n][m]
B[m][l]
result[n][l]
Затем уже значения матриц
Пример для функции execDynamic (для execStatic указать размерности вводом мы не можем, проверим вручную)

Input: 
3 4 2
1 2 3 4
5 6 7 8
9	10 11	12
13 14
15 16
17 18
19 20

Output:
170	180
426	452
682	724



Для execStatic n m l задаются вручную

Input: 
1 2 3 4
5 6 7 8
9	10 11	12
13 14
15 16
17 18
19 20

Output:
170	180
426	452
682	724
========================================================================================
между числами в строке используйте std::cout << ' ';
между строками используйте std::cout << std::endl;

В execStatic память для матриц выделяется статически

В execDynamic память для матриц выделяется динамически

Программа (execDynamic) должна проходить тесты. Для прохождения тестов необходимо сделать действие 1 или 2 

1)соберите проект и сверьте выходные данные, полученные из выходных tests/mtest/text{i}.txt с ответами
в tests/mtest/asnv{i}.txt

пример сравнения
cat tests/mtest/text0.txt | ./build/cmatrix > tests/test_result.txt
&& cmp tests/test_result.txt tests/mtest/asnv0.txt

2) создайте пул реквест на гитхабе github.com/ch1cly/CppTeaching/


Работа оценивается в
10 баллов
*/


void execStatic() {
    std::cout << "Память для матриц выделяется статически" << std::endl;
    int n, m, l;
    std::cout << "Введите размерности матриц (n m l): ";
    std::cin >> n >> m >> l;

    int A_static[100][100];
    int B_static[100][100];
    int result_static[100][100] = {0}; 

    std::cout << "Введите матрицу A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A_static[i][j];
        }
    }

    std::cout << "Введите матрицу B:" << std::endl;
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

    std::cout << "Результат умножения матриц:" << std::endl;
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
    std::cout << "Введите размерности матриц (n m l): ";
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

    std::cout << "Введите матрицу A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Введите матрицу B:" << std::endl;
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

    std::cout << "Результат умножения матриц:" << std::endl;
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