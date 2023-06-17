


void bubbleSort(Criminal *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j].getPower() > arr[j + 1].getPower()) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}