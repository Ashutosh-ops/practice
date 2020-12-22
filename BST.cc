#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int data;
    node *left;
    node *right;
} node;

node *root = NULL;

///////////////////////////////////////////////////////////////////////////////////////

node *find(node *root, int data)
{
    if (root == NULL)
    {
        return NULL; // or return root;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        if (current->data == data)
        {
            return current;
        }
        // std::cout << current->data << "  ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
    return NULL;
}

//////////////////////////////////////////////////////////////////////////////////////
node *getelement(int data)
{
    node *element = new node();
    element->data = data;
    element->left = element->right = NULL;
    return element;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = getelement(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
        return root;
    }
    else
    {
        root->right = insert(root->right, data);
        return root;
    }
}
/////////////////////////////////////////////////////////////////////////////////
void level_order_printing()
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        std::cout << current->data << "  ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    std::cout << root->data << "  ";
    inorder(root->right);
}
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout << root->data << "  ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    std::cout << root->data << "  ";
}
void BFS_order()
{
    int x;
    std::cout << "Enter 1 for Preorder traversal " << std::endl;
    std::cout << "Enter 2 for Inorder traversal" << std::endl;
    std::cout << "Enter 3 for Postorder traversal " << std::endl;
    std::cout << "Enter 4 to go to prev-menu " << std::endl;
    std::cin >> x;
    std::cout << std::endl;
    switch (x)
    {

    case 1:
        Preorder(root);
        std::cout << std::endl;
        std::cout << std::endl;
        break;
    case 2:
        inorder(root);
        std::cout << std::endl;
        std::cout << std::endl;
        break;
    case 3:
        Postorder(root);
        std::cout << std::endl;
        std::cout << std::endl;
        break;
    case 4:
        exit(0);
        break;
    default:
        std::cout << "you entered wrong choice: " << std::endl;
        break;
    }
}

// To know more about newline kindly visit the given URL:
// https://gcc.gnu.org/onlinedocs/libstdc++/manual/streambufs.html#io.streambuf.buffering

void printtree()
{
    std::cout << "Enter 1 for level order traversal." << std::endl;
    std::cout << "Enter 2 for Breath first traversal." << std::endl;
    std::cout << "Enter 3 to exit this sub-menu." << std::endl;
    int x;
    std::cout << "Input your choice: " << std::endl;
    std::cin >> x;
    std::cout << std::endl;
    switch (x)
    {
    case 1:
        level_order_printing();
        std::cout << std::endl;
        std::cout << std::endl;
        break;
    case 2:
        BFS_order();
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
    }
}

//////////////////////////////////////////////////////////////////////////////////

