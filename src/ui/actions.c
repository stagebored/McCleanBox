#include <lvgl.h>
#include "actions.h"
#include "screens.h"
#include "ui.h"

void action_show_eg_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_EG);
}
void action_show_fg_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_FG);
}
void action_show_graph_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_GRAPH);
}
void action_show_loadfile_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_LOAD_FILE);
}
void action_show_main_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_MAIN);
}
void action_show_sites_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_SITES);
}
void action_show_numin_dist_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_NUMIN_DIST);
}
void action_show_newfile_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_NEW_FILE);
}
void action_show_table_screen(lv_event_t *e) {
    loadScreen(SCREEN_ID_TABLE);
}
