#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

static void event_handler_cb_eg_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_prevresults(value);
        }
    }
}

static void event_handler_cb_eg_infobox(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_infobox(value);
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "McClean Box");
        }
        {
            // time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            // tabr
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.tabr = obj;
            lv_obj_set_pos(obj, 0, 15);
            lv_obj_set_size(obj, 320, 225);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_RIGHT);
            lv_tabview_set_tab_bar_size(obj, 75);
            add_style_tabview(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // tabs
                    lv_obj_t *obj = lv_tabview_get_tab_bar(parent_obj);
                    objects.tabs = obj;
                    add_style_tabbar(obj);
                }
                {
                    lv_obj_t *obj = lv_tabview_get_content(parent_obj);
                    add_style_tabcontent(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // t_file
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Gauge");
                            objects.t_file = obj;
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // bEG
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_eg = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_eg_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Vel Only");
                                        }
                                    }
                                }
                                {
                                    // bNew
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_new = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_newfile_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "New File");
                                        }
                                    }
                                }
                                {
                                    // bSites
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_sites = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_sites_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Sites");
                                        }
                                    }
                                }
                                {
                                    // bLoad
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_load = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_loadfile_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Load File");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // t_Dist
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "UI");
                            objects.t_dist = obj;
                            add_style_tile(obj);
                        }
                        {
                            // t_Depth
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Kit");
                            objects.t_depth = obj;
                            add_style_tile(obj);
                        }
                        {
                            // t_Vel
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Sys");
                            objects.t_vel = obj;
                            add_style_tile(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            lv_obj_set_pos(obj, 16, 93);
            lv_obj_set_size(obj, 214, 70);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_text(obj, "Vel Only: Simple Operation\n\nNew File: Records distance, depth, computes flow.");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            add_style_textbox(obj);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time;
            lv_label_set_text(objects.time, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_eg() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.eg = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // McCleanBox
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mc_clean_box = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "McleanBox");
        }
        {
            // time_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_5 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            // tabr_2
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.tabr_2 = obj;
            lv_obj_set_pos(obj, 0, 15);
            lv_obj_set_size(obj, 320, 225);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_RIGHT);
            lv_tabview_set_tab_bar_size(obj, 75);
            add_style_tabview(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // tabs_2
                    lv_obj_t *obj = lv_tabview_get_tab_bar(parent_obj);
                    objects.tabs_2 = obj;
                    add_style_tabbar(obj);
                }
                {
                    lv_obj_t *obj = lv_tabview_get_content(parent_obj);
                    add_style_tabcontent(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // t_Vel_2
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Gauge");
                            objects.t_vel_2 = obj;
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_chart_create(parent_obj);
                                    lv_obj_set_pos(obj, 90, 45);
                                    lv_obj_set_size(obj, 130, 134);
                                    add_style_chart(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // b_vclr_3
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vclr_3 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_ext_timer, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Reset");
                                        }
                                    }
                                }
                                {
                                    // b_vclr_2
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vclr_2 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_ext_timer, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Start");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj2 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, -37, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Flow ");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Time");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, -21, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "0.0000");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Rotations");
                                }
                            }
                        }
                        {
                            // t_Dist_2
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Results");
                            objects.t_dist_2 = obj;
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Previous Results");
                                }
                                {
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.obj0 = obj;
                                    lv_obj_set_pos(obj, 10, 74);
                                    lv_obj_set_size(obj, 210, 180);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_add_event_cb(obj, event_handler_cb_eg_obj0, LV_EVENT_ALL, 0);
                                    add_style_textbox(obj);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // t_file_2
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Menu");
                            objects.t_file_2 = obj;
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // b_ef_back
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_ef_back = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_main_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Main Menu");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 73, -334);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Info");
                                }
                                {
                                    // infobox
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.infobox = obj;
                                    lv_obj_set_pos(obj, 83, -260);
                                    lv_obj_set_size(obj, 210, 100);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_placeholder_text(obj, "[info]");
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_add_event_cb(obj, event_handler_cb_eg_infobox, LV_EVENT_ALL, 0);
                                    add_style_textbox(obj);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_eg();
}

