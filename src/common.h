// # 商业转载请联系作者获得授权，非商业转载请注明出处。
// # For commercial use, please contact the author for authorization. For non-commercial use, please indicate the source.
// # 协议(License)：署名-非商业性使用-相同方式共享 4.0 国际 (CC BY-NC-SA 4.0)
// # 作者(Author)：songjiahao
// # 链接(URL)：https://blog.songjiahao.com/archives/362
// # 来源(Source)：SAquariusの梦想屋

// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <Licenses - GNU Project - Free Software Foundation>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

void PrintVector(vector<int> nums);           // 可以用于调用打印一维整形数组
void PrintMatrix(vector<vector<int>> matrix); // 可以用于打印二维整形数组
vector<int> VectorFromString(const string &input);
string VectorToString(vector<int> vec);
vector<vector<int>> MatrixFromString(const string &input);
string MatrixToString(vector<vector<int>> mat);

// 链表定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 相关函数的声明
void insertList(ListNode *&head, int x); // 头插法在链表头部插入节点
void printList(ListNode *head);          // 打印链表
int getLenght(ListNode *head);           // 获取链表长度
ListNode *creatList(int a[], int n);     // 根据数组创建链表

#define null INT_MAX // 把力扣给定的null节点定义为int的最大值，用于识别空结点
// 二叉树的结构体定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *CreatTree(vector<int> &layerorder);      // 根据给定的层序序列建树的函数
int LayerOfTree(TreeNode *root);                   // 计算树的层数，用于绘制树形
void PrintTreeMatrix(vector<vector<int>> &matrix); // 用于打印树形结构专用的二维数组输出函数
void PrintTree(TreeNode *root);                    // 打印树的函数、

#ifdef _IMPLEMENTATION_
void PrintVector(vector<int> nums)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (i)
            putchar(' ');
        cout << nums[i];
    }
    putchar('\n');
    return;
}

void PrintMatrix(vector<vector<int>> matrix)
{
    int row = 0, col = 0;
    row = matrix.size();
    if (row)
        col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j)
                putchar(' ');
            cout << matrix[i][j];
        }
        putchar('\n');
    }
}

inline bool not_in(char a, const string &delims)
{
    for (int i = 0; i < delims.size(); i++)
    {
        if (a == delims[i])
        {
            return false;
        }
    }
    return true;
}

string StringRemove(const string &src, const string &delims)
{
    char *temp = (char *)alloca(src.size() + 1);
    int j = 0;
    vector<int> ret;
    for (int i = 0; i < src.size(); i++)
    {
        if (not_in(src[i], delims))
        {
            temp[j++] = src[i];
        }
    }
    temp[j] = 0;
    return string(temp);
}

std::vector<std::string_view> splitSV(std::string_view strv, std::string_view delims)
{
    std::vector<std::string_view> output;
    size_t first = 0;

    while (first < strv.size())
    {
        const auto second = strv.find(delims, first);
        if (first != second)
            output.emplace_back(strv.substr(first, second - first));
        if (second == std::string_view::npos)
            break;
        first = second + 1;
    }
    return output;
}

vector<int> VectorFromString(const string &input)
{
    vector<int> ret;
    string temp = StringRemove(input, " []\t\r\n");
    vector<string_view> num_list = splitSV(temp, ",");
    for (int i = 0; i < num_list.size(); i++)
        ret.emplace_back(atoi(string(num_list[i]).c_str()));
    return ret;
}

string VectorToString(vector<int> vec)
{
    stringstream ss;
    ss << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        ss << vec[i];
        if (i != vec.size() - 1)
            ss << ",";
    }
    ss << "]";
    return ss.str();
}

vector<vector<int>> MatrixFromString(const string &input)
{
    vector<vector<int>> ret;
    string temp = StringRemove(input, " \t\r\n");
    vector<string_view> nums_list = splitSV(temp, "],[");
    for (int i = 0; i < nums_list.size(); i++)
    {
        string row = StringRemove(string(nums_list[i]), "[]");
        vector<string_view> nums = splitSV(row, ",");
        vector<int> nums_vec;
        for (int j = 0; j < nums.size(); j++)
        {
            nums_vec.emplace_back(atoi(string(nums[j]).c_str()));
        }
        ret.emplace_back(nums_vec);
    }
    return ret;
}

string MatrixToString(vector<vector<int>> mat)
{
    stringstream ss;
    ss << "[";
    for (int i = 0; i < mat.size(); i++)
    {
        ss << "[";
        for (int j = 0; j < mat[i].size(); j++)
        {
            ss << mat[i][j];
            if (j != mat[i].size() - 1)
                ss << ",";
        }
        ss << "]";
        if (i != mat.size() - 1)
            ss << ",";
    }
    ss << "]";
    return ss.str();
}

