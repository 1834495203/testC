#include <assert.h>
#include <setjmp.h>
#include <stdarg.h>
#include "stdio.h"
#include "stdlib.h"
#include "./base/base.h"
#include "math.h"
#include "string.h"
#include "pthread.h"
#include "train/TrainStart.h"
#include "list/base/listData.h"
#include "conio.h"
#include "queue/base/queueQuiz.h"

typedef struct student{
    string name;
    string gender;
    int score;
}Student, *Stu;

#define X(a) (a*2)

void put(){
    FILE *p = fopen("D:\\github\\test.txt", "w");
    Stu student = malloc(sizeof(struct student));
    student->name = "裴橘";
    student->gender = "女";
    student->score = 99;
    fwrite(student, 1, sizeof(struct student), p);
    fclose(p);

    Stu read = malloc(sizeof(struct student));
    p = fopen("D:\\github\\test.txt", "r");
    fread(read, 1, sizeof(struct student), p);
    printf("%s\n", read->name);
    fclose(p);
}

void put_(){
    FILE *p = fopen("D:\\github\\test.txt", "w");
    Student std = {"裴橘", "女", 99};
    fwrite(&std, 1, sizeof(Student), p);
    fclose(p);
}

void get_(){
    Student stdRead;
    FILE *p = fopen("D:\\github\\test.txt", "r");
    fread(&stdRead, 1, sizeof(struct student), p);
    printf("%s\n", stdRead.name);
    fclose(p);
}

void read_(){
    FILE *p = fopen("D:\\github\\str.txt", "r");
    char *str = malloc(sizeof(char)*5);
    fread(str, 2, 2*sizeof(char), p);
    fclose(p);
    str[4] = '\0';
    printf("%s", str);
}

void find(const int arr[], int len) {
    int m1 = arr[0] > arr[1] ? arr[0] : arr[1];
    int m2 = arr[1] > arr[0] ? arr[0] : arr[1];
    for (int i = 2; i < len; ++i) {
        if (arr[i] > m2){
            if (arr[i] > m1) m1 = arr[i];
            else m2 = arr[i];
        }
    }
    printf("m1=%d, m2=%d", m1, m2);
}

int test(){
    int i = 100;
    for (int bool = 1; i < 1000; ++i, bool = 1) {
        for (int j = 2; j >= 0; --j)
            if ((i / (int) pow(9, j)) % 9 != (i / (int) pow(7, 2-j)) % 7) bool = 0;
        if (bool) break;
    }
    return i;
}

