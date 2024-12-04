#include <iostream>

void insertion_sort(int* const arr, const int size);
void print_array(const char* const comment, int* arr, const int size);

int main() {
    int arr[]{4, 2, 6, 1, 5, 3, 9};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	print_array("Массив до сортировки:", arr, arr_size);
    
    insertion_sort(arr, arr_size);

    print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}

void insertion_sort(int* const arr, const int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void print_array(const char* const comment, int* arr, const int size) {
	const char format = ' ';
	std::cout << comment;
	for (int i = 0; i < size; i++) {
		std::cout << format << arr[i];
	}
	std::cout << std::endl;
}