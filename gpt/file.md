在C语言中，进行文件操作需要使用标准C库中的文件操作函数，它们通常包含在`stdio.h`头文件中。下面是常用的文件操作函数及其参数说明：

1. **fopen()**：打开文件，返回一个指向`FILE`结构的指针。
   ```c
   FILE *fopen(const char *filename, const char *mode);
   ```
    - `filename`：要打开的文件名，以字符串形式表示。
    - `mode`：文件打开模式，以字符串形式表示。常用的模式有：
        - `"r"`：只读模式，打开一个已存在的文件，文件指针放在文件的开头。
        - `"w"`：只写模式，打开一个文件，如果文件不存在则创建，如果文件存在则截断（清空）文件内容，文件指针放在文件的开头。
        - `"a"`：追加模式，打开一个文件，如果文件不存在则创建，文件指针放在文件的末尾。
        - `"rb"`、`"wb"`、`"ab"`：用于以二进制形式打开文件。

2. **fclose()**：关闭文件。
   ```c
   int fclose(FILE *stream);
   ```
    - `stream`：指向`FILE`结构的指针，表示要关闭的文件。

3. **fread()**：从文件读取数据。
   ```c
   size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
   ```
    - `ptr`：指向一个用于存储读取数据的缓冲区。
    - `size`：要读取的数据项的数量。
    - `nmemb`：要读取的每个数据项的大小（字节数）。
    - `stream`：指向`FILE`结构的指针，表示要读取数据的文件。

4. **fwrite()**：向文件写入数据。
   ```c
   size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
   ```
    - `ptr`：指向一个包含要写入数据的缓冲区。
    - `size`：要写入的数据项的数量。
    - `nmemb`：要写入的每个数据项的大小（字节数）。
    - `stream`：指向`FILE`结构的指针，表示要写入数据的文件。

5. **fprintf()**：向文件写入格式化数据。
   ```c
   int fprintf(FILE *stream, const char *format, ...);
   ```
    - `stream`：指向`FILE`结构的指针，表示要写入数据的文件。
    - `format`：格式化字符串，指定要写入的数据的格式。
    - `...`：可变参数列表，用于按照格式化字符串指定的格式写入数据。

6. **fscanf()**：从文件读取格式化数据。
   ```c
   int fscanf(FILE *stream, const char *format, ...);
   ```
    - `stream`：指向`FILE`结构的指针，表示要读取数据的文件。
    - `format`：格式化字符串，指定要读取的数据的格式。
    - `...`：可变参数列表，用于接收按照格式化字符串指定的格式读取的数据。

7. **fgets()**：从文件读取一行字符串。
   ```c
   char *fgets(char *str, int n, FILE *stream);
   ```
    - `str`：指向字符数组的指针，用于存储读取的字符串。
    - `n`：要读取的最大字符数（包括终止符）。
    - `stream`：指向`FILE`结构的指针，表示要读取数据的文件。

8. **fputs()**：向文件写入一个字符串。
   ```c
   int fputs(const char *str, FILE *stream);
   ```
    - `str`：指向要写入文件的字符串。
    - `stream`：指向`FILE`结构的指针，表示要写入数据的文件。

9. **feof()**：检查文件结束标志。
   ```c
   int feof(FILE *stream);
   ```
    - `stream`：指向`FILE`结构的指针，表示要检查的文件。

10. **fseek()**：在文件中定位。
    ```c
    int fseek(FILE *stream, long offset, int whence);
    ```
    - `stream`：指向`FILE

`结构的指针，表示要定位的文件。
- `offset`：偏移量，表示要移动的字节数。
- `whence`：起始位置，用于指定偏移量相对于何处。可选值有：
- `SEEK_SET`：文件开头
- `SEEK_CUR`：当前位置
- `SEEK_END`：文件结尾

以上是一些常见的文件操作函数及其参数说明。在进行文件操作时，务必正确使用这些函数，并检查返回值以确保操作的正确执行。