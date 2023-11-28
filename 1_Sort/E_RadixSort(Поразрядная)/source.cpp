#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int findMaxLength(const vector<string>& arr) {
  int maxLength = 0;
  for (const string& str : arr) {
    if (str.length() > maxLength) {
      maxLength = str.length();
    }
  }
  return maxLength;
}

// Функция для распределения строк по корзинам для одной фазы
void countingSort(vector<string>& arr, int exp) {
  const int n = arr.size();
  const int base = 10;  // количество цифр от 0 до 9

  vector<vector<string>> buckets(base);

  // Распределение строк по корзинам
  for (int i = 0; i < n; i++) {
    int digit =
        (arr[i].length() >= exp) ? (arr[i][arr[i].length() - exp] - '0') : 0;
    buckets[digit].push_back(arr[i]);
  }

  // Извлечение строк из корзин в исходном порядке
  int index = 0;
  for (int i = 0; i < base; i++) {
    cout << "Bucket " << i << ": ";
    if (buckets[i].empty()) {
      cout << "empty";
    } else {
      for (size_t j = 0; j < buckets[i].size(); ++j) {
        cout;
        if (j + 1 != buckets[i].size())
          cout << buckets[i][j] << ", ";
        else
          cout << buckets[i][j];
        arr[index++] = buckets[i][j];
      }
    }
    cout << endl;
  }
}

// Функция для поразрядной сортировки
void radixSort(vector<string>& arr) {
  int maxLength = findMaxLength(arr);

  // Выполнение сортировки для каждой фазы
  for (int exp = 1; exp <= maxLength; exp++) {
    cout << "**********\nPhase " << exp << endl;
    countingSort(arr, exp);
  }
}

int main() {
  // Чтение входных данных
  size_t n;
  cin >> n;

  vector<string> array(n);
  for (size_t i = 0; i < n; ++i) cin >> array[i];

  // Вывод исходного массива
  cout << "Initial array:\n";
  for (auto it = array.begin(); it != array.end(); ++it) {
    if (it == prev(array.end()))
      cout << *it << endl;
    else
      cout << *it << ", ";
  }
  // Вызов функции поразрядной сортировки
  radixSort(array);

  // Вывод отсортированного массива
  cout << "**********\nSorted array:\n";
  for (auto it = array.begin(); it != array.end(); ++it) {
    if (it == prev(array.end()))
      cout << *it << endl;
    else
      cout << *it << ", ";
  }
  return 0;
}
