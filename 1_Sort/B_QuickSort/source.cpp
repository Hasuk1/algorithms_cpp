#include <iostream>
#include <random>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
  std::random_device rd;
  std::mt19937 gen(rd());
  int randomIndex = low + gen() % (high - low + 1);
  std::swap(arr[randomIndex], arr[high]);
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      std::swap(arr[++i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) std::cin >> arr[i];
  int l = 1;
  while (l < N && arr[l - 1] <= arr[l]) l++;
  if (l != N) quickSort(arr, 0, N - 1);

  for (int x : arr) std::cout << x << " ";

  return 0;
}