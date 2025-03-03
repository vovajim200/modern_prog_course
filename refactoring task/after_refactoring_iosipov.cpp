#include <cmath>
#include <iostream>


const std::string INPUT_PROMPT = "Введите ";
const std::string INCREASING_SEQUENCE_MESSAGE = "Последовательность возрастающая";
const std::string DECREASING_SEQUENCE_MESSAGE = "Последовательность не возрастающая";

void intputArray(int arr[], int size);
bool checkArrayIncreasing(const int arr[], int size);
void outputResult(bool isIncreasing);

int main() {
    const int arr_size = 10;
    int arr[arr_size];

    inputArray(arr, arr_size);

    bool isIncreasing = checkArrayIncreasing(arr, arr_size);

    outputResult(isIncreasing);

    return 0;
}

void inputArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << INPUT_PROMPT << i + 1 << " элемент: ";
        std::cin >> arr[i];
    }
}

bool CheckArrayIncreasing(const int arr[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void outputResult(const bool isIncreasing) {
    if (isIncreasing) {
        std::cout << INCREASING_SEQUENCE_MESSAGE << std::endl;
    } else {
        std::cout << DECREASING_SEQUENCE_MESSAGE << std::endl;
    }
}