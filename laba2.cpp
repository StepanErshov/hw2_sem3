#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Функция для инициализации векторов дефолтными значениями
void initDefault(std::vector<std::string>& names, std::vector<int>& grades) {
    // Пример дефолтных значений
    names = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Helen", "Ivan", "John" };
    grades = { 90, 85, 92, 78, 91, 87, 93, 89, 84, 95 };
}

// Функция для инициализации векторов случайными значениями
void initRandom(std::vector<std::string>& names, std::vector<int>& grades, int size) {
    // Здесь можно добавить генерацию случайных имен из словаря реалистичных имен
    // Заполнение вектора оценок случайными значениями от 0 до 100
    for (int i = 0; i < size; ++i) {
        grades.push_back(rand() % 101);
    }
}

// Функция для инициализации векторов значениями, введенными пользователем
void initUserInput(std::vector<std::string>& names, std::vector<int>& grades) {
    int size;
    std::cout << "Enter the number of students: ";
    std::cin >> size;
    std::cout << "Enter student names and grades:\n";
    for (int i = 0; i < size; ++i) {
        std::string name;
        int grade;
        std::cout << "Student name " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Student assessment " << i + 1 << ": ";
        std::cin >> grade;
        names.push_back(name);
        grades.push_back(grade);
    }
}

// Функция для вывода содержимого векторов с использованием range-based for-loop
void printVectorRange(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::cout << "Students and their grades (range-based for-loop):\n";
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    for (const auto& grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

// Функция для вывода содержимого векторов с использованием итератора
void printVectorIterator(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::cout << "Students and their grades (iterator):\n";
    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Функция для вывода содержимого векторов с использованием обычного индексового цикла
void printVectorIndex(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::cout << "Students and their grades (index cycle):\n";
    for (int i = 0; i < names.size(); ++i) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < grades.size(); ++i) {
        std::cout << grades[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для подсчета среднего значения оценок
double calculateAverage(const std::vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// Функция для нахождения медианы оценок
double calculateMedian(std::vector<int> grades) {
    std::sort(grades.begin(), grades.end());
    if (grades.size() % 2 == 0) {
        return (grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0;
    }
    else {
        return grades[grades.size() / 2];
    }
}

// Функция для нахождения моды оценок
std::vector<std::string> calculateMode(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::map<int, int> countMap; // Хранение числа повторений каждой оценки
    std::vector<std::string> modeNames; // Здесь будем хранить имена студентов с модной оценкой
    int maxCount = 0;

    for (int grade : grades) {
        countMap[grade]++;
        maxCount = std::max(maxCount, countMap[grade]);
    }

    // Поиск студентов с модной оценкой
    for (int i = 0; i < grades.size(); ++i) {
        if (countMap[grades[i]] == maxCount) {
            modeNames.push_back(names[i]);
        }
    }
    return modeNames;
}

int main() {
    std::vector<std::string> names;
    std::vector<int> grades;

    int choice;
    std::cout << "Select the vector initialization option:\n";
    std::cout << "1. Default values\n";
    std::cout << "2. Random values\n";
    std::cout << "3. User input\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        initDefault(names, grades);
        break;
    case 2:
        int size;
        std::cout << "Enter sample size: ";
        std::cin >> size;
        initRandom(names, grades, size);
        break;
    case 3:
        initUserInput(names, grades);
        break;
    default:
        std::cout << "Wrong choice. The program will be completed.\n";
        return 0;
    }

    // Вывод содержимого векторов
    printVectorRange(names, grades); // Используется range-based for-loop

    // Расчет и вывод среднего значения
    double average = calculateAverage(grades);
    std::cout << "Average ratings: " << average << std::endl;

    // Расчет и вывод медианы
    double median = calculateMedian(grades);
    std::cout << "Median ratings: " << median << std::endl;

    // Расчет и вывод моды
    std::vector<std::string> modeNames = calculateMode(names, grades);
    std::cout << "Fashion grade students:\n";
    for (const auto& name : modeNames) {
        std::cout << name << std::endl;
    }

    return 0;
}
