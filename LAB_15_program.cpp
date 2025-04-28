#include <iostream>
#include <windows.h>
using namespace std;

// Функція для сортування масиву за спаданням
void qsortDescending(int* mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];
    do {
        while (mas[i] > mid) {
            i++;
        }
        while (mas[j] < mid) {
            j--; 
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsortDescending(mas, j + 1);
    }
    if (i < size) {
        qsortDescending(&mas[i], size - i);
    }
}

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int array_size = 8;
    int array[array_size] = { 9, 7, 5, 6, 8, 2, 4, 1 };

    cout << "Масив до сортування:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Створюємо два окремих масиви для парних та непарних місць
    int even[array_size / 2 + 1]; // Для парних індексів 
    int odd[array_size / 2];      // Для непарних індексів 

    int evenCount = 0, oddCount = 0;

    // Розділяємо елементи
    for (int i = 0; i < array_size; i++) {
        if (i % 2 == 0) { // парні місця
            even[evenCount++] = array[i];
        }
        else {          // непарні місця
            odd[oddCount++] = array[i];
        }
    }

    // Сортуємо окремо
    qsortDescending(even, evenCount);
    qsortDescending(odd, oddCount);

    // Повертаємо назад у масив
    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < array_size; i++) {
        if (i % 2 == 0) {
            array[i] = even[evenCount++];
        }
        else {
            array[i] = odd[oddCount++];
        }
    }

    cout << "Масив після окремого сортування парних та непарних місць за спаданням:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
