#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_GTIMERV = 0,
    FLOW_GLOBAL_VARIABLE_ROTCOUNT = 1,
    FLOW_GLOBAL_VARIABLE_PREVRESULTS = 2,
    FLOW_GLOBAL_VARIABLE_TIME = 3,
    FLOW_GLOBAL_VARIABLE_INFOBOX = 4
};

// Native global variables

extern const char *get_var_gtimerv();
extern void set_var_gtimerv(const char *value);
extern const char *get_var_rotcount();
extern void set_var_rotcount(const char *value);
extern const char *get_var_prevresults();
extern void set_var_prevresults(const char *value);
extern const char *get_var_time();
extern void set_var_time(const char *value);
extern const char *get_var_infobox();
extern void set_var_infobox(const char *value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/