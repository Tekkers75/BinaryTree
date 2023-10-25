#pragma once
///@author Саранчин К.А.

#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;



// Функция для заполнения дерева случайными числами
template <class T>
void TreеRandom(TreeNode<T>* root, int numNodes, T minValue, T maxValue) {
    for (int i = 0; i < numNodes; i++) {
        T randomNum = rand() % (maxValue - minValue + 1) + minValue;
        Add(root, randomNum);
    }
}

template <class T>
void TestDel()
{
    TreeNode<int>* root = new TreeNode<int>(47, nullptr, nullptr);
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
    cout << endl;
    PrintTree(root, 1);

    Remove(root, 20);
    TreeNode<int>* node30 = root->left;
    assert(node30 != nullptr);
    assert(node30->data == 30);
    cout << endl;
    PrintTree(root, 1);

    Remove(root, 30);
    TreeNode<int>* node42 = root->left;
    assert(node42 != nullptr);
    assert(node42->data == 42);
    cout << endl;
    PrintTree(root, 1);

    Remove(root, 12);
    TreeNode<int>* node12 = node42->left;
    assert(node12 != nullptr);
    assert(node12->data == 8);
    cout << endl;
    PrintTree(root, 1);

    Remove(root, 67);
    TreeNode<int>* node75 = root->right->right;
    assert(node75 != nullptr);
    assert(node75->data == 75);
    cout << endl;
    PrintTree(root, 1);

    Remove(root, 65);
    TreeNode<int>* node65 = node75->left;
    assert(node65 == nullptr);
    cout << endl;
    PrintTree(root, 1);

}

//Функция для создания дерева с конкретными значениями в данных узлов
template <class T>
TreeNode<T>* CreateTree() {
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    Add(root, 25);
    Add(root, 7);
    Add(root, 16);
    Add(root, 15);
    Add(root, 3);
    Add(root, 26);
    Add(root, 38);
    Add(root, 40);
    Add(root, 39);
    Add(root, 55);
    return root;
}

//тестирование функции копирования дерева
void TestCopyTree()
{
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    TreеRandom(root, 10, 10, 50);
    //Копирование дерева
    TreeNode<int>* copiedRoot = CopyTree(root);
    DeleteTree(root);
    PrintTree(root, 1);
    cout << "Копия дерева" << endl;
    PrintTree(copiedRoot, 1);
    assert(root == nullptr);
    assert(copiedRoot != nullptr);
    assert(copiedRoot->data = 25);


    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    TreеRandom(root, 5, 5, 20);
    //Копирование дерева
    TreeNode<int>* copiedRoot1 = CopyTree(root1);
    DeleteTree(root1);
    assert(root1 == nullptr);
    assert(copiedRoot1 != nullptr);
    assert(copiedRoot1->data = 15);

    cout << "Копирование дерева пройдено" << endl;
}

