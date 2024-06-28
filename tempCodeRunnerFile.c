#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables to store the read values

    // Open the file for reading
    FILE *file = fopen("test.txt", "r");

    int a=getc(file);

    while (a!=EOF)
    {
        (int)putchar(a);
        a=getc(file);
    }
    
        fclose(file);

    return 0;
}
