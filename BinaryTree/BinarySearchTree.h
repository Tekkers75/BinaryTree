#pragma once
///@author Саранчин К.А.
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"
#include "AbstIterator.h"

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
        Insret(item);
    }

    // Конструктор копирования
    // При копировании из одного копируется в другой, и остаются оба
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
    // Создает копию дерева и присваивает ему другие данные того же типа
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
    // При перемещении дерево копируется, а тот что скопирован, уничтожается
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


    template<typename T>
    class Iterator : public AbstractIterator<T> {
    private:
        TreeNode<T>* current;


    public:
        Iterator(TreeNode<T>* node) {
            current = node;
        }

        T& operator*() override {
            // Возвращает ссылку на данные текущего узла
            return current->data;
        }

        AbstractIterator<T>& operator++() override {
            // Переход к следующему узлу в порядке возрастания
            if (current != nullptr) {
                if (current->right != nullptr) {
                    // Если есть правый подузел, идем вправо, затем все влево
                    current = current->right;
                    while (current->left != nullptr) {
                        current = current->left;
                    }
                }
                else {
                    // Если нет правого подузла, поднимаемся вверх по родителям,
                    // пока не найдем первый узел с которого мы свернули влево.
                    TreeNode<T>* parent = current->parent;
                    while (parent != nullptr && current == parent->right) {
                        current = parent;
                        parent = parent->parent;
                    }
                    current = parent;
                }
            }
            return *this;
        }

        AbstractIterator<T>& operator++(int) override {
            // Постфиксный инкремент (a++)
            Iterator<T> temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const AbstractIterator<T>& other) override {
            // Сравнение итераторов на равенство
            const Iterator* otherIterator = dynamic_cast<const Iterator*>(&other);
            return otherIterator != nullptr && current == otherIterator->current;
        }

        bool operator!=(const AbstractIterator<T>& other) override {
            // Сравнение итераторов на неравенство
            return !(*this == other);
        }
    };

    Iterator<T> begin() {
        TreeNode<T>* node = root;
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return Iterator<T>(node);
    }

    Iterator<T> end() {
        // Возвращает итератор, указывающий на конец списка (nullptr)
        return Iterator<T>(nullptr);
    }





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
    root = Add(root, item);
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