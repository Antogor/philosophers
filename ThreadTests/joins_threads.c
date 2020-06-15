/*
 * Program where father wait untils thread finish
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*func_thread(void *ptr);

int	main ()
{
	/*===Creation of a thread===*/	
	pthread_t	id_thread;
	int			error;
	char 		*return_value; //value that the thread will return

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
	/*===Thread join===*/
	printf("Father: I'm waiting\n");
		/*pthread_join()
		 * - id of the thread that must end for this process can continue
		 * - ptr void or data to save the vaulue that thread func return
		 * this func is used to keep in wait the father or another thread until the created and sended thread ends
		 */
	pthread_join(id_thread, (void *)&return_value);
	printf("Father: thread finished\n");
	printf("The return value of the thread is: %s\n", return_value);
	return (0);
}

void	*func_thread(void *ptr)
{
	char *value;

	printf("Thread: I'm working, i'll wait one sec\n");
	usleep(10000000); //func to stop the program, this will stop to program N microsec, in this case, 10 seg
	printf("Thread: I finish\n");
	value = "Value returned";
	return((void *)value);
}
