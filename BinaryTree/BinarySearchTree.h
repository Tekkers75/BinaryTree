#pragma once
///@author Саранчин К.А.
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"
#include "AbstIterator.h"
#include <stack>



using namespace std;


// объявление объекта для узла бинарного дерева
template <class T>
class BinSTree
{
private:
    // указатели левого и правого дочерних узлов
    TreeNode<T>* root;
    TreeNode<T>* current;
    int size;

public:
    // Конструктор по умолчанию
    BinSTree() : root(nullptr), current(nullptr), size(0) {}
    // Конструктор с параметрами
    BinSTree(const T& item) : root(nullptr), current(nullptr), size(0)
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
        this->current = this->root;
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
            this->current = this->root;
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
        this->current = other.current;
        // Перемещаем количество элементов дерева
        this->size = other.size;

        //обнуляем указатели исходного объекта
        other.root = nullptr;
        other.current = nullptr;
        other.size = 0;
    }
    // Деструктор
    ~BinSTree() { Clear(root); }

    TreeNode<T>* Curr() const { return current; };
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
        stack<TreeNode<T>*> stack;


        //помещение узлов дерева в стек
        void pushNodesintoStack(TreeNode<T>* node) {
            //пока узел не равен nullptr
            while (node != nullptr)
            {
                //помещаем узлы в стек
                stack.push(node);
                //переходим к левому поддереву
                node = node->left;
            }
        }


    public:
        //Конструктор
        Iterator(TreeNode<T>* root) {
            pushNodesintoStack(root);
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();
            }
            else
                current = nullptr;

        }
        // Оператор разыменования-доступа к данным
        T& operator*() override
        {
            return current->data;
        }

     
        //Оператор инкремента для BST
        AbstractIterator<T>& operator++() override {
            //если текущий не равен nullptr
            if (current->right != nullptr) {
                //помещаем в стек правое поддерево
                pushNodesintoStack(current->right);
            }
            //если стек пустой
            if (!stack.empty()) {
                //текущий-вершина стека
                current = stack.top();
                //вытащить элемент
                stack.pop();

            }
            //иначе текущии = nullptr
            else {
                current = nullptr;
            }

            return *this;
        }

        AbstractIterator<T>& operator++(int) override
        {
            Iterator iterator = *this;
            ++(*this);
            return iterator;
        }
        // Оператор равенства
        bool operator==(const AbstractIterator<T>& other) override
        {
            const Iterator* pOther = dynamic_cast<const Iterator*>(&other);
            return (pOther != nullptr && current == pOther->current);
        }

        // Оператор неравенства
        bool operator!=(const AbstractIterator<T>& other) override
        {
            return !(*this == other);
        }
    };

    // Итератор начала списка
    Iterator<T> begin()
    {
        return Iterator<T>(root);
    }

    // Итератор конца списка
    Iterator<T> end()
    {
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

