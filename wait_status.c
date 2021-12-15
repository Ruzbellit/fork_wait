#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

int maxrand(int max) {
  srand(time(0));
  return rand()%max;
}

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        int numRand;
        numRand = maxrand(50);
        printf("[%d] Soy el hijo\n", (int) getpid());
        printf("[%d] valor aleatorio hijo %d \n", (int) getpid(), numRand);
        printf("[%d] Termino ejecucion\n", (int) getpid());
        return numRand;
    } else {
        // parent goes down this path (original process)
        int returnhijo;
        printf("[%d] Soy el padre\n", (int) getpid());
        wait(&returnhijo);
        printf("[%d] el valor obtenido con wait(&status) es %d \n", (int) getpid(), returnhijo);
        printf("[%d] la validacion de WIFEXITED es %d \n", (int) getpid(), WIFEXITED(returnhijo));
        // el valor retornado por WIFEXITED es true si el hijo termino normalmente
        if (WIFEXITED(returnhijo) == true){
          printf("[%d] el valor de salida del proceso hijo es %d \n", (int) getpid(), WEXITSTATUS(returnhijo));
        }
        
        //return 0;
    }
    printf("[%d] Termino ejecucion\n", (int) getpid());
    //return 0;
}