//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
void sort() {
    int size;
    scanf_s("%d", &size);
    //动态分配二维数组
    int **res = (int **) malloc(sizeof(int *)*size);
    for (int i = 0; i < size; ++i)
        res[i] = (int *) malloc(sizeof(int)*size);
    int all[size*size];
    for (int i = 0; i < size * size; ++i) scanf_s("%d", &all[i]);
    for (int i = 0; i < size * size; ++i) {
        for (int j = 0; j < size * size - 1 - i; ++j) {
            if (all[j] > all[j+1]) {
                int temp = all[j];
                all[j] = all[j+1];
                all[j+1] = temp;
            }
        }
    }

    int p = 0;
    int q = size*size-1;
    //左上三角
    for (int i = 0; i <= (2*size-1)/2; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i % 2) res[i-j][j] = all[p++];
            else res[j][i-j] = all[p++];
        }
    }
    //右下三角
    for (int i = 2*size-2; i > (2*size-1)/2; --i) {
        for (int j = (2*size-1)/2; j >= i - (2*size-1)/2; --j) {
            if (i % 2) res[i-j][j] = all[q--];
            else res[j][i-j] = all[q--];
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

char *deleteStar(){
    char *str = (char*) malloc(sizeof(char));
    scanf("%s", str);
    int len = (int) strlen(str);
    int step = 0;
    char *p = &str[0];
    for (int i = 0; i < len; ++i) {
        if (*p == '*'){
            *p = str[i];
        } else if (*p != '*' && str[i] == '*') {
            step++;
        }
    }
    return null;
}

void re(int i) {
    while (i > 0) {
        printf("%d ", i%10);
        i /= 10;
    }
}

void uwu(void *ref) {
    printf("%s", (string) ref);
}

void *t(){
    int *p = new(int, 10);
    *p = 111;
    return p;
}

int *ttt(){
    def(int, *p, new(int, 2));
    *p = 222;
    *(p+1) = 333;
    return p;
}

void tst(void (*pUwu)(void *), void *(*pT)(), int *(*pTtt)()){
    pUwu("hello world\n");
    int *t = pT();
    int *tt = pTtt();
    printf("%d, %d, %d\n", *t, *tt, *(tt+1));
}

/**
 * 返回值为函数指针的函数
 * 该指针函数为指向参数为void *，返回值为void *的函数指针
 * @param pUwu 指针函数
 * @param s 字符串
 * @return 函数指针 指向返回值为void 参数为void *指针的函数
 */
void (*ts(void (*pUwu)(void *), string s))(void *) {
    def(string, vm, s);
    return pUwu;
}

void testPF(){
    void (*pUwu)(void *) = uwu;
    void *(*pT)() = t;
    int *(*pTtt)() = ttt;
    tst(pUwu, pT, pTtt);
}

void replace(char *old, char *sub, char *rpl, char *news){
    char *s1, *s2;
    while (*old != '\0') {
        for(s1 = old, s2 = sub; *s1 != '\0' && *s2 != '\0' && *s1 == *s2; s1++, s2++);
        if (*s2 != '\0')
            *news++ = *old++;
        else{
            for (s2 = rpl; *s2 != '\0'; s2++) {
                *news++ = *s2;
            }
            old = s1;
        }
    }
    *news = '\0';
}

const static int *outlet() {
    const static int a = 11;
    return &a;
}

void n(LinkedListNode *listNode){
    *listNode = *(listNode->next);
}

union testUnion{
    struct {
        int x, y, z;
    } u;
    int k;
    int j[4];
}is;

union delInt {
    int x;
    struct {
        char a[4];
    }byte;
}in;

typedef enum testEnum {
    aa, bb, cc, dd = 1, ee
}out;

#define iff(a, b, c) c=a>b?a:b

void testString(char *s) {
    char *p = malloc(sizeof(char));
    strcpy(p, s);
    *(p+1) = 'c';
    printf("%s", p);
}

void tsst(char *a, char *b, char *c) {
    while (*a && *b) {
        *c = *a;
        c++;
        a++;
        *c = *b;
        c++;
        b++;
    }
    printf("%s", a);
}

void sss(char x){
    if (x > 'a' && x < 'z' || x > 'A' && x < 'Z')
        printf("该字符为字母字符");
}

typedef struct stt {
    int arr[10];
    char *name;
} ST;

void testP1(int a){
    printf("%d", a);
}

void testP2(void (*p)(int), int b){
    (*p)(b);
    p(b);
}

void ascend(a, b)
int a;
int b;
{
    printf("%d, %d", a, b);
}

int pow3(int n, int x) {
    int last = 1;
    for (int i = 1; i <= x; ++i) {
        last = last * n % 1000;
    }
    return last;
}

void revStr(char *s){
    char *p = s, c;
    while (*p) p++;
    p--;
    if (s < p) {
        c = *s;
        *s = *p;
        *p = c;
        revStr(s+1);
        *p = '\0';
    }
}

void fun(int *p){
    p = p+1;
}

void cul() {
    int x, y, z;
    do {
        scanf_s("%d %d", &x, &y);
        printf("取余: %d\n", x%y);
    } while ((z = getchar()) != 'q');
}

union testUnion1{
    long long x;
    char z;
}ctc;

void fuc(int *a, int *b) {
    int *c;
    c = a; a = b; b = c;
}

void testMat(int **x) {
    printf("%d", **x);
}

int height(TreeNode *node) {
    if (null == node) return 0;
    else {
        int l = height(node->lchild);
        int r = height(node->rchild);
        return l > r ? l+1 : r+1;
    }
}

typedef union {
    char str[64];
    unsigned short  int x;
} UnC;

void testError(){
    errno = ERANGE;
}

jmp_buf exception_env;

void handle_error() {
    printf("An error occurred. Handling it...\n");
    longjmp(exception_env, 1); // 跳回到 setjmp() 调用点
}

// 一个接受可变数量参数的函数，计算它们的总和
int sum(int num, ...) {
    int total = 0;

    // 声明一个 va_list 对象，用于访问可变参数
    va_list args;

    // 初始化 va_list 对象，将其指向可变参数列表的开头
    va_start(args, num);

    // 遍历可变参数列表，并计算总和
    for (int i = 0; i < num; i++) {
        int arg = va_arg(args, int); // 从参数列表中获取一个参数
        total += arg;
    }

    // 结束参数列表的访问
    va_end(args);

    return total;
}

union tC{
    long long a;
    char c;
};

int *(*func1[2])(int *, int *, int *);
int (*func2[2])(const int *, const int *);

int *max(int *a, int *b, int *c) {
    int *x = *a > *b ? a : b;
    return *x > *c ? x : c;
}

int *min(int *a, int *b, int *c) {
    int *x = *a < *b ? a : b;
    return *x < *c ? x : c;
}

int mul(const int *a, const int *b) {
    return *a * *b;
}

int ivi(const int *a, const int *b) {
    return *b ? *a / (*b) : -1;
}

struct strX{
    int c;
} z;

void reverser(char *s) {
    char *p = s, c;
    while (*p) p++;
    p--;
    if (s < p) {
        c = *s;
        *s = *p;
        *p = '\0';
        reverser(s+1);
        *p = c;
    }
}

union {
    unsigned char c;
    unsigned int i[4];
}zx;

void ssss(int **x){
    *x = malloc(sizeof(int));
    **x = 5;
}

int isBST_(TreeNode *root){
    if (root == null) return 1;
    else {
        int l = isBST(root->lchild);
        int r = isBST(root->rchild);
        int current = 0;
        if (root->lchild && root->rchild) {
            current = root->lchild->data < root->data && root->rchild->data > root->data;
        }
        return l == 1 && r == 1 && current == 1;
    }
}

int main() {

//    char x[] = {'Q', 'H', 'C', 'Y', 'P', 'A', 'M', 'S', 'R', 'D', 'F', 'X'};
//    int y[] = {7, 2, 16, 15, 0, 12, 18, 17, 3, 5, 23, 24};
//    for (int i = 0; i < 12; ++i) {
//        printf("%d ", x[i] - 'A');
//        printf("%c ", y[i] + 'A');
//    }

//    convert_10_8();
//    hanoi(2, 'A', 'B', 'C');

//    int arr1[] = {5, 3, 7, 2, 6, 8, 9, 4, 1};
//    oddFrontOfEven_(arr1, 9);
//    printArray(arr1, 9);
//    LinkedListNode *temp = createList(arr1, 9);
//    insertLinkedList(&temp);
//    printLinkedList(temp);
//    LinkedListNode *odd, *even;
//    divideOddEven(temp, &odd, &even);
//    getch();

//    TreeNode *root = createTreeNode(50);
//    insertTreeNode(root, 25);
//    insertTreeNode(root, 100);
//    insertTreeNode(root, 15);
//    insertTreeNode(root, 35);
//    insertTreeNode(root, 75);
//    insertTreeNode(root, 125);
//    insertTreeNode(root, 200);
//    insertTreeNode(root, 225);
//    insertTreeNode(root, 325);
//    int x = isBST_(root);
//    int x = isBalanceBinaryTree(root);
//    printf("%d", x);
//    TreeNode *copy = null;
//    copyBinaryTree(root, &copy);
//    getch();

//    int var1[] = {1, 5, 2, 7, 6, 9, 3, 5, 4};
//    int var2[] = {7, 6, 9};
//    LinkedListNode *l1 = createList(var1, 9);
//    LinkedListNode *l2 = createList(var2, 3);
//    int i = isSubsequence(l1, l2);
//    printf("%d", i);

//    char *flag[] = {"red", "white", "red", "red", "white", "blue", "red", "blue"};
//    dutchFlagProblem(flag, 8);
//    for (int i = 0; i < 8; ++i) {
//        printf("%s ", flag[i]);
//    }

//    int arr[] = {5, 4, 7, 2, 8, 1, 9};
//    twoWayBubbleSort(arr, 7);
//    oddFrontOfEven(arr, 7);
//    int x = findMinorX(arr, 7, 2);
//    int x = kthSmallest(arr, 0, 6, 3);
//    printf("%d", x);
//    printArray(arr, 7);

//    TreeNode *root = createTreeNode(10);
//    insertTreeNode(root, 5);
//    insertTreeNode(root, 15);
//    insertTreeNode(root, 2);
//    insertTreeNode(root, 7);
//    insertTreeNode(root, 12);
//    insertTreeNode(root, 17);
//    linkedLeafNode(root);
//    getch();

//    // 示例前序遍历序列
//    char preOrder[] = "ABDECF";
//    int preOrderSize = sizeof(preOrder) - 1;  // 减去结尾的 '\0'
//
//    // 创建后序遍历序列的数组，并初始化为 '\0'
//    char postOrder[preOrderSize + 1];
//    for (int i = 0; i <= preOrderSize; i++) {
//        postOrder[i] = '\0';
//    }
//
//    // 调用函数进行转换
//    pre2Post(preOrder, 0, preOrderSize - 1, postOrder, 0, preOrderSize - 1);
//
//    // 输出后序遍历序列
//    printf("后序遍历序列: %s\n", postOrder);

//    TreeNode *root = createTreeNode(20);
//    insertTreeNode(root, 10);
//    insertTreeNode(root, 5);
//    insertTreeNode(root, 15);
//    insertTreeNode(root, 40);
//    insertTreeNode(root, 35);
//    insertTreeNode(root, 30);
//    insertTreeNode(root, 37);
//    insertTreeNode(root, 60);
//    insertTreeNode(root, 1);
//    insertTreeNode(root, 7);
//    insertTreeNode(root, 12);
//    postOrderNoRe(root);
//    TreeNode *p = root->rchild->lchild->lchild;
//    TreeNode *q = root->rchild->rchild;
//    int temp = getWidthOfBinaryTree(root);
//    TreeNode *temp = findTheNearestAncestor(root, p, q);
//    printf("%d", temp);
//    printBSTNotLessThanX(root, 12);

//    int var1[] = {11, 8, 7, 6, 5, 4, 2, 1}, var2[] = {19, 12, 9, 6, 5, 3, 2};
//    LinkedListNode *arr1 = createList(var1, 8);
//    LinkedListNode *arr2 = createList(var2, 7);
//    LinkedListNode *temp = intersection(arr1, arr2);
//    LinkedListNode *temp = mergeIdenticalElements(arr1, arr2);
//    printLinkedList(temp);
//    mergeTwoLinkedListInDecrement(arr1, arr2);
//    printLinkedList(arr1);

//    int arr[] = {88, 77, 77, 77, 55, 55, 44, 44, 33, 33, 22, 22, 11, 11};
//    LinkedListNode *temp = createList(arr, sizeof(arr) / sizeof(arr[0]));
//    removeIdenticalElements(temp);
//    printLinkedList(temp);

//    int arr[] = {11, 22, 33 ,44, 55, 66, 77};
//    LinkedListNode *head = createList(arr, 7);
//    LinkedListNode *a, *b;
//    divideLinkedListIntermittent(head, &a, &b);
//    printLinkedList(a);

//    int arr[] = {11, 22, 33, 44, 55, 66, 77};
//    int *even, *odd;
//    int even_len, odd_len;
//    divideParity(arr, 7, &odd, &odd_len, &even, &even_len);
//    for (int i = 0; i < odd_len; ++i) printf("%d ", odd[i]);

//    TreeNode *root = createTreeNode(50);
//    insertTreeNode(root, 100);
//    insertTreeNode(root, 25);
//    insertTreeNode(root, 150);
//    insertTreeNode(root, 15);
//    insertTreeNode(root, 75);
//    insertTreeNode(root, 5);
//    insertTreeNode(root, 35);
//    deletePresetNode(&root, 100);
//    int i = isBalanceBinaryTree(root);
//    printf("%d", i);
//    inorderTraversal(root);
//    inorderTraversal(root);

//    TreeNode *root = createTreeNode(10);
//    insertTreeNode(root, 15);
//    insertTreeNode(root, 5);
//    int i = getBinaryTreeHeight(root);
//    printf("%d", i);

//    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2 ,1};
//    shellSort(arr, 9, 4);
//    printArray(arr, 9);

//    TreeNode *root = createTreeNode(20);
//    TreeNode *l = createTreeNode(15);
//    TreeNode *l1 = createTreeNode(13);
//    TreeNode *l2 = createTreeNode(18);
//    TreeNode *l3 = createTreeNode(30);
//    root->lchild = l;
//    root->lchild->lchild = l1;
//    root->lchild->rchild = l2;
//    root->rchild = l3;
//    printf("%d", isBST(root));

//    char *s = "abaabcaba";
//    int *next = malloc(sizeof(int)*100);
//    getNext(s, next);
//
//    printArray(next, (int) strlen(s));

//    int arr[] = {1, 2, 3, 4, 5};
//
//    LinkedListNode *head = createList(arr, 5);
//    linkedListReverse(head);
//    linkedListOrder(head);
//    deleteLinkedListRange(head, 2, 3);
//    printLinkedList(head);

//    char ss[] = "abc";
//    char *p = ss;
//    for (; *p; p++)
//        if (*p >= 'a' && *p <= 'z') *p = (char) (*p - 32); // Convert to uppercase
//    printf("%s\n", ss); // Output: "ABC"


//    int arr[] = {7, 4, 6, 7, 1, 8, 2, 7};
//    LinkedListNode *temp = createList(arr, 8);
//    deleteMin4LinkedList(temp);
//    deleteInLinkedList(temp->next, temp, 7);
//    printLinkedList(temp);

//    struct strX *xx = malloc(sizeof(struct strX));
//    printf("%d", xx->c);
//    free(xx);

//    int a = 10, b = 20, c = 30, res = 0;
//    func1[0] = max;
//    func1[1] = min;
//    func2[0] = mul;
//    func2[1] = ivi;
//
//    for (int i = 0; i < 2; )
//        res += (*func2[i++])((*func1[0])(&a, &b, &c), (*func1[1])(&a, &b, &c));
//    printf("%d", res);

//    FILE *p = fopen("D:\\github\\files\\temp.txt", "r+");
//    int n = 0;
//    fscanf_s(p, "%d", &n);
//    printf("%d ", n);
//    for (int i = 1; i <= 10; ++i) {
//        fprintf(p, "%3d", i);
//    }
//    for (int i = 0; i < 5; ++i) {
//        fseek(p, i*6L, SEEK_SET);
//        fscanf_s(p, "%d", &n);
//        printf("%d ", n);
//    }
//    fclose(p);

//    int arr[] = {1, 1, 1, 1, 4, 4, 4, 4, 4, 4};
//    int i = hasGroupsSizeX(arr, 10);
//    printf("%d", i);

//    int arr[] = {3, 5, 8};
//
//    TreeNode *temp = sortedArray2BST(arr, 3);
//    inorderTraversal(temp);

//    int arr[] = {-1, -7, 7, -4, 19, 6, -9, -5, -2, -5};
//    LinkedListNode *temp = createList(arr, sizeof(arr) / sizeof(arr[0]));
//    LinkedListNode *p = temp;
//    while (p->next != null) p = p->next;
//    p->next = p;
//    int i = hasCycle(temp);
//    printf("%d", i);

//    int inorder[] = {-1, 2, 4, 1, 4, 2, 3};
//    int postorder[] = {-1, 4, 2, 4, 3, 2, 1};
//    int size = sizeof(inorder) / sizeof(inorder[0]);
//    int postIndex = size-1;
//    TreeNode *temp = createTree(inorder, 0, size-1, postorder, &postIndex);
//
//    int p = isSymmetric(temp);
//    printf("%d", p);

//
//    int i = searchBinaryTree4MinNode(temp);
//    printf("%d", i);

//    void *(*(*p)(void *(*a)(void), int))(int, int (*(*b)(int))());

//    if (!setjmp(exception_env)) {
//        printf("Program started.\n");
//        // 模拟一个错误
//        handle_error();
//        printf("Result"); // 这行代码不会被执行
//    }
//    printf("ok");

//    char str[] = "hello world anx nothing and";
//    char target[] = " and";
//
//    int i = isStringMatch(str, target, sizeof(str) / sizeof(char), sizeof(target) / sizeof(char));
//    printf("%d", i);

//    TreeNode *node = createTreeNode(10);
//    insertTreeNode(node, 14);
//    insertTreeNode(node, 5);
//    insertTreeNode(node, 12);
//    insertTreeNode(node, 16);
//
//    int h = height(node);
//    printf("%d", h);

//    int arr[] = {9, 8, 7, 6, 5, 4};
//    LinkedListNode *node = createList(arr, 6);
//    int i = isOrdered(node);
//    printf("%d", i);

//    TreeNode *node = createTreeNode(25);
//    insertTreeNode(node, 12);
//    insertTreeNode(node, 17);
//    insertTreeNode(node, 30);
//    insertTreeNode(node, 37);
//    insertTreeNode(node, 29);
//    insertTreeNode(node, 10);
//
//    TreeNode *dat = searchBST(node, 30);
//    printf("%d", dat->data);

//    char *b = "{}[]()";
//    int i = matchBracket(b);
//    printf("%d", i);

//    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
//    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};
//    int size = sizeof(inOrder) / sizeof(inOrder[0]);
//    int postIndex = size - 1;
//
//    TreeNode *tree = createTree(inOrder, 0, size-1, postOrder, &postIndex);
//
//    inorderTraversal(tree);
//
//    int data = 0;
//    int res = binaryTreeNodeHeight(tree, 5, data);
//    printf("%d", res);

//    int arr[] = {5, 5, 5, 5, 1, 5, 5, 5, 5};
//    OrderedList *list = initOrderedList(arr, 9);
//    removeItems4OrderList(list, 5);
//    printArray(list->data, list->size);

//    int i = isStringSymmetry();
//    printf("%d", i);

//    TreeNode *head1 = createTreeNode(11);
//    TreeNode *head2 = createTreeNode(11);
//    TreeNode *node2 = createTreeNode(22);
//    TreeNode *node3 = createTreeNode(33);
//
//    head1->lchild = node2;
//    head1->rchild = node3;
//
//    head2->lchild = node2;
//    head2->rchild = node3;
//
//    int i = isBinaryTreeSame(head1, head2);
//
//    printf("%d", i);

//    SharedStack *stack = malloc(sizeof(SharedStack));
//    SeparatedStack *var1 = malloc(sizeof(SeparatedStack));
//    SeparatedStack *var2 = malloc(sizeof(SeparatedStack));
//
//    initSharedStack(stack, var1, var2);
//
//    insert4SharedStack(stack, var1, 11);
//    insert4SharedStack(stack, var2, 22);

//    int arr[] = {4, 6, 7, 1, 2, 9, 8};
//    for (int i = 2; i >= 0; --i) {
//        adjustMaxHeap(arr, 7, i);
//    }
//    printf("%d", arr[0]);

//    int arr[] = {1};
//    QueueNode *data = malloc(sizeof(int));
//    OrderedQueue *queue = orderedQueueInit(arr, 1);
//    push4OrderQueue(queue, 2);
//    push4OrderQueue(queue, 3);
//    push4OrderQueue(queue, 4);
//    push4OrderQueue(queue, 5);
//    push4OrderQueue(queue, 6);
//
//    pop4OrderQueue(queue, data);
//    pop4OrderQueue(queue, data);
//    pop4OrderQueue(queue, data);
//    pop4OrderQueue(queue, data);
//
//    push4OrderQueue(queue, 22);
//    push4OrderQueue(queue, 33);
//    push4OrderQueue(queue, 44);
//    push4OrderQueue(queue, 55);
//    push4OrderQueue(queue, 66);
//    push4OrderQueue(queue, 77);
//    push4OrderQueue(queue, 88);
//    printf("%d", *data);

//    int n = 3, m = 3;
//    int **x = malloc(sizeof(int *)*n);
//    for (int i = 0; i < m; ++i) *x = malloc(sizeof(int)*m);
//    int a[] = {1, 2, 3};
//    int b[] = {4, 5, 6};
//    int c[] = {7, 8, 9};
//    x[0] = a;
//    x[1] = b;
//    x[2] = c;
//    findSaddlePoint(x, m, n);

//    ctc.z = 'c';
//    ctc.x = 0x123456;
//    printf("%lld %x", sizeof(ctc) ,ctc.z);

//    ListNode x[] = {9, 7, 5};
//    LinkedList list = createList(x, 3);
//    printLinkedList(list);
//    listInsert(list, 8);
//    printLinkedList(list);
    return 0;
}
