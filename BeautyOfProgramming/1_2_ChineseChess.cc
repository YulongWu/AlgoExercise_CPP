BYTE i = 81;
while(i --) {
    if(i / 9 % 3 == i % 9 % 3)
        continue;
    printf("A= %d, B= %d\n", i / 9 + 1, i % 9 +1);
}
struct {
    unsigned char a:4;
    unsigned char b:4;
} i;
for(i.a = 1; i.a <= 9; i.a++)
    for(a.b = 1; i.b <= 9; i.b++)
        if(i.a % 3 != i.b % 3)
            printf("A= %d, B= %d\n", i.a, i.b);
