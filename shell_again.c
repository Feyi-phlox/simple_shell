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

    char *arguments[MAX_ARGUMENTS];
    char *token;
    int arg_count, i;

    while (1) {
        write(STDOUT_FILENO, "Shell> ", 7);

        characters_read = getline(&command, &command_size, stdin);

        if (characters_read == -1) {
            write(STDOUT_FILENO, "\nExiting the shell...\n", 22);
            break;
        }

        
        for (i = 0; command[i] != '\n' && command[i] != '\0'; i++);
        command[i] = '\0';

        if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0) {
            write(STDOUT_FILENO, "Exiting the shell...\n", 21);
            break;
        }

        token = strtok(command, " ");
        arg_count = 0;

        while (token != NULL && arg_count < MAX_ARGUMENTS) {
            arguments[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        arguments[arg_count] = NULL;

        if (fork() == 0) {
            execv(arguments[0], arguments);
            write(STDOUT_FILENO, "Failed to execute the command.\n", 31);
            exit(1);
        } else {
            wait(NULL);
        }
    }

    free(command);

    return 0;
}

