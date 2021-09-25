
#include <bits/stdc++.h>
using namespace std;
class BST
{
    int data;
    BST *left, *right;
public:
    BST();

    BST(int);
    BST* Insert(BST*, int);
    void Inorder(BST*);
    void Preorder(BST*);
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
    if (value >= root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

typedef pair<int,int> pii;
vector<int>ans1;
vector<int>ans2;
void BST ::Inorder(BST* root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    ans1.push_back(root->data);
    //cout << root->data << ",";
    Inorder(root->right);
}
void BST ::Preorder(BST* root)
{
    if (!root)
    {
        return;
    }
    ans2.push_back(root->data);
    Preorder(root->left);
    Preorder(root->right);
}
// Driver code
int a[1000000];
int dd[1000000];
vector<int>save;
int main()
{
    BST b, *root = NULL;
    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> a[i];
        if ( dd[a[i]] == 0)
        {
            save.push_back(a[i]);
        }
        dd[a[i]]++;
    }
    root = b.Insert(root,save[0]);
    for(int i=1;i<save.size();i++)
        b.Insert(root,save[i]);
    b.Inorder(root);
    for(int i=0;i<ans1.size()-1;i++)
    {
        for(int j=1;j<=dd[ans1[i]];j++)
            cout << ans1[i] << ",";
    }
    for(int j=1;j<=dd[ans1[ans1.size()-1]];j++)
        cout << ans1[ans1.size()-1];
    cout << endl;
    b.Preorder(root);

    for(int i=0;i<ans2.size()-1;i++)
    {
        for(int j=1;j<=dd[ans2[i]];j++)
            cout << ans2[i] << ",";
    }
    for(int j=1;j<=dd[ans2[ans1.size()-1]];j++)
        cout << ans2[ans2.size()-1];
    cout << endl;
    return 0;
}