// 插入链表,头插,无头结点
void insertList(ListNode *&head, int x)
{
    ListNode *p = new ListNode(x);
    if (head == nullptr)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

// 打印链表
void printList(ListNode *head)
{
    if (head == nullptr)
    { // 空链表输出空
        printf("NULL\n");
        return;
    }
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    putchar('\n');
}

// 获取链表长度
int getLenght(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

// 根据一个数组序列，使用头插创建链表，需要知道元素个数
ListNode *creatList(int a[], int n)
{
    ListNode *head = nullptr;
    if (n > 0)
        reverse(a, a + n); // 头插方法创建的链表是给定序列的逆序，这里提前逆置一下
    for (int i = 0; i < n; i++)
    { // 得到给定序列顺序的链表
        insertList(head, a[i]);
    }
    return head;
}

TreeNode *CreatTree(vector<int> &layerorder)
{ // 根据层序序列建树
    int n = layerorder.size();
    if (n == 0)
        return nullptr; // 计算序列元素个数，如果空树返回空指针
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(layerorder[0]); // 创建根结点并入队
    q.push(root);
    for (int i = 0; i <= (n - 1) / 2; i++)
    { // 只需处理第一个结点到最后一个非叶子结点
        if (layerorder[i] == null)
            continue;              // 如果是空结点则跳过
        TreeNode *now = q.front(); // 从队列中取出当前结点
        q.pop();
        int left = 2 * i + 1, right = 2 * (i + 1); // 计算当前结点的左右孩子的位置
        if (left < n && layerorder[left] != null)
        { // 如果左孩子存在且不为空时创建左孩子结点并入队
            now->left = new TreeNode(layerorder[left]);
            q.push(now->left);
        }
        if (right < n && layerorder[right] != null)
        { // 如果右孩子存在且不为空时创建右孩子结点并入队
            now->right = new TreeNode(layerorder[right]);
            q.push(now->right);
        }
    }
    return root; // 返回创建好的树
}

int LayerOfTree(TreeNode *root)
{ // 层序遍历获取树高
    if (root == nullptr)
        return 0;
    int layer = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        layer++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *now = q.front();
            q.pop();
            if (now->left)
                q.push(now->left);
            if (now->right)
                q.push(now->right);
        }
    }
    return layer;
}

void PrintTreeMatrix(vector<vector<int>> &matrix)
{ // 打印填充了树形结构的二维数组
    int row = 0, col = 0;
    row = matrix.size();
    string flag = string(3, ' '); // 空白位置使用3个空格占用
    if (row)
        col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j)
                putchar(' ');
            if (matrix[i][j] == null)
                cout << flag; // 如果是空节点则打印空字符
            else
                printf("%3d", matrix[i][j]); // 否则输出三个字符宽度的数字
        }
        cout << string(2, '\n'); // 增大行距以避免树形看起来太扁
    }
}

void PrintTree(TreeNode *root)
{ // 根据树形填充一个二维数组
    if (root == nullptr)
    { // 如果是空树则只输出NULL
        puts("NULL");
        return;
    }
    struct node
    { // 每一个节点对应二维数组中的一个坐标
        int x, y;
        node() {}
        node(int x_, int y_) : x(x_), y(y_) {}
    };
    unordered_map<TreeNode *, node> mp;                        // 节点指针和二维数组坐标的对应关系
    int layer = LayerOfTree(root);                             // 获取树高
    int rol = (1 << layer) - 1;                                // 按照满二叉树的最后一行数量计算（每个元素中间用空格分开,共为奇数个空位）
    vector<vector<int>> matrix(layer, vector<int>(rol, null)); // 用于填充的二维数组，用INT_MAX初始化
    int offset = 1 << (layer - 2);                             // 偏移量，根的孩子与根节点的坐标偏移量为1<<(layer-2)
    queue<TreeNode *> q;                                       // 以层序遍历的方式填充
    q.push(root);
    int i = 0, j = rol / 2; // 根节点所在的坐标为第一行的中间
    mp[root] = node(i, j);  // 填充并记录坐标
    matrix[i][j] = root->val;
    while (!q.empty())
    { // 层序遍历
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            TreeNode *now = q.front();
            q.pop();
            i = mp[now].x, j = mp[now].y; // 获取队头元素的坐标
            if (now->left)
            { // 如果左孩子存在，则左孩子入队并填充
                q.push(now->left);
                int tempi = i + 1, tempj = j - offset; // 左孩子位于下一行，并且向左偏移
                matrix[tempi][tempj] = now->left->val;
                mp[now->left] = node(tempi, tempj);
            }
            if (now->right)
            { // 右孩子同理
                q.push(now->right);
                int tempi = i + 1, tempj = j + offset; // 右孩子位于下一行，并且向右偏移
                matrix[tempi][tempj] = now->right->val;
                mp[now->right] = node(tempi, tempj);
            }
        }
        offset >>= 1; // 偏移量每次减半
    }
    PrintTreeMatrix(matrix); // 打印最后的结果
    return;
}

#endif
