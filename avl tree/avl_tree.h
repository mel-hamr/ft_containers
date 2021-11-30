#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>


class Node {
   public:
  int value;
  std::string key;
  Node *left;
  Node *right;
  Node *parent;
  int height;
};

int height(Node *N)
{
  if (N == NULL)
	return 0;
  return N->height;
}

int max(int a, int b) 
{
  return (a > b) ? a : b;
}

int getBalanceFactor(Node *N)
{
  if (N == NULL)
	return 0;
  return height(N->left) - height(N->right);
}

// Rotate right
Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	y->parent = x->parent;
	x->parent = y;
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

Node *newNode(std::string key,int value)
{
  Node *node = new Node();
  node->key = key;
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  node->height = 1;
  return (node);
}

Node *insertNode(Node *node, std::string key,int value)
{
  // Find the correct postion and insert the node
	Node *n_node;


	if (node == NULL)
		return (newNode(key,value));
	if (value < node->value)
	{
		n_node = insertNode(node->left, key,value);
		node->left = n_node;
		n_node->parent = node;
	}
	else if (value > node->value)
	{
		n_node = insertNode(node->right, key,value);
		node->right = n_node;
		n_node->parent = node;
	}
	else
		return node;

	// Update the balance factor of each node and
	// balance the tree
	node->height = 1 + max(height(node->left),
				height(node->right));
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor > 1) {
		std::cout << "FB =" << balanceFactor<<  "\n";
		if (value < node->left->value) {
		return rightRotate(node);
		} else if (value > node->left->value) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (value > node->right->value) {
		return leftRotate(node);
		} else if (value < node->right->value) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
		}
	}
	return node;
}

void printTree(Node *root, std::string indent, bool last)
{
  if (root != nullptr)
  {
	std::cout << indent;
	if (last) 
	{
		std::cout << "R----";
		indent += "   ";
	} 
	else
	{
		std::cout << "L----";
		indent += "|  ";
	}

	std::cout << root->value << " "<< root->height<<std::endl;
	printTree(root->left, indent, false);
	printTree(root->right, indent, true);
  }
}
// Delete a node
Node *deleteNode(Node *root, int value) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (value < root->value)
    root->left = deleteNode(root->left, value);
  else if (value > root->value)
    root->right = deleteNode(root->right, value);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->value = temp->value;
      root->right = deleteNode(root->right,
                   temp->value);
    }
  }
Node *search(Node *root,int val)
{
	if(root == NULL)
		return (NULL);
	if(root->value == val)
		return (root);
	if(root->value < val)
	{
		root = search(root->right,val);
	}
	if(root->value > val)
	{
		root = search(root->left,val);
	}
	return(root);
}
#endif