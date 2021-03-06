#include "config.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static TargetPlatform get_default_target(void) {
#if defined(__linux__) && defined(__x86_64)
  return TARGET_AMD64_LINUX_GNU;
#endif

#ifdef __CYGWIN__
  return TARGET_AMD64_W64_WINDOWS_GNU;
#endif

  return TARGET_UNKNOWN;
}

static _Noreturn void argument_error() {
  ERROR("Usage: azcc [file...]\n");
}

Config *parse_argument(int argc, char **argv) {
  Config *confing = calloc(1, sizeof(Config));
  confing->target = get_default_target();
  confing->filename = NULL;

  for (int i = 1; i < argc; i++) {
    char *p = argv[i];
    if (start_with(p, "--")) {
      p += 2;
      if (start_with(p, "target")) {
        p += strlen("target");

        if (!start_with(p, "="))
          argument_error();
        p++;

        if (start_with(p, "amd64-linux-gnu") ||
            start_with(p, "x86_64-linux-gnu") || start_with(p, "x64-linux-gnu"))
          confing->target = TARGET_AMD64_LINUX_GNU;
        else if (start_with(p, "amd64-w64-windows-gnu") ||
                 start_with(p, "x86_64-w64-windows-gnu") ||
                 start_with(p, "x64-w64-windows-gnu"))
          confing->target = TARGET_AMD64_W64_WINDOWS_GNU;
        else if (start_with(p, "aarch64-linux-gnu") ||
                 start_with(p, "armv8-linux-gnu"))
          confing->target = TARGET_AARCH64_LINUX_GNU;
        else
          argument_error();
      } else if (start_with(p, "version")) {
        printf("azcc: Azarashi2931's C Compiler version 0.1\n");
        printf("Target: amd64-linux-gnu\n");
        exit(0);
      } else {
        argument_error();
      }

      continue;
    }

    if (start_with(p, "-")) {
      p++;
      if (strlen(p) == 0) {
        if (confing->filename) {
          argument_error();
        }
      }

      for (size_t j = 0; j < strlen(p); j++) {
        switch (*p) {
        default:
          argument_error();
        }
      }

      continue;
    }

    confing->filename = p;
  }

  return confing;
}
