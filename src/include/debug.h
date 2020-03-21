/**
* DEBUG_MODE & DEBUG_MODE_COLOR will be set to "on" or "off"
* depending on the value of DEBUG_COLOR_OFF and DEBUG_ON
*/
#ifndef DEBUG_H
#define DEBUG_H

#if defined(DEBUG_COLOR_OFF)
    #define DEBUG_COLOR(x)
#else
    #define DEBUG_COLOR(x) "\x1b[" x "m"
#endif

#define KRST DEBUG_COLOR("0")
#define KRED DEBUG_COLOR("31")
#define KGRN DEBUG_COLOR("32")
#define KYEL DEBUG_COLOR("33")
#define KBLU DEBUG_COLOR("34")
#define KMAG DEBUG_COLOR("35")
#define KCYN DEBUG_COLOR("36")
#define KWHT DEBUG_COLOR("37")

#if defined(DEBUG_ON) || defined(DEBUG_MODE)
#include <string.h>
#include <stdio.h>
#include <libgen.h>
#include <errno.h>

#define debug_init(log_name) debug_primary(log_name)
#define __dbg_print(fmt, args...) \
    printf(fmt "\n" KRST, ##args); fflush(stdout); fflush(stderr);
#else
#define debug_init(log_name)
#define __dbg_print(fmt, args...)
#endif

#define debug(fmt, args...) \
__dbg_print(fmt, ##args);

#define debug_where(fmt, args...) \
__dbg_print(KMAG "[%s:%d] " fmt, __FUNCTION__, __LINE__, ##args);

#define debug_info(fmt, args...) \
__dbg_print(KCYN fmt, ##args);

#define debug_success(fmt, args...) \
__dbg_print(KGRN fmt, ##args);

#define debug_warning(fmt, args...) \
__dbg_print(KYEL fmt, ##args);

#define debug_danger(fmt, args...) \
__dbg_print(KRED fmt, ##args);

#define debug_primary(fmt, args...) \
__dbg_print(KBLU fmt, ##args);

//indicate unit test pass/fail
#define test_passed(fmt, args...) \
debug_success("[test=passed] " fmt, ##args);

#define test_failed(fmt, args...) \
debug_danger("[test=failed] " fmt, ##args);

//warn on non-0 status codes, presume these are handled correctly
#define debug_errno(fmt, args...) { \
    if(errno == 0) { \
        debug_danger("[%s:%d] Error: Something went wrong but no errno was set", __FUNCTION__, __LINE__) \
    } else { \
        debug_warning("[%s:%d] Error %d: %s " fmt, __FUNCTION__, __LINE__, errno, strerror(errno), ##args); \
    } \
}
#endif

#if defined(DEBUG_ON) || defined(DEBUG_MODE)
void debug_hex(char *str);
#endif
