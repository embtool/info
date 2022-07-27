#include "info.h"
#include <stdio.h>

void print_json_build_info(void)
{
    printf("{\n");
    printf("  \"git_commit_describe\": \"%s\",\n", git_commit_describe);
    printf("  \"git_commit_hash\": \"%s\",\n", git_commit_hash);
    printf("  \"build_type\": \"%s\",\n", build_type);
    printf("  \"build_user\": \"%s\",\n", build_user);
    printf("  \"build_date\": \"%s\",\n", build_date);
    printf("  \"build_time\": %lu\n", build_time);
    printf("}\n");
}

int main(void)
{
    print_json_build_info();

    return 0;
}