void tick_screen_eg() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_5;
            lv_label_set_text(objects.time_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_rotcount();
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_gtimerv();
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_prevresults();
        const char *cur_val = lv_textarea_get_text(objects.obj0);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj0);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_textarea_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_infobox();
        const char *cur_val = lv_textarea_get_text(objects.infobox);
        uint32_t max_length = lv_textarea_get_max_length(objects.infobox);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.infobox;
            lv_textarea_set_text(objects.infobox, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_load_file() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.load_file = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_6 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "Load File");
        }
        {
            // time_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_6 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            // b_back_3
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_back_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_add_event_cb(obj, action_show_main_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // load_load
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.load_load = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_show_fg_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Load");
                }
            }
        }
    }
    
    tick_screen_load_file();
}

void tick_screen_load_file() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_6;
            lv_label_set_text(objects.time_6, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_sites() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.sites = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "Manage Sites");
        }
        {
            // time_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_3 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            // b_back_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_back_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_add_event_cb(obj, action_show_main_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 140, 110);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_label_button(obj);
            lv_label_set_text(obj, "Sites");
        }
    }
    
    tick_screen_sites();
}

void tick_screen_sites() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_3;
            lv_label_set_text(objects.time_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_fg() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.fg = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "[site name] ");
        }
        {
            // time_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_2 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            // tabr_1
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.tabr_1 = obj;
            lv_obj_set_pos(obj, 0, 15);
            lv_obj_set_size(obj, 320, 225);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_RIGHT);
            lv_tabview_set_tab_bar_size(obj, 75);
            lv_obj_add_event_cb(obj, action_show_graph_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_tabview(obj);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // tabs_1
                    lv_obj_t *obj = lv_tabview_get_tab_bar(parent_obj);
                    objects.tabs_1 = obj;
                    add_style_tabbar(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_base_dir(obj, LV_BASE_DIR_LTR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_tabview_get_content(parent_obj);
                    add_style_tabbar(obj);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_outline_pad(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_outline_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // t_file_1
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "File");
                            objects.t_file_1 = obj;
                            add_style_tile(obj);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_margin_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_margin_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_margin_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_margin_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_pad(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // bGraph_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_graph_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_graph_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Graph");
                                        }
                                    }
                                }
                                {
                                    // bSave
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_save = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Save");
                                        }
                                    }
                                }
                                {
                                    // bTable_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_table_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_table_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Table");
                                        }
                                    }
                                }
                                {
                                    // bsavexit
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.bsavexit = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_main_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Save+Exit");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // t_Dist_1
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Distance");
                            objects.t_dist_1 = obj;
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // bdisplus
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.bdisplus = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "+.05");
                                        }
                                    }
                                }
                                {
                                    // bdisneg
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.bdisneg = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "-.05");
                                        }
                                    }
                                }
                                {
                                    // b_dep_npad
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_dep_npad = obj;
                                    lv_obj_set_pos(obj, 58, -68);
                                    lv_obj_set_size(obj, 100, 50);
                                    lv_obj_add_event_cb(obj, action_show_numin_dist_screen, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Set Dist");
                                        }
                                    }
                                }
                                {
                                    // bprev_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.bprev_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "<<");
                                        }
                                    }
                                }
                                {
                                    // bnext_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.bnext_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, ">>");
                                        }
                                    }
                                }
                                {
                                    // bInsert_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_insert_1 = obj;
                                    lv_obj_set_pos(obj, 58, -68);
                                    lv_obj_set_size(obj, 100, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Insert");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // t_Depth_1
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Depth");
                            objects.t_depth_1 = obj;
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // b_vup_2
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vup_2 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Up");
                                        }
                                    }
                                }
                                {
                                    // b_vdown_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vdown_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "Down");
                                        }
                                    }
                                }
                                {
                                    // b_dprev_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_dprev_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "=<<");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // t_Vel_1
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Velocity");
                            objects.t_vel_1 = obj;
                            lv_obj_add_event_cb(obj, action_ext_timer, LV_EVENT_PRESSED, (void *)0);
                            add_style_tile(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -10, -156);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_x(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Time");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_x(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Rotations");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 55, LV_SIZE_CONTENT);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 51, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "@0.4d");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                                    add_style_label_topbar(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_x(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Flow ");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj3 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_x(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj4 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 75, LV_SIZE_CONTENT);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                                    add_style_label_values(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_x(obj, -50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "0.12345");
                                }
                                {
                                    // b_vclr_4
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vclr_4 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 22);
                                    lv_obj_add_event_cb(obj, action_ext_timer, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_translate_y(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "CLR");
                                        }
                                    }
                                }
                                {
                                    // b_vup_3
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vup_3 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "/\\");
                                        }
                                    }
                                }
                                {
                                    // b_vdown_3
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vdown_3 = obj;
                                    lv_obj_set_pos(obj, 15, -69);
                                    lv_obj_set_size(obj, 50, 50);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "\\/");
                                        }
                                    }
                                }
                                {
                                    // b_vclr_1
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.b_vclr_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 50);
                                    lv_obj_add_event_cb(obj, action_ext_timer, LV_EVENT_PRESSED, (void *)0);
                                    add_style_s_button(obj);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            add_style_label_button(obj);
                                            lv_label_set_text(obj, "GO");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_chart_create(parent_obj);
                                    lv_obj_set_pos(obj, 90, 45);
                                    lv_obj_set_size(obj, 150, 100);
                                    add_style_chart(obj);
                                    lv_obj_set_style_grid_cell_column_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_column_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_span(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_row_pos(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_x_align(obj, LV_GRID_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_grid_cell_y_align(obj, LV_GRID_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_fg();
}

void tick_screen_fg() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_2;
            lv_label_set_text(objects.time_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_gtimerv();
        const char *cur_val = lv_label_get_text(objects.obj3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj3;
            lv_label_set_text(objects.obj3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_rotcount();
        const char *cur_val = lv_label_get_text(objects.obj4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj4;
            lv_label_set_text(objects.obj4, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_graph() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.graph = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "Graph");
        }
        {
            // time_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_1 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            // b_back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_back = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_add_event_cb(obj, action_show_fg_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, action_show_fg_screen, LV_EVENT_PRESSED, (void *)0);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            lv_obj_t *obj = lv_chart_create(parent_obj);
            lv_obj_set_pos(obj, 0, 15);
            lv_obj_set_size(obj, 320, 175);
            add_style_chart(obj);
        }
    }
    
    tick_screen_graph();
}

void tick_screen_graph() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_1;
            lv_label_set_text(objects.time_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_table() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.table = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_4 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "Data Table");
        }
        {
            // time_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_4 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            // b_back_2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_back_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_add_event_cb(obj, action_show_fg_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 110, 88);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_label_button(obj);
            lv_label_set_text(obj, "table");
        }
    }
    
    tick_screen_table();
}

void tick_screen_table() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_4;
            lv_label_set_text(objects.time_4, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_new_file() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.new_file = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_7 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "New File");
        }
        {
            // time_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_7 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            // b_back_4
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_back_4 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_add_event_cb(obj, action_show_main_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // New_New
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.new_new = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_show_fg_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_s_button(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_button(obj);
                    lv_label_set_text(obj, "Start");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 14, 25);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_label_button(obj);
            lv_label_set_text(obj, "new");
        }
    }
    
    tick_screen_new_file();
}

