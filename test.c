#include <stdio.h>
#include <unistd.h>

int main(){

    int num, num1;
    char t[10];
    printf("Type :");
    scanf("%dis%d%s", &num, &num1, t);
    printf("Num is : %d  %d %s\n", num, num1, t);
    // Example 1: No \n - might not see output immediately
printf("Loading");
sleep(3);  // Wait 3 seconds
printf("Done");
// You might not see "Loading" until program ends!

// Example 2: With \n - prints immediately
printf("Loading\n");
sleep(3);
printf("Done\n");
// You'll see "Loading" right away, then "Done" after 3 seconds

// Example 3: \n in the middle works fine
printf("Hello\nWorld\n");
// Prints:
// Hello
// World

return 0;
}