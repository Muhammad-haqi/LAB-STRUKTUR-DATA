/*
Nama: Muhammad Haqi Rasya Arazy
NIM: 241401109
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // Ketemu sel kosong
                for (int num = 1; num <= 9; num++) { // Coba angka 1-9
                    if (isValid(board, row, col, num)) { // Jika valid
                        board[row][col] = num; // Masukkan angka
                        if (solveSudoku(board)) { // Rekursi
                            return true;
                        }
                        board[row][col] = 0; // Backtrack jika gagal
                    }
                }
                return false; // Tidak ada angka valid
            }
        }
    }
    return true; // Tidak ada sel kosong (solusi ditemukan)
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}
