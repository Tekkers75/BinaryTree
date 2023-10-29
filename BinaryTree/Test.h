#pragma once
///@author �������� �.�.

#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;



// ������� ��� ���������� ������ ���������� �������
template <class T>
void Tre�Random(TreeNode<T>* root, int numNodes, T minValue, T maxValue) {
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

//������� ��� �������� ������ � ����������� ���������� � ������ �����
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

//������������ ������� ����������� ������
void TestCopyTree()
{
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    Tre�Random(root, 10, 10, 50);
    //����������� ������
    TreeNode<int>* copiedRoot = CopyTree(root);
    DeleteTree(root);
    PrintTree(root, 1);
    cout << "����� ������" << endl;
    PrintTree(copiedRoot, 1);
    assert(root == nullptr);
    assert(copiedRoot != nullptr);
    assert(copiedRoot->data = 25);


    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    Tre�Random(root, 5, 5, 20);
    //����������� ������
    TreeNode<int>* copiedRoot1 = CopyTree(root1);
    DeleteTree(root1);
    assert(root1 == nullptr);
    assert(copiedRoot1 != nullptr);
    assert(copiedRoot1->data = 15);

    cout << "����������� ������ ��������" << endl;
}

//������������ ������� �������� ���� 
void TestRemove()
{
    // ������� �������� ������ ��� ������������
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

    // ����������� ������, ������ ������
    DeleteTree(root);
    cout << "�������� ��������" << endl;
}
//������������ ������� ������
void TestSearch() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = CreateTree<int>();
    PrintTree(root, 1);

    assert(Search(root, 35) == 0); // �������� 35 ��������� �� ������ 0
    assert(Search(root, 25) == 1); // �������� 25 ��������� �� ������ 1
    assert(Search(root, 38) == 1); // �������� 38 ��������� �� ������ 1
    assert(Search(root, 7) == 2);  // �������� 7 ��������� �� ������ 2
    assert(Search(root, 26) == 2); // �������� 26 ��������� �� ������ 2
    assert(Search(root, 40) == 2); // �������� 40 ��������� �� ������ 2
    assert(Search(root, 16) == 3); // �������� 16 ��������� �� ������ 3
    assert(Search(root, 3) == 3);  // �������� 3 ��������� �� ������ 3 
    assert(Search(root, 39) == 3); // �������� 39 ��������� �� ������ 3
    assert(Search(root, 55) == 3); // �������� 55 ��������� �� ������ 3
    assert(Search(root, 15) == 4); // �������� 15 ��������� �� ������ 4
    // ��������� ����� �� ������������� ���������
    assert(Search(root, 1) == -1);  // �������� 1 ����������� � ������
    assert(Search(root, 9) == -1);  // �������� 9 ����������� � ������
    assert(Search(root, 100) == -1);  // �������� 100 ����������� � ������

    // ����������� ������, ������ ������
    DeleteTree(root);
    cout << "����� �������" << endl;
}
//������������ ������� ����������
void TestAdd() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(40, nullptr, nullptr);
    Add(root, 25);
    Add(root, 70);
    Add(root, 30);
    Add(root, 45);
    Add(root, 43);

    //PrintTree(root, 1);


    // ������� 0
    assert(root->data == 40);

    // ������� 1
    assert(root->left->data == 25);
    assert(root->right->data == 70);

    // ������� 2
    assert(root->left->left == nullptr);
    assert(root->left->right->data == 30);
    assert(root->right->right == nullptr);
    assert(root->right->left->data == 45);

    // ������� 3
    assert(root->right->left->left->data == 43);

    // ����������� ������, ������ ������
    DeleteTree(root);

    cout << "���������� ��������" << endl;
}
//������������ ������� �������
void TestDepth() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    Tre�Random(root, 9, 11, 87);
    // ��������� ������� ������
    assert(Depth(root) == 3);
    // ����������� ������, ������ ������
    DeleteTree(root);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // ��������� ������� ������
    assert(Depth(root1) == 0);
    // ����������� ������, ������ ������
    DeleteTree(root1);


    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(23, nullptr, nullptr);
    Tre�Random(root, 21, 1, 80);
    // ��������� ������� ������
    assert(Depth(root2) == 8);
    // ����������� ������, ������ ������
    DeleteTree(root2);
    cout << "������� ������� �������" << endl;
}
//������������ ������� �������� �����
void TestCountNodes() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    Tre�Random(root, 10, 20, 100);
    PrintTree(root, 1);
    // ��������� ���������� ����� � ������
    assert(countNode(root) == 11);
    // ����������� ������, ������ ������
    DeleteTree(root);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // ��������� ���������� ����� � ������
    assert(countNode(root1) == 1);
    // ����������� ������, ������ ������
    DeleteTree(root1);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    Tre�Random(root, 5, 20, 50);
    // ��������� ���������� ����� � ������
    assert(countNode(root2) == 6);
    // ����������� ������, ������ ������
    DeleteTree(root2);

    cout << "������� ����� �������" << endl;
}

//������������ ������� �������� �������
void TestCountLeaf() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    Tre�Random(root, 10, 10, 50);
    int count = 0;
    CountLeaf(root, count);
    // ���������, ��� ���������� ������� ����� ���������� ��������
    assert(count == 3);
    // ����������� ������, ������ ������
    DeleteTree(root);



    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    Tre�Random(root, 15, 20, 60);
    int count2 = 0;
    CountLeaf(root2, count2);
    // ���������, ��� ���������� ������� ����� ���������� ��������
    assert(count == 5);
    // ����������� ������, ������ ������
    DeleteTree(root2);
    cout << "������� ������� �������" << endl;
}




/// ����� ��� BST

