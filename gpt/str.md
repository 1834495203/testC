在C语言中，常用的操作字符串的函数主要包含在`string.h`头文件中。下面列出了一些常见的操作字符串的函数及其参数说明：

1. **strlen()**：计算字符串长度，不包括字符串末尾的空字符('\0')。
   ```c
   size_t strlen(const char *str);
   ```
    - `str`：指向要计算长度的字符串的指针。

2. **strcpy()**：将一个字符串复制到另一个字符串。
   ```c
   char *strcpy(char *dest, const char *src);
   ```
    - `dest`：指向目标字符串的指针，表示复制后的结果将存储在此处。
    - `src`：指向源字符串的指针，表示要复制的字符串。

3. **strncpy()**：将一个字符串的指定长度复制到另一个字符串。
   ```c
   char *strncpy(char *dest, const char *src, size_t n);
   ```
    - `dest`：指向目标字符串的指针，表示复制后的结果将存储在此处。
    - `src`：指向源字符串的指针，表示要复制的字符串。
    - `n`：要复制的字符数，不超过目标字符串的大小。

4. **strcmp()**：比较两个字符串的大小，返回一个整数表示比较结果。
   ```c
   int strcmp(const char *str1, const char *str2);
   ```
    - `str1`：指向第一个字符串的指针。
    - `str2`：指向第二个字符串的指针。

5. **strncmp()**：比较两个字符串的前n个字符的大小，返回一个整数表示比较结果。
   ```c
   int strncmp(const char *str1, const char *str2, size_t n);
   ```
    - `str1`：指向第一个字符串的指针。
    - `str2`：指向第二个字符串的指针。
    - `n`：要比较的字符数。

6. **strcat()**：将一个字符串连接到另一个字符串的末尾。
   ```c
   char *strcat(char *dest, const char *src);
   ```
    - `dest`：指向目标字符串的指针，表示连接后的结果将存储在此处。
    - `src`：指向要连接的字符串。

7. **strncat()**：将一个字符串的指定长度连接到另一个字符串的末尾。
   ```c
   char *strncat(char *dest, const char *src, size_t n);
   ```
    - `dest`：指向目标字符串的指针，表示连接后的结果将存储在此处。
    - `src`：指向要连接的字符串。
    - `n`：要连接的字符数，不超过目标字符串的大小。

8. **strstr()**：在一个字符串中查找指定子串的第一次出现，并返回一个指向该子串的指针。
   ```c
   char *strstr(const char *str, const char *substr);
   ```
    - `str`：指向要查找的字符串。
    - `substr`：指向要查找的子串。

9. **strchr()**：在一个字符串中查找指定字符的第一次出现，并返回一个指向该字符的指针。
   ```c
   char *strchr(const char *str, int c);
   ```
    - `str`：指向要查找的字符串。
    - `c`：要查找的字符。

10. **strrchr()**：在一个字符串中查找指定字符的最后一次出现，并返回一个指向该字符的指针。
    ```c
    char *strrchr(const char *str, int c);
    ```
    - `str`：指向要查找的字符串。
    - `c`：要查找的字符。

11. **strcpy_s()**：安全版本的strcpy()函数，防止缓冲区溢出。
    ```c
    errno_t strcpy_s(char *dest, rsize_t destsz, const char *src);
    ```
    - `dest`：指向目标字符串的指针，表示复制后的结果将存储在此处。
    - `destsz`：目标字符串缓冲区的大小。
    - `src`：指向源字符串的指针，表示要复制的字符串。

12. **strncpy_s()**：安全版本的strncpy()函数，防止缓冲区溢出。
    ```c
    errno_t strncpy_s(char *dest, rsize_t destsz, const char *src, rsize_t count);
    ```
    - `dest`：指向目标字符串的指针，表示复制后的结果将存储在此处。
    - `destsz`：目标字符串缓冲区的大小。
    - `src`：指向源字符串的指针，表示要复制的字符串。
    - `count`：要复制的字符数，不超过目标字符串缓冲区的大小。

这些函数可以帮助你在C程序中进行字符串的处理，但在使用它们时要注意确保字符串的

有效性，避免缓冲区溢出等安全问题。