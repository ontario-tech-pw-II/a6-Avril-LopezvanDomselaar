#include "str.h"

int main() {
  str s1;
  cout << s1 << endl;

  str s2("Hello");
  cout << s2 << endl;

  str s3("!!!");

  str s4 = s2 + s3;
  cout << s4 << endl;

  str s5, s6;
  cin >> s5 >> s6;
  cout << s5 << ' ' << s6 << endl;

  return 0;
}
