#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int n = atoi(argv[1]);
  pid_t pid;
  for (int i = 0; i < n; i++){
    pid = fork();
    if (pid == 0){
      int fin = 2*(i+1)-1;
      int suma = 0;
      printf("Listado de números impresos por proceso %d\n", getpid());
      for (int j = i; j <= fin; j++){
        printf("Proceso %d, secuencia %d\n", getpid(), j);
        suma += j;
      }
      exit(suma);
    }
  }
  sleep(1);
  for (int i = 0; i < n; i++){
    int status;
    pid_t pid_hijo = wait(&status);
    printf("Hijo %d terminó con suma: %d\n", pid_hijo, WEXITSTATUS(status));
  }
return 0;
}
