#include <iostream>

using namespace std;

int main()
{
  int numbers[10] = {8, 4, 2, 7, 6, 1, 0, 3, 5, 9};
  int temp;
  // Selection sort.

  for (int i = 0; i <= 10; i++)
  {
    // Set the minimum value and the index location of that value.
    int min_index = i;
    int min_value = numbers[i];

    for (int j = (i + 1); j <= 9; j++)
    {
      // Compare minimum value with the next one to find the smallest value.
      // Change the minimum when found.
      if (min_value > numbers[j])
      {
        min_index = j;
        min_value = numbers[j];
      }
    }
    temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp;
  }

  for (int i = 0; i <= 9; i++)
  {
    cout << numbers[i] << ", ";
  }
  return 0;
}
