#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy_M1(char *dest, const char *src) {
    if(!src) {
        if(!dest) free(dest);
        dest = NULL;
        return dest;
    }
    const char *p_len = src;
    char *p_dest;
    for(; *p_len != '\0'; ++p_len);
    int len = p_len - src + 1;
    p_dest = dest = (char *)malloc(len * sizeof(char));
    if(!p_dest)
        exit(1);
    for(; p_dest - dest < len; ++p_dest)
        *p_dest = *src++;
    return dest;
}
/*
 * The above function has misunderstood the interface of strcpy, the right and decent one should like following.
 */
char *strcpy_M2(char *dest, const char *src) {
    if(!dest || !src)
        return NULL;
    char *head = dest;
    while(*dest++ = *src++);
    return head;
}

int main() {
    char *dest, *src = "abcdef ";
    dest = strcpy_M1(dest, src);
    printf("dest address: %p\n", dest);
    printf("%sover\n", dest);
    free(dest);
    dest = (char *)malloc(sizeof(src)+1);
    printf("dest address: %p\n", dest);
    strcpy_M2(dest, src);
    printf("%sover\n", dest);
    free(dest);
    /* would cause error: "Bus error: 10"
    dest = (char *)malloc(sizeof(src)-1);
    strcpy(dest, src);
    printf("%sover\n", dest);
    */
    char *dest2 = "abcdefghi";
    char dest3[] = "abcdefghi";
    printf("dest2 address: %p\n", dest2);
    printf("dest3 address: %p\n", dest3);
    static char sstr[] = "abcc";
    char *p = (char *)src;
    *p = 'd';
    printf("sstr address: %p, sstr: %s\n", sstr, sstr);
    printf("address of sstr pointer: %p\n", &sstr);
    getchar();
    strcpy(dest2, src);
    printf("%sover\n", src);
}
