#include "str.h"
#include <cstring>

str::str()
{
  _buf = nullptr;
  _n = 0;
}

str::str(char ch)
{
   _n = 1;
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i)
    _buf[i] = c_str[i];
}
str::str(const str &s)
{
  _n = s._n;
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i)
    _buf[i] = s._buf[i];
}

str::~str()
{
  if (_buf)
    delete [] _buf;
  _n = 0;
  _buf = nullptr;
}

void str::print()
{
  for (int i = 0; i < _n; ++i)
    cout << _buf[i];
  cout << endl;
}

void str::clear()
{
  if (_buf)
    delete [] _buf;

  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s)
{
  char *p = new char[_n + s._n];

  int i;

  for (i = 0; i < _n; ++i)
    p[i] = _buf[i];

  for (int j = 0; j < s._n; ++i,++j)
    p[i] = s._buf[j];

  if (_buf)
    delete [] _buf;

  _buf = p;
  _n = _n + s._n;
}

void swap(str& x, str& y)
{
  char *tmp;
  int ntmp;

  tmp = x._buf;
  x._buf = y._buf;
  y._buf = tmp;

  ntmp = x._n;
  x._n = y._n;
  y._n = ntmp;

}

const str& str::operator=(const str& s)
{
  // if the current string isn't empty, we empty it
  if (_buf){
    delete [] _buf;
  }

  _n = s.length();
  _buf = new char[_n];
  // copy str into the current empty string
  strcat(_buf, s._buf);

}

str operator+(const str& a, const str& b)
{
  int sz = a.length() + b.length();
  char *newS = new char[sz];
  strcat(newS, a._buf);
  strcat(newS, b._buf);
  str newString(newS);

  return newString;
}

ostream& operator<<(ostream& os, const str& s)
{
  if(!s.is_empty()) {
    for (int i = 0; i < s.length(); ++i) {
      cout << s._buf[i];
    }
  }
  else cout << "[null str]";

  return os;
}

istream& operator>>(istream& is, str& s)
{
  char* temp_buf = new char[100];

  cout << "Enter string: " << endl;
  is >> temp_buf;

  s = str(temp_buf);

  return is;
}
