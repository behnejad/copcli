#include "cop_cli.h"

void cop_cli_start(cli_ctx * ctx)
{
    printf("[%s@%s]%s", ctx->user, ctx->hostname, ctx->delimiter);
    int i =  getch();
    printf("%d %X [%c]", i, i, i);
    puts("\n");
}
