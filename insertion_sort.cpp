#include <iostream>

using namespace std;

int main()
{
  int numbers[10] = {8, 4, 2, 7, 6, 1, 0, 3, 5, 9};
  // Insertion sort

  for (int i = 0; i <= 10; i++)
  {
    int value = numbers[i];
    int index = i;

    while (index > 0 && numbers[index - 1] > value)
    {
      numbers[index] = numbers[index - 1];
      index--;
    }
    numbers[index] = value;
  }

  for (int i = 0; i <= 9; i++)
  {
    cout << numbers[i] << ", ";
  }

  return 0;
}
