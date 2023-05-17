#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include<Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream inputFile("NUMBERS.DAT", ios::binary);
    if (!inputFile) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    vector<int> numbers;
    int currentNumber;

    // Чтение чисел из файла
    while (inputFile.read(reinterpret_cast<char*>(&currentNumber), sizeof(currentNumber))) {
        numbers.push_back(currentNumber);
    }

    inputFile.close();

    // Задание 1: Найти количество отрицательных чисел в файле
    int negativeCount = 0;
    for (int number : numbers) {
        if (number < 0) {
            negativeCount++;
        }
    }

    // Задание 2: Найти среднее значение чисел, больших нуля
    double sum = 0.0;
    int positiveCount = 0;
    for (int number : numbers) {
        if (number > 0) {
            sum += number;
            positiveCount++;
        }
    }

    // Проверка деления на ноль
    if (positiveCount == 0) {
        cout << "Нет положительных чисел для вычисления среднего значения." << endl;
        return 1;
    }

    double average = sum / positiveCount;

    // Вывод результатов на экран
    cout << "Количество отрицательных чисел: " << negativeCount << endl;
    cout << "Среднее значение положительных чисел: " << fixed << setprecision(2) << average << endl;

    // Запись результатов в текстовый файл
    string outputFileName;
    cout << "Введите имя текстового файла для сохранения результатов: ";
    cin >> outputFileName;

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Ошибка открытия файла для записи." << endl;
        return 1;
    }

    // Запись чисел и результатов в текстовый файл
    outputFile << "Числа в файле:" << endl;
    for (int number : numbers) {
        outputFile << number << endl;
    }
    outputFile << "Количество отрицательных чисел: " << negativeCount << endl;
    outputFile << "Среднее значение положительных чисел: " << fixed << setprecision(2) << average << endl;

    outputFile.close();

    cout << "Результаты сохранены в файле \"" << outputFileName << "\"." << endl;

    return 0;
}
