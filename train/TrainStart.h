//
// Created by asus on 2023/8/10.
//

#ifndef TESTC_TRAINSTART_H
#define TESTC_TRAINSTART_H

#include "../base/base.h"

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

#endif //TESTC_TRAINSTART_H
