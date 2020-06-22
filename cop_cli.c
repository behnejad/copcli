#include "cop_cli.h"

void cop_cli_start(cli_entry * root)
{
    printf("%s %s ", root->prefix, root->delimiter);
    getch();
    puts("\n");
}
