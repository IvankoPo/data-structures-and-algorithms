#include<iostream>

struct BinaryTree
{
    int Data;
    BinaryTree* Left;
    BinaryTree* Right;
    BinaryTree(int d)
    {
        this->Data = d;
        this->Left = NULL;
        this->Right = NULL;
    }
    // Поиск возвращает узел с заданным значением
    // Иначе NULL
    BinaryTree* Find(BinaryTree* Node, int Value)
    {
        if (Node == NULL)
            return NULL;
        if (Node->Data == Value)
            return Node;
        if (Node->Data > Value)
            return Find(Node->Left, Value);
        else
            return Find(Node->Right, Value);
    }
    // Поиск минимального
    BinaryTree* FindMinimum(BinaryTree* node)
    {
        if (node == NULL)
            return NULL;
        while(node->Left != NULL)
            node = node->Left;
        return node;
    }
    BinaryTree* FindMaximum(BinaryTree* node)
    {
        if (node == NULL)
            return NULL;
        while(node->Right != NULL)
            node = node->Right;
        return node;
    }
    // Вставка
    void Insert(BinaryTree*& Node, int Value)
    {
        if (Node == NULL){
            Node = new BinaryTree(Value);
            return;
        }
        if (Node->Data > Value)
            Insert(Node->Left, Value);
        else
            Insert(Node->Right, Value);
    }
    // Кол-во вершин в дереве
    int Count(BinaryTree* node)
    {
        if (node == NULL)
            return 0;
        return Count(node->Left) + Count(node->Right) + 1;
    }
    // DFS - обход в глубину
    // Прямой обход pre-order
    // Обратный обход post-order
    // Поперечный обход in-order
    void preOrderDFS(BinaryTree* node)
    {
        if (node == NULL)
            return;
        std::cout << node->Data << std::endl;
        preOrderDFS(node->Left);
        preOrderDFS(node->Right);
    }
    void postOrderDFS(BinaryTree* node)
    {
        if (node == NULL)
            return;
        postOrderDFS(node->Left);
        postOrderDFS(node->Right);
        std::cout << node->Data << std::endl;
    }
    void inOrderDFS(BinaryTree* node)
    {
        if (node == NULL)
            return;
        inOrderDFS(node->Left);
        std::cout << node->Data << std::endl;
        inOrderDFS(node->Right);
    }
};
int main()
{
    BinaryTree* Root = new BinaryTree(19);
    Root->Insert(Root, 25);
    Root->Insert(Root, 22);
    Root->Insert(Root, 16);
    Root->Insert(Root ,18);
    Root->Insert(Root, 13);
    BinaryTree* res = Root->FindMaximum(Root);
    std::cout << "Max - " << res->Data << std::endl;
    res = Root->FindMinimum(Root);
    std::cout << "Min - " << res->Data << std::endl;
    std::cout << "Кол-во вершин - " << Root->Count(Root) << std::endl;
    // Обходы
    std::cout << "--------------" << std::endl;
    Root->preOrderDFS(Root);
    std::cout << "--------------" << std::endl;
    Root->postOrderDFS(Root);
    std::cout<< "---------------" << std::endl;
    Root->inOrderDFS(Root);
    return 0;
}