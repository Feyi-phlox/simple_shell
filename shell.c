#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char *command = NULL;
    size_t command_size = MAX_COMMAND_LENGTH;
    ssize_t characters_read;

    while (1) {
        write(STDOUT_FILENO, "Shell> ", 7);

        /* Read the user's command using getline() */
        characters_read = getline(&command, &command_size, stdin);

        /* Check for end-of-file condition (Ctrl+D) */
        if (characters_read == -1) {
            write(STDOUT_FILENO, "\nExiting the shell...\n", 22);
            break;
        }

        /* Remove newline character from the command */
        int i;
        for (i = 0; command[i] != '\n' && command[i] != '\0'; i++);
        command[i] = '\0';

        /* Exit the shell if the user enters "exit" or "quit" */
        if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0) {
            write(STDOUT_FILENO, "Exiting the shell...\n", 21);
            break;
        }

        /* Tokenize the command into arguments using strtok() */
        char *arguments[MAX_ARGUMENTS];
        char *token = strtok(command, " ");
        int arg_count = 0;

        while (token != NULL && arg_count < MAX_ARGUMENTS) {
            arguments[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        arguments[arg_count] = NULL;

        /* Execute the command with the arguments using execv() */
        if (fork() == 0) {
            /* Child process */
            execv(arguments[0], arguments);
            /* execv only returns if an error occurred */
            write(STDOUT_FILENO, "Failed to execute the command.\n", 31);
            exit(1);
        } else {
            /* Parent process */
            /* Wait for the child process to complete */
            wait(NULL);
        }
    }

    /* Free the dynamically allocated memory */
    free(command);

    return 0;
}

