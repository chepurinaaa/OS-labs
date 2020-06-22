#include <stdio.h>
#include <stdlib.h>

int main () {
    char name[20];
    puts("Enter name: ");
    scanf("%19s", name);
    printf("Hello,  %s.\n\n\tNice to see you.\n", name);

    puts("Enter name: ");
    scanf("%19s", name);
    printf("Hello,  %s.\n\n\tNice to see you.\n", name);

    char name1[20]="Anna";
    char a_letter=name1[0];
    name1[0]=name1[3];
    name1[3]=a_letter;
    puts(name1);

    return 0;
}
