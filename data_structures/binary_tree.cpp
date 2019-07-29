#include <iostream>
#include <queue>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

class Binary_tree
{
  public:
    Binary_tree()
    {
      root = NULL;
    }

    node* get_root()
    {
      return root;
    }

    void add_node(int n)
    {
      node *tmp = new node;
      tmp->data = n;
      tmp->left = NULL;
      tmp->right = NULL;

      if(root == NULL)
      {
        root = tmp;
      }
    }

    void insert_node(int n, node *leaf)
    {
      if(n < leaf->data)
      {
        if(leaf->left != NULL)
        {
          insert_node(n, leaf->left);
        }
        else
        {
          leaf->left = new node;
          leaf = leaf->left;
          leaf->data = n;
          leaf->left = NULL;
          leaf->right = NULL;
        }
      }
      if(n > leaf->data)
      {
        if(leaf->right != NULL)
        {
          insert_node(n, leaf->right);
        }
        else
        {
          leaf->right = new node;
          leaf = leaf->right;
          leaf->data = n;
          leaf->left = NULL;
          leaf->right = NULL;
        }
      }
    }
    // Preorder traversal.
    void print_preorder(node *leaf)
    {
      node *tmp = new node;
      tmp = leaf;
      cout << tmp->data << endl;
      if(tmp->left != NULL)
      {
        print_preorder(tmp->left);
      }
      else
      {
        cout << "NULL" << endl;
      }
      if(tmp->right != NULL)
      {
        print_preorder(tmp->right);
      }
      else
      {
        cout << "NULL" << endl;
      }
    }
    // Level order traversal.
    void print_level_order()
    {
      if(root == NULL)
      {return;}

      queue <node *> q;

      q.push(root);
      int marker = root->data;
      while(q.empty() != true)
      {
        node *tmp = q.front();
        cout << tmp->data << " ";
        if(marker == tmp->data)
        {
          cout << " " << endl;
          if(tmp->right != NULL)
          {
            marker = tmp->right->data;
          }
          if(tmp->right == NULL && tmp->left != NULL)
          {
            marker = tmp->left->data;
          }
          if(tmp->right == NULL and tmp->left == NULL)
          {
            marker = q.back()->data;
          }
        }
        q.pop();

        if(tmp->left != NULL)
        {
          q.push(tmp->left);
        }
        if(tmp->right != NULL)
        {
          q.push(tmp->right);
        }
      }
      cout << " " << endl;
      cout << " " << endl;
    }
      node* delete_node(node *leaf, int n)
      {
        if(leaf->left != NULL)
        {
          if(leaf->left->data == n)
          {
            if(leaf->left->left == NULL && leaf->left->right == NULL)
            {
              leaf->left = NULL;
              return leaf;
            }
            else if(leaf->left->left == NULL)
            {
              leaf->left = leaf->left->left;
              return leaf;
            }
            else if(leaf->left->right == NULL)
            {
              leaf->right = leaf->left->right;
              return leaf;
            }
            else
            {
              node *tmp_left = new node;
              node *tmp_right = new node;

              tmp_left = leaf->left->left;
              tmp_right = leaf->left->right;

              leaf->left = tmp_left;
              leaf->left->right = tmp_right;

              return leaf;
            }
          }
        }

        if(leaf->right != NULL)
        {
          if(leaf->right->data == n)
          {
            if(leaf->right->left == NULL && leaf->right->right == NULL)
            {
              leaf->right = NULL;
              return leaf;
            }
            else if(leaf->right->left == NULL)
            {
              leaf->right = leaf->right->right;
              return leaf;
            }
            else if(leaf->right->right == NULL)
            {
              leaf->right = leaf->right->left;
              return leaf;
            }
            else
            {
              cout << "this" << endl;
              node *tmp_left = new node;
              node *tmp_right = new node;

              tmp_left = leaf->right->left;
              tmp_right = leaf->right->right;

              leaf->right = tmp_right;
              leaf->right->left = tmp_left;
              return leaf;
            }
          }
        }

        if(n > leaf->data)
        {
          delete_node(leaf->right, n);
        }
        if(n < leaf->data)
        {
          delete_node(leaf->left, n);
        }
      }
  private:
    node *root;
};

int main()
{
  Binary_tree root;
  root.add_node(10);
  root.insert_node(5, root.get_root());
  root.insert_node(2, root.get_root());
  root.insert_node(15, root.get_root());
  root.insert_node(12, root.get_root());
  root.insert_node(4, root.get_root());
  root.insert_node(6, root.get_root());
  root.insert_node(3, root.get_root());
  root.insert_node(4, root.get_root());
  //root.print_preorder(root.get_root());
  root.print_level_order();
  root.delete_node(root.get_root(), 15);
  root.print_level_order();


  return 0;
}
