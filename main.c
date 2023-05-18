#include "main.h"

/**
 * main - program entry point
 * @argc: Argument count to know number of inputs
 * @argv: arg vectors for list of progs
 * @env: environment variable
 * Return: 0 on success
 */

int main(int argc, char *argv[], char **env){
	char *ui = "Cisfun$ ", *buffer = NULL;
	size_t buffer_size = 0;
	pid_t pid;
	ssize_t nbytes;
	int status, pipe_use = 0;

	
	while (1 && !pipe_use){
		
		/* Display this in the terminal when the program starts */
		if (isatty(STDIN_FILENO) == 0)
			pipe_use = 1;
		
		/* Display this in the terminal when program starts */
		write(STDOUT_FILENO, ui, 8);

		/* Fetch data from the standard input */
		nbytes = getline(&buffer, &buffer_size, stdin);
		if (nbytes == -1){
			/* Print an error to the terminal and free memory */
			printf("Error from (getline) function\n");
			free(buffer);
			exit(EXIT_FAILURE);
	}
		/* remove new line character from getline */
		printf("nbytes value is %ld\n", nbytes); /* to know the nybytes */
		if (buffer[nbytes - 1] == '\n')
			buffer[nbytes - 1] == '\0';
		/* Create a child process here to execute any parsed command */
		pid = fork();
		if(pid == -1){
			printf("Error from (fork) function\n");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			/* execve function */
			printf("Hello from child\n");
		}
	}
		wait(&status);
		free(buffer);


	return (0);

}
