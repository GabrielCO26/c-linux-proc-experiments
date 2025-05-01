#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  pid_t pids[n];
  int resultados[n];
  
  for (int i = 0; i < n; i++) {
      pid_t pid = fork();
      if (pid == 0) { // Proceso hijo
          int fin = 2 * (i + 1) - 1;
          int suma = 0;
          printf("Listado de números impresos por proceso %d\n", getpid());
          for (int j = i; j <= fin; j++) {
              printf("Proceso %d, secuencia %d\n", getpid(), j);
              suma += j;
          }
      exit(suma);
      } else { // Proceso padre
          int status;
          waitpid(pid, &status, 0);
          pids[i] = pid;
          resultados[i] = WEXITSTATUS(status);
      }
  }

  for (int i = 0; i < n; i++) {
      printf("Hijo con PID %d terminó con suma: %d\n", pids[i], resultados[i]);
  }
  return 0;
}

