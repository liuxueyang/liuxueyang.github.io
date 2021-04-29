#include <iostream>

using namespace std;

using TypeId = const void *;

template<typename T>
class TypeIdHelper {
public:
  static bool dummy;
};

template <typename T>
bool TypeIdHelper<T>::dummy = false;

template<typename T>
TypeId GetTypeId() {
  return &(TypeIdHelper<T>::dummy);
}

int add(int a, int b) { return a + b; }
int add1(int a, int b) { return a + b; }

int main() {
  cout << GetTypeId<int>() << endl;
  cout << GetTypeId<double>() << endl;
  cout << GetTypeId<char>() << endl;
  cout << GetTypeId<int>() << endl;

  auto f = [](int x, int y) { return x + y; };
  cout << GetTypeId<decltype(f)>() << endl;

  auto f1 = [](int x, int y) { return x + y; };
  cout << GetTypeId<decltype(f1)>() << endl;

  cout << GetTypeId<decltype(f)>() << endl;

  cout << GetTypeId<decltype(add)>() << endl;
  cout << GetTypeId<decltype(add1)>() << endl;

  return 0;
}
