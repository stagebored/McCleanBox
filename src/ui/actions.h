#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_show_fg_screen(lv_event_t * e);
extern void action_show_main_screen(lv_event_t * e);
extern void action_show_table_screen(lv_event_t * e);
extern void action_show_eg_screen(lv_event_t * e);
extern void action_show_graph_screen(lv_event_t * e);
extern void action_show_loadfile_screen(lv_event_t * e);
extern void action_show_newfile_screen(lv_event_t * e);
extern void action_show_sites_screen(lv_event_t * e);
extern void action_show_textinput_screen(lv_event_t * e);
extern void action_ext_input_type(lv_event_t * e);
extern void action_show_numin_dist_screen(lv_event_t * e);
extern void action_ext_kbkey(lv_event_t * e);
extern void action_ext_timer(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/