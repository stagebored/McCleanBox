#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *eg;
    lv_obj_t *load_file;
    lv_obj_t *sites;
    lv_obj_t *fg;
    lv_obj_t *graph;
    lv_obj_t *table;
    lv_obj_t *new_file;
    lv_obj_t *numin_dist;
    lv_obj_t *toptext;
    lv_obj_t *time;
    lv_obj_t *tabr;
    lv_obj_t *tabs;
    lv_obj_t *t_file;
    lv_obj_t *b_eg;
    lv_obj_t *b_new;
    lv_obj_t *b_sites;
    lv_obj_t *b_load;
    lv_obj_t *t_dist;
    lv_obj_t *t_depth;
    lv_obj_t *t_vel;
    lv_obj_t *mc_clean_box;
    lv_obj_t *time_5;
    lv_obj_t *tabr_2;
    lv_obj_t *tabs_2;
    lv_obj_t *t_vel_2;
    lv_obj_t *b_vclr_3;
    lv_obj_t *b_vclr_2;
    lv_obj_t *t_dist_2;
    lv_obj_t *obj0;
    lv_obj_t *t_file_2;
    lv_obj_t *b_ef_back;
    lv_obj_t *infobox;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *toptext_6;
    lv_obj_t *time_6;
    lv_obj_t *b_back_3;
    lv_obj_t *load_load;
    lv_obj_t *toptext_3;
    lv_obj_t *time_3;
    lv_obj_t *b_back_1;
    lv_obj_t *toptext_2;
    lv_obj_t *time_2;
    lv_obj_t *tabr_1;
    lv_obj_t *tabs_1;
    lv_obj_t *t_file_1;
    lv_obj_t *b_graph_1;
    lv_obj_t *b_save;
    lv_obj_t *b_table_1;
    lv_obj_t *bsavexit;
    lv_obj_t *t_dist_1;
    lv_obj_t *bdisplus;
    lv_obj_t *bdisneg;
    lv_obj_t *b_dep_npad;
    lv_obj_t *bprev_1;
    lv_obj_t *bnext_1;
    lv_obj_t *b_insert_1;
    lv_obj_t *t_depth_1;
    lv_obj_t *b_vup_2;
    lv_obj_t *b_vdown_1;
    lv_obj_t *b_dprev_1;
    lv_obj_t *t_vel_1;
    lv_obj_t *b_vclr_4;
    lv_obj_t *b_vup_3;
    lv_obj_t *b_vdown_3;
    lv_obj_t *b_vclr_1;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *toptext_1;
    lv_obj_t *time_1;
    lv_obj_t *b_back;
    lv_obj_t *toptext_4;
    lv_obj_t *time_4;
    lv_obj_t *b_back_2;
    lv_obj_t *toptext_7;
    lv_obj_t *time_7;
    lv_obj_t *b_back_4;
    lv_obj_t *new_new;
    lv_obj_t *toptext_8;
    lv_obj_t *time_8;
    lv_obj_t *kbtextarea;
    lv_obj_t *kbtextarea_1;
    lv_obj_t *obj5;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_EG = 2,
    SCREEN_ID_LOAD_FILE = 3,
    SCREEN_ID_SITES = 4,
    SCREEN_ID_FG = 5,
    SCREEN_ID_GRAPH = 6,
    SCREEN_ID_TABLE = 7,
    SCREEN_ID_NEW_FILE = 8,
    SCREEN_ID_NUMIN_DIST = 9,
};

void create_screen_main();
void tick_screen_main();

void create_screen_eg();
void tick_screen_eg();

void create_screen_load_file();
void tick_screen_load_file();

void create_screen_sites();
void tick_screen_sites();

void create_screen_fg();
void tick_screen_fg();

void create_screen_graph();
void tick_screen_graph();

void create_screen_table();
void tick_screen_table();

void create_screen_new_file();
void tick_screen_new_file();

void create_screen_numin_dist();
void tick_screen_numin_dist();

enum Themes {
    THEME_ID_RETRO,
    THEME_ID_UO_D,
    THEME_ID_BNW,
};
enum Colors {
    COLOR_ID_BUTTONS,
    COLOR_ID_HL_GREEN,
    COLOR_ID_HL_BLUE,
    COLOR_ID_HL_ORANGE,
    COLOR_ID_HL_RED,
    COLOR_ID_BG_LIGHT,
    COLOR_ID_BG_DARK,
    COLOR_ID_SHI_GREEN,
    COLOR_ID_SHI_RED,
    COLOR_ID_SHI_MAIN,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[3][10];
extern uint32_t active_theme_index;

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/