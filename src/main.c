#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>

#include "wm.h"
#include "osrelease.h"

const char *FOOT = "\033[31m\"\033[0m";
const char *RESET = "\033[0m";

const char *argp_program_version = "bunnyfetch 0.0.1";
const char *argp_program_bug_address = "<git@someyellowbunny.com>";
static char doc[] = "bunnyfetch -- tiny system info fetch utility.";

static struct argp argp = { 0, 0, 0, doc};

const char *title(struct utsname *uts) {
    const char *name = getlogin();

    size_t len = strlen(name) + strlen(uts->nodename);

    char *ret = malloc(len + 1);

    strcpy(ret, name);
    strcat(ret, "@");
    strcat(ret, uts->nodename);

    return ret;
}

const char *shell() {
    const char *sp = getenv("SHELL");
    const char *name = strrchr(sp, '/');

    if (name) {
        name = name + 1;
    } else { name = sp; }

    return name;
}

int main(int argc, char **argv) {
    argp_parse(&argp, argc, argv, 0, 0, 0);
    OsInfo info;

    if (init_osrelease(&info) != 0) {
        fprintf(stderr, "failed to initialized OsInfo");
        return 1;
    }

    struct utsname uts;
    uname(&uts);

    const char *t = title(&uts);
    
    printf(""
    "            \033[31m%s%s\n"
    "            \033[%smOS %s%s\n"
    "   (\\ /)    \033[33mKernel%s %s\n"
    "   ( . .)   \033[34mShell%s %s\n"
    "   c(%s)(%s)  \033[35mWM%s %s",
    t, RESET,
    info.color, RESET, info.name,
    RESET, uts.release,
    RESET, shell(),
    FOOT, FOOT,
    RESET, window_manager()
    );
    printf("\n         ");
    for (int i = 0; i < 8; i++) {
        printf("\033[4%dm   ", i);
    }
    printf("%s\n         ", RESET);
    for (int i = 0; i < 8; i++) {
        printf("\033[10%dm   ", i);
    }
    printf("%s\n", RESET);

    return 0;
}