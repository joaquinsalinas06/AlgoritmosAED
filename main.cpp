#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

void quicksort(int arr[], int tamano) {
    if (tamano <= 1) {
        return;
    }
    int pivot = arr[tamano - 1];
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
    int* arr = new int[10];
    int* arr2 = new int[100];
    int* arr3 = new int[1000];
    int* arr4 = new int[10000];
    int* arr5 = new int[100000];
    int* arr6 = new int[1000000];

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < 10; i++) {
        arr[i] = distribution(generator);
    }

    for (int i = 0; i < 100; i++) {
        arr2[i] = distribution(generator);
    }

    for (int i = 0; i < 1000; i++) {
        arr3[i] = distribution(generator);
    }

    for (int i = 0; i < 10000; i++) {
        arr4[i] = distribution(generator);
    }

    for (int i = 0; i < 100000; i++) {
        arr5[i] = distribution(generator);
    }

    for (int i = 0; i < 1000000; i++) {
        arr6[i] = distribution(generator);
    }

    cout << "Array 1: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* arr_copia = new int[10];
    int* arr2_copia = new int[100];
    int* arr3_copia = new int[1000];
    int* arr4_copia = new int[10000];
    int* arr5_copia = new int[100000];
    int* arr6_copia = new int[1000000];

    copy(arr, arr + 10, arr_copia);
    copy(arr2, arr2 + 100, arr2_copia);
    copy(arr3, arr3 + 1000, arr3_copia);
    copy(arr4, arr4 + 10000, arr4_copia);
    copy(arr5, arr5 + 100000, arr5_copia);
    copy(arr6, arr6 + 1000000, arr6_copia);

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

    auto start6 = chrono::system_clock::now();
    quicksort(arr6, 1000000);
    auto end6 = chrono::system_clock::now();
    chrono::duration<float, milli> duration6 = end6 - start6;
    cout << "Tiempo de ejecucion para 1000000 elementos: " << duration6.count() << "ms" << endl;

    cout << "\nInsertion sort" << endl;

    auto start7 = chrono::system_clock::now();
    insertionsort(arr_copia, 10);
    auto end7 = chrono::system_clock::now();
    chrono::duration<float, milli> duration7 = end7 - start7;
    cout << "Tiempo de ejecucion para 10 elementos: " << duration7.count() << "ms" << endl;

    auto start8 = chrono::system_clock::now();
    insertionsort(arr2_copia, 100);
    auto end8 = chrono::system_clock::now();
    chrono::duration<float, milli> duration8 = end8 - start8;
    cout << "Tiempo de ejecucion para 100 elementos: " << duration8.count() << "ms" << endl;

    auto start9 = chrono::system_clock::now();
    insertionsort(arr3_copia, 1000);
    auto end9 = chrono::system_clock::now();
    chrono::duration<float, milli> duration9 = end9 - start9;
    cout << "Tiempo de ejecucion para 1000 elementos: " << duration9.count() << "ms" << endl;

    auto start10 = chrono::system_clock::now();
    insertionsort(arr4_copia, 10000);
    auto end10 = chrono::system_clock::now();
    chrono::duration<float, milli> duration10 = end10 - start10;
    cout << "Tiempo de ejecucion para 10000 elementos: " << duration10.count() << "ms" << endl;

    auto start11 = chrono::system_clock::now();
    insertionsort(arr5_copia, 100000);
    auto end11 = chrono::system_clock::now();
    chrono::duration<float, milli> duration11 = end11 - start11;
    cout << "Tiempo de ejecucion para 100000 elementos: " << duration11.count() << "ms" << endl;

    auto start12 = chrono::system_clock::now();
    insertionsort(arr6_copia, 1000000);
    auto end12 = chrono::system_clock::now();
    chrono::duration<float, milli> duration12 = end12 - start12;
    cout << "Tiempo de ejecucion para 1000000 elementos: " << duration12.count() << "ms" << endl;

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr_copia;
    delete[] arr2_copia;
    delete[] arr3_copia;
    delete[] arr4_copia;
    delete[] arr5_copia;
    delete[] arr6_copia;

    return 0;
}
