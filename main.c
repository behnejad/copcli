#include <stdio.h>

#include "cop_cli.h"

//--- share nodes ---
cli_node share_node_print =
{
    .name = "print"
};

cli_node share_node_get =
{
    .name = "get"
};

cli_node * share_nodes[] = {&share_node_print, &share_node_get};
//------------
//--- system ---
cli_branch system_branch =
{
    .name = "system",
    .sub_branch = {0, NULL},
    .node = {sizeof(share_nodes), share_nodes}
};

cli_branch * root_branch[] = {&system_branch};
//------------
//--- root ---
cli_branch root =
{
    .name = "",
    .sub_branch = {sizeof(root_branch), root_branch},
    .node = {sizeof(share_nodes), share_nodes}
};

cli_ctx ctx =
{
    .user = "COP",
    .hostname = "Mikortik",
    .delimiter = " > ",
    .root = &root,
};
//------------

int main()
{
    printf("Hello World!\n");
    cop_cli_start(&ctx);
    return 0;
}
