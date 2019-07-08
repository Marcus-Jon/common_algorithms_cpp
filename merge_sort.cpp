#include <iostream>

using namespace std;

void merge(int num_array[], int left, int midpoint, int right)
{
  int x = 0;
  int y = 0;
  int z = left;

  int val_1 = midpoint - left + 1;
  int val_2 = right - midpoint;

  int Left[val_1];
  int Right[val_2];

  for (int i = 0; i < val_1; i++) {Left[i] = num_array[left + i];}
  for (int j = 0; j < val_2; j++) {Right[j] = num_array[midpoint + 1 + j];}

  while(x < val_1 && y < val_2)
    {
      if(Left[x] <= Right[y])
        {
          num_array[z] = Left[x];
          x++;
        }
      else
        {
          num_array[z] = Right[y];
          y++;
        }
      z++;
    }
    while(x < val_1)
      {
        num_array[z] = Left[x];
        x++;
        z++;
      }
    while(y < val_2)
      {
        num_array[z] = Right[y];
        y++;
        z++;
      }

}


void merge_sort(int num_array[], int left, int right)
{
  if (left < right)
  {
    int midpoint = left + (right - left) / 2;

    merge_sort(num_array, left, midpoint);
    merge_sort(num_array, midpoint + 1, right);

    merge(num_array, left, midpoint , right);
  }

}


int main()
{
  int num_array[10] = {1, 5, 3, 8, 6, 0, 9, 2, 4, 7};
  int array_size = (sizeof(num_array)/sizeof(*num_array));
  merge_sort(num_array, 0, array_size - 1);

  for (int i = 0; i < array_size; i++)
  {
    cout << num_array[i] << ',';
  }

  return 0;
}
