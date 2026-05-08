#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(string &arr) {
    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(string &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L = "", R = "";

    for (int i = 0; i < n1; i++) L += arr[l + i];
    for (int j = 0; j < n2; j++) R += arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(string &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void shellSort(string &arr) {
    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp2 = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp2;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    string pilihanStr;
    int pilihan;

    do {
        system("cls");
        cout << "----------------------------------\n";
        cout << "|            SORTING             |\n";
        cout << "----------------------------------\n";
        cout << " 1. Insertion Sort (Nama)\n";
        cout << " 2. Merge Sort (Nama)\n";
        cout << " 3. Shell Sort (Nama)\n";
        cout << " 4. Quick Sort (NIM)\n";
        cout << " 5. Bubble Sort (NIM)\n";
        cout << " 6. Selection Sort (NIM)\n";
        cout << " 7. Exit\n";
        cout << "----------------------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihanStr;
        pilihan = atoi(pilihanStr.c_str());

        cout << "\n";

        if (pilihan >= 1 && pilihan <= 3) {
            string nama;
            cout << "Masukkan Nama tanpa menggunakan spasi : ";
            cin >> nama;
            cout << "\n";
            
            switch (pilihan) {
                case 1:
                    cout << "[ Insertion Sort (Nama) ]\n";
                    cout << "Input Awal : " << nama << "\n";
                    insertionSort(nama);
                    cout << "Output Hasil : " << nama << "\n";
                    break;
                case 2:
                    cout << "[ Merge Sort (Nama) ]\n";
                    cout << "Input Awal : " << nama << "\n";
                    mergeSort(nama, 0, nama.length() - 1);
                    cout << "Output Hasil : " << nama << "\n";
                    break;
                case 3:
                    cout << "[ Shell Sort (Nama) ]\n";
                    cout << "Input Awal : " << nama << "\n";
                    shellSort(nama);
                    cout << "Output Hasil : " << nama << "\n";
                    break;
            }
        } else if (pilihan >= 4 && pilihan <= 6) {
            string nimStr;
            cout << "Masukkan NIM : ";
            cin >> nimStr;
            cout << "\n";

            int nimSize = nimStr.length();
            int *nimArray = new int[nimSize];
            for(int i = 0; i < nimSize; i++) {
                nimArray[i] = nimStr[i] - '0';
            }

            switch (pilihan) {
                case 4:
                    cout << "[ Quick Sort (NIM) ]\n";
                    cout << "Input Awal : "; tampilkanArray(nimArray, nimSize);
                    quickSort(nimArray, 0, nimSize - 1);
                    cout << "Output Hasil : "; tampilkanArray(nimArray, nimSize);
                    break;
                case 5:
                    cout << "[ Bubble Sort (NIM) ]\n";
                    cout << "Input Awal : "; tampilkanArray(nimArray, nimSize);
                    bubbleSort(nimArray, nimSize);
                    cout << "Output Hasil : "; tampilkanArray(nimArray, nimSize);
                    break;
                case 6:
                    cout << "[ Selection Sort (NIM) ]\n";
                    cout << "Input Awal : "; tampilkanArray(nimArray, nimSize);
                    selectionSort(nimArray, nimSize);
                    cout << "Output Hasil : "; tampilkanArray(nimArray, nimSize);
                    break;
            }
            delete[] nimArray;
        } else if (pilihan == 7) {
            cout << "Terima kasih Code by Muhammad Raffa Azisha\n";
        } else {
            cout << "Pilihan tidak valid\n";
        }

        if (pilihan != 7) {
            cout << "\nTekan tombol apa saja untuk kembali";
            getch();
        }

    } while (pilihan != 7);

    return 0;
}