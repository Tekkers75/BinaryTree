#pragma once
///@author �������� �.�.
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"
#include "AbstIterator.h"
#include <stack>



using namespace std;


// ���������� ������� ��� ���� ��������� ������
template <class T>
class BinSTree
{
private:
    // ��������� ������ � ������� �������� �����
    TreeNode<T>* root;
    TreeNode<T>* current;
    int size;

public:
    // ����������� �� ���������
    BinSTree() : root(nullptr), current(nullptr), size(0) {}
    // ����������� � �����������
    BinSTree(const T& item) : root(nullptr), current(nullptr), size(0)
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
        this->current = this->root;
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
            this->current = this->root;
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
        this->current = other.current;
        // ���������� ���������� ��������� ������
        this->size = other.size;

        //�������� ��������� ��������� �������
        other.root = nullptr;
        other.current = nullptr;
        other.size = 0;
    }
    // ����������
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


        //��������� ����� ������ � ����
        void pushNodesintoStack(TreeNode<T>* node) {
            //���� ���� �� ����� nullptr
            while (node != nullptr)
            {
                //�������� ���� � ����
                stack.push(node);
                //��������� � ������ ���������
                node = node->left;
            }
        }


    public:
        //�����������
        Iterator(TreeNode<T>* root) {
            pushNodesintoStack(root);
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();
            }
            else
                current = nullptr;

        }
        // �������� �������������-������� � ������
        T& operator*() override
        {
            return current->data;
        }

     
        //�������� ���������� ��� BST
        AbstractIterator<T>& operator++() override {
            //���� ������� �� ����� nullptr
            if (current->right != nullptr) {
                //�������� � ���� ������ ���������
                pushNodesintoStack(current->right);
            }
            //���� ���� ������
            if (!stack.empty()) {
                //�������-������� �����
                current = stack.top();
                //�������� �������
                stack.pop();

            }
            //����� ������� = nullptr
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
        // �������� ���������
        bool operator==(const AbstractIterator<T>& other) override
        {
            const Iterator* pOther = dynamic_cast<const Iterator*>(&other);
            return (pOther != nullptr && current == pOther->current);
        }

        // �������� �����������
        bool operator!=(const AbstractIterator<T>& other) override
        {
            return !(*this == other);
        }
    };

    // �������� ������ ������
    Iterator<T> begin()
    {
        return Iterator<T>(root);
    }

    // �������� ����� ������
    Iterator<T> end()
    {
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

