#include <iostream>

using namespace std;

class Stack
{
  public:
    Stack()
    {}
    void Insert(int val)
    {
      if(top == (n - 1))
      {
        cout << "Stack Overflow" << endl;
      }
      else
      {
        top ++;
        stack[top] = val;
      }
    }
    void Delete()
    {
      if(top < 0)
      {
        cout << "Stack empty, item cannot be removed" << endl;
      }
      else
      {
        stack[top] = 0;
        top --;
      }

    }
    void Print()
    {
      for(int i = 0; i <= top; i++)
      {
        cout << stack[i] << ',';
      }
      cout << '\n';
    }

    int get_top_val()
    {
      return stack[top];
    }
    void set_size(int size)
    {
      stack = new int[size];
      n = size;
    }
  private:
    int* stack;
    int n;
    int top = -1;
};

int main()
{
  Stack s;

  s.set_size(10);

  s.Insert(5);
  s.Insert(20);
  s.Insert(2314);

  s.Print();

  cout << s.get_top_val() << endl;

  s.Delete();

  s.Print();

  return 0;
}
