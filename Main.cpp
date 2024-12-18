#include <iostream>
#include <fstream>
#include <string>

// Задача 3
// Функции для проверки типа символа
bool isVowel(char c) {
    const std::string vowels = "аеэиоуюяАЕЭИОУЮЯ"; // Гласные буквы
    return vowels.find(c) != std::string::npos; // Проверяем наличие символа в строке гласных
}

bool isConsonant(char c) {
    const std::string consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ"; // Согласные буквы
    return consonants.find(c) != std::string::npos; // Проверяем наличие символа в строке согласных
}

bool isDigit(char c) {
    const std::string digits = "0123456789"; // Цифры
    return digits.find(c) != std::string::npos; // Проверяем наличие символа в строке цифр
}

// Задача 3
std::string Cessar(const std::string& str, int n) {
    std::string r; // Результирующая строка для зашифрованного текста

    for (char c : str) {
        // Применяем сдвиг только для букв
        if (isalpha(c)) {
            c = c + n; // Просто сдвигаем символ
        }
        r += c; // Добавляем символ в результирующую строку
    }

    return r; // Возвращаем зашифрованную строку
}

int main() {
    setlocale(LC_ALL, "RUS");

    //  Задача 1
    std::string inputFileName1 = "file1.txt";  // Имя первого входного файла
    std::string inputFileName2 = "file2.txt";  // Имя второго входного файла

    std::ifstream inputFile1(inputFileName1);
    std::ifstream inputFile2(inputFileName2);

    // Проверяем, открылись ли файлы
    if (!inputFile1.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << inputFileName1 << std::endl;
        return 1;
    }

    if (!inputFile2.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << inputFileName2 << std::endl;
        return 1;
    }

    std::string line1, line2;
    bool Difference = false; // Флаг для отслеживания различий

    while (std::getline(inputFile1, line1) && std::getline(inputFile2, line2)) {
        if (line1 != line2) {
            // Если строки не совпадают, выводим их
            std::cout << "Несовпадающие строки:" << std::endl;
            std::cout << "Файл 1: " << line1 << std::endl;
            std::cout << "Файл 2: " << line2 << std::endl;
            Difference = true; // Устанавливаем флаг различий
        }
    }

    // Проверка на случай, если один файл длиннее другого
    while (std::getline(inputFile1, line1)) {
        std::cout << "Файл 1: " << line1 << " (Нет соответствующей строки в Файл 2)" << std::endl;
        Difference = true;
    }

    while (std::getline(inputFile2, line2)) {
        std::cout << "Файл 2: " << line2 << " (Нет соответствующей строки в Файл 1)" << std::endl;
        Difference = true;
    }

    // Если нет различий, сообщаем об этом
    if (!Difference) {
        std::cout << "Все строки совпадают." << std::endl;
    }

    // Закрываем файлы
    inputFile1.close();
    inputFile2.close();

    // Задача 2
    std::string inputFileName = "input.txt";  // Имя входного файла
    std::string outputFileName = "statistics.txt"; // Имя выходного файла

    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    // Проверяем, открылись ли файлы
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << inputFileName << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << outputFileName << std::endl;
        return 1;
    }

    std::string line;
    int characterCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    while (std::getline(inputFile, line)) {
        lineCount++; // Увеличиваем количество строк
        characterCount += line.length(); // Увеличиваем количество символов

        // Проверяем каждый символ в строке
        for (size_t i = 0; i < line.length(); ++i) {
            char currentChar = line[i]; // Текущий символ

            if (isVowel(currentChar)) {
                vowelCount++; // Увеличиваем количество гласных
            }
            else if (isConsonant(currentChar)) {
                consonantCount++; // Увеличиваем количество согласных
            }
            else if (isDigit(currentChar)) {
                digitCount++; // Увеличиваем количество цифр
            }
        }
    }

    // Записываем результаты в выходной файл
    outputFile << "Количество символов: " << characterCount << std::endl;
    outputFile << "Количество строк: " << lineCount << std::endl;
    outputFile << "Количество гласных букв: " << vowelCount << std::endl;
    outputFile << "Количество согласных букв: " << consonantCount << std::endl;
    outputFile << "Количество цифр: " << digitCount << std::endl;

    // Закрываем файлы
    inputFile.close();
    outputFile.close();

    // Задача 3
    std::string Start = "Start.txt";  // Имя входного файла
    std::string Finish = "Finish.txt"; // Имя выходного файла
    int key = 3; // Ключ шифрования

    std::ifstream inputFile(Start); // Открываем входной файл
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << Start << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    std::ofstream outputFile(Finish); // Открываем выходной файл
    if (!outputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << Finish << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    std::string line;

    // Считываем каждую строку из входного файла и шифруем
    while (std::getline(inputFile, line)) {
        std::string encryptedLine = Cessar(line, key); // Зашифровываем строку
        outputFile << encryptedLine << std::endl; // Записываем зашифрованную строку в выходной файл
    }

    inputFile.close(); // Закрываем входной файл
    outputFile.close(); // Закрываем выходной файл

    std::cout << "Шифрование завершено." << std::endl;

    return 0;
}

