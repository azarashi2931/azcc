#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdio.h>

#define ERROR(...)                                                             \
  {                                                                            \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\n");                                                     \
    exit(EXIT_FAILURE);                                                        \
  }

#define ERROR_AT(location, ...)                                                \
  {                                                                            \
    const char *line = location;                                               \
    while (user_input < line && line[-1] != '\n')                              \
      line--;                                                                  \
                                                                               \
    const char *end = location;                                                \
    while (*end != '\n')                                                       \
      end++;                                                                   \
                                                                               \
    int line_num = 1;                                                          \
    for (const char *p = user_input; p < line; p++)                            \
      if (*p == '\n')                                                          \
        line_num++;                                                            \
                                                                               \
    const int indent = fprintf(stderr, "%s:%d: ", filename, line_num);         \
    const int line_width = end - line;                                         \
    fprintf(stderr, "%.*s\n", line_width, line);                               \
                                                                               \
    const int pos = location - line + indent;                                  \
    fprintf(stderr, "%*s", pos, " ");                                          \
    fprintf(stderr, "^ ");                                                     \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\n");                                                     \
    exit(EXIT_FAILURE);                                                        \
  }

#define INSERT_COMMENT(...)                                                    \
  {                                                                            \
    printf("# ");                                                              \
    printf(__VA_ARGS__);                                                       \
    printf("\n");                                                              \
  }

extern const char *user_input;
extern const char *filename; // 入力ファイル名

bool start_with(const char *p, const char *q);
const char *read_path(const char *path);
const char *read_stdin(void);

#endif
