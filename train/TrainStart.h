//
// Created by asus on 2023/8/10.
//

#ifndef TESTC_TRAINSTART_H
#define TESTC_TRAINSTART_H

#include "../base/base.h"
#include "../list/base/listData.h"
#include "../tree/base/treeData.h"
#include "../stack/stackData.h"

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
 * @return 根节点
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
 * 判断括号是否匹配 {[]} ({}) [()]
 * @param bracket 括号数组
 * @return 是否匹配
 */
int matchBracket(char *bracket);

/**
 * 二叉查找树的查找
 * @param head 二叉查找树的根节点
 * @param data 值
 * @return 如果有则返回该节点，否则返回null
 */
TreeNode *searchBST(TreeNode *head, Node data);

/**
 * 判断单链表是否是单增或者单减或者无序
 * @param list 单链表
 * @return 递增或递减或无序 2未初始化 1递增 0递减 -1无序
 */
int isOrdered(LinkedListNode *list);

/**
 * 求二叉树的深度
 * @param node 二叉树根节点
 * @return 深度
 */
int binaryTreeDepth(TreeNode *node);

/**
 * 检测org字符串中是否含有dest字串
 * @param org 主串
 * @param dest 字串
 * @return 返回dest在org中的下标
 */
int isStringMatch(char *org, char *dest, int org_len, int dest_len);

/**
 * 求二叉树中最小值的节点值
 * @param node 二叉树头节点
 * @return 最小节点值
 */
Node searchBinaryTree4MinNode(TreeNode *node);

/**
 * 求出二叉排序树中左子树最大与右子树最小的节点值
 * @param node 二叉树节点
 * @return 节点值的数组
 */
Node *searchBST4B_M(TreeNode *node);

/**
 * 判断二叉树是否对称
 * 注意是对称而不是相似
 * @param node 根节点
 * @return 是否对称
 */
int isSymmetric(TreeNode *node);

/**
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
 * @param nums 升序的整型数组 严格递增
 * @param numSize 数组长度
 * @return 根节点
 */
TreeNode *sortedArray2BST(int *nums, int numSize);

/**
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）
 * @param head 链表的头节点
 * @return 是否有环
 */
int hasCycle(LinkedListNode *head);

/**
 * 给定一副牌，每张牌上都写着一个整数。
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * @param deck 给定一副牌，每张牌上都写着一个整数。
 * @param deckSize 大小
 * @return 仅当你可选的 X >= 2 时返回 true。
 */
int hasGroupsSizeX(int* deck, int deckSize);

// 辗转相除法求最大公约数
int gcd(int a, int b);

/**
 * 删除指定值的节点
 * @param node 头节点
 * @param pre 节点之前的节点
 * @param k 值
 */
void deleteInLinkedList(LinkedListNode *node, LinkedListNode *pre, ListNode k);

/**
 * 删除链表中最小节点值
 * @param node 根节点
 */
void deleteMin4LinkedList(LinkedListNode *node);

/**
 * 链表的就地逆置
 * @param head 头节点
 */
void linkedListReverse(LinkedListNode *head);

/**
 * 链表的递增排序
 * @param head 头节点
 */
void linkedListOrder(LinkedListNode *head);

/**
 * 删除链表中ab范围内的节点
 * @param head
 * @param a
 * @param b
 */
void deleteLinkedListRange(LinkedListNode *head, int a, int b);

/**
 * 二叉树的叶子节点个数
 * @param root 根节点
 * @return 个数
 */
int countLeaf(TreeNode *root);

/**
 * 匹配模式 求next数组
 * @param s 字串
 * @param next next数组
 */
void getNext(char *s, int next[]);

/**
 * 判断是否为二叉排序树
 * @param root 根节点
 */
int isBST(TreeNode *root);

/**
 * 希尔排序
 * @param arr 数组
 * @param len 长度
 * @param dk 增量
 */
void shellSort(int *arr, int len, int dk);

/**
 * 非递归求二叉树的高度
 * @param root 根节点
 * @return 高度
 */
int getBinaryTreeHeight(TreeNode *root);

/**
 * 判断是否为完全二叉树
 * @param root 根节点
 * @return 是否为完全二叉树
 */
int isCompleteBinaryTree(TreeNode *root);

/**
 * 计算二叉树中所有度为二的节点
 * @param root 根节点
 * @return 度为2节点的数量
 */
int getDegreeOf2InBinaryTree(TreeNode *root);

/**
 * 交换二叉树的左右子节点
 * @param root
 */
void exchangeChildInBinaryTree(TreeNode *root);

/**
 * 返回给定二叉树的先序遍历中index下标的节点
 * @param root 根节点
 * @param index 下标
 * @return 指定二叉树
 */
TreeNode *getPresetPreorderNode(TreeNode *root, int index);

/**
 * 删除指定节点值为data的子树，并释放相应空间
 * @param root 根节点
 * @param data 值
 */
