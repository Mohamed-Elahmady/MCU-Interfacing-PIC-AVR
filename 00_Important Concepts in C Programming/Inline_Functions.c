#include <stdio.h>

__attribute__((always_inline))inline int ret_2(void){
    return 2;
}

int ret_3(void){
    return 3;
}

int main(){
    int sum = ret_2() + ret_3();
    printf("%d\n", sum);
    return 0;
}