//
// Created by asus on 2023/8/10.
//

#include "stdlib.h"
#include "TrainStart.h"
#include "math.h"
#include "string.h"
#include "../queue/base/queueData.h"
#include "../queue/base/queueQuiz.h"
#include "../base/base.h"

double calculateE() {
    int n;
    double e = 1;
    printf("请输入n:");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        double temp = 1;
        for (int j = 1; j <= i; ++j) temp *= 1.0/j;
        e += temp;
    }

    return e;
}

int pascalTriangle(int row, int col) {
    if (col == 0 || row == col) return 1;
    else
        return pascalTriangle(row - 1, col - 1) + pascalTriangle(row - 1, col);
}

void generatePascalTriangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", pascalTriangle(i, j));
        }
        printf("\n");
    }
}

void exchange(int *var1, int *var2){
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void printArray(int *arr, int len) {
    if (len == 0) return;
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

//
void bubbleSort(int *arr, int len) {
    if (len == 0) return;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                exchange(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectSort(int *arr, int len) {
    if (len == 0) return;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (arr[i] > arr[j])
                exchange(&arr[i], &arr[j]);
        }
    }
}

void insertSort(int *arr, int len) {
    if (len == 0) return;
    int i, j;
    for (i = 1; i < len; ++i) {
        int temp = arr[i];
        for (j = i-1; j >= 0; --j) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            } else break;
        }
        arr[j+1] = temp;
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        //将高位与基准比较，如果高位小于基准，则将其赋给低位
        while (low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        //反之则反
        while (low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }
    //将基准放置
    arr[low] = pivot;
    return low;
}

void quickSort(int *arr, int low, int high) {
    int pivot;
    if (low < high) {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int binarySearch(const int *arr, int len, int k) {
    if (len == 0) return -1;
    int low = 0, high = len-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == k) return mid;
        if (k > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

boolean isPrime(int n) {
    if (n <= 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int convert_(const char *x, int len) {
    if (len == 0) return 0;
    static const char n[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int res = 0;
    for (int i = len-1; i >= 0; --i) {
        if (x[i] > 'f' || x[i] < '0') return -1;
        for (int j = 0; j < 16; ++j)
            if (x[i] == n[j])
                res += j * (1 << 4*(len-i-1));
    }
    return res;
}

char *cat(char *var1, char *var2) {
    char *p = var1, *q = var2, *res, *head;
    int len1 = 0, len2 = 0;
    while (*p++ != '\0') len1++;
    while (*q++ != '\0') len2++;
    res = new(char, len1+len2+1);
    head = res;
    while (*var1 != '\0') *res++ = *var1++;
    while (*var2 != '\0') *res++ = *var2++;
    *res = '\0';
    return head;
}

void narcissistic(int n) {
    for (int i = (int) pow(10, n-1); i < pow(10, n); ++i) {
        int temp = i, res = 0;
        for (int j = 0; j < n; ++j) {
            int k = temp%10;
            res += (int) pow(k, n);
            temp /= 10;
        }
        if (res == i) printf("%d ", res);
    }
}

void printAndFree(LinkedList head, LinkedList tail) {
    LinkedList temp = head;
    if (head != tail)
        printAndFree(temp->next, tail);
    printf("%c ", temp->data);
    free(temp);
}

void inputAndOutput() {
    char input;
    LinkedList list = malloc(sizeof(LinkedListNode));
    list->next = null;
    LinkedList p = list->next;

    printf("请输入一串字符:\n");
    while ((input = (char) getchar()) != '\n') {
        LinkedList temp = malloc(sizeof(LinkedListNode));
        temp->data = input; temp->next = null;
        if (p == null) list->next = temp;
        else p->next = temp;
        p = temp;
    }

    printAndFree(list->next, p);
}

void deleteInX(LinkedList list, ListNode x) {
    if (list == null) return;
    LinkedList front = list;
    LinkedList rear = list->next;
    while (rear != null) {
        if (rear->data == x) {
            LinkedList temp = rear->next;
            free(rear);
            front->next = temp;
            rear = temp;
        } else {
            rear = rear->next;
            front = front->next;
        }
    }
}

LinkedList createList(const ListNode *arr, int len) {
    if (len == 0) return null;
    LinkedList rs = malloc(sizeof(LinkedListNode));
    rs->next = null;
    for (int i = 0; i < len; ++i) {
        LinkedList temp = malloc(sizeof(LinkedListNode));
        temp->data = arr[i];
        temp->next = rs->next;
        rs->next = temp;
    }
    return rs;
}

void printLinkedList(LinkedList list) {
    if (list == null) return;
    LinkedList temp = list->next;
    while (temp != null) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sum_s() {
    double rs = 0;
    int isNeg = 1;
    for (int i = 1; i <= 101; i+=2) {
        if (isNeg) rs += (double) 1/i;
        else rs -= (double) 1/i;
        isNeg = !isNeg;
    }
    printf("%f", rs);
}

void doWhile_555555() {
    int i = 555555, range = 100, rs = 0;
    do if (!(i % range) && range > rs) rs = range;
    while (++range <= 999);
    printf("%d", rs);
}

void reverse_() {
    int input;
    scanf("%d", &input);
    while (input) {
        printf("%d ", input%10);
        input /= 10;
    }
}

double recordStudent(S_ *s, S_ *rs, int *n) {
    S_ *res = malloc(sizeof(struct stu_)*(*n));
    S_ *p = res;
    int sum = 0;
    double avg = 0;
    for (int i = 0; i < *n; ++i) avg += s[i].score;
    avg = avg/(double) *n;
    for (int i = 0; i < *n; ++i) {
        if (s[i].score >= avg) {
            *p++ = s[i];
            sum++;
        }
    }
    *rs = *res;
    *n = sum;
    return avg;
}

double toSum_a(double a) {
    return 1.0/(2*a - 1) - 1.0/(2*a);
}

double sum_a(int n) {
    double rs = 0;
    for (int i = 1; i <= n; ++i) {
        rs += toSum_a(i);
    }
    return rs;
}

void checkStrStar(char **str, int n) {
    char *p = *str;
    int step = 0;
    while (*p != '\0') {
        if (*p == '*' && n > 0) {
            n--;
            step++;
        }
        else if (*p != '*' && n == 0) {
            *str = (p-step);
            break;
        }
        p++;
    }
    printf("%s\n", *str);
}

void reverse_s(char *str, int len) {
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    printf("%s", str);
}

void print99() {
    int i, j;
    for (i = 1; i <= 9; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("% d * %d = %d ", j, i, i*j);
        }
        printf("\n");
    }
}

char *addBinary(char *a, char *b) {
    int a_len = (int) strlen(a), b_len = (int) strlen(b), x = 0;
    
    return NULL;
}

void getReverse() {
    int x;
    scanf_s("%d", &x);

    while (x != 0) {
        printf("%d", x%10);
        x /= 10;
    }
}

#define isUpper(c) c >= 'A' && c <= 'Z'
#define isLower(c) c >= 'a' && c <= 'z'
#define isNumber(c) c >= '0' && c <= '9'
#define isSpace(c) c == ' '

void classify() {
    char *s = malloc(sizeof(char));
    gets(s);
    char *temp = s;
    int u = 0, l = 0, n = 0, sp = 0, o = 0;

    while (*temp != '\0') {
        if (isNumber(*temp)) n++;
        else if (isLower(*temp)) l++;
        else if (isUpper(*temp)) u++;
        else if (isSpace(*temp)) sp++;
        else o++;
        temp++;
    }

    printf("大写字符数为：%d，小写字符数为：%d，数字字符数为：%d，空格字符数为：%d，其他字符数为：%d", u, l, n, sp, o);
}

// 找出数组中不重复的数字，异或的应用 异或还可用于交换两个元素值
int singleNumber(const int *nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++)
        result ^= nums[i];
    return result;
}

TreeNode *createTreeNode(Node data) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    node->lchild = null;
    node->rchild = null;
    return node;
}

TreeNode *insertTreeNode(TreeNode *node, Node data) {
    if (node == null)
        return createTreeNode(data);
    if (data < node->data) {
        node->lchild = insertTreeNode(node->lchild, data);
    } else if (data > node->data) {
        node->rchild = insertTreeNode(node->rchild, data);
    }
    return node;
}

void inorderTraversal(TreeNode *node) {
    if (node != null) {
        inorderTraversal(node->lchild);
        printf("%d ", node->data);
        inorderTraversal(node->rchild);
    }
}

int findLatent(int total, int height) {
    int rs = 1;
    for (int i = 0; i < height; ++i) rs <<= 1;
    printf("%d\n", rs);
    return total / (rs-1);
}

void listInsert(LinkedList list, ListNode data) {
    if (list == null) return;
    LinkedListNode *create = malloc(sizeof(LinkedListNode));
    create->data = data;
    create->next = null;
    LinkedListNode *temp = list->next;
    LinkedListNode *node = temp->next;
    if (null == node) temp->next = create;
    else {
        int order = (temp->data - node->data) > 0 ? true : false;
        LinkedListNode *front = list;
        while (front != null) {
            //当数组为递减数组时
            if (order && temp->data > data) {
                front = temp;
                temp = temp->next;
            } else if (order && temp->data <= data) {
                front->next = create;
                create->next = temp;
                break;
            }
            //当数组为递增数组时
            if (!order && temp->data < data) {
                front = temp;
                temp = temp->next;
            } else if (!order && temp->data >= data) {
                front->next = create;
                create->next = temp;
                break;
            }
        }
    }
}

void findSaddlePoint(int **matrix, int m, int n) {
    int j;
    for (int i = 0; i < m; ++i) {
        int min = matrix[i][0];
        //找出行最小
        for (j = 0; j < n; ++j)
            if (min > matrix[i][j]) {
                min = matrix[i][j];
                break;
            }
        j = j == n ? 0 : j;
        //是否为列最大
        int is = true;
        for (int k = 0; k < m && is; ++k)
            if (min < matrix[k][j]) is = false;
        if (is) printf("%d ", min);
    }
}

void adjustMaxHeap(int *arr, int len, int k) {
    int temp = arr[k];
    //这里i初始化是k节点的左节点下标，同时循环时i会指向较大的那个子节点
    for (int i = k*2+1; i <= len; i=i*2+1) {
        //左节点与右节点比较, 指向最大的孩子节点
        if (i < len && arr[i] < arr[i+1]) i++;
        //调整完成
        if (temp >= arr[i]) break;
        else {
            //将根节点与较大的子节点交换，并继续从交换处向下调整
            arr[k] = arr[i];
            k = i;
        }
    }
    //最终根节点的位置
    arr[k] = temp;
}

void initSharedStack(SharedStack *stack, SeparatedStack *var1, SeparatedStack *var2) {
    stack->total_size = 0;
    var1->type = 0;
    var1->size = 0;
    var1->index = 0;
    var2->type = 1;
    var2->size = 0;
    var2->index = SHARED_STACK_MAX - 1;
    stack->stack_one_index = var1->index;
    stack->stack_two_index = var2->index;
}

int insert4SharedStack(SharedStack *stack, SeparatedStack *var, int data) {
    if (stack == null || var == null) return -1;
    if (stack->total_size+1 == SHARED_STACK_MAX) return -1;
    if (var->type == 0) {
        stack->datum[stack->stack_one_index++] = data;
        var->index = stack->stack_one_index;
    } else {
        stack->datum[stack->stack_two_index--] = data;
        var->index = stack->stack_two_index;
    }
    stack->total_size++;
    var->size++;
    return 1;
}

int isBinaryTreeSame(TreeNode *var1, TreeNode *var2) {
    if (var1 != null && var2 != null) {
        int l = isBinaryTreeSame(var1->lchild, var2->lchild);
        int r = isBinaryTreeSame(var1->rchild, var2->rchild);
        if (l == 0 || r == 0) return 0;
        return var1->data == var2->data;
    }
    return var1 == null && var2 == null;
}

#define FILE_STRING_MAX (1 << 3) // aka 8

int isStringSymmetry() {
    FILE *p = fopen("D:\\github\\files\\string.txt", "r");
    char *var = malloc(sizeof(char) * FILE_STRING_MAX);
    char c;
    int start = 0, len = 0;
    int capacity = FILE_STRING_MAX;
    while ((c = (char) fgetc(p)) != EOF) {
        *(var + len) = c;
        len++;
        //扩容
        if (len >= capacity) {
            char *temp = realloc(var, (capacity <<= 1) * sizeof(char));
            if (null == temp) {
                printf("扩容发生错误!");
                free(var);
                exit(1);
            } else var = temp;
        }
    }
    fclose(p);
    *(var + len) = '\0';
    len -= 1;
    while (start <= len && var[start++] == var[len--]);
    return var[start] == var[len];
}

OrderedList *initOrderedList(const int *data, int len) {
    OrderedList *temp = malloc(sizeof(OrderedList));
    for (int i = 0; i < len; ++i) temp->data[i] = data[i];
    temp->size = len > ORDER_LIST_MAX_LENGTH ? ORDER_LIST_MAX_LENGTH : len;
    return temp;
}

void removeItems4OrderList(OrderedList *list, int item) {
    int step = 0;
    for (int i = 0; i < list->size; ++i) {
        if (list->data[i] != item) list->data[i-step] = list->data[i];
        else step++;
    }
    list->size -= step;
}

// 在中序遍历序列中查找根节点的索引
int findRootIndex(const int *inorder, int inStart, int inEnd, int rootValue) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootValue) {
            return i;
        }
    }
    return -1;
}

TreeNode *createTree(int *inorder, int inStart, int inEnd, int *postorder, int *postIndex) {
    if (inStart > inEnd) return null;

    // 后序遍历序列的最后一个元素是根节点
    int rootValue = postorder[(*postIndex)--];

    // 创建根节点
    TreeNode *root = malloc(sizeof(TreeNode));
    root->data = rootValue;
    root->lchild = root->rchild = null;

    // 在中序遍历序列中找到根节点的位置
    int rootIndex = findRootIndex(inorder, inStart, inEnd, rootValue);

    // 递归构建右子树（注意：先构建右子树）
    root->rchild = createTree(inorder, rootIndex + 1, inEnd, postorder, postIndex);
    // 递归构建左子树
    root->lchild = createTree(inorder, inStart, rootIndex - 1, postorder, postIndex);

    return root;
}

int binaryTreeNodeHeight(TreeNode *var, Node data, int current) {
    if (var == null) return 0;
    if (var->data == data) return current;

    int left = binaryTreeNodeHeight(var->lchild, data, current+1);
    int right = binaryTreeNodeHeight(var->rchild, data, current+1);

    return left ? left : right;
}

int matchBracket(char *bracket) {
    if (null == bracket) return 0;
    LinkedQueue *queue = initLinkedQueue();
    char *p = bracket;
    push4LinkedQueue(queue, *p++);
    while (*p != '\0') {
        switch (*p) {
            case '}': {
                if (!isLinkedQueueEmpty(queue) && queue->head->data == '{') pop4LinkedQueue(queue);
                else push4LinkedQueue(queue, *p);
                p++;
                break;
            }
            case ')':{
                if (!isLinkedQueueEmpty(queue) && queue->head->data == '(') pop4LinkedQueue(queue);
                else push4LinkedQueue(queue, *p);
                p++;
                break;
            }
            case ']':{
                if (!isLinkedQueueEmpty(queue) && queue->head->data == '[') pop4LinkedQueue(queue);
                else push4LinkedQueue(queue, *p);
                p++;
                break;
            }
            default:
                push4LinkedQueue(queue, *p++);
        }
    }
    return isLinkedQueueEmpty(queue);
}

TreeNode *searchBST(TreeNode *head, Node data) {
    if (null != head) {
        TreeNode *temp = head;
        if (data > head->data) temp = searchBST(head->rchild, data);
        else if (data < head->data) temp = searchBST(head->lchild, data);
        return temp;
    }
    return null;
}

typedef enum Order {
    DISORDER = -1, DECREASE, INCREASE, NOT_INITIATED
}Order;

Order isOrdered(LinkedListNode *list) {
    Order order = NOT_INITIATED;
    if (null == list) return order;
    LinkedListNode *temp = list->next;
    while (null != temp->next) {
        int temp_order = temp->data > temp->next->data ? DECREASE : INCREASE;
        if (NOT_INITIATED == order) order = temp_order;
        else if (order != temp_order) {
            order = DISORDER;
            break;
        }
        temp = temp->next;
    }
    return order;
}

int binaryTreeDepth(TreeNode *node) {
    if (null == node) return 0;
    else {
        int l = binaryTreeDepth(node->lchild);
        int r = binaryTreeDepth(node->rchild);
        return l > r ? l+1 : r+1;
    }
}

int isStringMatch(char *org, char *dest, int org_len, int dest_len) {
    assert_(dest != NULL && org != NULL && org_len > 0 && dest_len > 0, "输入的数据有误!");
    char *temp = org;
    while ((temp = memchr(temp, *dest, org_len - (temp - org))))
        //改进可能会越界的情况
        if (dest_len > strlen(temp)) return -1;
        else if (memcmp(temp, dest, dest_len) == 0) return (int) (temp - org);
        else temp += 1;
    return -1;
}

Node searchBinaryTree4MinNode(TreeNode *node) {
    if (null == node) return INT_MAX;
    else {
        int l = searchBinaryTree4MinNode(node->lchild);
        int r = searchBinaryTree4MinNode(node->rchild);
        int min = r < l ? r : l;
        return node->data < min ? node->data : min;
    }
}

Node *searchBST4B_M(TreeNode *node) {
    if (null == node) return null;
    else {
        TreeNode *left = node->lchild;
        TreeNode *right = node->rchild;
        while (null != left->rchild) left = left->rchild;
        while (null != right->lchild) right = right->lchild;
        int *rs = malloc(sizeof(int)*2);
        *rs = left->data, *(rs+1) = right->data;
        return rs;
    }
}

/**
 * 判断二叉树是否对称，即有两个二叉树在做比较，所以应该从左右两个子树出发，依次比较左右孩子
 * @param left 左子树根节点
 * @param right 右子树根节点
 * @return 是否对称
 */
int isSymmetricT(TreeNode *left, TreeNode *right) {
    if (null == left && null == right) return 1;
    else if (null == left || null == right) return 0;
    else {
        int ll = isSymmetricT(left->lchild, right->rchild);
        int rr = isSymmetricT(left->rchild, right->lchild);
        return ll == 1 && rr == 1 && left->data == right->data;
    }
}

int isSymmetric(TreeNode *node) {
    return isSymmetricT(node->lchild, node->rchild);
}

void reverse_array(int *arr, int len){
    for (int i = 0; i < len / 2; ++i) {
        arr[i] = arr[i] ^ arr[len - i - 1];
        arr[len - i - 1] = arr[i] ^ arr[len - i - 1];
        arr[i] = arr[i] ^ arr[len - i - 1];
    }
}

//分治
TreeNode *sortedArray2BST(int *nums, int numSize) {
    if (numSize == 0) return null;
    int mid = numSize / 2;
    TreeNode *temp = createTreeNode(nums[mid]);
    temp->lchild = sortedArray2BST(nums, mid);
    temp->rchild = sortedArray2BST(nums + mid + 1, numSize - mid - 1);
    return temp;
}

//快慢指针
int hasCycle(LinkedListNode *head) {
    LinkedListNode *slow = head;
    LinkedListNode *fast = head->next;
    if (null == fast) return 0;
    while (null != fast && null != fast->next && null != slow && slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return null != slow && null != fast && slow == fast;
}

int hasGroupsSizeX(int *deck, int deckSize) {
    quickSort(deck, 0, deckSize - 1);
    int i = 0, k = 0, arr[deckSize];
    for (int j = 0; j < deckSize - 1; ++j)
        if (deck[j] != deck[j+1]) {
            arr[i++] = k + 1;
            k = 0;
        }
        else k++;
    if (k != 0) arr[i++] = k + 1;

    return 1;
}

// 辗转相除法求最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void deleteInLinkedList(LinkedListNode *node, LinkedListNode *pre, ListNode k) {
    if (NULL == node) return;
    else {
        deleteInLinkedList(node->next, node, k);
        if (node->data == k) {
            LinkedListNode *temp = node;
            pre->next = temp->next;
            free(temp);
        }
    }
}

void deleteMin4LinkedList(LinkedListNode *node) {
    LinkedListNode *p = NULL;
    node = node->next;
    while (NULL != node->next) {
        if (p == NULL || p->next->data > node->next->data) {
            p = node;
        }
        node = node->next;
    }
    if (p != null) {
        LinkedListNode *temp = p->next;
        if (temp == null) p->next = null;
        else {
            p->next = temp->next;
            free(temp);
        }
    }
}

void linkedListReverse(LinkedListNode *head) {
    if (null == head || null == head->next) return;
    LinkedListNode *p = head->next;
    LinkedListNode *q = p;
    while (p->next != null) {
        head->next = p->next;
        p = p->next;
    }
    while (p != q) {
        LinkedListNode *temp = q->next;
        q->next = p->next;
        p->next = q;
        q = temp;
    }
}

void linkedListOrder(LinkedListNode *head) {
    if (null == head || null == head->next) return;
    LinkedListNode *p = head->next;
    while (p) {
        LinkedListNode *temp = p, *min = temp;
        for(; temp; temp = temp->next)
            if (temp->data < min->data) min = temp;
        int data = p->data;
        p->data = min->data;
        min->data = data;
        p = p->next;
    }
}

void deleteLinkedListRange(LinkedListNode *head, int a, int b) {
    if (null == head || null == head->next) return;
    LinkedListNode *p = head;
    while (p->next) {
        if (p->next->data >= a && p->next->data <= b) {
            LinkedListNode *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        p = p->next;
    }
}

int countLeaf(TreeNode *root) {
    if (null == root) return 0;
    else {
        int l = countLeaf(root->lchild);
        int r = countLeaf(root->rchild);
        int current = root->lchild == null && root->rchild == null ? 1 : 0;
        return l + r + current;
    }
}

void getNext(char *s, int *next) {
    int i = 1, j = 0;
    next[i] = 0;
    while (i < strlen(s)) {
        if (j == 0 || s[i] == s[j]) {
            i++; j++;
            next[i] = j;
        } else j = next[j];
    }
}

int isBST(TreeNode *root) {
    if (root == null) return 1;
    else {
        int l = isBST(root->lchild);
        int r = isBST(root->rchild);
        int ll = 1, rr = 1;
        if (root->lchild != null)
            ll = root->data > root->lchild->data;
        if (root->rchild != null)
            rr = root->data < root->rchild->data;
        return l && r && ll && rr;
    }
}

void shellSort(int *arr, int len, int dk) {
    int i, j;
    for (; dk >= 1; dk /= 2) {
        for (i = dk + 1; i < len; i++) {
            int temp = arr[i];
            for (j = i-dk; j >= 0 && arr[j] > temp; j-=dk) {
                if (arr[j] > temp) arr[j+dk] = arr[j];
                else break;
            }
            arr[j+dk] = temp;
        }
    }
}
