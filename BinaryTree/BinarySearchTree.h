#pragma once
///@author �������� �.�.
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"

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
        Insert(item);
    }

    // ����������� �����������
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
    root = AddNode(root, item);
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