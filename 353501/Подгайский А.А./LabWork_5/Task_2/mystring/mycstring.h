#include "stddef.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

void *my_memcpy(void *s1, const void *s2, size_t n);
void *my_memmove(void *s1, const void *s2, size_t n);
char *my_strcpy(char *s1, const char *s2);
char *my_strncpy(char *s1, const char *s2, size_t n);
char *my_strcat(char *s1, const char *s2);
char *my_strncat(char *s1, const char *s2, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
int my_strcmp(const char *s1, const char *s2);
//int my_strcoll(const char *s1, const char *s2);

//helper for strtok
bool _isInStr(char, const char*);

int my_strncmp(const char *s1, const char *s2, size_t n);
size_t my_strxfrm(char *s1, const char *s2, size_t n);
char *my_strtok(char *s1, const char *s2);
void *my_memset(void *s, int c, size_t n);
const char *my_strerror(int errnum);
size_t my_strlen(const char *s);

#ifdef __cplusplus
}
#endif
