#include <iostream>

using namespace std;

class Queue
{
  public:
    Queue()
    {}

    void Insert(int val)
    {
      if(rear == (n - 1))
      {
        cout << "Queue Overflow" << endl;
      }
      else
      {
        rear ++;
        queue[rear] = val;
      }
    }
    void Delete()
    {
      if(rear < front)
      {
        cout << "Cannot remove item, queue empty" << endl;
      }
      else
      {
        int temp;
        for(int i = 1; i <= rear; i++)
        {
          queue[i - 1] = queue[i];
        }
        rear --;
      }
    }
    void Print()
    {
      for (int i = front; i <= rear; i++)
      {
        cout << queue[i] << ',';
      }
      cout << '\n';
    }
    int get_front_val()
    {
      return queue[front];
    }
    int get_rear_val()
    {
      return queue[rear];
    }
    void set_size(int size)
    {
      queue = new int[size];
      n = size;
    }

  private:
    int* queue;
    int n;
    int front = 0;
    int rear = -1;
};

int main()
{
  Queue q;
  q.set_size(10);

  q.Insert(5);
  q.Insert(4);
  q.Insert(10);
  q.Insert(29);
  q.Print();
  q.Delete();
  q.Print();

  cout << q.get_rear_val() << endl;

  return 0;
}
