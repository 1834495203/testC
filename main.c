#include "stdio.h"
#include "stdlib.h"
#include "./base/base.h"
#include "math.h"
#include "string.h"
#include "pthread.h"
#include "train/TrainStart.h"

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
void sort(){
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

typedef struct tet{
    int a;
    char b;
}Te;

int main() {
    Te t = {.a = 10, .b = 'c'};
    printf("%d", t.a);
    return 0;
}
