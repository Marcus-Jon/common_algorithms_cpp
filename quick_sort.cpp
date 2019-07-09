#include <iostream>

using namespace std;

int partition(int num_array[], int first, int last)
{
  int pivot = num_array[first];
  int leftmark =  first + 1;
  int rightmark = last;
  int temp;

  bool finished = false;

  while(!finished)
  {
    while(leftmark <= rightmark && num_array[leftmark] <= pivot)
    {
      leftmark++;
    }
    while(rightmark >= leftmark && num_array[rightmark] >= pivot)
    {
      rightmark--;
    }
    if(rightmark < leftmark)
    {
      finished = true;
    }
    else
    {
      temp = num_array[leftmark];
      num_array[leftmark] = num_array[rightmark];
      num_array[rightmark] = temp;
    }
  }
  temp = num_array[first];
  num_array[first] = num_array[rightmark];
  num_array[rightmark] = temp;

  return rightmark;
}

void helper(int num_array[], int first, int last)
{
  if(first < last)
  {
    int split = partition(num_array, first, last);

    helper(num_array, first, (split - 1));
    helper(num_array, (split + 1), last);
  }
}

void quick_sort(int num_array[])
{
  helper(num_array, 0, 9);
}

int main()
{
  int num_array[10] = {1, 5, 3, 8, 6, 0, 9, 2, 4, 7};

  quick_sort(num_array);

  for (int i = 0; i < 10; i++)
  {
    cout << num_array[i] << ',';
  }
  return 0;
}
