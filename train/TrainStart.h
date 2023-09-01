//
// Created by asus on 2023/8/10.
//

#ifndef TESTC_TRAINSTART_H
#define TESTC_TRAINSTART_H

#include "../base/base.h"
#include "../list/base/listData.h"

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

#endif //TESTC_TRAINSTART_H
