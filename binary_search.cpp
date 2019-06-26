#include <iostream>

using namespace std;

int main()
{
  int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Binary search for integers.

  bool found = 0;
  int min = 0;
  int max = 9;

  int search_value;
  cout << "What are you searching for" << endl;
  cin >> search_value;
  cout << "search value is: " << search_value << endl;

  while(found == 0)
  {
    int avg = (min + max) / 2;
    cout << "average is: " << avg << endl;

    if(numbers[avg] == search_value)
    {
      found = 1;
      cout << "found at position " << avg << endl;
    }
    else if(search_value > numbers[avg])
    {
      min = avg + 1;
    }
    else if(search_value < numbers[avg])
    {
      max = avg - 1;
    }
  }
  return 0;
}
