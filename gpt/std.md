C语言标准库提供了许多用于标准输入（键盘输入）和标准输出（屏幕输出）的函数，以下是一些常用的标准输入输出函数列表：

**标准输入函数：**

1. **scanf：** 从标准输入读取格式化数据。
```c
int scanf(const char *format, ...);
```

2. **gets：** 从标准输入读取一行字符串（不安全，不推荐使用）。
```c
char *gets(char *str);
```

3. **fgets：** 从标准输入读取一行字符串（安全）。
```c
char *fgets(char *str, int size, FILE *stream);
```

**标准输出函数：**

1. **printf：** 格式化输出数据到标准输出。
```c
int printf(const char *format, ...);
```

2. **puts：** 输出字符串到标准输出，自动添加换行符。
```c
int puts(const char *str);
```

3. **fputs：** 输出字符串到指定文件流，不自动添加换行符。
```c
int fputs(const char *str, FILE *stream);
```

4. **putchar：** 输出一个字符到标准输出。
```c
int putchar(int c);
```

5. **fputc：** 输出一个字符到指定文件流。
```c
int fputc(int c, FILE *stream);
```

这些函数用于实现C语言程序的基本输入输出操作。在使用这些函数时，请注意格式化字符串、数据类型、缓冲区大小、文件流等相关细节，以确保程序的正确运行和安全性。