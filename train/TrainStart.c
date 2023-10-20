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
    printf("������n:");
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
        //����λ���׼�Ƚϣ������λС�ڻ�׼�����丳����λ
        while (low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        //��֮��
        while (low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }
    //����׼����
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

    printf("������һ���ַ�:\n");
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
    scanf_s("%d", &input);
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

    printf("��д�ַ���Ϊ��%d��Сд�ַ���Ϊ��%d�������ַ���Ϊ��%d���ո��ַ���Ϊ��%d�������ַ���Ϊ��%d", u, l, n, sp, o);
}

// �ҳ������в��ظ������֣�����Ӧ�� ��򻹿����ڽ�������Ԫ��ֵ
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
            //������Ϊ�ݼ�����ʱ
            if (order && temp->data > data) {
                front = temp;
                temp = temp->next;
            } else if (order && temp->data <= data) {
                front->next = create;
                create->next = temp;
                break;
            }
            //������Ϊ��������ʱ
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
        //�ҳ�����С
        for (j = 0; j < n; ++j)
            if (min > matrix[i][j]) {
                min = matrix[i][j];
                break;
            }
        j = j == n ? 0 : j;
        //�Ƿ�Ϊ�����
        int is = true;
        for (int k = 0; k < m && is; ++k)
            if (min < matrix[k][j]) is = false;
        if (is) printf("%d ", min);
    }
}

void adjustMaxHeap(int *arr, int len, int k) {
    int temp = arr[k];
    //����i��ʼ����k�ڵ����ڵ��±꣬ͬʱѭ��ʱi��ָ��ϴ���Ǹ��ӽڵ�
    for (int i = k*2+1; i <= len; i=i*2+1) {
        //��ڵ����ҽڵ�Ƚ�, ָ�����ĺ��ӽڵ�
        if (i < len && arr[i] < arr[i+1]) i++;
        //�������
        if (temp >= arr[i]) break;
        else {
            //�����ڵ���ϴ���ӽڵ㽻�����������ӽ��������µ���
            arr[k] = arr[i];
            k = i;
        }
    }
    //���ո��ڵ��λ��
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
        //����
        if (len >= capacity) {
            char *temp = realloc(var, (capacity <<= 1) * sizeof(char));
            if (null == temp) {
                printf("���ݷ�������!");
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

// ��������������в��Ҹ��ڵ������
int findRootIndex(const int *inorder, int inStart, int inEnd, int rootValue) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootValue) {
            return i;
        }
    }
    return -1;
}

/**
 *  �÷�
 *  int inorder[] = {-1, 2, 4, 1, 4, 2, 3};
 *  int postorder[] = {-1, 4, 2, 4, 3, 2, 1};
 *  int size = sizeof(inorder) / sizeof(inorder[0]);
 *  int postIndex = size-1;
 *  TreeNode *temp = createTree(inorder, 0, size-1, postorder, &postIndex);
 * @param inorder ����
 * @param inStart ����Ŀ�ͷ�±�
 * @param inEnd ����Ľ�β�±�
 * @param postorder ����
 * @param postIndex �����β�±� ��why:��Ϊ��������и��ڵ��������һ��λ�ã�
 * @return ���ڵ�
 */
