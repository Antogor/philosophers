/*
 * Program to print a number in a infinite loop where
 * one loop increment the number while
 * the thread decrement the same number
 */

#include <pthread.h>
#include <stdio.h>

void	*func_thread(void *ptr);

int	COUNT = 0; //Global count, acces in main and func thread

int	main ()
{
	/*===Creation of a thread===*/	
	pthread_t	id_thread;
	int			error;

		/*pthread_create()
		 * - memmory addres to a pthread_t data that will contain the id of the thread
		 * - thread atributes, with NULL the func determinate de basic threads atributes
		 * - ptr to a func that return void
		 * - the parametrer that will send to a func
		 * This func return a value, 0 if everything gone well, != 0 if gone wrong
		 */
	error = pthread_create (&id_thread, NULL, func_thread, NULL);
	if (error != 0)
	{
		printf("Fail to create thread");
		return (0);
	}
	while (1)
	{
		printf("Father: %d\n", COUNT);
		COUNT++;
	}
	return (0);
}

void	*func_thread(void *ptr)
{
	while (1)
	{
		printf("Thread: %d\n", COUNT);
		COUNT--;
	}

}
