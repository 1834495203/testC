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

//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
void sort() {
    int size;
    scanf("%d", &size);
    //动态分配二维数组
    int **res = (int**) malloc(sizeof(int*)*size);
    for (int i = 0; i < size; ++i)
        res[i] = (int*) malloc(sizeof(int)*size);
    int all[size*size];
    for (int i = 0; i < size * size; ++i) scanf("%d", &all[i]);
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

void fuc(int *a, int *b){
    int *c;
    c = a; a = b; b = c;
}

void testMat(int **x) {
    printf("%d", **x);
}

int main() {

    char *b = "{}[]()";

    int i = matchBracket(b);

    printf("%d", i);

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
