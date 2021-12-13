#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fibonacci(int num) {
   if ( num == 0 )
     return 0;
   else if ( num == 1 )
     return 1;
   else
     return ( fibonacci(num-1) + fibonacci(num-2) );
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
        printf("[%d] Soy el hijo\n", (int) getpid());
        printf("el fibonacci de 25 es: %d\n", fibonacci(25));
    } else {
        // parent goes down this path (original process)
        // int wc = wait(NULL);
        printf("[%d] Soy el padre\n", (int) getpid());
    }
    printf("[%d] Termino ejecucion\n", (int) getpid());
    return 0;
}
