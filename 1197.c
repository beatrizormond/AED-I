#include <stdio.h>

int main(){
    int n, v, t, i;
    float a, deslocamento;

    scanf("%d", &n);
    if(n == EOF){
        break;
    }
    for (i=0; i<n; i++){
        scanf("%d %d", &v, &t);
        a = (v/t);

        deslocamento = (v * (2*t) * ((a*(2t))/2));
    }
    printf("%.0f\n", deslocamento);

    return 0;
}

