#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


 typedef struct t_philosopher {
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int must_to_eat;
	int eated;
	int philosopher_number;
	pthread_t* thread;
} t_philosopher;

int total_philosophers;
pthread_mutex_t* fork;

void* func_actions(void* arg) {

	t_philosopher philo  = *(t_philosopher*)arg;
    // Bloquear el mutex correspondiente al hilo
    pthread_mutex_lock(&fork[philo.philosopher_number]);
    // Bloquear el mutex n+1, y el primero si el hilo es el último
    pthread_mutex_lock(&fork[(philo.philosopher_number + 1) % total_philosophers]);

    // Sección crítica
    printf("%ld %d has taken a fork\n", time(NULL), philo.philosopher_number);
    printf("%ld %d is eating\n", time(NULL), philo.philosopher_number);
    sleep(philo.time_to_eat); // Dormir durante 2 segundos (2,000,000 microsegundos)

    // Desbloquear el mutex correspondiente al hilo
    pthread_mutex_unlock(&fork[philo.philosopher_number]);
    // Bloquear el mutex n+1, y el primero si el hilo es el último
    pthread_mutex_unlock(&fork[(philo.philosopher_number + 1) % total_philosophers]);

    printf("%ld %d is sleeping\n", time(NULL), philo.philosopher_number);
	sleep(philo.time_to_sleep);


    return NULL;
}

int main(int argc, char* argv[]) {
	

	t_philosopher* philos;

	if (argc > 5 || argc < 4) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

   	total_philosophers = atoi(argv[1]);
	philos = malloc(total_philosophers * sizeof(t_philosopher));
   	fork = malloc(total_philosophers * sizeof(pthread_mutex_t));
   	for (int i = 0; i < total_philosophers; i++) {
   		philos[i].thread = malloc(sizeof(pthread_t));
		philos[i].time_to_die = atoi(argv[2]);
		philos[i].time_to_eat = atoi(argv[3]);
		philos[i].time_to_sleep = atoi(argv[4]);
		philos[i].philosopher_number = i;
		if (argc == 5){
   			philos[i].must_to_eat = atoi(argv[5]);
		}
       	pthread_mutex_init(&fork[i], NULL);
       	pthread_create(philos[i].thread, NULL, func_actions, &philos[i]);
       	pthread_join(philos[i].thread, NULL);
       	pthread_mutex_destroy(&fork[i]);
   	}

    free(philos);
    free(fork);

    return 0;
}
