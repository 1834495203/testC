//
// Created by asus on 2023/8/10.
//

#ifndef TESTC_TRAINSTART_H
#define TESTC_TRAINSTART_H

#include "../base/base.h"
#include "../list/base/listData.h"
#include "../tree/base/treeData.h"

/**
 * 打印数组
 * @param arr 数组
 * @param len 长度
 */
void printArray(int *arr, int len);

/**
 * 交换数据
 * @param var1 数据1
 * @param var2 数据2
 */
void exchange(int *var1, int *var2);

/**
 * 适用于快速排序，一次划分
 * @param arr 数组
 * @param low 低位下标
 * @param high 高位下标
 * @return 基准下标
 */
int partition(int *arr, int low, int high);

/**
 * 计算e的近似值
 * @return e
 */
double calculateE();

/**
 * 打印杨辉三角
 * @param n 高度
 */
void generatePascalTriangle(int n);

/**
 * 冒泡排序
 * @param arr 数组
 * @param len 长度
 */
void bubbleSort(int *arr, int len);

/**
 * 直接选择排序
 * @param arr 数组
 * @param len 长度
 */
void selectSort(int *arr, int len);

/**
 * 直接插入排序
 * @param arr 数组
 * @param len 长度
 */
void insertSort(int *arr, int len);

/**
 * 快速排序
 * @param arr 数组
 * @param len 长度
 * @param low 对位下标
 * @param high 高位下标
 */
void quickSort(int *arr, int low, int high);

/**
 * 二分查找
 * @param arr 数组
 * @param len 长度
 * @param k 关键字
 */
int binarySearch(const int *arr, int len, int k);

/**
 * 判断是否为素数
 * @param n 数据
 * @return 是否为素数
 */
boolean isPrime(int n);

/**
 * 将十六进制转化为十进制
 * @param x 十六进制
 * @return 十进制
 */
int convert_(const char *x, int len);

/**
 * 连接字符串
 * @param var1 字符串1
 * @param var2  字符串2
 * @return 连接的字符串
 */
char *cat(char *var1, char *var2);

/**
 * 打印所有n位数的水仙花数
 * @param n n位数
 */
void narcissistic(int n);

/**
 * 输入字符组成链表，然后反向输出
 */
void inputAndOutput();

/**
 * 删除链表中所有x的数据
 * @param list 链表
 * @param x 数据
 */
void deleteInX(LinkedList list, ListNode x);

/**
 * 创建链表
 * @param arr 数组
 * @return 链表头节点
 */
LinkedList createList(const ListNode *arr, int len);

/**
 * 打印链表
 * @param list 链表
 */
void printLinkedList(LinkedList list);

/**
 * *********************************************************
 */

/**
 * 莱布尼茨级数
 * s = 1 - 1/3 + 1/5 - 1/7 + ... + 1/101
 */
void sum_s();

/**
 * 求出555555中约数最大的三位数
 */
void doWhile_555555();

/**
 * 反转输入的数字
 */
void reverse_();

typedef struct stu_ {
    int sid, score;
}S_;

/**
 * 将高于平均分的学生的数据放入数组rs, 人数放入n, 返回平均分
 * @param s 学生数组
 * @param rs 高于平均分的学生
 * @param n 人数
 * @return 平均分
 */
double recordStudent(S_ *s, S_ *rs, int *n);

/**
 * 计算 s = (1 - 1/2) + (1/3 - 1/4) + ... + (1/(2n-1) - 1/2n)
 * @param n 长度
 * @return 值
 */
double sum_a(int n);

/**
 * 检查开头的 * 是否符合预期，删除多余的 *
 * @param str 字符串
 * @param n *数量
 */
void checkStrStar(char **str, int n);

/**
 * 逆置字符串
 * @param str 字符串
 * @param len 长度
 */
void reverse_s(char *str, int len);

/**
 * 99乘法表
 */
void print99();

/**
 * 二进制求和
 * @param a 二进制字符串1
 * @param b 二进制字符串2
 * @return 和
 */
