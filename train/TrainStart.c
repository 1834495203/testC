//
// Created by asus on 2023/8/10.
//

#include "TrainStart.h"
#include "math.h"

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

int pascalTriangle(int row, int col){
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
