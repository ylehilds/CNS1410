#include <iostream>

using namespace std;

class Node
{
public:
   Node(string v);
   ~Node();
   string value;
   Node* left;
   Node* right;
   Node* copy();
};

Node::Node(string v) : value(v), left(NULL), right(NULL) { }

Node::~Node()
{
   //cout << "deleting " << value << "\n";
   delete left;
   delete right;
}

Node* Node::copy()
{
   Node* n = new Node(value);
   if (left != NULL)
      n->left = left->copy();
   if (right != NULL)
      n->right = right->copy();
   return n;
}

class Tree
{
public:
   Tree();
   ~Tree();
   Tree(const Tree& right);
   void add(string v);
   bool contains(string v);
   Tree& operator=(const Tree& right);
private:
   void free();
   void copy(const Tree& right);
   Node* root;
};

Tree::Tree() : root(NULL) { }

Tree::~Tree() { free(); }

void Tree::free() { delete root; }

void Tree::copy(const Tree& right)
{
   if (right.root == NULL)
      root = NULL;
   else
      root = right.root->copy();
}

Tree::Tree(const Tree& right)
{
   copy(right);
}

Tree& Tree::operator=(const Tree& right)
{
   if (this != &right) 
   {
      free();
      copy(right);
   }
   return *this;
}

void Tree::add(string v) 
{
   if (root == NULL) 
   {
      root = new Node(v);
      return;
   }
   Node * r = root;
   while (r != NULL) 
   {
      if (v < r->value)
      {
	 if (r->left == NULL)
	 {
	    r->left = new Node(v);
	    return;
	 }
	 else r = r->left;
      } else {
	 if (r->right == NULL)
	 {
	    r->right = new Node(v);
	    return;
	 }
	 else r = r->right;
      }
   }
}

bool Tree::contains(string v)
{
   if (root == NULL)
      return false;
   Node* r = root;
   while (r != NULL)
   {
      if (r->value == v)
	 return true;
      if (v < r->value)
	 r = r->left;
      else
	 r = r->right;
   }
   return false;
}

int main() {
   Tree a;
   a.add("Juliet");
   a.add("Eve");
   a.add("Adam");
   a.add("Romeo");
   a.add("Penelope");
   a.add("Tom");
   a.add("Harry");
   if (a.contains("Eve"))
      cout << "contains eve\n";
   if (a.contains("Joe"))
      cout << "contains joe\n";
   else
      cout << "does not contain joe\n";
   Tree b;
   b = a;
   if (b.contains("Eve"))
      cout << "contains eve\n";
   if (b.contains("Joe"))
      cout << "contains joe\n";
   else
      cout << "does not contain joe\n";
}

