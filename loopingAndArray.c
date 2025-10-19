#include <stdio.h>

int main(){
    int first_matrix[3][3]={{10, 20, 30},
                            {10, 35, 40},
                            {15, 25, 20}};

    int second_matrix[3][2] ={{10,50},
                              {20,40},
                              {30,10}};
    printf("---------------------\n");
    printf("first matrix : \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("| %d ", first_matrix[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");
    printf("second matrix : \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            printf("| %d ", second_matrix[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");

    int result[3][2];

    for(int m=0; m<3; m++){
        for(int n=0; n<2 ; n++){
            int temp_sum=0;
            for(int p=0; p<3;p++){
                temp_sum +=first_matrix[m][p]*second_matrix[p][n];
            }
            result[m][n]=temp_sum;
        }

    }

    printf("result matrix : \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            printf("| %d ", result[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");

    return 0;
}

