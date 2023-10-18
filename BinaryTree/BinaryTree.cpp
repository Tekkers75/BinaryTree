//
// @author Саранчин К.А.
#include <iostream>
#include "BinaryTree.h"
#include "Test.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "rus");

    int count = 0;


    TreeNode<int>* root = new TreeNode<int>(47, nullptr, nullptr, nullptr);
    Add(root, 60);
    Add(root, 30);
    Add(root, 20);
    Add(root, 67);
    Add(root, 42);
    Add(root, 75);
    Add(root, 12);
    Add(root, 8);
    Add(root, 10);
    Add(root, 0);
    Add(root, 65);
    Add(root, -2);

    //Копирование дерева
    TreeNode<int>* copiedRoot = CopyTree(root);
    PrintTree(root, 1);
    //DeleteTree(root);

    cout << "Копия дерева" << endl;
    PrintTree(copiedRoot, 1);
    int* arr = new int[countNode(root)];



    cout << endl << "Количество узлов = " << countNode(root) << endl;

    cout << "Глубина дерева = " << Depth(root) << endl;


    CountLeaf(root, count);
    cout << "Кол-во листьев = " << count << endl;

    //cout << "Прямой обход" << "\n";
    //preorderPrint(root, &Inc);
    //cout << "\n";
    //cout << "Обратный обход" << "\n";
    //postorderPrint(root, &Multiplication);
    //cout << "\n";
    //cout << "Обратный симметричный обход." << "\n";
    //reverseInorderPrint(root, &Sqr);
    //cout << "\n";

    bool found = Search(root, 5);
    if (found) {
        cout << "Значение найдено в дереве" << endl;
    }
    else {
        cout << "Значение не найдено в дереве" << endl;
    }

    Remove(root, 12);

    PrintTree(root, 1);

    AddArr(root, arr, 0);
    for (int i = 0; i < countNode(root); i++)
    {
        cout << arr[i] << " ";
    }

    //int arr1[] { 1, 5, 2, 6, 7, 3, 4 };
    //ReadAdd(root, arr1);

    //PrintTree(root, 1);

    FindMin(root);

    cout << endl;
    BFS(root);

    //for (const auto& item : root) {
    //    std::cout << item << " ";
    //}
    
    BinSTree<int> root1(4);
    root1.Insret(5);
    root1.Insret(7);
    root1.Insret(9);
    root1.Insret(2);
    root1.Insret(1);

    


  


    for (auto it = root1.begin(); it != root1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    root1.ListSize();

    


    return 0;
}