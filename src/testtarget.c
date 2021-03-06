#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
    #include <Windows.h>
    #define sleepms(x) Sleep(x)
#else
    #include <unistd.h>
    #define ONE_MS_IN_US 1000
    #define sleepms(x) usleep(x*ONE_MS_IN_US)
#endif

#define PRINT_PID !_WIN32

#define EXPECTED_ARGC 7

// C standard guarantees that the members are sequential in memory
typedef struct {
    int32_t Money;
    int32_t Gold;
    int8_t GentooInstalled;
    int8_t PrivilegeChecked;
    int16_t SpeedOfSeriousShit;
    char *Name; // target platform: x86, if sizeof(char *) is not 4...pray
} GlobalState;

// Use a static state struct so that its location is always predictable
static GlobalState globalState;

/** Prints help.
 * 
 * @param programName Name of the currently-run program.
 */
static void Help(const char *programName);

/** Parses the command line arguments and stores them in state.
 *
 * @param state Pointer to the state object where the args are stored.
 * @param argc  Length of argv.
 * @param argv  Command line arguments.
 * @return      true if the operation succeeded, otherwise false.
 */
static bool ParseArgs(GlobalState *state, int argc, char *argv[]);

static void PrintPing(const GlobalState *state);


int main(int argc, char *argv[]) {
    if (argc < 1) {
        // someone's doing exec hax
        Help("testtarget");
        return EXIT_FAILURE;
    }

    if (!ParseArgs(&globalState, argc, argv)) {
        Help(argv[0]);
        return EXIT_FAILURE;
    }

#ifdef PRINT_PID
    printf("PID: %d\n", getpid());
#endif
    printf("State struct address: %"PRIXPTR"\n", (uintptr_t)&globalState);
    fflush(stdout);
    
    unsigned int sleepCycles = 0;
    while (true) {
        if (sleepCycles % 50 == 0) {
            // ping every 5 sec
            PrintPing(&globalState);
            fflush(stdout);
        }
        sleepms(100);
        sleepCycles++;
    }

    free(globalState.Name);
    return EXIT_SUCCESS;
}

void PrintPing(const GlobalState *s) {
    puts("State");
    puts("MONEY      GOLD       ISGENTOO   ISPRIV     SPEED      NAME          ");
    printf(
        "%-10d %-10d %-10s %-10s %-10d %-10s\n",
        s->Money,
        s->Gold,
        s->GentooInstalled ? "true" : "false",
        s->PrivilegeChecked ? "true" : "false",
        s->SpeedOfSeriousShit,
        s->Name
    );
    puts("");
}

void Help(const char *progName) {
    puts("TestTarget - A test program for use as a memory reading target.");
    puts("");
    printf("USAGE:    %s money gold isgentoo ispriv speed name\n", progName);
    puts("");
    puts("OPTIONS:\n");
    puts("money:    Integer value of the Money variable");
    puts("gold:     Integer value of the Gold variable");
    puts("isgentoo: Boolean (1=true,0=false) value for the GentooInstalled variable");
    puts("ispriv:   Boolean (1=true,0=false) value for the PrivilegeChecked variable");
    puts("speed:    Short value for the SpeedOfSeriousShit variable");
    puts("name:     String value for the Name variable, max 1024 chars");
    puts("");
    puts("Backing variable types:");
    puts("    Integer=int32_t, Short=int16_t, Boolean=int8_t, String=char *");
    puts("");
    puts("The provided variables are set into static variables, for easy access.");
    puts("After setting the variables, the address of the state struct is printed");
    puts("with the PRIXPTR format specifier. Then, a call is made to getchar() ");
    puts("to pause execution.");
    puts("");
}

bool ParseArgs(GlobalState *state, int argc, char *argv[]) {
    if (argc < EXPECTED_ARGC || state == NULL || argv == NULL) {
        return false;
    }

    state->Money = atoi(argv[1]);
    state->Gold = atoi(argv[2]);
    state->GentooInstalled = (int8_t)atoi(argv[3]);
    state->PrivilegeChecked = (int8_t)atoi(argv[4]);
    state->SpeedOfSeriousShit = (int16_t)atoi(argv[5]);
    char *namebuf = calloc(1025, sizeof(char)); // calloc provides zeroed memory blocks
    if (namebuf == NULL) {
        fputs("Could not allocate 1025 bytes for name buffer!", stderr);
        return false;
    }
    state->Name = strncpy(namebuf, argv[6], 1024);
    return true;
}