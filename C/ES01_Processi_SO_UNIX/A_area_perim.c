#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main() {
    int cateto1 = 15;
    int cateto2 = 40;
    pid_t pid;

    pid = fork();

    if (pid < 0) { perror("Fork failed");  return 1; }

    if (pid > 0) { 
        double area = 0.5 * cateto1 * cateto2;
        printf("Processo Padre => L'area del triangolo rettangolo è: %.2f\n", area);
    } else if (!pid) {
        double ipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
        double perimetro = cateto1 + cateto2 + ipotenusa;
        printf("Processo Figlio => Il perimetro del triangolo rettangolo è: %.2f\n", perimetro);
    }
    return 0;
}
