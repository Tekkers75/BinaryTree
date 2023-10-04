#pragma once
///@author Саранчин К.А.
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"

using namespace std;


// объявление объекта для узла бинарного дерева
template <class T>
class BinSTree
{
private:
    // указатели левого и правого дочерних узлов
    TreeNode<T>* root;
    TreeNode<T>* curr;

    int size;

public:
    // Конструктор по умолчанию
    BinSTree() : root(nullptr), curr(nullptr), size(0) {}
    // Конструктор с параметрами
    BinSTree(const T& item) : root(nullptr), curr(nullptr), size(0)
    {
        Insert(item);
    }

    // Конструктор копирования
    BinSTree(const BinSTree& other)
    {
        // Копируем размер
        this->size = other.size;
        // Копируем дерево
        this->root = CopyTree(other.root);
        // Устанавливаем указатель на текущий узел в корень
        this->curr = this->root;
    }

    // Оператор присваивания копирования
    BinSTree& operator=(const BinSTree& other)
    {
        if (this != &other) {
            // Копируем размер
            this->size = other.size;
            // Копируем дерево
            Clear(this->root); // Очищаем текущее дерево
            this->root = CopyTree(other.root);
            // Устанавливаем указатель на текущий узел в корень
            this->curr = this->root;
        }
        return *this;
    }
    // Конструктор перемещения
    BinSTree(BinSTree&& other)
    {
        // Перемещаем указатель на корень
        this->root = other.root;
        // Перемещаем указатель на текущий узел
        this->curr = other.curr;
        // Перемещаем количество элементов дерева
        this->size = other.size;

        //обнуляем указатели исходного объекта
        other.root = nullptr;
        other.curr = nullptr;
        other.size = 0;
    }
    // Деструктор
    ~BinSTree() { Clear(root); }

    TreeNode<T>* Curr() const { return curr; };
    int Find(const T& item);
    void Insret(const T& item);
    void Delete(const T& item);
    void Clear(TreeNode<T>* node);
    bool ListEmpty()const;
    int ListSize()const;

};
//проверка на пустое дерево
template<class T>
bool BinSTree<T>::ListEmpty() const {
    return (root == nullptr);
}
//очистка дерева
template<class T>
void BinSTree<T>::Clear(TreeNode<T>* node) {
    if (node) {
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
}
// Поиск узла по значению и вывод его уровня
template<class T>
int BinSTree<T>::Find(const T& item) {
    return Search(root, item);
}

// Вставка нового элемента
template<class T>
void BinSTree<T>::Insret(const T& item) {
    root = AddNode(root, item);
    size++;
}

// Удаление узла по значению
template<class T>
void BinSTree<T>::Delete(const T& item) {
    root = Remove(root, item);
    size--;
}

//подсчет размера дерева
template<class T>
int BinSTree<T>::ListSize() const {
    return size;
}