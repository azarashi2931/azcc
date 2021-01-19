int test_assert(int, int, char *);
int printf();

int test1() {
  int x[3];
  x[0] = -1;
  x[1] = 2;
  int y;
  y = 4;
  return x[0] + y;
}
int test2() {
  char x[3];
  x[0] = 1;
  return x[0];
}
int test3() {
  char x[3];
  x[0] = 1;
  x[1] = 2;
  int y;
  y = x[0];
  return y;
}
int test4() {
  char x[3];
  x[0] = 1;
  x[1] = 2;
  int y;
  y = 4;
  return x[0] + y;
}
int test5() {
  char x[3];
  x[0] = -1;
  x[1] = 2;
  int y;
  y = 4;
  return x[0] + y;
}
int test6() {
  char *x = "abcdefghij";
  return x[0];
}
int test7() {
  char *x = "abcdefghij";
  return x[1];
}
int test8() {
  char *x = "abcdefghij";
  return x[2];
}
int test9() {
  char *x = "abcdefghij";
  return x[3];
}
int test10() {
  char *x = "abcdefghij";
  return x[4];
}
int test11() {
  char *x = "abcdefghij";
  return x[5];
}

int main() {
  test_assert(3, test1(),
         "int x[3]; x[0] = -1; x[1] = 2; int y; y = 4; return x[0] + y;");
  test_assert(1, test2(), "char x[3]; x[0] = 1; return x[0];");
  test_assert(1, test3(),
         "char x[3]; x[0] = 1; x[1] = 2; int y; y = x[0]; return y;");
  test_assert(5, test4(),
         "char x[3]; x[0] = 1; x[1] = 2; int y; y = 4; return x[0] + y;");
  test_assert(3, test5(),
         "char x[3]; x[0] = -1; x[1] = 2; int y; y = 4; return x[0] + y; ");
  test_assert(97, test6(), "char* x = \"abcdefghij\"; return x[0];");
  test_assert(98, test7(), "char* x = \"abcdefghij\"; return x[1];");
  test_assert(99, test8(), "char* x = \"abcdefghij\"; return x[2];");
  test_assert(100, test9(), "char* x = \"abcdefghij\"; return x[3];");
  test_assert(101, test10(), "char* x = \"abcdefghij\"; return x[4];");
  test_assert(102, test11(), "char* x = \"abcdefghij\"; return x[5];");
  return 0;
}