void tick_screen_new_file() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_7;
            lv_label_set_text(objects.time_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_numin_dist() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.numin_dist = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // toptext_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.toptext_8 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 245, 15);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "Number Input (is broken)");
        }
        {
            // time_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_8 = obj;
            lv_obj_set_pos(obj, 245, 0);
            lv_obj_set_size(obj, 75, 15);
            add_style_label_topbar(obj);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 0, 15);
            lv_obj_set_size(obj, 320, 225);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, action_ext_kbkey, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_add_event_cb(obj, action_show_fg_screen, LV_EVENT_READY, (void *)0);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // kbtextarea
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.kbtextarea = obj;
                    lv_obj_set_pos(obj, 0, 25);
                    lv_obj_set_size(obj, 125, 30);
                    lv_textarea_set_accepted_chars(obj, ".0123456789");
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "000.000");
                    lv_textarea_set_placeholder_text(obj, "000.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_FLOATING);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE);
                    add_style_kbtextarea(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // kbtextarea_1
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.kbtextarea_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 125, 25);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "Distance");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_FLOATING);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE);
                    add_style_kbtextarea(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.obj5, objects.kbtextarea);
    
    tick_screen_numin_dist();
}

void tick_screen_numin_dist() {
    {
        const char *new_val = get_var_time();
        const char *cur_val = lv_label_get_text(objects.time_8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_8;
            lv_label_set_text(objects.time_8, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void change_color_theme(uint32_t theme_index) {
    active_theme_index = theme_index;
    
    lv_style_set_bg_color(get_style_tile_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_s_button_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_text_color(get_style_s_button_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_border_color(get_style_s_button_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_s_button_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][9]));
    
    lv_style_set_text_color(get_style_label_values_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_text_color(get_style_label_topbar_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_outline_color(get_style_label_topbar_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_label_topbar_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][9]));
    
    lv_style_set_bg_color(get_style_chart_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_border_color(get_style_chart_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_line_color(get_style_chart_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_bg_color(get_style_textbox_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_text_color(get_style_textbox_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_bg_color(get_style_tabview_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_tabbar_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_bg_color(get_style_tabcontent_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_kbtextarea_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_border_color(get_style_kbtextarea_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_text_color(get_style_kbtextarea_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_text_color(get_style_dropdown_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_dropdown_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_text_color(get_style_checkbox_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_bg_color(get_style_checkbox_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_obj_set_style_bg_color(objects.tabs_1, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_invalidate(objects.main);
    lv_obj_invalidate(objects.eg);
    lv_obj_invalidate(objects.load_file);
    lv_obj_invalidate(objects.sites);
    lv_obj_invalidate(objects.fg);
    lv_obj_invalidate(objects.graph);
    lv_obj_invalidate(objects.table);
    lv_obj_invalidate(objects.new_file);
    lv_obj_invalidate(objects.numin_dist);
}

uint32_t theme_colors[3][10] = {
    { 0xff8bd600, 0xffc800ff, 0xffe100ff, 0xfffb00ff, 0xffff00d0, 0xffff00a2, 0xff144314, 0xfffb00ff, 0xffff00dd, 0xff4d804d },
    { 0xfffffaf4, 0xffc4ebd0, 0xffd1e2f2, 0xffffecd2, 0xfff4cec3, 0xffddd9d6, 0xff464646, 0xff01d17c, 0xffff6264, 0xff4365e2 },
    { 0xffffffff, 0xffc4ebd0, 0xffd1e2f2, 0xffffecd2, 0xfff4cec3, 0xff7d7d78, 0xff464646, 0xff01d17c, 0xffff6264, 0xff000000 },
};


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_eg,
    tick_screen_load_file,
    tick_screen_sites,
    tick_screen_fg,
    tick_screen_graph,
    tick_screen_table,
    tick_screen_new_file,
    tick_screen_numin_dist,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_eg();
    create_screen_load_file();
    create_screen_sites();
    create_screen_fg();
    create_screen_graph();
    create_screen_table();
    create_screen_new_file();
    create_screen_numin_dist();
}