//тестирование функции удаления узла 
void TestRemove()
{
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = CreateTree<int>();
    PrintTree(root, 1);

    Remove(root, 38);
    TreeNode<int>* node38 = root->right;
    assert(node38 != nullptr);
    assert(node38->data == 40);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;

    Remove(root, 7);
    TreeNode<int>* node7 = root->left->left;
    assert(node7 != nullptr);
    assert(node7->data == 15);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;


    Remove(root, 15);
    TreeNode<int>* node15 = root->left->left;
    assert(node15 != nullptr);
    assert(node15->data == 16);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;


    Remove(root, 3);
    TreeNode<int>* node3 = root->left->left->left;
    assert(node3 == nullptr);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;

    Remove(root, 40);
    TreeNode<int>* node40 = root->right;
    assert(node40 != nullptr);
    assert(node40->data == 55);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;

    // Освобождаем память, удаляя дерево
    DeleteTree(root);
    cout << "Удаление пройдено" << endl;
}
//тестирование функции поиска
void TestSearch() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = CreateTree<int>();
    PrintTree(root, 1);

    assert(Search(root, 35) == 0); // Значение 35 находится на уровне 0
    assert(Search(root, 25) == 1); // Значение 25 находится на уровне 1
    assert(Search(root, 38) == 1); // Значение 38 находится на уровне 1
    assert(Search(root, 7) == 2);  // Значение 7 находится на уровне 2
    assert(Search(root, 26) == 2); // Значение 26 находится на уровне 2
    assert(Search(root, 40) == 2); // Значение 40 находится на уровне 2
    assert(Search(root, 16) == 3); // Значение 16 находится на уровне 3
    assert(Search(root, 3) == 3);  // Значение 3 находится на уровне 3 
    assert(Search(root, 39) == 3); // Значение 39 находится на уровне 3
    assert(Search(root, 55) == 3); // Значение 55 находится на уровне 3
    assert(Search(root, 15) == 4); // Значение 15 находится на уровне 4
    // Тестируем поиск на отсутствующих значениях
    assert(Search(root, 1) == -1);  // Значение 1 отсутствует в дереве
    assert(Search(root, 9) == -1);  // Значение 9 отсутствует в дереве
    assert(Search(root, 100) == -1);  // Значение 100 отсутствует в дереве

    // Освобождаем память, удаляя дерево
    DeleteTree(root);
    cout << "Поиск пройден" << endl;
}
//тестирование функции добавления
void TestAdd() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(40, nullptr, nullptr);
    Add(root, 25);
    Add(root, 70);
    Add(root, 30);
    Add(root, 45);
    Add(root, 43);

    //PrintTree(root, 1);


    // Уровень 0
    assert(root->data == 40);

    // Уровень 1
    assert(root->left->data == 25);
    assert(root->right->data == 70);

    // Уровень 2
    assert(root->left->left == nullptr);
    assert(root->left->right->data == 30);
    assert(root->right->right == nullptr);
    assert(root->right->left->data == 45);

    // Уровень 3
    assert(root->right->left->left->data == 43);

    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    cout << "Добавление пройдено" << endl;
}
//тестирование функции глубины
void TestDepth() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    TreеRandom(root, 9, 11, 87);
    // Проверяем глубину дерева
    assert(Depth(root) == 3);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // Проверяем глубину дерева
    assert(Depth(root1) == 0);
    // Освобождаем память, удаляя дерево
    DeleteTree(root1);


    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(23, nullptr, nullptr);
    TreеRandom(root, 21, 1, 80);
    // Проверяем глубину дерева
    assert(Depth(root2) == 8);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);
    cout << "Подсчет глубины пройден" << endl;
}
//тестирование функции подсчета узлов
void TestCountNodes() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    TreеRandom(root, 10, 20, 100);
    PrintTree(root, 1);
    // Проверяем количество узлов в дереве
    assert(countNode(root) == 11);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // Проверяем количество узлов в дереве
    assert(countNode(root1) == 1);
    // Освобождаем память, удаляя дерево
    DeleteTree(root1);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    TreеRandom(root, 5, 20, 50);
    // Проверяем количество узлов в дереве
    assert(countNode(root2) == 6);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);

    cout << "Подсчет узлов пройден" << endl;
}

//тестирование функции подсчета листьев
void TestCountLeaf() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    TreеRandom(root, 10, 10, 50);
    int count = 0;
    CountLeaf(root, count);
    // Проверяем, что количество листьев равно ожидаемому значению
    assert(count == 3);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);



    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    TreеRandom(root, 15, 20, 60);
    int count2 = 0;
    CountLeaf(root2, count2);
    // Проверяем, что количество листьев равно ожидаемому значению
    assert(count == 5);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);
    cout << "Подсчет листьев пройден" << endl;
}




/// Тесты для BST

//тестирование конструктора копирования
template<class T>
void TestCopyConstructor() {
    // Создаем первое дерево
    BinSTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(8);

    // Создаем второе дерево и инициализируем его копией первого дерева
    BinSTree<int> tree2(tree1);

    // Проверяем размеры деревьев
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // Изменяем первое дерево
    tree1.Insret(10);

    // Проверяем, что изменение первого дерева не влияет на второе дерево
    assert(tree1.ListSize() == 4);
    assert(tree2.ListSize() == 3);

    cout << "Конструктор копирования тест пройден" << endl;
}
//тестирование оператора присваивания копирования
template<class T>
void TestCopyOperator() {
    // Создаем первое дерево
    BinSTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
    // Создаем второе дерево,присвоив ему значения из первого через оператор присваивания копирования
    BinSTree<int> tree2;
    tree2 = tree1;
    // Проверяем размеры деревьев
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // Изменяем первое дерево
    tree1.Delete(7);

    // Проверяем, что изменение первого дерева не влияет на второе дерево
    assert(tree1.ListSize() == 2);
    assert(tree2.ListSize() == 3);

    cout << "Оператор присваивания копирования тест пройден" << endl;

}
//тестирование конструктора перемещения
template<class T>
void TestMoveConstructor() {
    // Создаем первое дерево
    BinSTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
    // Вызываем конструктор перемещения данных из tree1 в tree2
    BinSTree<int> tree2(move(tree1));
    // Проверяем размер и пустоту первого деревa
    assert(tree1.ListSize() == 0);
    assert(tree1.ListEmpty() == true);
    //Проверяем, что tree2 содержит перемещенные данные
    assert(tree2.ListSize() == 3);
    assert(tree2.ListEmpty() == false);

    cout << "Конструктор перемещения тест пройден" << endl;
}

