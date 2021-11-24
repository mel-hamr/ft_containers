#include "avl_tree.h"


int main()
{
    avl *first;
    avl *node;



    first = new_node("first",10);


    first = insert_new_node(first,new_node("seconde",5));
    first = insert_new_node(first,new_node("seconde",12));
    first = insert_new_node(first,new_node("seconde",6));
    first = insert_new_node(first,new_node("seconde",13));
    first = insert_new_node(first,new_node("seconde",1));
    first = insert_new_node(first,new_node("seconde",11));



    // std::cout << first->right->right->_value;
    // std::cout << first->left->right->_value;

    print_tree(first);


}