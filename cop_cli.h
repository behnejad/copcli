/*
 .----------------.  .----------------.  .----------------.
| .--------------. || .--------------. || .--------------. |
| |     ______   | || |     ____     | || |   ______     | |
| |   .' ___  |  | || |   .'    `.   | || |  |_   __ \   | |
| |  / .'   \_|  | || |  /  .--.  \  | || |    | |__) |  | |
| |  | |         | || |  | |    | |  | || |    |  ___/   | |
| |  \ `.___.'\  | || |  \  `--'  /  | || |   _| |_      | |
| |   `._____.'  | || |   `.____.'   | || |  |_____|     | |
| |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'
*/

#ifndef COP_CLI_H
#define COP_CLI_H 1

#include <stdio.h>
#include <conio.h>

typedef struct cli_node
{
    const char * name;
} cli_node;

typedef struct cli_branch
{
    const char * name;

    struct
    {
        int count;
        struct cli_branch ** items;
    } sub_branch;

    struct
    {
        int count;
        struct cli_node ** items;
    } node;
} cli_branch;

typedef struct cli_ctx
{
    const cli_branch * root;
    cli_branch * current_entry;
    const char * delimiter;
    const char * user;
    const char * hostname;
    struct
    {
        int count;
        struct cli_node ** items;
    } global_nodes;
    void (*help_callback)(cli_branch * current);
} cli_ctx;

//------------

void cop_cli_start(cli_ctx * ctx);

#endif // COP_CLI_H
