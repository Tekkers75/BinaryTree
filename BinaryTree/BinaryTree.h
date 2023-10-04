#pragma once
///@author �������� �.�.

#include <vector>
#include <iomanip>
#include <cassert>
#include <queue>

using namespace std;

/// ������:
/// �������� ������ ����            // Struct TreeNode
/// �������� ������                 // void DeleteTree(TreeNode<T>* root)
/// �������� ������ ����            // void DeleteTreeNode(TreeNode<T>* node)
/// ������ ����                     // void PrintNode(const TreeNode<T>* node)
/// ����� ������ NLR, LNR, RNL      // void preorderPrint(TreeNode<T>* root), void postorderPrint(TreeNode<T>* root), void reverseInorderPrint(TreeNode<T>* root)
/// ������ ������ - �����           // void PrintTree(TreeNode<T>* node, int level)
/// ������� �������                 // void CountLeaf(TreeNode<T>* t, int& count)
/// ������� ������� ������          // int Depth(TreeNode<T>* t) 
/// ���������� ������               // TreeNode<T>* Add(TreeNode<T>* node, const T& aData)
/// �������� ����� � ������         // bool Search(TreeNode<T>* root, const T& data) 
/// ������ ������ � ������          // int AddArr(TreeNode<T>* node, T arr[], int i) 
/// ������ ������ �� �������        // void BinaryTreeFromVector(vector<T> vec)
/// ������� ���������� �����        // int countNode(TreeNode<T>* node)
/// �������� �����                  // TreeNode<T>* Remove(TreeNode<T>* root, const T& data) 
/// ����� ���������� �����������    // TreeNode<T>* FindMin(TreeNode<T>* root)
/// ����������� ������              // TreeNode<T>* CopyTree(TreeNode<T>* node)
/// ������ � ������                 // void BFS(TreeNode<T>* root)
/// ���������� ������ ���� �� 10    // void Inc(TreeNode<T>* node) 
/// ��������� ������ ���� � 10 ���  // void Multiplication(TreeNode<T>* node)




// ���������� ������� ��� ���� ��������� ������
template <class T>
struct TreeNode
{
    // ��������� ������ � ������� �������� �����
    TreeNode<T>* left;
    TreeNode<T>* right;

    // �������� �������, ����������� ����������
    T data;

    // ����������� �������������� ���� ������ � ����������
    // �������� NULL ������������� ������� ���������
    TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
        //: data(item), left(lptr), right(rptr)
    {
        data = item;
        left = lptr;
        right = rptr;
    }
    // ������ ������� � ����� ����������
    TreeNode<T>* Left() const { return left; }
    TreeNode<T>* Right() const { return right; }
    // friend class BinSTree<T>;
};


/// �������� ������
template <class T>
void DeleteTree(TreeNode<T>* root)
{
    if (root != nullptr) {
         return;

        DeleteTree(root->Left());
        DeleteTree(root->Right());

        delete root;
    }
    root = nullptr;
}


/// �������� ������ ����
template<class T>
void DeleteTreeNode(TreeNode<T>* node) {
    delete node;
}

/// ������ ����
template <class T>
void PrintNode(const TreeNode<T>* node)
{
    if (node == nullptr)
    {
        cout << "-" << endl;
    }
    else
    {
        cout << node->data << endl;
    }
}

// ������� �������� �������� ��������� ������ ������ � ������������ �������.
// �� ���� � ��������������� �������
/// NLR
template <class T>
void preorderPrint(TreeNode<T>* root, void(*func)(TreeNode<T>*))
{
    if (root == NULL)   // ������� ������
    {
        return;
    }
    //cout << root->data << " ";
    func(root);
    preorderPrint(root->left, func);   //����������� ����� ������ ���������
    preorderPrint(root->right, func);  //����������� ����� ������� ���������
}


// ������� �������� �������� ��������� ������ ������ � �������� �������.
// LRN
template <class T>
void postorderPrint(TreeNode<T>* root, void(*func)(TreeNode<T>*))
{
    if (root == NULL)   // ������� ������
    {
        return;
    }
    postorderPrint(root->left, func);   //����������� ����� ������ ���������
    postorderPrint(root->right, func);  //����������� ����� ������� ���������
    //cout << root->data << " ";
    func(root);
}

// ������� �������� �������� ��������� ������ ������ � �������� ������������ �������.
// RNL
template <class T>
void reverseInorderPrint(TreeNode<T>* root, void(*func)(TreeNode<T>*))
{
    if (root == NULL)   // ������� ������
    {
        return;
    }
    reverseInorderPrint(root->right, func);  //����������� ����� ������� ���������
    func(root);
    //cout << root->data << " ";
    reverseInorderPrint(root->left, func);   //����������� ����� ������ ���������

}


