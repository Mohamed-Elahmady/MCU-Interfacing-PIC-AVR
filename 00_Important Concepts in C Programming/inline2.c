#include <stdio.h>

static inline int returnnum(void){
    return 33;
}

int main(){
    int sum = returnnum();
    printf("%d\n", sum);
    return 0;
}