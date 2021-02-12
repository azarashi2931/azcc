
#ifndef ERRNO_H
#define ERRNO_H

#if defined(__linux__) && defined(__x86_64)

int *__errno_location();
#define errno (*__errno_location())

#elif defined(__CYGWIN__) && defined(__x86_64)

#define errno (*__errno())
extern int *__errno(void);

#else

static_assert(0, "Unsupported enviroment");

#endif

#endif