TreeNode *createTree(int *inorder, int inStart, int inEnd, int *postorder, int *postIndex) {
    if (inStart > inEnd) return null;

    // ����������е����һ��Ԫ���Ǹ��ڵ�
    int rootValue = postorder[(*postIndex)--];

    // �������ڵ�
    TreeNode *root = malloc(sizeof(TreeNode));
    root->data = rootValue;
    root->lchild = root->rchild = null;

    // ����������������ҵ����ڵ��λ��
    int rootIndex = findRootIndex(inorder, inStart, inEnd, rootValue);

    // �ݹ鹹����������ע�⣺�ȹ�����������
    root->rchild = createTree(inorder, rootIndex + 1, inEnd, postorder, postIndex);
    // �ݹ鹹��������
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
    assert_(dest != NULL && org != NULL && org_len > 0 && dest_len > 0, "�������������!");
    char *temp = org;
    while ((temp = memchr(temp, *dest, org_len - (temp - org))))
        //�Ľ����ܻ�Խ������
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
 * �ж϶������Ƿ�Գƣ��������������������Ƚϣ�����Ӧ�ô����������������������αȽ����Һ���
 * @param left ���������ڵ�
 * @param right ���������ڵ�
 * @return �Ƿ�Գ�
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

//����
TreeNode *sortedArray2BST(int *nums, int numSize) {
    if (numSize == 0) return null;
    int mid = numSize / 2;
    TreeNode *temp = createTreeNode(nums[mid]);
    temp->lchild = sortedArray2BST(nums, mid);
    temp->rchild = sortedArray2BST(nums + mid + 1, numSize - mid - 1);
    return temp;
}

//����ָ��
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

// շת����������Լ��
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

//�ǵݹ��ȡ���ĸ߶�(��α���)
int getBinaryTreeHeight(TreeNode *root) {
    if (root == null) return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;
    TreeNode *queue[100];
    queue[++rear] = root;
    while (front < rear) {
        TreeNode *temp = queue[++front];
        if (temp->lchild) queue[++rear] = temp->lchild;
        if (temp->rchild) queue[++rear] = temp->rchild;
        // lastָ��ǰ������ҽڵ㣬ÿ�γ�����last�Ƚϣ�������������1��ͬʱlastָ����һ�����ҽڵ�
        if (front == last) {
            level++;
            last = rear;
        }
    }
    return level;
}

//��α�����˼·
int isCompleteBinaryTree(TreeNode *root) {
    if (root == null) return 0;
    TreeNode *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;
    while (rear > front) {
        TreeNode *temp = queue[++front];
        if (temp == null) {
            TreeNode *p;
            while (rear > front) {
                p = queue[++front];
                if (p) return 0;
            }
        }
        queue[++rear] = temp->lchild;
        queue[++rear] = temp->rchild;
    }
    return 1;
}

int getDegreeOf2InBinaryTree(TreeNode *root) {
    if (root == null) return 0;
    else {
        int l = getDegreeOf2InBinaryTree(root->lchild);
        int r = getDegreeOf2InBinaryTree(root->rchild);
        if (root->lchild != null && root->rchild != null) return 1 + l + r;
        return l + r;
    }
}

/**
 * ��δ���ʵ����һ���������������˶�������ÿ���ڵ������������������
 * ����һ�����͵Ķ���������Binary Tree Mirror��������Ҳ����Ϊ��ת��������
 * @param root ���ڵ�
 */
void exchangeChildInBinaryTree(TreeNode *root) {
    if (root == null) return;
    else {
        exchangeChildInBinaryTree(root->lchild);
        exchangeChildInBinaryTree(root->rchild);
        TreeNode *temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
    }
}

TreeNode *getPresetPreorderNode(TreeNode *root, int index) {
    if (root == null || index < 0) return null;
    else if (index == 0) return root;
    else {
        // �ݹ�����������������ҵ�Ŀ��ڵ����������
        TreeNode *l = getPresetPreorderNode(root->lchild, --index);
        if (l) return l;
        // �ݹ�����������������ҵ�Ŀ��ڵ����������
        TreeNode *r = getPresetPreorderNode(root->rchild, --index);
        if (r) return r;
    }
    return null;
}

void deletePresetNode(TreeNode **root, Node data) {
    if (*root == null) return;
    if ((*root)->data == data) {
        TreeNode* left = (*root)->lchild;
        TreeNode* right = (*root)->rchild;
        free(*root);
        *root = null; // ɾ��ƥ��ڵ�

        // �ݹ�ɾ����������������
        deletePresetNode(&left, data);
        deletePresetNode(&right, data);
    } else {
        // �ݹ������������������
        deletePresetNode(&(*root)->lchild, data);
        deletePresetNode(&(*root)->rchild, data);
    }
}

int printAncestorsInBinaryTree(TreeNode *root, Node data) {
    // �����Ϊ�գ�����0��ʾδ�ҵ�
    if (root == null) return 0;

    // ����ҵ�Ŀ��ڵ㣬����1��ʾ�ҵ�
    if (root->data == data) return 1;

    // ���������в���Ŀ��ڵ�
    int left = printAncestorsInBinaryTree(root->lchild, data);

    // ���������в���Ŀ��ڵ�
    int right = printAncestorsInBinaryTree(root->rchild, data);

    // ���Ŀ��ڵ��������������������ҵ�����ӡ��ǰ�ڵ���Ϊ����
    if (left || right) printf("%d ", root->data);

    // �����Ƿ��ҵ�Ŀ��ڵ�
    return left || right;
}

int isBalanceBinaryTree(TreeNode *root) {
    if (root == null) return 0;
    else {
        int l = isBalanceBinaryTree(root->lchild);
        int r = isBalanceBinaryTree(root->rchild);
        if (root->lchild != null) l += 1;
        if (root->rchild != null) r += 1;
        return abs(l - r) <= 1;
    }
}

void divideParity(const int *arr, int len, int **odd, int *odd_len, int **even, int *even_len) {
    if (len == 0) return;
    int current_index = 1, odd_index = 0, even_index = 0;
    if (len % 2) {
        *odd_len = (len/2) + 1;
        *even_len = *odd_len - 1;
    } else *odd_len = *even_len = len / 2;
    *odd = malloc(*odd_len * sizeof(int));
    *even = malloc(*even_len * sizeof(int));
    while (current_index <= len) {
        if (current_index % 2) (*odd)[odd_index++] = arr[current_index - 1];
        else (*even)[even_index++] = arr[current_index - 1];
        current_index++;
    }
}

void divideLinkedListIntermittent(LinkedListNode *arr, LinkedListNode **a, LinkedListNode **b) {
    if (arr == null) return;
    //aҪ����ͷ�巨
    *a = malloc(sizeof(LinkedListNode));
    (*a)->next = null;
    //bҪ����β�巨
    *b = malloc(sizeof(LinkedListNode));
    (*b)->next = null;
    LinkedListNode *b_rear = null;
    int bool = 1;
    while (arr->next != null) {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        temp->data = arr->next->data;
        if (bool) {
            temp->next = (*a)->next;
            (*a)->next = temp;
        } else {
            temp->next = null;
            if (b_rear == null) {
                (*b)->next = temp;
                b_rear = temp;
            } else {
                b_rear->next = temp;
                b_rear = temp;
            }
        }
        bool = !bool;
        arr = arr->next;
    }
}

void removeIdenticalElements(LinkedListNode *arr) {
    if (arr == null) return;
    ListNode temp = arr->next->data;
    arr = arr->next;
    while (arr->next != null) {
        if (arr->next->data == temp) {
            LinkedListNode *p = arr->next;
            arr->next = p->next;
            free(p);
        } else {
            arr = arr->next;
            temp = arr->data;
        }
    }
}

void mergeTwoLinkedListInDecrement(LinkedListNode *var1, LinkedListNode *var2) {
    LinkedListNode *p = var1->next, *q = var2->next;
    var1->next = null;
    while (p != null && q != null) {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        temp->data = p->data < q->data ? p->data : q->data;
        temp->next = var1->next;
        var1->next = temp;
        if (temp->data == p->data)
            p = p->next;
        else if (temp->data == q->data)
            q = q->next;
    }
    while (p) {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        temp->data = p->data;
        temp->next = var1->next;
        var1->next = temp;
        p = p->next;
    }
    while (q) {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        temp->data = q->data;
        temp->next = var1->next;
        var1->next = temp;
        q = q->next;
    }
}

LinkedListNode *mergeIdenticalElements(LinkedListNode *var1, LinkedListNode *var2) {
    LinkedListNode *q = var1->next, *p = var2->next;
    LinkedListNode *res = malloc(sizeof(LinkedListNode));
    res->next = null;
    while (p && q) {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        if (p->data == q->data) {
            temp->data = q->data;
            temp->next = res->next;
            res->next =temp;
            p = p->next;
            q = q->next;
        }
        else {
            if (p->data > q->data) q = q->next;
            else p = p->next;
        }
    }
    return res;
}

//TODO ���޸ĵ��㷨
LinkedListNode *intersection(LinkedListNode *var1, LinkedListNode *var2) {
    LinkedListNode *pa = var1->next;
    LinkedListNode *pb = var2->next;
    LinkedListNode *u, *pc = var1;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pa = pa->next;
            free(u);
        }
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = null;
    free(var2);
    return var1;
}

