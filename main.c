#include "livcsll.h"

int main(void) {
    INFO("PROGRAMM STARTED");
    WARN("CMAKE NOT FOUND");
    SUCCESS("TEST PASSED");
    ERROR("%s", "BUILD FAILED");
    sleep(1);
    if (has_color_support() == 1) {
        SUCCESS("has_color_support(): %d", has_color_support());
    } else {
        ERROR("has_color_support(): %d", has_color_support());
    }
    return 0;
}