//���������� ����� ��������
const int indentBlock = 6;
//�������� num�������� � ������� ������
void IndentBlanks(int num) {
    for (int i = 0; i < num; i++)
        cout << "  ";
}

//������ ������ �����,��������� RNL- �����������
template<class T>
void PrintTree(TreeNode<T>* node, int level) {
    //�������� ������ ������ ���� node, ���� �� �� ����� nullptr
    if (node != nullptr)
    {
        //�������� ������ ��������� ���� node
        PrintTree(node->Right(), level + 1);
        //��������� ������� ������� � ������� ���� ������
        IndentBlanks(indentBlock * level);
        cout << node->data << endl;
        //�������� ����� ��������� ���� node
        PrintTree(node->Left(), level + 1);
    }
}

//������� ������� ������,�.� �����, ������� �� ����� ��������
template <class T>
void CountLeaf(TreeNode<T>* t, int& count) {
    // ������������� ��������� ������ �����������
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count); //������ ����� ���������
        CountLeaf(t->Right(), count);// ������ ������ ���������

        // ���������,�������� �� ������ ���� ������
        //���� ��, �� ���������� ���������� ���������� count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }

}
//������� ������� (�������) ������
template<class T>
int Depth(TreeNode<T>* t) {
    int depthLeft, depthRight, depthValue;
    //���� ������ ������,��� �������=-1
    if (t == nullptr)
    {
        depthValue = -1;
    }
    else
        //�������� ����� �����������
        //���������� ������� ������� � ������ �����������
        //����������� �� ���������������
    {
        depthLeft = Depth(t->Left());
        depthRight = Depth(t->Right());
        //��������� ��������
        //�������� ������������ ����� depthLeft � depthRight
        //depthValue = 1 + (depthLeft > depthRight ? depthLeft : depthRight);

        if (depthLeft > depthRight)
        {
            depthValue = 1 + depthLeft;
        }
        else {

            depthValue = 1 + depthRight;
        }
    }
    return depthValue;
}

//������� �������� ������
template <class T>
TreeNode<T>* Add(TreeNode<T>* node, const T& aData)

{
    //���� ����� �� ����������

    if (node == nullptr)

    { //�������� �� � ������� � ��� ������

        return new TreeNode<int>(aData, nullptr, nullptr);

    }

    if (aData < node->data) {
        // ���������� ��������� �������� � ����� ���������
        node->left = Add(node->left, aData);
    }
    else if (aData > node->data) {
        // ���������� ��������� �������� � ������ ���������
        node->right = Add(node->right, aData);
    }

    // ���� �������� ��� ������������ � ������, ������ �� ������

    return node;
}

/// ����� � �������� ������ 
template<class T>
bool Search(TreeNode<T>* root, const T& data) {
    if (root == nullptr) {
        // ������ ������ ��� ��������� ����� ����� (���� ��� ��������)
        return false;
    }

    if (data == root->data) {
        // �������� ������� � ������� ����
        return true;
    }
    else if (data < root->data) {
        // ���������� ���� �������� � ����� ���������
        return Search(root->left, data);
    }
    else {
        // ���������� ���� �������� � ������ ���������
        return Search(root->right, data);
    }
}

/// ���������� � ������
template <class T>
int AddArr(TreeNode<T>* node, T arr[], int i)
{
    if (node == nullptr) {
        // ������ ������ ��� ��������� ����� ����� (���� ��� ��������)
        return i;
    }

    if (node->left != nullptr) {
        // ���������� ��������� �������� � ����� ���������
        i = AddArr(node->left, arr, i);
    }

    arr[i] = node->data;
    i++;

    if (node->right != nullptr) {
        // ���������� ��������� �������� � ������ ���������
        i = AddArr(node->right, arr, i);
    }
    return i;
}

// ���������� ��������� ������ �� �������, �������� � ������� �������� ����.�������
// ( ������,����� � ������ �������,������� ������,������� ������� � �.�)
template<class T>
void BinaryTreeFromVector(vector<T> vec) {
    // �������� ��������� ���� � ������ ��������� �������
    TreeNode<int>* root = new TreeNode<int>(vec.at(0), nullptr, nullptr);
    for (int i = 0; i < vec.size(); i++) {
        int left = 2 * i + 1;// ���������� ������� ������ �������
        int right = left + 1; // ���������� ������� ������� �������
        if (left < vec.size())
            AddNode(root, vec.at(i));
        if (right < vec.size())
            AddNode(root, vec.at(i));

    }
    PrintTree(root, 0);
}

