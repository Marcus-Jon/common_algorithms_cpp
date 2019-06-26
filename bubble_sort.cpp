#include <iostream>

using namespace std;

int main()
{
  int numbers[10] = {8, 4, 2, 7, 6, 1, 0, 3, 5, 9};

  int temp;
  for (int i = 0; i <= 9; i++)
  {
    for (int j = 0; j <= (9 - i); j++)
    {
      if (numbers[j] > numbers[j + 1])
      {
        temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }


  for (int i = 0; i <= 9; i++)
  {
    cout << numbers[i] << ", ";
  }
  return 0;
}
