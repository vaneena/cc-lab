#include<iostream>
#include <cstring>
#include<string>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

typedef struct treenode* tree;
struct treenode
{
    char info;
    tree left;
    tree right;
};

static int i = 0;
char nextsym(char input[]), next;
char input[10];

int main()
{
    tree root = nullptr;  // Initialize root as nullptr
    int len;
    tree proc_e();
    void inorder(tree root);

    cout << "Enter an expression: \n";
    cin >> input;

    len = strlen(input);
    next = nextsym(input);
    root = proc_e();

    if (len != i - 1)
    {
        cout << "Error" << endl;
        cin.get();  // Pauses the screen
        exit(0);
    }
    else
    {
        cout << "It's a valid expression\n";
        inorder(root);
    }

    return 0;
}

tree treebuild(char x, tree a, tree b)
{
    tree t = new treenode;
    t->info = x;
    t->left = a;
    t->right = b;
    return t;
}

tree proc_e()
{
    tree a, b;
    tree proc_t();
    a = proc_t();

    while (next == '+' || next == '-')
    {
        if (next == '+')
        {
            next = nextsym(input);
            b = proc_t();
            a = treebuild('+', a, b);
        }
        else
        {
            next = nextsym(input);
            b = proc_t();
            a = treebuild('-', a, b);
        }
    }

    return a;
}

tree proc_t()
{
    tree a, b;
    tree proc_v();
    a = proc_v();

    while (next == '*' || next == '/')
    {
        if (next == '*')
        {
            next = nextsym(input);
            b = proc_v();
            a = treebuild('*', a, b);
        }
        else
        {
            next = nextsym(input);
            b = proc_v();
            a = treebuild('/', a, b);  // Fixed the division operator
        }
    }

    return a;
}

tree proc_v()
{
    tree a;

    if (isalpha(next))
        a = treebuild(next, nullptr, nullptr);
    else
    {
        cout << "Error";
        cin.get();  // Pauses the screen
        exit(0);
    }

    next = nextsym(input);
    return a;
}

char nextsym(char input[])
{
    i++;
    return input[i - 1];
}

void inorder(tree t)
{
    if (t != nullptr)
    {
        inorder(t->left);
        cout << t->info << "   ";
        inorder(t->right);
    }
}
