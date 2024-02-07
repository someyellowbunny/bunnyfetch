#include <argp.h>
#include <stdlib.h>

#include "osrelease.h"

const char *argp_program_version = "bunnyfetch 0.0.1";
const char *argp_program_bug_address = "<git@someyellowbunny.com>";
static char doc[] = "bunnyfetch -- tiny system info fetch utility.";

static struct argp argp = { 0, 0, 0, doc};

int main(int argc, char **argv) {
    argp_parse(&argp, argc, argv, 0, 0, 0);
    OsInfo info;

    if (init_osrelease(&info) != 0) {
        fprintf(stderr, "failed to initialized OsInfo");
        return 1;
    }

    

    return 0;
}