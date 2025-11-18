#include <stdio.h>

int main (){
    int t, v;

    while(scanf("%d%d", &v, &t) != EOF){
        printf("%d\n", v*(2*t));
    }

}