void getMinMaxInBST(TreeNode *root, Node *max, Node *min) {
    if (root == null) return;
    TreeNode *p = root->lchild, *q = root->rchild;
    while (p->lchild) p = p->lchild;
    while (q->rchild) q = q->rchild;
    *max = q->data;
    *min = p->data;
}

void printBSTNotLessThanX(TreeNode *root, Node x) {
    if (root == null) return;
    else {
        printBSTNotLessThanX(root->rchild, x);
        if (root->data >= x) printf("%d ", root->data);
        printBSTNotLessThanX(root->lchild, x);
    }
}

TreeNode *findTheNearestAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == null) return null;
    if (root == q || root == p) return root;
    TreeNode *l = findTheNearestAncestor(root->lchild, p, q);
    TreeNode *r = findTheNearestAncestor(root->rchild, p, q);
    if (l != null && r != null) return root;
    else return l != null ? l : r;
}

//��α�����˼�� �ö���
int getWidthOfBinaryTree(TreeNode *root) {
    TreeNode *queue[100];
    int front = -1, rear = -1, max = 0;
    queue[++rear] = root;
    //last�����²�����һ���ڵ��ڶ����е�λ��
    int last = rear;
    while (rear > front) {
        TreeNode *temp = queue[++front];
        if (temp->lchild != null) queue[++rear] = temp->lchild;
        if (temp->rchild != null) queue[++rear] = temp->rchild;
        //��last = front ��ζ�Ÿò��Ѿ�ȫ�������ˣ� ��ʱ�����е�rearָ�������һ������һ���ڵ���±�
        if (last == front) {
            max = (rear - front) > max ? (rear - front) : max;
            last = rear;
        }
    }
    return max;
}

