
#include <iostream>
using namespace std;
class BST
{

    int data;

    BST *left, *right;


public:

    // Default constructor.

    BST();


    // Parameterized constructor.

    BST(int);


    // Insert function.

    BST* Insert(BST*, int);



    void Inorder(BST*);
};


BST ::BST()

    : data(0)

    , left(NULL)

    , right(NULL)
{
}

BST ::BST(int value)
{

    data = value;

    left = right = NULL;
}


BST* BST ::Insert(BST* root, int value)
{

    if (!root)

    {
        return new BST(value);

    }

    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);

    }


    // Return 'root' node, after insertion.

    return root;
}

// Inorder traversal function.
// This gives data in sorted order.

void BST ::Inorder(BST* root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
void BST ::preorder(BST* root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}
// Driver code

int main()
{
    BST b, *root = NULL;
    int n;
    cin >> n;
    int x;
    cin >> x;
    root = b.Insert(root,x);
    for(int i=2;i<=n;i++)
    {
        int x;
        cin >> x;
        b.Insert(root,x);
    }
    b.Inorder(root);
    b.preorder(root);
    return 0;
}
