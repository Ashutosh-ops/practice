// WAP to Search an Element in a Tree Recursively.

#include <stdio.h>
#include <stdlib.h>
// #include<conio.h>

// void insert( long int data);
// void inOrder(struct node *node);
// void preOrder(struct node *node);
// void postOrder(struct node *node);
// void search( struct node* current, int key);

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void In_order(struct node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    In_order(curr->left);
    printf("%d\t", curr->data);
    In_order(curr->right);
}

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t", root->data);
}

struct node *newNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *InsertRoot(struct node *current, int data)
{
    if (current == NULL)
    {
        current = newNode(data);
        return current;
    }
    else if (data <= current->data)
    {
        current->left = InsertRoot(current->left, data);
        return current;
    }
    else
    {
        current->right = InsertRoot(current->right, data);
        return current;
    }
}

void search(struct node *parent, int key)
{
    struct node *current = parent;

    if (current == NULL)
    {
        return;
    }
    else
    {
        if (current->data == key)
        {
            printf("\n Element Found!\n");
            return;
        }
        else if (key < current->data)
        {
            search(current->left, key);
        }
        else
        {
            search(current->right, key);
        }
    }
}

int main()
{
    int choice;
    int data, key;
    // struct node *root;
    while (1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                     Binary Search Tree                     |");
        printf("\n ------------------------------------------------------------\n\n");

        printf(" Press any key to Continue... ");
        getchar();

        printf("\n\n --X--X--X--X--X-- Operation on Linked List --X--X--X--X--X--");
        printf("\n|                                                            |");
        printf("\nX    1. Insert Data                                          X");
        printf("\n|    2. Inorder Traversal                                    |");
        printf("\nX    3. Preorder traversal                                   X");
        printf("\n|    4. Postorder Traversal                                  |");
        printf("\nX    5. Search an Element                                    X");
        printf("\n|    6. Exit                                                 |");
        printf("\nX                                                            X");
        printf("\n --X--X--X--X--X--X--X--X--X---X--X--X--X--X--X--X--X--X--X--");

        printf("\n\n Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n ------------------------------------------------------------");
            printf("\n|                       Insertion of data                    |");
            printf("\n ------------------------------------------------------------\n\n");
            printf("\n Enter the Element: ");
            scanf("%d", &data);
            root = InsertRoot(root, data);
            break;
        case 2:
            // printf("\n ------------------------------------------------------------");
            // printf("\n|                      Inorder Traversal!                   |");
            // printf("\n ------------------------------------------------------------\n\n");
            printf("\nCalled\n");
            In_order(root);
            break;
        case 3:
            printf("\n ------------------------------------------------------------");
            printf("\n|                      Preorder Traversal!                   |");
            printf("\n ------------------------------------------------------------\n\n");

            preOrder(root);
            break;
        case 4:
            printf("\n ------------------------------------------------------------");
            printf("\n|                     Postorder Traversal!                   |");
            printf("\n ------------------------------------------------------------\n\n");

            postOrder(root);
            break;
        case 5:
            printf("\n ------------------------------------------------------------");
            printf("\n|                       Searching Element!                   |");
            printf("\n ------------------------------------------------------------\n\n");
            printf("Enter the Element to Search: ");
            scanf("%d", &key);
            search(root, key);
            break;
        case 6:
            printf("\n ------------------------------------------------------------");
            printf("\n|              Linked List Implementation Ended!             |");
            printf("\n ------------------------------------------------------------\n\n");
            exit(0);
            break;
        default:
            printf("\n ------------------------------------------------------------");
            printf("\n|                       Invalid Choice!                      |");
            printf("\n ------------------------------------------------------------\n\n");
        }
    }
    return 0;
}
