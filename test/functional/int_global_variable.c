int test_assert(int, int, char *);
int printf();

int a;
int test1() {
  int a[2];
  a[0] = 1;
  a[1] = 2;
  int *p;
  p = a;
  return p[0] + p[1];
}

int asdjuwgehij;
int test2() {
  int a[2];
  a[0] = 1;
  a[1] = 2;
  int *p;
  p = a;
  return p[0] + p[1];
}

int test3() {
  a = 1;
  return a;
}

int b;
int test4() {
  a = 1;
  b = 2;
  return a + b;
}

int c = 12;
int test5() { return c; }

int main() {
  test_assert(3, test1(),
         "int a; int main(){ int a[2]; a[0] = 1; a[1] = 2; int *p; p = a;..."
         /*"return p[0] + p[1]; }"*/);
  test_assert(
      3, test2(),
      "int asdjuwgehij; int main(){ int a[2]; a[0] = 1; a[1] = 2; int *p; p..."
      /*"= a; return p[0] + p[1]; }"*/);
  test_assert(1, test3(), "int a; int main(){ a = 1; return a; }");
  test_assert(3, test4(), "int a; int b; int main(){ a = 1; b = 2; return a + b; }");
  test_assert(12, test5(), "int c = 12; int main(){ return c; }");
  printf("OK\n");
  return 0;
}
