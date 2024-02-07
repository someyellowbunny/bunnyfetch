#include <argp.h>

const char *argp_program_version = "0.0.1";
const char *argp_program_bug_address = "<git@someyellowbunny.com";
static char doc[] = "bunnyfetch -- tiny system info fetch utility.";

static struct argp argp = { 0, 0, 0, doc};

int main(int argc, char **argv) {
    argp_parse(&argp, argc, argv, 0, 0, 0);
    return 0;
}