void deletePresetNode(TreeNode **root, Node data);

/**
 * 打印指定节点的祖先
 * @param root 根节点
 * @param data 指定节点
 */
int printAncestorsInBinaryTree(TreeNode *root, Node data);

/**
 * 是否是二叉平衡树
 * @param root 根节点
 * @return 是否是二叉平衡树
 */
int isBalanceBinaryTree(TreeNode *root);

/**
 * 将数组分为奇数组和偶数组
 * @param arr 数组
 * @param odd 奇数组
 * @param even 偶数组
 */
void divideParity(const int *arr, int len, int **odd, int *odd_len, int **even, int *even_len);

/**
 * 拆分链表， 隔一个为一个链表
 * @param array 原链表
 * @param a 链表a
 * @param b 链表b
 */
void divideLinkedListIntermittent(LinkedListNode *arr, LinkedListNode **a, LinkedListNode **b);

/**
 * 删除在递增有序的链表中相同的元素
 * @param arr 链表
 */
void removeIdenticalElements(LinkedListNode *arr);

/**
 * 将两个递增有序的链表合并成一个递减的链表
 * @param var1 链表1
 * @param var2 链表2
 */
void mergeTwoLinkedListInDecrement(LinkedListNode *var1, LinkedListNode *var2);

/**
 * 获取两个链表中的公共元素
 * @param var1 链表1
 * @param var2 链表2
 * @return 公共元素链表
 */
LinkedListNode *mergeIdenticalElements(LinkedListNode *var1, LinkedListNode *var2);

/**
 * 求两个链表的交集
 * @param var1 链表1
 * @param var2 链表2
 * @return 交集链表
 */
LinkedListNode *intersection(LinkedListNode *var1, LinkedListNode *var2);

/**
 * 求出BST中的最小值和最大值
 * @param root 根节点
 * @param max 最大值
 * @param min 最小值
 */
void getMinMaxInBST(TreeNode *root, Node *max, Node *min);

/**
 * 递增输出在二叉排序树中不小与x的数据
 * @param root 根节点
 * @param x 数据
 */
void printBSTNotLessThanX(TreeNode *root, Node x);

/**
 * 找到p节点和q节点最近的祖先节点
 * @param root 根节点
 * @param p 节点p
 * @param q 节点q
 * @return 祖先节点
 */
TreeNode *findTheNearestAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

/**
 * 计算二叉树的最大宽度
 * @param root 根节点
 * @return 宽度
 */
int getWidthOfBinaryTree(TreeNode *root);

/**
 * 在满二叉树中由先序序列求后序序列
 * @param preorder 先序序列
 * @return 后序序列
 */
void pre2Post(char preOrder[], int preStart, int preEnd, char postOrder[], int postStart, int postEnd);

/**
 * 后序遍历的非递归算法
 * @param root 根节点
 */
void postOrderNoRe(TreeNode *root);

/**
 * 将节点按从左到右的顺序连接成链表，并用叶节点的右指针来存放单链表指针
 * @param root 根节点
 */
void linkedLeafNode(TreeNode *root);

/**
 * 双向冒泡排序 一趟把最大的元素放在最后面 一趟把最小的元素放在最前面
 * @param arr 数组
 * @param len 长度
 */
void twoWayBubbleSort(int *arr, int len);

/**
 * 将所有奇数移到偶数的前面
 * @param arr
 * @param len
 */
void oddFrontOfEven(int *arr, int len);

/**
 * 找到第x小的元素
 * @param arr 数组
 * @param len 长度
 * @param x 第x小的元素
 * @return 第x小的元素的值
 */
int findMinorX(int *arr, int len, int x);

/**
 * 用快速选择算法实现 找到第x小的元素
 * @param arr 数组
 * @param low 最小下标
 * @param high 最大下标
 * @param k 第k小
 * @return 第k小的元素值
 */
int kthSmallest(int arr[], int low, int high, int k);

/**
 * 荷兰国旗问题 将数组中的字符串由 红 白 蓝 的顺序排列好
 * @param flag 字符串数组
 * @param len 长度
 */
void dutchFlagProblem(char *flag[], int len);

/**
 * dist是否为org的子序列
 * @param org 原链表
 * @param dist 子链表
 * @return 是否是子序列
 */
int isSubsequence(LinkedListNode *org, LinkedListNode *dist);

/**
 * 复制二叉树
 * @param root 根节点
 * @param copy 新的二叉树
 */
void copyBinaryTree(TreeNode *root, TreeNode **copy);

/**
 * 将无序链表分为由递增的奇数链和偶数链
 * @param list 链表
 * @param odd 奇数链表
 * @param even 偶数链表
 */
void divideOddEven(LinkedListNode *list, LinkedListNode **odd, LinkedListNode **even);
#endif //TESTC_TRAINSTART_H