//TODO �����
/**
 * ʾ��ǰ���������
 * char preOrder[] = "ABDECF";
 * int preOrderSize = sizeof(preOrder) - 1;  // ��ȥ��β�� '\0'
 * // ��������������е����飬����ʼ��Ϊ '\0'
 * char postOrder[preOrderSize + 1];
 * for (int i = 0; i <= preOrderSize; i++) {
 *      postOrder[i] = '\0';
 *  }
 *  // ���ú�������ת��
 *  pre2Post(preOrder, 0, preOrderSize - 1, postOrder, 0, preOrderSize - 1);
 *  // ��������������
 *  printf("�����������: %s\n", postOrder);
 */
void pre2Post(char preOrder[], int preStart, int preEnd, char postOrder[], int postStart, int postEnd) {
    if (preStart > preEnd || postStart > postEnd) {
        return;
    }

    // ǰ������ĵ�һ���ڵ�һ���Ǹ��ڵ�
    char rootData = preOrder[preStart];
    postOrder[postEnd] = rootData;

    // ���Ҹ��ڵ���ǰ������е�λ��
    int rootIndex;
    for (rootIndex = preStart; rootIndex <= preEnd; rootIndex++) {
        if (preOrder[rootIndex] == rootData) {
            break;
        }
    }

    // �����������Ľڵ�����
    int leftSubtreeSize = rootIndex - preStart;

    // �ݹ鴦��������
    pre2Post(preOrder, preStart + 1, preStart + leftSubtreeSize, postOrder, postStart, postStart + leftSubtreeSize - 1);

    // �ݹ鴦��������
    pre2Post(preOrder, preStart + leftSubtreeSize + 1, preEnd, postOrder, postStart + leftSubtreeSize, postEnd - 1);
}

