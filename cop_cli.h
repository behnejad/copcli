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

typedef struct cli_entry
{
    const char * prefix;
    const char * delimiter;
    cli_branch * entry;
} cli_entry;


//------------

void cop_cli_start(cli_entry * root);

#endif // COP_CLI_H
