#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) { // Proceso hijo             
            printf("Proceso hijo: PID = %d, PPID = %d\n", getpid(), getppid());
            while (1) { sleep(1); } // mantiene el proceso en ejecución
        } else if (pid > 0) { // Proceso padre
            printf("Proceso padre: PID = %d, hijo creado = %d\n", getpid(), pid);
            sleep(1); // Esperar antes de crear el siguiente hijo
        } else {
            // Error en el fork
            perror("Error al crear el proceso");
            exit(1);
        }
    }
    while (1) { sleep(1); } // mantiene el proceso padre en ejecución
    return 0;
}