/**
 * ������ǰ������򣬲��õ�������ȵ�˼�룬�����������෴��
 * һֱ���������������Һ���Ϊ�գ�����ݵ���һ���ڵ�����������ظ�������
 * @param root ���ڵ�
 */
void postOrderNoRe(TreeNode *root) {
    TreeNode *stack[100], *res[100];
    int s_top = -1, r_top = -1;
    stack[++s_top] = root;
    res[++r_top] = root;
    for(;;) {
        TreeNode *temp = res[r_top]->rchild;
        // �����ǰ�ڵ���к���Ϊ�� ���ظ����ݵ���һ���ڵ������ ֱ�����Ӳ�Ϊ��
        while (s_top != -1 && temp == null) temp = stack[s_top--]->lchild;
        if (temp == null) break;
        res[++r_top] = temp;
        stack[++s_top] = temp;
    }
    while (r_top != -1) printf("%d ", res[--r_top]->data);
}

void linkedLeafNode(TreeNode *root) {
    TreeNode *stack[100];
    int s_top = -1;
    TreeNode *p = root;
    TreeNode *pre_leaf = null;
    while (p || s_top != -1) {
        if (p) {
            stack[++s_top] = p;
            p = p->lchild;
        } else {
            //����ע�������ջ�Ĵ����� 's_top--' ������ '--s_top'. ���ǻ��ڳ�ʼ��ʱs_top = -1��ԭ��
            p = stack[s_top--];
            if (p->lchild == null && p->rchild == null) {
                if (pre_leaf == null) pre_leaf = p;
                else {
                    pre_leaf->rchild = p;
                    pre_leaf = p;
                }
            }
            p = p->rchild;
        }
    }
}

/**
 * ��δ���ʵ�ֵ���˫��ð������Two-way Bubble Sort����Ҳ����Ϊ��β������Cocktail Sort����
 * ����ð�������һ�ֱ��壬���������ұȽϺͽ���Ԫ�أ������ҵ������ؽ��бȽϺͽ�����
 * �Ա㽫���ֵ����Сֵͬʱ�ƶ�����ȷ��λ�á�
 */
void twoWayBubbleSort(int *arr, int len) {
    int p_min = len - 1, p_max = 0;
    //ѭ������Ϊ�����һ�룬ÿ��ѭ���󶼻���һ�����ֵ����Сֵ���ŵ���ȷ��λ��
    for (int i = 0; i < len/2; i++, p_max++, p_min--) {
        //�����ֵ���������
        for (int j = p_max; j <= p_min - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        //����Сֵ������ǰ��
        for (int j = p_min; j >= p_max + 1; --j) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//���ڿ��������˼�� �Ľ��㷨 O(n)
void polishOddFrontOfEven(int *arr, int len) {
    int p_odd = 0, p_even = len-1;
    for (; p_odd < p_even; p_even--, p_odd++) {
        while (arr[p_odd] % 2 == 1) p_odd++;
        while (arr[p_even] % 2 == 0) p_even--;
        if (p_even > p_odd) {
            int temp = arr[p_odd];
            arr[p_odd] = arr[p_even];
            arr[p_even] = temp;
        }
    }
}

void oddFrontOfEven(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] % 2 == 1) continue;
        for (int j = i+1; j < len; ++j) {
            if (arr[j] % 2 == 1) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                break;
            }
        }
    }
}

//���ڿ��������Ѱ��k��С��Ԫ��
int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pos = partition(arr, low, high);
        if (pos - low == k - 1) return arr[pos];
        if (pos - low > k - 1) return kthSmallest(arr, low, pos - 1, k);
        return kthSmallest(arr, pos + 1, high, k - pos + low - 1);
    }
    return -1;
}

int findMinorX(int *arr, int len, int x) {
    if (x > len) return -1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] < arr[j+1]) {
                exchange(&arr[j], &arr[j+1]);
            }
        }
    }
    return arr[len - x];
}

