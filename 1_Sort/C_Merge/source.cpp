#include <iostream>
#include <vector>

template <typename T>
void mergeArrays(typename std::vector<T>::const_iterator begin1,
                 typename std::vector<T>::const_iterator end1,
                 typename std::vector<T>::const_iterator begin2,
                 typename std::vector<T>::const_iterator end2,
                 std::vector<T>& result) {
  result.clear();
  while (begin1 != end1 && begin2 != end2) {
    if (*begin1 <= *begin2)
      result.push_back(*begin1++);
    else
      result.push_back(*begin2++);
  }

  result.insert(result.end(), begin1, end1);
  result.insert(result.end(), begin2, end2);
}

int main() {
  int N, M;

  std::cin >> N;
  std::vector<int> array1(N);
  for (int i = 0; i < N; ++i) std::cin >> array1[i];

  std::cin >> M;
  std::vector<int> array2(M);
  for (int i = 0; i < M; ++i) std::cin >> array2[i];

  std::vector<int> resultOfMerged;
  mergeArrays(array1.begin(), array1.end(), array2.begin(), array2.end(),
              resultOfMerged);

  for (int x : resultOfMerged) std::cout << x << " ";
  return 0;
}
