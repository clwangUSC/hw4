#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int getHeight(Node *root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int leftHeight = 1+getHeight(root->left);
	int rightHeight = 1+getHeight(root->right);
	int greatestHeight = leftHeight;
	if(rightHeight>greatestHeight)
	{
		greatestHeight = rightHeight;
	}
	return greatestHeight;
}

bool equalPaths(Node * root)
{
    if(root == nullptr)
    {
        return true;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    if(root->left != nullptr)
    {
        if(root->left->left == nullptr && root->left->right == nullptr)
        {
            return (root->right == nullptr || (root->right->left==nullptr && root->right->right==nullptr));
        }
    }
    if(root->right != nullptr)
    {
        if(root->right->left == nullptr&&root->right->right == nullptr)
        {
            return (root->left == nullptr || (root->left->left==nullptr && root->left->right==nullptr));
        }
    }
    
    /*
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if(rightHeight!=leftHeight)
    {
      return false;
    }
    */
    return (equalPaths(root->right)&&equalPaths(root->left));
}




/**bool treeComplete(Node* root)
{
    if(root == nullptr)
    {
        return true;
    }
    else if(root->left==nullptr && root->right==nullptr)
    {
        return true;
    }
    else if(root->left==nullptr && root->right!=nullptr)
    {
        return false;
    }
    else if(root->left!=nullptr && root->right==nullptr) 
    {
        return false;
    }
    else
    {
        return (equalPaths(root->right) && equalPaths(root->left));
    }
} **/