void dutchFlagProblem(char **flag, int len) {
    int p_red = 0, p_blue = len - 1, p_current = p_red;
    while (p_current <= p_blue) {
        if (strcmp(flag[p_current], "red") == 0) {
            char *temp = flag[p_red];
            flag[p_red] = flag[p_current];
            flag[p_current] = temp;
            p_red++;
        }
        if (strcmp(flag[p_current], "blue") == 0) {
            char *temp = flag[p_blue];
            flag[p_blue] = flag[p_current];
            flag[p_current] = temp;
            p_blue--;
        }
        p_current++;
    }
}

int isSubsequence(LinkedListNode *org, LinkedListNode *dist) {
    LinkedListNode *p_org = org->next, *p_dist = dist->next;
    while (p_org != null) {
        LinkedListNode *p_temp_dist = p_dist;
        LinkedListNode *p_temp_org = p_org;
        while (p_temp_dist != null && p_temp_org->data == p_temp_dist->data) {
            p_temp_org = p_temp_org->next;
            p_temp_dist = p_temp_dist->next;
        }
        if (p_temp_dist == null) return 1;
        else p_org = p_org->next;
    }
    return 0;
}

void copyBinaryTree(TreeNode *root, TreeNode **copy) {
    TreeNode *stack_root[100], *stack_copy[100];
    int s_top = -1;
    TreeNode *p = root;
    TreeNode *p_copy = null;
    int isLeft = 1;
    while (p || s_top != -1) {
        if (p) {
            TreeNode *temp = malloc(sizeof(TreeNode));
            temp->data = p->data;
            temp->lchild = null;
            temp->rchild = null;
            if (*copy == null) *copy = temp;
            else if (isLeft == 1) stack_copy[s_top]->lchild = temp;
            else {
                //���ڸ��ڵ��Ѿ���������������Ҫ+1��ȡ���ڵ�
                stack_copy[s_top+1]->rchild = temp;
                isLeft = 1;
            }
            stack_root[++s_top] = p;
            stack_copy[s_top] = temp;
            p = p->lchild;
        } else {
            isLeft = 0;
            p = stack_root[s_top--];
            p = p->rchild;
        }
    }
}

void divideOddEven(LinkedListNode *list, LinkedListNode **odd, LinkedListNode **even) {
    *odd = malloc(sizeof(LinkedListNode));
    *even = malloc(sizeof(LinkedListNode));
    (*odd)->next = null, (*even)->next = null;
    LinkedListNode *p_list = list;
    while (p_list->next != null) {
        LinkedListNode *temp = malloc(sizeof(LinkedListNode));
        temp->data = p_list->next->data;
        temp->next = null;
        if (temp->data % 2 == 0) {
            if ((*even)->next == null) (*even)->next = temp;
            else {
                LinkedListNode *temp_even = *even;
                while (temp_even->next != null) {
                    if (temp_even->next->data > temp->data) {
                        temp->next = temp_even->next;
                        temp_even->next = temp;
                        break;
                    }
                    temp_even = temp_even->next;
                }
                if (temp_even->next == null) temp_even->next = temp;
            }
        } else if (temp->data % 2 == 1) {
            if ((*odd)->next == null) (*odd)->next = temp;
            else {
                LinkedListNode *temp_odd = *odd;
                while (temp_odd->next != null) {
                    if (temp_odd->next->data > temp->data) {
                        temp->next = temp_odd->next;
                        temp_odd->next = temp;
                        break;
                    }
                    temp_odd = temp_odd->next;
                }
                if (temp_odd->next == null) temp_odd->next = temp;
            }
        }
        LinkedListNode *next = p_list->next;
        free(p_list);
        p_list = next;
    }
}

int getHeightTree(TreeNode *root) {
    if (root == null) return 0;
    else {
        int l = getHeightTree(root->lchild);
        int r = getHeightTree(root->rchild);
        return 1 + (int) fmax(l, r);
    }
}

