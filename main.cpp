#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

void quicksort(int arr[], int tamano) {
    if (tamano <= 1) {
        return;
    }
    int pivot = arr[tamano / 2];
    int i = 0;
    int j = tamano - 1;
    while (i < j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quicksort(arr, j + 1);
    quicksort(arr + i, tamano - i);
}


void insertionsort(int arr[], int tamano) {
    for (int i = 1; i < tamano; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[10], arr2[100], arr3[1000], arr4[10000], arr5[100000];
    srand(time(NULL));

    generate(begin(arr), end(arr), []() {
        return rand() % 100;});

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    generate(begin(arr2), end(arr2), []() {
        return rand() % 100;});

    generate(begin(arr3), end(arr3), []() {
        return rand() % 100;});

    generate(begin(arr4), end(arr4), []() {
        return rand() % 100;});

    generate(begin(arr5), end(arr5), []() {
        return rand() % 100;});

    int arr1_copia[10],arr2_copia[100],arr3_copia[1000],arr4_copia[10000],arr5_copia[100000];
    copy(begin(arr), end(arr), begin(arr1_copia));
    copy(begin(arr2), end(arr2), begin(arr2_copia));
    copy(begin(arr3), end(arr3), begin(arr3_copia));
    copy(begin(arr4), end(arr4), begin(arr4_copia));
    copy(begin(arr5), end(arr5), begin(arr5_copia));

    cout << "\nQuicksort" << endl;

    auto start = chrono::system_clock::now();
    quicksort(arr, 10);
    auto end = chrono::system_clock::now();
    chrono::duration<float, milli> duration = end - start;
    cout << "Tiempo de ejecucion para 10 elementos: " << duration.count() << "ms" << endl;

    auto start2 = chrono::system_clock::now();
    quicksort(arr2, 100);
    auto end2 = chrono::system_clock::now();
    chrono::duration<float, milli> duration2 = end2 - start2;
    cout << "Tiempo de ejecucion para 100 elementos: " << duration2.count() << "ms" << endl;

    auto start3 = chrono::system_clock::now();
    quicksort(arr3, 1000);
    auto end3 = chrono::system_clock::now();
    chrono::duration<float, milli> duration3 = end3 - start3;
    cout << "Tiempo de ejecucion para 1000 elementos: " << duration3.count() << "ms" << endl;

    auto start4 = chrono::system_clock::now();
    quicksort(arr4, 10000);
    auto end4 = chrono::system_clock::now();
    chrono::duration<float, milli> duration4 = end4 - start4;
    cout << "Tiempo de ejecucion para 10000 elementos: " << duration4.count() << "ms" << endl;

    auto start5 = chrono::system_clock::now();
    quicksort(arr5, 100000);
    auto end5 = chrono::system_clock::now();
    chrono::duration<float, milli> duration5 = end5 - start5;
    cout << "Tiempo de ejecucion para 100000 elementos: " << duration5.count() << "ms" << endl;

    cout << "\nInsertion sort" << endl;

    auto start6 = chrono::system_clock::now();
    insertionsort(arr1_copia, 10);
    auto end6 = chrono::system_clock::now();
    chrono::duration<float, milli> duration6 = end6 - start6;
    cout << "Tiempo de ejecucion para 10 elementos: " << duration6.count() << "ms" << endl;

    auto start7 = chrono::system_clock::now();
    insertionsort(arr2_copia, 100);
    auto end7 = chrono::system_clock::now();
    chrono::duration<float, milli> duration7 = end7 - start7;
    cout << "Tiempo de ejecucion para 100 elementos: " << duration7.count() << "ms" << endl;

    auto start8 = chrono::system_clock::now();
    insertionsort(arr3_copia, 1000);
    auto end8 = chrono::system_clock::now();
    chrono::duration<float, milli> duration8 = end8 - start8;
    cout << "Tiempo de ejecucion para 1000 elementos: " << duration8.count() << "ms" << endl;

    auto start9 = chrono::system_clock::now();
    insertionsort(arr4_copia, 10000);
    auto end9 = chrono::system_clock::now();
    chrono::duration<float, milli> duration9 = end9 - start9;
    cout << "Tiempo de ejecucion para 10000 elementos: " << duration9.count() << "ms" << endl;

    auto start10 = chrono::system_clock::now();
    insertionsort(arr5_copia, 100000);
    auto end10 = chrono::system_clock::now();
    chrono::duration<float, milli> duration10 = end10 - start10;
    cout << "Tiempo de ejecucion para 100000 elementos: " << duration10.count() << "ms" << endl;




    return 0;
}