char *addBinary(char * a, char * b);

/**
 * 从键盘上输入任意整数，求它的逆序数
 */
void getReverse();

/**
 * 统计大写字母，小写字母，数字字符，空格等
 */
void classify();

/**
 * 二叉树节点的构造
 * @param data 数据
 * @return 二叉树节点
 */
TreeNode *createTreeNode(Node data);

/**
 * 二叉搜索树的构造
 * @param node 节点
 * @param data 数据
 * @return 节点
 */
TreeNode *insertTreeNode(TreeNode *node, Node data);

/**
 * 中序遍历
 * @param node 头节点
 */
void inorderTraversal(TreeNode *node);

/**
 * 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 * @param nums 非空 整数数组 nums, 除了某个元素只出现一次以外，其余每个元素均出现两次。
 * @param numsSize size
 * @return 找出那个只出现了一次的元素。
 */
int singleNumber(const int *nums, int numsSize);

/**
 * 一个灯塔，每一层是上一层的2倍，知道总共和高度，求底层灯塔的数量
 * @param total 总共
 * @param height 高度
 * @return 底层灯塔数量
 */
int findLatent(int total, int height);

/**
 * 插入有序链表，要求有序
 * @param list 头节点
 * @param data 数据
 */
void listInsert(LinkedList list, ListNode data);

/**
 * 找矩阵中的鞍点，其在其行中最小，在其列中最大
 * @param matrix m*n的矩阵
 * @param m 行
 * @param n 列
 */
void findSaddlePoint(int **matrix, int m, int n);

/**
 * 调整大根堆
 * @param arr 堆数组
 * @param len 长度
 * @param k 根节点
 */
void adjustMaxHeap(int arr[], int len, int k);

#define SHARED_STACK_MAX (1 << 3)
//共享栈
typedef struct SharedStack {
    int datum[SHARED_STACK_MAX];
    int total_size;
    int stack_one_index, stack_two_index;
} SharedStack;

//单个栈的信息
typedef struct SeparatedStack {
    int type;
    int size;
    int index;
} SeparatedStack;

/**
 * 共享栈的初始化
 * @param stack 共享栈
 * @param var1 栈1
 * @param var2 栈2
 */
void initSharedStack(SharedStack *stack, SeparatedStack *var1, SeparatedStack *var2);

/**
 * 向共享栈中添加元素
 * @param stack
 * @param var
 * @return
 */
int insert4SharedStack(SharedStack *stack, SeparatedStack *var, int data);

/**
 * 判断两个树是否相等
 * @param var1 树一
 * @param var2 树二
 * @return 是否相等
 */
int isBinaryTreeSame(TreeNode *var1, TreeNode *var2);

/**
 * 判断存储在文本中的字符串是否对称
 * 路径：D:\github\files\string.txt
 * @return 是否对称
 */
int isStringSymmetry();

/**
 * 顺序表的初始化
 * @param data 数据
 * @param len 数据长度
 * @return 顺序表
 */
OrderedList *initOrderedList(const int *data, int len);

/**
 * 删除顺序表中所有为item的元素
 * @param list 顺序表
 * @param item 元素
 */
void removeItems4OrderList(OrderedList *list, int item);

/**
 * 通过后序遍历与中序遍历递归地构造二叉树
 * @param inorder 中序遍历
 * @param inStart 中序起始位置
 * @param inEnd 中序结束位置
 * @param postorder 后序遍历
 * @param postIndex  后序节点
 * @return
 */
TreeNode *createTree(int *inorder, int inStart, int inEnd, int *postorder, int *postIndex);

/**
 * 返回某点在完全二叉树中的层数
 * @param var 二叉树
 * @param data 节点
 * @param current 当前节点的层数
 * @return 层数
 */
int binaryTreeNodeHeight(TreeNode *var, Node data, int current);

/**
 * 判断括号是否匹配 {} () []
 * @param bracket 括号数组
 * @return 是否匹配
 */
int matchBracket(char *bracket);

#endif //TESTC_TRAINSTART_H
