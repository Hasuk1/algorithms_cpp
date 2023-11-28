#include <iostream>
#include <vector>

using namespace std;

void mergeArrays(vector<long int>::iterator begin1,
                 vector<long int>::iterator end1,
                 vector<long int>::iterator begin2,
                 vector<long int>::iterator end2,
                 vector<long int>::iterator resbegin) {
  while (begin1 != end1 && begin2 != end2) {
    if (*begin1 < *begin2)
      *(resbegin++) = *(begin1++);
    else
      *(resbegin++) = *(begin2++);
  }
  while (begin2 != end2) *(resbegin++) = *(begin2++);
  while (begin1 != end1) *(resbegin++) = *(begin1++);
}

void mergeSort(vector<long int>::iterator massBegin,
               vector<long int>::iterator massEnd, int massSize) {
  if (massSize < 2) return;
  vector<long int>::iterator sredn = massBegin + massSize / 2;
  vector<long int> left(massBegin, sredn);
  vector<long int> right(sredn, massEnd);
  mergeSort(left.begin(), left.end(), left.size());
  mergeSort(right.begin(), right.end(), right.size());
  mergeArrays(left.begin(), left.end(), right.begin(), right.end(), massBegin);
}

int main() {
  int num1;
  cin >> num1;
  vector<long int> mass1(num1);
  for (int i = 0; i < num1; i++) cin >> mass1[i];

  mergeSort(mass1.begin(), mass1.end(), mass1.size());

  for (int i = 0; i < num1; i++) cout << mass1[i] << " ";
  return 0;
}