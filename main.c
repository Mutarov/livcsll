#include "livcsll.h"

int main(void) {
    L_INFO("PROGRAMM STARTED");
    L_WARN("CMAKE NOT FOUND");
    L_SUCCESS("TEST PASSED");
    L_ERROR("%s", "BUILD FAILED");
    return 0;
}