int miniteration()
{
    if (root == NULL)
    {
        std::cout << "Error ! Tree is empty" << std::endl;
        return -1;
    }
    node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

int minrecursion(node *root)
{
    if (root == NULL)
    {
        std::cout << "Error ! Tree is empty" << std::endl;
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return minrecursion(root->left);
}

int maxiteration()
{
    if (root == NULL)
    {
        std::cout << "Error ! Tree is empty" << std::endl;
        return -1;
    }
    node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int maxrecursion(node *root)
{
    if (root == NULL)
    {
        std::cout << "Error ! Tree is empty" << std::endl;
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return maxrecursion(root->right);
}
////////////////////////////////////////////////////////////////////////////////////
void findlog()
{
    int x;
    std::cout << "Enter 1 for finding min. term in BST via recursion " << std::endl;
    std::cout << "Enter 2 for finding min. term in BST via iteration " << std::endl;
    std::cout << "Enter 3 for finding max. term in BST via recursion " << std::endl;
    std::cout << "Enter 4 for finding max. term in BST via iteration " << std::endl;
    std::cout << "Enter 5 to go to pre-menu " << std::endl;
    std::cin >> x;
    std::cout << std::endl;
    switch (x)
    {
    case 1:
        std::cout << "Minimum in BST: " << minrecursion(root) << std::endl;
        break;
    case 2:
        std::cout << "Minimum in BST: " << miniteration() << std::endl;
        break;
    case 3:
        std::cout << "Maximum in BST: " << maxrecursion(root) << std::endl;
        break;
    case 4:
        std::cout << "Maximum in BST: " << maxiteration() << std::endl;
        break;
    case 5:
        // exit(0);
        break;
    default:
        std::cout << "You Entered wrong choice " << std::endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////
bool Is_Sub_tree_lesser(node *root, int data)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < data &&
        Is_Sub_tree_lesser(root->left, data) &&
        Is_Sub_tree_lesser(root->right, data))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Is_Sub_tree_greater(node *root, int data)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > data &&
        Is_Sub_tree_greater(root->left, data) &&
        Is_Sub_tree_greater(root->right, data))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsBST(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (Is_Sub_tree_lesser(root->left, root->data) &&
        Is_Sub_tree_greater(root->right, root->data) &&
        IsBST(root->left) &&
        IsBST(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//////////////////////////////////////////////////////////////////////////////

int find_height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return (((find_height(root->left) >= find_height(root->right)) ? find_height(root->left) : find_height(root->right)) + 1);
    // int lst, rst;
    // lst = find_height(root->left);
    // rst = find_height(root->right);
}
//////////////////////////////////////////////////////////////////////////////////
// Recursive Method:-

// node* minrecursion_nod(node *root)
// {
//     if (root == NULL)
//     {
//         std::cout << "Error ! Tree is empty" << std::endl;
//         return NULL;
//     }
//     else if (root->left == NULL)
//     {
//         return root;
//     }
//     return minrecursion_nod(root->left);
// }
/************************************************************************************************************/
// Iterative Method:-

node *findmin(node *temp)
{
    if (temp == NULL)
    {
        return NULL;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *delete_an_element(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete_an_element(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_an_element(root->right, data);
    }
    else
    {
        //When there is no child:
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        //When there is one child:
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        // When there is 2 child:
        else
        {
            node *temp = findmin(root->left);
            root->data = temp->data;
            root->right = delete_an_element(root->right, temp->data);
        }
    }
    return root;
}
///////////////////////////////////////////////////////////////////////////////////

node *getsuccessor(node *root, int data)
{
    //searching node O(h)
    node *current = find(root, data);
    if (current == NULL)
    {
        return NULL;
    }
    //Case 1: node has right subtree
    if (current->right != NULL)
    {
        // temp = findmin(current->right);
        // std::cout << temp->data << std::endl;
        return findmin(current->right);
    }
    // Case 2: no right subtree
    else
    {
        node *successor = NULL, *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        // std::cout << successor->data << std::endl;
        return successor;
    }
}

int menu()
{
    int x = 0;
    std::cout << "Enter 1 for insert element in BST " << std::endl;
    std::cout << "Enter 2 for printing the BST " << std::endl;
    std::cout << "Enter 3 for finding max. or min. term in BST " << std::endl;
    std::cout << "Enter 4 for check BST is BST or not." << std::endl;
    std::cout << "Enter 5 for finding the height of BST." << std::endl;
    std::cout << "Enter 6 for delete an element in BST. " << std::endl;
    std::cout << "Enter 7 to get successor of desired data(element)." << std::endl;
    std::cout << "Enter 8 to exit from menu " << std::endl;
    std::cout << "Enter 9 to search in BST" << std::endl;
    std::cout << "Input your choice: ";
    cin >> x;
    std::cout << std::endl;
    return x;
}

int main(int argc, const char **argv)
{
    root = NULL;
    int data;
    node *temp;
    while (true)
    {
        switch (menu())
        {
        case 1:
            // int data;
            std::cout << "Enter the element: ";
            std::cin >> data;
            std::cout << std::endl;
            root = insert(root, data);
            break;
        case 2:
            printtree();
            break;
        case 3:
            findlog();
            break;
        case 4:
            std::cout << IsBST(root) << std::endl;
            std::cout << std::endl;
            break;
        case 5:
            std::cout << find_height(root) << std::endl;
            break;
        case 6:
            // int data;
            std::cout << "Enter the element you want to delete from BST: ";
            std::cin >> data;
            std::cout << std::endl;
            delete_an_element(root, data);
            break;
        case 7:
            // int data;
            // node *temp;
            std::cout << "Enter the element to get it's successor. ";
            std::cin >> data;
            temp = getsuccessor(root, data);
            std::cout << temp->data << std::endl;
            break;
        case 8:
            exit(0);
            break;
        case 9:
            std::cout << "Enter the element to search: ";
            std::cin >> data;
            std::cout << std::endl;
            temp = find(root, data);
            if (temp == NULL)
            {
                std::cout << "Element not present "<< std::endl;
            }
            else
            {
                std::cout << "Congrats ! Element "<<temp->data<< " is present."<< std::endl;
                std::cout << std::endl;
            }
            break;
        default:
            std::cout << "You ! Entered wrong input, try again" << std::endl;
            break;
        }
    }
    return 0;
}