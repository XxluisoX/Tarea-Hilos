#include <stdio.h>
#include <pthread.h>

void *contar_hacia_atras(void *arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t mi_hilo;

    if (pthread_create(&mi_hilo, NULL, contar_hacia_atras, NULL) != 0) {
        fprintf(stderr, "Error al crear el hilo.\n");
        return 1;
    }

    for (int i = 1; i <= 10000; i++) {
        printf("Principal: %d\n", i);
    }

    pthread_join(mi_hilo, NULL);

    return 0;
}
