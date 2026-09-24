
#include <stdio.h>
#include <stdlib.h>

#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/builtin.h"
#include "../include/signals.h"

int main()
{
    char *line;
    char **tokens;

    initialize_signals();

    printf("=====================================\n");
    printf("DevSecOps Command Console Version 6.0\n");
    printf("=====================================\n");

    while (1)
    {
        printf("devshell> ");

        line = read_line();

        tokens = parse_line(line);

        if (execute_builtin(tokens) == 0)
        {
            execute(tokens);
        }

        free_tokens(tokens);
        free(line);
    }

    return 0;
}
