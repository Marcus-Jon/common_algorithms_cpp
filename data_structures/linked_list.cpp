#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

class Linked_List
{
  public:
    Linked_List()
    {
      head = NULL;
      tail = NULL;
    }
    // returns the head position of the list.
    node* get_head()
    {
      return head;
    }

    // returns the position that the user requests so that a new node can be inserted at that position.
    node* get_pos(node *a)
    {
      int n;
      cout << "Which position do you want? (starts at 0)" << endl;
      cin >> n;
      int i = 1;
      node* current;
      current = head;
      while(i != n && current != NULL)
      {
        current = current->next;
        i++;
      }
      return current;
    }
    // adding nodes ------------------------------------------------------------
    void add_head(int n)
    {
      node *tmp = new node;
      tmp->data = n;
      tmp->next = head;
      head = tmp;
    }

    void add_node(int n)
    {
      // the new operator allows the memory space to be assigned dynamically.
      // this amount of memory allocated is determined at runtime rather than compile.
      // the amount of memory for the node struct is allocated.
      // the address of that memory is assigned to a pointer.
      node *tmp = new node;
      // giving a value to the data of the tmp node.
      tmp->data = n;
      tmp->next = NULL;

      // if head is null the current node will become the head.
      if(head == NULL)
      {
        head = tmp;
        tail = tmp;
      }
      else
      // the tail node will be changed to point to the new node.
      {
        tail->next = tmp;
        tail = tail->next;
      }
    }

    void insert_node(node *a, int n)
    {
      node *tmp = new node;
      tmp->data = n;
      tmp->next = a->next;
      a->next = tmp;
    }

    void delete_node(node *a)
    {
      node *tmp;
      tmp = a->next;
      a->next = tmp->next;
      delete tmp;
    }
    // printing ----------------------------------------------------------------
    void print_list()
    {
      node *tmp;
      tmp = head;
      // while the next element is not null print and move to next element
      while(tmp != NULL)
      {
        cout << tmp->data << endl;
        tmp = tmp->next;
      }
    }

    // joining -----------------------------------------------------------------
    /* used to join to lists together. Static means that it will have
    scope for the lifetime of the program.*/
    static void join_list(node *a, node *b)
    {
      if(a != NULL && b != NULL)
      {
        // if the next element is null then the next element becomes the head of b.
        if(a->next == NULL)
        {
          a->next = b;
        }
        else
        {
          join_list(a->next, b);
        }
      }
    }
  private:
    node *head, *tail;
};

int main()
{
  Linked_List a_list;
  a_list.add_node(3);
  a_list.add_node(6);

  Linked_List b_list;
  b_list.add_node(4);
  b_list.add_node(7);

  Linked_List::join_list(a_list.get_head(), b_list.get_head());

  a_list.add_head(2);

  node* pos;
  pos = a_list.get_pos(a_list.get_head());
  a_list.insert_node(pos, 123);
  a_list.print_list();

  pos = a_list.get_pos(a_list.get_head());
  a_list.delete_node(pos);
  a_list.print_list();

  return 0;
}

//https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/
