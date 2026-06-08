#include <stdio.h>

int main (){

    int t1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int t2[3][3];


    //SENTIDO ANTIHORARIO, PARA FAZER HORARIO FAZER [j][2-i]
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            t2[2-j][i] = t1[i][j];
        }
        printf("\n");
    }


for (int i = 0; i <3; i++){
        for (int j = 0; j < 3; j++){
printf("%d", t2[i][j]);
        }printf("\n");}

    return 0;
}