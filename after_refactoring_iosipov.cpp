#include <iostream>
#include <cmath>

const int ARRAY_SIZE = 10;
const std::string INPUT_PROMPT = "Введите ";
const std::string INCREASING_SEQUENCE_MESSAGE = "Последовательность возрастающая";
const std::string DECREASING_SEQUENCE_MESSAGE = "Последовательность не возрастающая";

void arrayInput(double array[], int size);
bool isIncreasing(const double array[], int size);
void outputResult(bool isIncreasing);

int main() {
    double array[ARRAY_SIZE];

    arrayInput(array, ARRAY_SIZE);

    bool increasingSequence = isIncreasing(array, ARRAY_SIZE);

    outputResult(increasingSequence);

    return 0;
}

void arrayInput(double array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << INPUT_PROMPT << i + 1 << " элемент: ";
        std::cin >> array[i];
    }
}

bool isIncreasing(const double array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void outputResult(bool isIncreasing) {
    if (isIncreasing) {
        std::cout << INCREASING_SEQUENCE_MESSAGE << std::endl;
    } else {
        std::cout << DECREASING_SEQUENCE_MESSAGE << std::endl;
    }
}