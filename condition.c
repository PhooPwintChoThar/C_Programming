#include <stdio.h>

int main(){
    int scores;
    printf("Enter your score: ");
    scanf("%d", &scores);

    if(scores>=80)
        printf("Your Grade is A\n");
    else if(scores>=50)
        printf("Your Grade is B\n");
    else if (scores>=40)
        printf("Your Grade is C\n");
        
    else{
        printf("Your Grade is D\n");
        printf("\nYou fail\n");
    }
    

    return 0;
    
}