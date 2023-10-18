#pragma once
///@author �������� �.�.
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"
#include "AbstIterator.h"

using namespace std;


// ���������� ������� ��� ���� ��������� ������
template <class T>
class BinSTree
{
private:
    // ��������� ������ � ������� �������� �����
    TreeNode<T>* root;
    TreeNode<T>* curr;
    int size;

public:
    // ����������� �� ���������
    BinSTree() : root(nullptr), curr(nullptr), size(0) {}
    // ����������� � �����������
    BinSTree(const T& item) : root(nullptr), curr(nullptr), size(0)
    {
        Insret(item);
    }

    // ����������� �����������
    // ��� ����������� �� ������ ���������� � ������, � �������� ���
    BinSTree(const BinSTree& other)
    {
        // �������� ������
        this->size = other.size;
        // �������� ������
        this->root = CopyTree(other.root);
        // ������������� ��������� �� ������� ���� � ������
        this->curr = this->root;
    }

    // �������� ������������ ����������� 
    // ������� ����� ������ � ����������� ��� ������ ������ ���� �� ����
    BinSTree& operator=(const BinSTree& other)
    {
        if (this != &other) {
            // �������� ������
            this->size = other.size;
            // �������� ������
            Clear(this->root); // ������� ������� ������
            this->root = CopyTree(other.root);
            // ������������� ��������� �� ������� ���� � ������
            this->curr = this->root;
        }
        return *this;
    }
    // ����������� �����������
    // ��� ����������� ������ ����������, � ��� ��� ����������, ������������
    BinSTree(BinSTree&& other)
    {
        // ���������� ��������� �� ������
        this->root = other.root;
        // ���������� ��������� �� ������� ����
        this->curr = other.curr;
        // ���������� ���������� ��������� ������
        this->size = other.size;

        //�������� ��������� ��������� �������
        other.root = nullptr;
        other.curr = nullptr;
        other.size = 0;
    }
    // ����������
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
            // ���������� ������ �� ������ �������� ����
            return current->data;
        }

        AbstractIterator<T>& operator++() override {
            // ������� � ���������� ���� � ������� �����������
            if (current != nullptr) {
                if (current->right != nullptr) {
                    // ���� ���� ������ �������, ���� ������, ����� ��� �����
                    current = current->right;
                    while (current->left != nullptr) {
                        current = current->left;
                    }
                }
                else {
                    // ���� ��� ������� �������, ����������� ����� �� ���������,
                    // ���� �� ������ ������ ���� � �������� �� �������� �����.
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
            // ����������� ��������� (a++)
            Iterator<T> temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const AbstractIterator<T>& other) override {
            // ��������� ���������� �� ���������
            const Iterator* otherIterator = dynamic_cast<const Iterator*>(&other);
            return otherIterator != nullptr && current == otherIterator->current;
        }

        bool operator!=(const AbstractIterator<T>& other) override {
            // ��������� ���������� �� �����������
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
        // ���������� ��������, ����������� �� ����� ������ (nullptr)
        return Iterator<T>(nullptr);
    }





};
//�������� �� ������ ������
template<class T>
bool BinSTree<T>::ListEmpty() const {
    return (root == nullptr);
}
//������� ������
template<class T>
void BinSTree<T>::Clear(TreeNode<T>* node) {
    if (node) {
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
}
// ����� ���� �� �������� � ����� ��� ������
template<class T>
int BinSTree<T>::Find(const T& item) {
    return Search(root, item);
}

// ������� ������ ��������
template<class T>
void BinSTree<T>::Insret(const T& item) {
    root = Add(root, item);
    size++;
}

// �������� ���� �� ��������
template<class T>
void BinSTree<T>::Delete(const T& item) {
    root = Remove(root, item);
    size--;
}

//������� ������� ������
template<class T>
int BinSTree<T>::ListSize() const {
    return size;
}