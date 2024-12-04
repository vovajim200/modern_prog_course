#include "io.hpp"
#include "sortings.hpp"

int main() {
    int arr[] = {4, 3, 2, 1, 2, 3, 9, 3};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	my_namespace::print_array("Массив до сортировки:", arr, arr_size);
    
    my_namespace::sortings::insertion_sort(arr, arr_size);

    my_namespace::print_array("Массив после сортировки: ", arr, arr_size);

    return 0;
}