/// ������� ���������� �����
template <class T>
int countNode(TreeNode<T>* node)
{
    int left, right;

    if (node->Left() == nullptr && node->Right() == nullptr)
        return 1;

    if (node->Left() != nullptr)
        left = countNode(node->Left());
    else left = 0;

    if (node->Right() != nullptr)
        right = countNode(node->Right());
    else right = 0;

    return left + right + 1;
}

/// �������� ����
template<class T>
TreeNode<T>* Remove(TreeNode<T>* root, const T& data) {
    TreeNode<T>* parent;

    if (root == nullptr) {
        // ������ ������ ��� ��������� ����� ����� (���� ��� ��������)
        return nullptr;
    }

    if (data < root->data) {
        // ���������� ������� �������� �� ������ ���������
        root->left = Remove(root->left, data);
    }
    else if (data > root->data) {
        // ���������� ������� �������� �� ������� ���������
        root->right = Remove(root->right, data);
    }
    else {
        // ������ ����, ������� ����� �������

        if (root->left == nullptr && root->right == nullptr) {
            // ���� �������� ������ (�� ����� ��������)
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            // ���� ����� ������ ������� �������
            parent = root;
            root = root->right;
            delete parent;
        }
        else if (root->right == nullptr) {
            // ���� ����� ������ ������ �������
            parent = root;
            root = root->left;
            delete parent;
        }
        else {
            // ���� ����� ��� �������
            TreeNode<T>* parent = FindMin(root->right);
            root->data = parent->data;
            root->right = Remove(root->right, parent->data);
        }
    }

    return root;
}

/// ����� ���������� �����������
template<class T>
TreeNode<T>* FindMin(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// ������� ������ TreeNode � ������������� ������ lptr � rptr.
// �� ��������� ��������� �������� NULL.
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
    TreeNode<T>* rptr = nullptr)
{
    TreeNode<T>* p;

    // ������� new ��� �������� ������ ����
    // �������� ���� ��������� lptr � rptr
    p = new TreeNode<T>(item, lptr, rptr);

    // ���� ������ ������������, ��������� 
    // ��������� ���������� �� ������
    if (p == nullptr)
    {
        cout <<
            "������ ��� ��������� ������!\n";
        exit(1);
    }
    // ������� ��������� �� ���������� �������� ������
    return p;
}

//����������� ������
template <class T>
TreeNode<T>* CopyTree(TreeNode<T>* node) {
    //������� ��������� �� ����� ����
    TreeNode<T>* newlptr, * newrptr, * newnode;
    //���� node ����� nullptr, �� ��� ������� ������ ��������
    if (node == nullptr)
        return nullptr;
    //���� � ���� node ���� ����� ������� (node->left), 
    // ���������� ����������� ����� ������� CopyTree ��� ����������� ������ ���������. ��������� ����������� � newlptr.
    if (node->left != nullptr)
        newlptr = CopyTree(node->left);
    else
        newlptr = nullptr;
    //���� � ���� node ���� ������ �������(node->right), 
    // ���������� ����������� ����� ������� CopyTree ��� ����������� ������� ���������.��������� ����������� � newrptr.
    if (node->right != nullptr)
        newrptr = CopyTree(node->right);
    else newrptr = nullptr;
    // ��������� ����� ���� newnode � ������� node->data � ����������� 
    // �� ������������� ����� � ������ ����������(newlptr � newrptr ��������������).
    //����� ���� newnode ���������� �������� ����� �������������� ���������.
    newnode = new TreeNode<int>(node->data, newlptr, newrptr);
    return newnode;
}

//������ ������ � ������ � �������������� �������
template <class T>
void BFS(TreeNode<T>* root) {
    if (root == nullptr)
        return;
    //������� ������ �������
    queue <TreeNode<T>*> q;
    //�������� � ������� �������� ����
    q.push(root);
    // ���� �� ��� ���, ���� queue �� ������ ������
    while (!q.empty()) {
        //������� ��������� �� ������ �������
        TreeNode<T>* current = q.front();
        //��������� ������ �������
        q.pop();
        // ��������� �������� ����
        PrintNode(current);
        //���������� ������ � ������� ������� �������� ���� � �������
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}


//���������� ������ ���� �� 10
template <class T>
void Inc(TreeNode<T>* node) {
    node->data += 10;
}

//��������� ������ ���� � 10 ���
template <class T>
void Multiplication(TreeNode<T>* node) {
    node->data = node->data * 10;
}

//���������� � ������� ������ ���� 
template <class T>
void Sqr(TreeNode<T>* node) {
    node->data = node->data * node->data;
}