//������������ ������������ �����������
template<class T>
void TestCopyConstructor() {
    // ������� ������ ������
    BinSTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(8);

    // ������� ������ ������ � �������������� ��� ������ ������� ������
    BinSTree<int> tree2(tree1);

    // ��������� ������� ��������
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // �������� ������ ������
    tree1.Insret(10);

    // ���������, ��� ��������� ������� ������ �� ������ �� ������ ������
    assert(tree1.ListSize() == 4);
    assert(tree2.ListSize() == 3);

    cout << "����������� ����������� ���� �������" << endl;
}
//������������ ��������� ������������ �����������
template<class T>
void TestCopyOperator() {
    // ������� ������ ������
    BinSTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
    // ������� ������ ������,�������� ��� �������� �� ������� ����� �������� ������������ �����������
    BinSTree<int> tree2;
    tree2 = tree1;
    // ��������� ������� ��������
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // �������� ������ ������
    tree1.Delete(7);

    // ���������, ��� ��������� ������� ������ �� ������ �� ������ ������
    assert(tree1.ListSize() == 2);
    assert(tree2.ListSize() == 3);

    cout << "�������� ������������ ����������� ���� �������" << endl;

}
//������������ ������������ �����������
template<class T>
void TestMoveConstructor() {
    // ������� ������ ������
    BinSTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
    // �������� ����������� ����������� ������ �� tree1 � tree2
    BinSTree<int> tree2(move(tree1));
    // ��������� ������ � ������� ������� �����a
    assert(tree1.ListSize() == 0);
    assert(tree1.ListEmpty() == true);
    //���������, ��� tree2 �������� ������������ ������
    assert(tree2.ListSize() == 3);
    assert(tree2.ListEmpty() == false);

    cout << "����������� ����������� ���� �������" << endl;
}

template<class T>
//���� �������
void TestInsert() {
    // ������� ������ ������
    BinSTree<T> tree;
    assert(tree.ListSize() == 0);
    // ��������� �������� � ������
    tree.Insert(5);
    assert(tree.ListSize() == 1);
    tree.Insert(3);
    assert(tree.ListSize() == 2);
    tree.Insert(7);
    assert(tree.ListSize() == 3);
    tree.Insert(2);
    assert(tree.ListSize() == 4);
    tree.Insert(4);
    //��������� � ������ � ���������
        // ��������� ������ ������
    assert(tree.ListSize() == 5);
    cout << "������� ��������" << endl;
}
template<class T>
//���� ��������
void TestRemove() {

    BinSTree<T> tree;

    // ��������� �������� � ������
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    // ������� �������� �� ������
    tree.Delete(5);
    tree.Delete(2);

    // ��������� ������ ������ ����� ��������
    assert(tree.ListSize() == 3);
    // �������� ������ ������
    int treeSize = tree.ListSize();

    // ������� ������ ��� �������� ��������� ������
    int* arr = new int[treeSize];

    // �������� ������ � ������
    PrintArr(tree.Curr(), arr, 0);


    // ��������� ��������� ���������
    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 7);

    // ����������� ���������� ������
    delete[] arr;
    cout << "�������� ���� �������" << endl;
}
template<class T>
//���� �����
void TestFind() {

    BinSTree<T> tree;

    // ��������� �������� � ������
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);

    // ��������� ����� ���������
    assert(tree.Find(5) == 0);  // ������� 5 ������ ���� ������
    assert(tree.Find(2) == 2);  // ������� 2 ������ ���� ������
    assert(tree.Find(6) == -1); // ������� 6 �� ������ ���� ������
    cout << "����� ���� �������" << endl;
}


//������� �������� �������� ������ 
BinSTree<int> CreateTestBST() {
    // ������� ������ ������ BinSTree
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

//������� �������� ����������� ����� �������� ������ 
BinSTree<int> CreateTestBSTLeft() {
    // ������� ������ ������ BinSearchTree
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

    // �������� �������� ������ ������
    auto it = bst.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 3);


    BinSTree<int> bst1 = CreateTestBSTLeft();
    // �������� �������� ������ ������
    auto it1 = bst1.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it1 == 1);

    cout << "�������� ������ BST �������" << endl;
}
void TestBSTDataOperator() {
    BinSTree<int> bst = CreateTestBST();

    // �������� �������� ������ ������
    auto it = bst.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 3);

    // ��������� � ���������� ����
    ++it;

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 7);
    ++it;
    assert(*it == 15);
    ++it;
    assert(*it == 16);


    BinSTree<int> bst1 = CreateTestBSTLeft();
    // �������� �������� ������ ������
    auto it1 = bst1.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it1 == 1);

    // ��������� � ���������� ����
    ++it1;

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it1 == 2);
    ++it1;
    assert(*it1 == 4);
    ++it1;
    assert(*it1 == 6);
    cout << "�������� ������������� �������" << endl;
}

// ���� ���������� ���������
void TestIncOperator() {
    BinSTree<int> bst = CreateTestBST();

    // �������� �������� ������ ������
    auto it = bst.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 3);

    // ��������� � ���������� ����
    ++it;

    // ��������� �������� �������� ���� ����� �������� �������������
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

    cout << "�������� ������������� �������" << endl;
}
//���� ��������� ���������
void TestOperatorEqual() {
    BinSTree<int> bst = CreateTestBST();

    //�������� ���������
    auto it1 = bst.begin();
    auto it2 = bst.begin();

    // ���������, ��� ��������� ����� ���� ����� � ������� ��������� ���������
    assert(it1 == it2);



    cout << "�������� ��������� �������" << endl;
}

void TestOperatorUnequal() {
    BinSTree<int> bst = CreateTestBST();

    //�������� ���������
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    ++it2;
    // ���������, ��� ��������� ����� ���� ����� � ������� ��������� ���������
    assert(it1 != it2);



    cout << "�������� ����������� �������" << endl;
}