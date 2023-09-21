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
    //����i��ʼ����k�ڵ����ڵ㣬ͬʱѭ��ʱi��ָ��ϴ���Ǹ��ڵ�
    for (int i = k*2+1; i <= len; i=i*2+1) {
        //��ڵ����ҽڵ�Ƚ�
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
