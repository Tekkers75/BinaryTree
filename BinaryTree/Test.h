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

template<class T>
//тест вставка
void TestInsert() {
    // Создаем объект дерева
    BinSTree<T> tree;
    assert(tree.ListSize() == 0);
    // Вставляем элементы в дерево
    tree.Insert(5);
    assert(tree.ListSize() == 1);
    tree.Insert(3);
    assert(tree.ListSize() == 2);
    tree.Insert(7);
    assert(tree.ListSize() == 3);
    tree.Insert(2);
    assert(tree.ListSize() == 4);
    tree.Insert(4);
    //перевести в массив и проверить
        // Проверяем размер дерева
    assert(tree.ListSize() == 5);
    cout << "Вставка пройдена" << endl;
}
template<class T>
//тест удаление
void TestRemove() {

    BinSTree<T> tree;

    // Вставляем элементы в дерево
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    // Удаляем элементы из дерева
    tree.Delete(5);
    tree.Delete(2);

    // Проверяем размер дерева после удаления
    assert(tree.ListSize() == 3);
    // Получаем размер дерева
    int treeSize = tree.ListSize();

    // Создаем массив для хранения элементов дерева
    int* arr = new int[treeSize];

    // Печатаем дерево в массив
    PrintArr(tree.Curr(), arr, 0);


    // Проверяем ожидаемый результат
    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 7);

    // Освобождаем выделенную память
    delete[] arr;
    cout << "Удаление тест пройден" << endl;
}
template<class T>
//тест поиск
void TestFind() {

    BinSTree<T> tree;

    // Вставляем элементы в дерево
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);

    // Проверяем поиск элементов
    assert(tree.Find(5) == 0);  // Элемент 5 должен быть найден
    assert(tree.Find(2) == 2);  // Элемент 2 должен быть найден
    assert(tree.Find(6) == -1); // Элемент 6 не должен быть найден
    cout << "Поиск тест пройден" << endl;
}


//создаем тестовое бинарное дерево 
BinSTree<int> CreateTestBST() {
    // Создаем объект класса BinSTree
    BinSTree<int> bst;

    bst.Insret(35);
    bst.Insret(25);
    bst.Insret(7);
    bst.Insret(16);
    bst.Insret(15);
    bst.Insret(3);
    bst.Insret(26);
    bst.Insret(38);
    bst.Insret(40);
    bst.Insret(39);
    bst.Insret(55);
    return bst;
}

//создаем тестовое вырожденное влево бинарное дерево 
BinSTree<int> CreateTestBSTLeft() {
    // Создаем объект класса BinSearchTree
    BinSTree<int> bst;

    bst.Insret(27);
    bst.Insret(25);
    bst.Insret(17);
    bst.Insret(16);
    bst.Insret(10);
    bst.Insret(9);
    bst.Insret(6);
    bst.Insret(4);
    bst.Insret(2);
    bst.Insret(1);
    return bst;
}
void TestBSTIterator() {
    BinSTree<int> bst = CreateTestBST();

    // Получаем итератор начала списка
    auto it = bst.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 3);


    BinSTree<int> bst1 = CreateTestBSTLeft();
    // Получаем итератор начала списка
    auto it1 = bst1.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it1 == 1);

    cout << "Итератор начала BST пройден" << endl;
}
void TestBSTDataOperator() {
    BinSTree<int> bst = CreateTestBST();

    // Получаем итератор начала списка
    auto it = bst.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 3);

    // Переходим к следующему узлу
    ++it;

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 7);
    ++it;
    assert(*it == 15);
    ++it;
    assert(*it == 16);


    BinSTree<int> bst1 = CreateTestBSTLeft();
    // Получаем итератор начала списка
    auto it1 = bst1.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it1 == 1);

    // Переходим к следующему узлу
    ++it1;

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it1 == 2);
    ++it1;
    assert(*it1 == 4);
    ++it1;
    assert(*it1 == 6);
    cout << "Оператор разыменования пройден" << endl;
}

// тест инкремента итератора
void TestIncOperator() {
    BinSTree<int> bst = CreateTestBST();

    // Получаем итератор начала списка
    auto it = bst.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 3);

    // Переходим к следующему узлу
    ++it;

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 7);
    ++it;
    assert(*it == 15);
    ++it;
    assert(*it == 16);
    ++it;
    assert(*it == 25);
    ++it;
    assert(*it == 26);
    ++it;
    assert(*it == 35);
    ++it;
    assert(*it == 38);
    ++it;
    assert(*it == 39);
    ++it;
    assert(*it == 40);
    ++it;
    assert(*it == 55);

    cout << "Оператор разыменования пройден" << endl;
}
//тест оператора равенства
void TestOperatorEqual() {
    BinSTree<int> bst = CreateTestBST();

    //Получаем итераторы
    auto it1 = bst.begin();
    auto it2 = bst.begin();

    // Проверяем, что итераторы равны друг другу с помощью оператора равенства
    assert(it1 == it2);



    cout << "Оператор равенства пройден" << endl;
}

void TestOperatorUnequal() {
    BinSTree<int> bst = CreateTestBST();

    //Получаем итераторы
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    ++it2;
    // Проверяем, что итераторы равны друг другу с помощью оператора равенства
    assert(it1 != it2);



    cout << "Оператор неравенства пройден" << endl;
}