#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua bagian yang sudah terurut dalam vektor arr
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;   // ukuran subarray kiri
    int n2 = right - mid;      // ukuran subarray kanan

    vector<int> L(n1), R(n2);  // vektor sementara untuk menyimpan data subarray kiri dan kanan

    // Salin data ke vektor sementara L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;   // indeks untuk L
    int j = 0;   // indeks untuk R
    int k = left; // indeks untuk arr

    // Gabungkan elemen dari L dan R ke arr secara terurut
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

    // Salin sisa elemen dari L jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari R jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort yang mengurutkan arr antara indeks left dan right
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) // basis rekursi: jika subarray hanya satu elemen atau kosong
        return;

    int mid = left + (right - left) / 2; // cari titik tengah subarray

    mergeSort(arr, left, mid);      // rekursif urutkan subarray kiri
    mergeSort(arr, mid + 1, right); // rekursif urutkan subarray kanan
    
    merge(arr, left, mid, right);   // gabungkan hasil pengurutan kedua subarray
}

// Fungsi untuk mencetak elemen-elemen array ke layar
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(data);

    mergeSort(data, 0, n - 1); // panggil fungsi mergeSort untuk mengurutkan data

    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;
}
