C语言标准库提供了许多用于操作字符串的函数，以下是一些常用的字符串操作函数列表：

1. **strlen：** 返回字符串的长度（不包括null终止符）。
```c
size_t strlen(const char *str);
```

2. **strcpy：** 将一个字符串复制到另一个字符串中。
```c
char *strcpy(char *dest, const char *src);
```

3. **strncpy：** 安全地将指定长度的字符串复制到目标字符串中。
```c
char *strncpy(char *dest, const char *src, size_t n);
```

4. **strcat：** 将一个字符串连接到另一个字符串的末尾。
```c
char *strcat(char *dest, const char *src);
```

5. **strncat：** 安全地将指定长度的字符串连接到目标字符串末尾。
```c
char *strncat(char *dest, const char *src, size_t n);
```

6. **strcmp：** 比较两个字符串的内容。
```c
int strcmp(const char *str1, const char *str2);
```

7. **strncmp：** 安全地比较两个字符串的内容，只比较指定长度。
```c
int strncmp(const char *str1, const char *str2, size_t n);
```

8. **strstr：** 在一个字符串中搜索另一个子字符串的第一次出现。
```c
char *strstr(const char *haystack, const char *needle);
```

9. **strchr：** 在一个字符串中搜索一个字符的第一次出现。
```c
char *strchr(const char *str, int c);
```

10. **strtok：** 将字符串分割为一系列子字符串，使用指定的分隔符。
```c
char *strtok(char *str, const char *delimiters);
```

11. **sprintf：** 将格式化的数据写入字符串中。
```c
int sprintf(char *str, const char *format, ...);
```

12. **sscanf：** 从字符串中读取格式化的数据。
```c
int sscanf(const char *str, const char *format, ...);
```

13. **memcpy：** 将内存块从一个位置复制到另一个位置。
```c
void *memcpy(void *dest, const void *src, size_t n);
```

14. **memset：** 将内存块设置为指定的值。
```c
void *memset(void *ptr, int value, size_t num);
```

这些函数只是C语言标准库中的一部分字符串操作函数。在使用这些函数时，请务必注意字符串的长度、缓冲区大小、边界条件等，以防止潜在的缓冲区溢出和其他安全问题。