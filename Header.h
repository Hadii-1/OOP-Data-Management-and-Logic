#pragma once
#include<iostream>

using namespace std;
// ========================= Question 1 =========================
//class Tapcode {
//    char arr[5][5] = {
//        'A','B','C','D','E',
//        'F','G','H','I','J',
//        'L','M','N','O','P',
//        'Q','R','S','T','U',
//        'V','W','X','Y','Z'
//    };
//
//public:
//
//    char makeUpper(char ch) {
//        if (ch >= 'a' && ch <= 'z')
//            return ch - 32;
//        return ch;
//    }
//
//    bool isAlphabet(char ch) {
//        return (ch >= 'A' && ch <= 'Z');
//    }
//
//    bool isNumber(char ch) {
//        return (ch >= '0' && ch <= '9');
//    }
//
//    char* converttotapcode(char* message) {
//        char* tapcode = new char[500];
//        int index = 0;
//
//        for (int i = 0; message[i] != '\0'; ) {
//
//            char letter = makeUpper(message[i]);
//
//            // skip non letters except space
//            if (!isAlphabet(letter) && letter != ' ') {
//                i++;
//                continue;
//            }
//
//            // space -> 0
//            if (letter == ' ') {
//                tapcode[index++] = '0';
//                i++;
//                continue;
//            }
//
//            // K treated as C
//            if (letter == 'K') letter = 'C';
//
//            // find letter in matrix
//            for (int r = 0; r < 5; r++) {
//                for (int c = 0; c < 5; c++) {
//                    if (arr[r][c] == letter) {
//                        tapcode[index++] = (r + 1) + '0';
//                        tapcode[index++] = (c + 1) + '0';
//                    }
//                }
//            }
//
//            i++;
//        }
//        tapcode[index] = '\0';
//        return tapcode;
//    }
//
//    char* convertostring(char* tapcode) {
//        char* str = new char[500];
//        int index = 0;
//
//        for (int i = 0; tapcode[i] != '\0'; ) {
//
//            if (tapcode[i] == '0') {
//                str[index++] = ' ';
//                i++;
//                continue;
//            }
//
//            if (isNumber(tapcode[i]) && isNumber(tapcode[i + 1])) {
//                int row = tapcode[i] - '0';
//                int col = tapcode[i + 1] - '0';
//
//                if (row >= 1 && row <= 5 && col >= 1 && col <= 5)
//                    str[index++] = arr[row - 1][col - 1];
//
//                i += 2;
//            }
//            else {
//                i++;
//            }
//        }
//
//        str[index] = '\0';
//        return str;
//    }
//};
class Array {
    int* arr;
    int size;

public:
    Array() {
        arr = nullptr;
        this->size = 0;
    }

    Array(int size) {
        arr = new int[size] {0};
        this->size = size;
    }

    Array(int* arr, int size) { // initializing an array with existing array
        this->size = size;
        this->arr = new int[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
    }

    Array(const Array& a) { // copy constructor deep copy
        size = a.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a.arr[i];
        }
    }

    int getAt(int i) {
        return arr[i];
    }

    void setAt(int i, int val) {
        arr[i] = val;
    }

    Array subArr(int pos, int size) { // return subarray of size and starting from pos
        Array subArray(size);
        for (int i = 0; i < size; i++) {
            subArray.setAt(i, arr[pos + i]);
        }
        return subArray;
    }

    Array subArr(int pos) { // return subarray from pos to end 
        Array subArray(this->size - pos);
        for (int i = 0; i < this->size - pos; i++) {
            subArray.setAt(i, arr[pos + i]);
        }
        return subArray;
    }

    int* subArrPointer(int pos, int size) {
        int* subArray = new int[size];
        for (int i = 0; i < size; i++) {
            subArray[i] = arr[pos + i];
        }
        return subArray;
    }

    int* subArrPointer(int pos) {
        int* subArray = new int[this->size - pos];
        for (int i = 0; i < this->size - pos; i++) {
            subArray[i] = arr[pos + i];
        }
        return subArray;
    }

    void push_back(int a) {
        int* newArr = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        newArr[size] = a;
        size++;
        delete[] arr;
        arr = newArr;
    }

    int pop_back() {
        if (size <= 0) return -1; // safety check
        int last = arr[size - 1];
        int* newArr = nullptr;
        if (size > 1)
            newArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newArr[i] = arr[i];
        }
        size--;
        delete[] arr;
        arr = newArr;
        return last;
    }

    int insert(int idx, int val) {
        if (idx < 0 || idx > size) {
            return -1; // invalid index
        }
        int* newArr = new int[size + 1];
        for (int i = 0; i < idx; i++) {
            newArr[i] = arr[i];
        }
        newArr[idx] = val;
        for (int i = idx; i < size; i++) {
            newArr[i + 1] = arr[i];
        }
        size++;
        delete[] arr;
        arr = newArr;
        return 1;
    }

    int erase(int idx, int val) { 
        if (idx < 0 || idx >= size) {
            return -1; // invalid index
        }
        int* newArr = nullptr;
        if (size > 1)
            newArr = new int[size - 1];
        for (int i = 0; i < idx; i++) {
            newArr[i] = arr[i];
        }
        for (int i = idx + 1; i < size; i++) {
            newArr[i - 1] = arr[i];
        }
        size--;
        delete[] arr;
        arr = newArr;
        return 1;
    }

    void sizeFunc() { 
        cout << "Size of array is: " << length() * sizeof(int) << endl;
    }

    int length() {
        return size;
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    int value(int idx) {
        return arr[idx];
    }

    void assign(int idx, int val) {
        arr[idx] = val;
    }

    void copy(const Array& Arr) {
        delete[] arr;
        this->size = Arr.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = Arr.arr[i];
        }
    }

    void copy(const int* arr, int size) {
        delete[] this->arr;
        this->size = size;
        this->arr = new int[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    Array find(int val) {
        Array ofIndexes;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                ofIndexes.push_back(i);
            }
        }
        return ofIndexes; 
    }

    bool equal(Array& a) {
        if (size != a.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] != a.arr[i]) {
                return false;
            }
        }
        return true;
    }

    int sort() {
        bool sorted = true;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return 1;
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    arr[j] = arr[j] ^ arr[j + 1];
                    arr[j + 1] = arr[j] ^ arr[j + 1];
                    arr[j] = arr[j] ^ arr[j + 1];
                }
            }
        }
        return 0;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            arr[i] = arr[i] ^ arr[size - i - 1];
            arr[size - i - 1] = arr[i] ^ arr[size - i - 1];
            arr[i] = arr[i] ^ arr[size - i - 1];
        }
    }

    ~Array() {
        delete[] arr;
        arr = nullptr;
    }
};
