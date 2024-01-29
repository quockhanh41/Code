#include <iostream>
#include <vector>
using namespace std;
class Node // component
{
public:
    Node(){};
    virtual double evaluate() = 0;
};

class NumNode : public Node // leaf
{
    int value;

public:
    NumNode(int value)
    {
        this->value = value;
    }
    double evaluate() { return value; }
};

class Opnode : public Node // composite
{
private:
    char op;
    Node *right;
    Node *left;

public:
    Opnode(char op)
    {
        this->op = op;
    }
    void addRight(NumNode newNode)
    {
        Node *node = &newNode;
        right = node;
    }
    void addRight(Opnode newNode)
    {
        Node *node = &newNode;
        right = node;
    }
    void addLeft(NumNode newNode)
    {
        Node *node = &newNode;
        left = node;
    }
    void addLeft(Opnode newNode)
    {
        Node *node = &newNode;
        left = node;
    }
    double evaluate()
    {
        if (op == '+')
            return right->evaluate() + left->evaluate();
        else if (op == '-')
            return right->evaluate() - left->evaluate();
        if (op == '*')
            return right->evaluate() * left->evaluate();
        return right->evaluate() / left->evaluate();
    }
};

int main()
{
    Opnode n1('+');
    n1.addLeft(NumNode(3));
    n1.addRight(NumNode(4));

    Opnode n2('*');
    n2.addLeft(NumNode(2));
    n2.addRight(n1);

    double x = n2.evaluate();
    cout << x;
    return 0;
}