void insertLinkedList(LinkedListNode **head) {
    if (head == null || *head == null) return;

    LinkedListNode *sortedList = null;  // �����򲿷ֵ�����
    LinkedListNode *current = *head;   // ��ǰ������ڵ�

    while (current != null) {
        LinkedListNode *next = current->next; // ������һ���ڵ��Ա���������
        if (sortedList == null || current->data <= sortedList->data) {
            // �����ǰ�ڵ��ֵС������������ĵ�һ���ڵ㣬ֱ�Ӳ��뵽����ͷ��
            current->next = null;
            sortedList = current;
        } else {
            // ���򣬱��������������ҵ���ȷ�Ĳ���λ��
            LinkedListNode *temp = sortedList;
            while (temp->next != null && temp->next->data < current->data) {
                temp = temp->next;
            }
            // ���뵱ǰ�ڵ㵽����������ĺ���λ��
            current->next = temp->next;
            temp->next = current;
        }
        current = next; // ������һ���ڵ�
    }

    *head = sortedList; // ����ԭʼ����ͷָ��
}

void insertSortBinary(int *arr, int len) {
    int i, j;
    for(i = 1; i < len; i++) {
        int temp = arr[i];
        // ����������ö��ֲ����ҵ�����λ��
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low+high) / 2;
            if (arr[mid] > temp) high = mid - 1;
            else low = mid + 1;
        }
        //һ�����ƶ�
        for(j = i-1; j >= high + 1; j--)
            arr[j+1] = arr[j];
        arr[high+1] = temp;
    }
}

int getNodesNum(TreeNode *root) {
    if (root == null) return 0;
    else {
        int l = getNodesNum(root->lchild);
        int r = getNodesNum(root->rchild);
        return l + r + 1;
    }
}

ALGraph *convert_Matrix2Adjacent(MGraph matrix) {
    ALGraph *alg = malloc(sizeof(ALGraph));
    alg->arcNum = matrix.arcNum;
    alg->vexNum = matrix.vexNum;
    //����ת�������
    for (int i = 0; i < matrix.vexNum; ++i) {
        alg->vertices[i].data = matrix.Vex[i];
        alg->vertices[i].first = null;
    }
    // �����ڽӾ��󣬽�����Ԫ����ӵ��ڽӱ�
    for (int i = 0; i < matrix.vexNum; ++i) {
        for (int j = 0; j < matrix.vexNum; ++j) {
            if (matrix.Edge[i][j] != 0) {
                ArcNode *arcNode = (ArcNode *)malloc(sizeof(ArcNode));
                arcNode->adjVex = j;
                arcNode->next = alg->vertices[i].first;
                alg->vertices[i].first = arcNode;
            }
        }
    }
    return alg;
}

int sumTreeNodeData(TreeNode *root) {
    if (root == null) return 0;
    else {
        int l = sumTreeNodeData(root->lchild);
        int r = sumTreeNodeData(root->rchild);
        return l + r + root->data;
    }
}

void oddFrontOfEven_(int *arr, int len) {
    int p_even = len - 1, p_odd = 0;
    while (p_even > p_odd) {
        while (p_even > p_odd && arr[p_odd] % 2 == 1) p_odd++;
        while (p_even > p_odd && arr[p_even] % 2 == 0) p_even--;
        int temp = arr[p_odd];
        arr[p_odd] = arr[p_even];
        arr[p_even] = temp;
    }
}

void convert_10_8() {
    int stack[100];
    int s_top = -1;
    int x;
    scanf_s("%d", &x);
    while (x) {
        stack[++s_top] = x % 8;
        x /= 8;
    }
    while (s_top != -1) printf("%d", stack[s_top--]);
}

void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, target, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, target);
    hanoi(n - 1, auxiliary, source, target);
}

int **transposition(int **arr, int n, int m) {
    int **trans = malloc(sizeof(int *) * n);
    for (int i = 0; i < m; ++i) trans[i] = malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            trans[i][j] = arr[j][i];
        }
    }
    return trans;
}
