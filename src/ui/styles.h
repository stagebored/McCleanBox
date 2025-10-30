#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: tile
lv_style_t *get_style_tile_MAIN_DEFAULT();
void add_style_tile(lv_obj_t *obj);
void remove_style_tile(lv_obj_t *obj);

// Style: s_button
lv_style_t *get_style_s_button_MAIN_DEFAULT();
lv_style_t *get_style_s_button_MAIN_PRESSED();
void add_style_s_button(lv_obj_t *obj);
void remove_style_s_button(lv_obj_t *obj);

// Style: label_button
lv_style_t *get_style_label_button_MAIN_DEFAULT();
void add_style_label_button(lv_obj_t *obj);
void remove_style_label_button(lv_obj_t *obj);

// Style: label_values
lv_style_t *get_style_label_values_MAIN_DEFAULT();
void add_style_label_values(lv_obj_t *obj);
void remove_style_label_values(lv_obj_t *obj);

// Style: label_topbar
lv_style_t *get_style_label_topbar_MAIN_DEFAULT();
void add_style_label_topbar(lv_obj_t *obj);
void remove_style_label_topbar(lv_obj_t *obj);

// Style: chart
lv_style_t *get_style_chart_MAIN_DEFAULT();
void add_style_chart(lv_obj_t *obj);
void remove_style_chart(lv_obj_t *obj);

// Style: textbox
lv_style_t *get_style_textbox_MAIN_DEFAULT();
void add_style_textbox(lv_obj_t *obj);
void remove_style_textbox(lv_obj_t *obj);

// Style: tabview
lv_style_t *get_style_tabview_MAIN_DEFAULT();
void add_style_tabview(lv_obj_t *obj);
void remove_style_tabview(lv_obj_t *obj);

// Style: tabbar
lv_style_t *get_style_tabbar_MAIN_DEFAULT();
void add_style_tabbar(lv_obj_t *obj);
void remove_style_tabbar(lv_obj_t *obj);

// Style: tabcontent
lv_style_t *get_style_tabcontent_MAIN_DEFAULT();
void add_style_tabcontent(lv_obj_t *obj);
void remove_style_tabcontent(lv_obj_t *obj);

// Style: kbtextarea
lv_style_t *get_style_kbtextarea_MAIN_DEFAULT();
void add_style_kbtextarea(lv_obj_t *obj);
void remove_style_kbtextarea(lv_obj_t *obj);

// Style: dropdown
lv_style_t *get_style_dropdown_MAIN_DEFAULT();
void add_style_dropdown(lv_obj_t *obj);
void remove_style_dropdown(lv_obj_t *obj);

// Style: checkbox
lv_style_t *get_style_checkbox_MAIN_DEFAULT();
lv_style_t *get_style_checkbox_INDICATOR_DEFAULT();
void add_style_checkbox(lv_obj_t *obj);
void remove_style_checkbox(lv_obj_t *obj);

// Style: slider
void add_style_slider(lv_obj_t *obj);
void remove_style_slider(lv_obj_t *obj);

// Style: roller
lv_style_t *get_style_roller_MAIN_DEFAULT();
void add_style_roller(lv_obj_t *obj);
void remove_style_roller(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/