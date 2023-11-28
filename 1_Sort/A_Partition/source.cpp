#include <iostream>
#include <vector>

void partition(std::vector<long long int> &arr, int low, int high, int pivot,
               int *lessIndex, int *equalIndex) {
  int less = low, equal = low, more = high;

  while (equal <= more) {
    if (arr[equal] < pivot) {
      std::swap(arr[less++], arr[equal++]);
    } else if (arr[equal] == pivot) {
      equal++;
    } else {
      std::swap(arr[equal], arr[more--]);
    }
  }
  *lessIndex = less;
  *equalIndex = equal;
}

int main() {
  int N;
  std::cin >> N;

  std::vector<long long int> sequence(N);
  for (int i = 0; i < N; i++) {
    std::cin >> sequence[i];
  }

  long long int pivot;
  std::cin >> pivot;

  int lessIndex, equalIndex;
  partition(sequence, 0, N - 1, pivot, &lessIndex, &equalIndex);

  int lessCount = lessIndex;
  int equalCount = equalIndex - lessIndex;
  int greaterCount = N - lessIndex;

  std::cout << lessCount << "\n" << greaterCount << "\n";
  return 0;
}