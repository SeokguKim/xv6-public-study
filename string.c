#include "types.h"
#include "x86.h"

void*
memset(void *dst, int c, uint n)
{
  if ((int)dst%4 == 0 && n%4 == 0){
    c &= 0xFF;
    stosl(dst, (c<<24)|(c<<16)|(c<<8)|c, n/4);
  } else
    stosb(dst, c, n);
  return dst;
}

int
memcmp(const void *v1, const void *v2, uint n)
{
  const uchar *s1, *s2;

  s1 = v1;
  s2 = v2;
  while(n-- > 0){
    if(*s1 != *s2)
      return *s1 - *s2;
    s1++, s2++;
  }

  return 0;
}

void*
memmove(void *dst, const void *src, uint n)
{
  const char *s;
  char *d;

  s = src;
  d = dst;
  if(s < d && s + n > d){
    s += n;
    d += n;
    while(n-- > 0)
      *--d = *--s;
  } else
    while(n-- > 0)
      *d++ = *s++;

  return dst;
}

// memcpy exists to placate GCC.  Use memmove.
void*
memcpy(void *dst, const void *src, uint n)
{
  return memmove(dst, src, n);
}

int
strncmp(const char *p, const char *q, uint n)
{
  while(n > 0 && *p && *p == *q)
    n--, p++, q++;
  if(n == 0)
    return 0;
  return (uchar)*p - (uchar)*q;
}

char*
strncpy(char *s, const char *t, int n)
{
  char *os;

  os = s;
  while(n-- > 0 && (*s++ = *t++) != 0)
    ;
  while(n-- > 0)
    *s++ = 0;
  return os;
}

// Like strncpy but guaranteed to NUL-terminate.
char*
safestrcpy(char *s, const char *t, int n)
{
  char *os;

  os = s;
  if(n <= 0)
    return os;
  while(--n > 0 && (*s++ = *t++) != 0)
    ;
  *s = 0;
  return os;
}

int
strlen(const char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    ;
  return n;
}

// by seokgukim begin
int
padstr(char *s, const char *t, int n)
{
  int len = strlen(t);
  if (len > n)
    return -1;

  for(int i = 0; i < len; i++)
    s[i] = t[i];
  for(int i=len; i < n; i++)
    s[i] = ' ';
  s[n - 1] = 0;
  return 0;
}

int
padnum(char *s, int x, int n)
{

  int idx = 0;
  if(x == 0){
    s[0] = '0';
    idx++;
  }
  else{
    while(x > 0){
      s[idx++] = '0' + x % 10;
      x /= 10;
    }
    for(int i = 0; i < idx / 2; i++){
      char tmp = s[i];
      s[i] = s[idx - 1 - i];
      s[idx - 1 - i] = tmp;
      }
  }
  for(int i = idx; i < n; i++)
    s[i] = ' ';
  s[n - 1] = 0;
  return 0;
}
//by seokgukim end