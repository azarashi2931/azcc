#ifndef STDIO_H
#define STDIO_H

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define EOF -1

#include <stdlib.h>

typedef struct __FILE FILE;

#if defined(__linux__) && defined(__x86_64)

extern FILE *stderr;

#elif defined(__CYGWIN__) && defined(__x86_64)

struct _reent {
  int _errno;
  //__FILE *_stdin, *_stdout, *_stderr;
  FILE *_stdin;
  FILE *_stdout;
  FILE *_stderr;

  /*
   * Struct BodY
   */
};

extern struct _reent *_impure_ptr;

// struct _reent *__getreent(void);
// #define _REENT (__getreent())

#define _REENT _impure_ptr

#define stderr (_REENT->_stderr)

#else

static_assert(0, "Unsupported enviroment");

#endif

int fprintf();
int printf();
int sprintf();

FILE *fopen(const char *filename, const char *mode);
int fseek(FILE *stream, /*long*/ int offset,
          int origin); // azccの内部では整数値は常に64bitかつlong未実装のため
int ftell(FILE *stream);
size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
int fclose(FILE *stream);

int getchar();

#endif
