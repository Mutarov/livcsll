#ifndef livcsll
#define livcsll

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_GRAY    "\033[90m"

int has_color_support() {
    static int checked = -1;
    if (checked == -1) {
        checked = isatty(fileno(stdout));
    }
    return checked;
}

static const char* get_current_time() {
    static char buffer[20];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);
    return buffer;
}

#define LOG(level_color, level, fmt, ...) do { \
    const char *time_str = get_current_time(); \
    if (has_color_support()) { \
        printf(COLOR_GRAY "[%s] " level_color "(%s) " fmt COLOR_RESET "\n", \
        time_str, level, ##__VA_ARGS__); \
    } else { \
        printf("[%s] (%s) " fmt "\n", time_str, level, ##__VA_ARGS__); \
    } \
} while(0)

#define INFO(fmt, ...)    LOG(COLOR_WHITE,  "INFO",    fmt, ##__VA_ARGS__)
#define SUCCESS(fmt, ...) LOG(COLOR_GREEN,  "SUCCESS", fmt, ##__VA_ARGS__)
#define WARN(fmt, ...)    LOG(COLOR_YELLOW, "WARN",    fmt, ##__VA_ARGS__)
#define ERROR(fmt, ...)   LOG(COLOR_RED,    "ERROR",   fmt, ##__VA_ARGS__)

#endif //livcsll