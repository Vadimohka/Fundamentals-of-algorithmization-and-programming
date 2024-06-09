#include "stringFun.h"
#include "stdlib.h"
#include "sys/errno.h"
#include <stdint.h>
void *memcpy(void *dst_, const void *src_, size_t n) {
  const unsigned char *src = (const unsigned char *)src_;
  unsigned char *dst = (unsigned char *)dst_;
  for (size_t i = 0; i < n; ++i) {
    dst[i] = src[i];
  }
  return dst_;
}


void *memmove(void *dst_, const void *src_, size_t n) {
  const unsigned char *src = (const unsigned char *)src_;
  unsigned char *dst = (unsigned char *)dst_;

  unsigned char *tmp = (unsigned char *)malloc(n);
  memcpy(tmp, src_, n);
  memcpy(dst, tmp, n);
  free(tmp);
  return dst_;
}

char *strcpy(char *dst, const char *src) {
  const char *s_cur = src;
  char *d_cur = dst;
  while (*s_cur != '\0') {
    *d_cur = *s_cur;
    ++s_cur;
    ++d_cur;
  }
  *d_cur = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  const char *s_cur = src;
  char *d_cur = dst;
  size_t i = 0;
  while (*s_cur != '\0' && i < n) {
    *d_cur = *s_cur;
    ++s_cur;
    ++d_cur;
    ++i;
  }
  *d_cur = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
    char *dst_end = dst + strlen(dst);

  const char *s_cur = src;
  char *d_cur = dst_end;
  while (*s_cur != '\0') {
    *d_cur = *s_cur;
    ++d_cur;
    ++s_cur;
  }
  *d_cur = '\0';
  return dst;
}

char *strncat(char *dst, const char *src, size_t n) {
    char *dst_end = dst + strlen(dst);
  const char *s_cur = src;
  char *d_cur = dst_end;
  int i = 0;
  while (*s_cur != '\0' && i < n) {
    *d_cur = *s_cur;
    ++d_cur;
    ++s_cur;
    ++i;
  }
  *d_cur = '\0';
  return dst;
}

int memcmp(const void *s1_, const void *s2_, size_t n) {
  size_t i;  
  const unsigned char * cs = (const unsigned char*) s1_;
  const unsigned char * ct = (const unsigned char*) s2_;

  for (i = 0; i < n; i++, cs++, ct++)
  {
    if (*cs < *ct)
    {
      return -1;
    }
    else if (*cs > *ct)
    {
      return 1;
    }
  }
  return 0;
}


int strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 < *s2) {
      return -1;
    } else if (*s1 > *s2) {
      return 1;
    }
    ++s1;
    ++s2;
  }

  if (*s1 == '\0' && *s2 != '\0') {
    return -1;
  } else if (*s1 != '\0' && *s2 == '\0') {
    return 1;
  } else {
    return 0;
  }
}

int strncmp(const char *s1, const char *s2, size_t n) {
  if (n == 0) {
    return 0;
  }

  size_t i = 0;
  while ((*s1 != '\0' && *s2 != '\0') && i < n - 1) {
    if (*s1 < *s2) {
      return -1;
    } else if (*s1 > *s2) {
      return 1;
    }
    ++i;
    ++s1;
    ++s2;
  }

  if (*s1 == '\0' && *s2 != '\0') {
    return -1;
  } else if (*s1 != '\0' && *s2 == '\0') {
    return 1;
  } else {
    return 0;
  }
}

size_t strlen(const char *s) {
  size_t i = 0;
  while (s[i] != '\0') {
    ++i;
  }
  return i;
}
bool IsInStr(char c, const char *s) {
  const char *p = s;
  while (*p != '\0') {
    if (*p == c) {
      return true;
    }
    ++p;
  }
  return false;
}

char *strtok(char *str, const char *delim) {
  static char *carry = NULL;

  char *p;
  if (str != NULL) {
    p = str;
  } else {
    if (carry == NULL) {
      return NULL;
    }
    p = carry;
  }

  while (IsInStr(*p, delim) && *p != '\0') {
    ++p;
  }
  if (*p == '\0')
    return NULL;

  char *remember = p;

  while (!IsInStr(*p, delim) && *p != '\0') {
    ++p;
  }

  if (*p == '\0') {
    carry = NULL;
    return remember;
  } else {
    *p = '\0';
    carry = p + 1;
    return remember;
  }
}


void *memset(void *s, int c, size_t n) {
  unsigned char val = (unsigned char)c;
  unsigned char *i = (unsigned char *)s;
  unsigned char *end = i + n;
  while (i != end) {
    *i = val;
    ++i;
  }
  return s;
}

