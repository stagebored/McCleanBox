#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: tile
//

void init_style_tile_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_layout(style, LV_LAYOUT_GRID);
    {
        static lv_coord_t dsc[] = {50, 87, 50, LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_row_dsc_array(style, dsc);
    }
    {
        static lv_coord_t dsc[] = {115, 100, LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_column_dsc_array(style, dsc);
    }
    lv_style_set_grid_column_align(style, LV_GRID_ALIGN_CENTER);
    lv_style_set_grid_row_align(style, LV_GRID_ALIGN_CENTER);
    lv_style_set_grid_cell_x_align(style, LV_GRID_ALIGN_CENTER);
    lv_style_set_grid_cell_y_align(style, LV_GRID_ALIGN_CENTER);
};

lv_style_t *get_style_tile_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tile_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tile(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tile_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tile(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tile_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: s_button
//

void init_style_s_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &lv_font_montserrat_14);
    lv_style_set_text_letter_space(style, 0);
    lv_style_set_text_line_space(style, 0);
    lv_style_set_radius(style, 2);
    lv_style_set_align(style, LV_ALIGN_CENTER);
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_border_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_border_width(style, 1);
};

lv_style_t *get_style_s_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_s_button_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_s_button_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][9]));
};

lv_style_t *get_style_s_button_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_s_button_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_s_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_s_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_s_button_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_s_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_s_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_s_button_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: label_button
//

void init_style_label_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 5);
    lv_style_set_pad_left(style, 5);
};

lv_style_t *get_style_label_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: label_values
//

void init_style_label_values_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_text_font(style, &lv_font_montserrat_24);
};

lv_style_t *get_style_label_values_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_values_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_values(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_values_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_values(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_values_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: label_topbar
//

void init_style_label_topbar_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_outline_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_outline_width(style, 1);
    lv_style_set_text_font(style, &lv_font_montserrat_12);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][9]));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_label_topbar_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_topbar_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_topbar(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_topbar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_topbar(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_topbar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: chart
//

void init_style_chart_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_border_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_border_opa(style, 255);
    lv_style_set_border_width(style, 1);
    lv_style_set_line_width(style, 0);
    lv_style_set_radius(style, 2);
    lv_style_set_pad_top(style, 2);
    lv_style_set_pad_bottom(style, 2);
    lv_style_set_pad_left(style, 2);
    lv_style_set_pad_right(style, 2);
    lv_style_set_pad_row(style, 2);
    lv_style_set_pad_column(style, 2);
    lv_style_set_line_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
};

lv_style_t *get_style_chart_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_chart_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_chart(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_chart_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_chart(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_chart_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: textbox
//

void init_style_textbox_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_border_width(style, 0);
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_text_font(style, &lv_font_montserrat_14);
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
};

lv_style_t *get_style_textbox_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_textbox_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_textbox(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_textbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_textbox(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_textbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: tabview
//

void init_style_tabview_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
};

lv_style_t *get_style_tabview_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tabview_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tabview(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tabview_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tabview(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tabview_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: tabbar
//

void init_style_tabbar_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_margin_top(style, 0);
    lv_style_set_margin_bottom(style, 0);
    lv_style_set_margin_left(style, 0);
    lv_style_set_margin_right(style, 0);
    lv_style_set_pad_column(style, 10);
    lv_style_set_pad_row(style, 10);
};

lv_style_t *get_style_tabbar_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tabbar_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tabbar(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tabbar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tabbar(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tabbar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: tabcontent
//

void init_style_tabcontent_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_margin_top(style, 0);
    lv_style_set_margin_bottom(style, 0);
    lv_style_set_margin_left(style, 0);
    lv_style_set_margin_right(style, 0);
    lv_style_set_pad_column(style, 10);
    lv_style_set_pad_row(style, 10);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_top(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
};

lv_style_t *get_style_tabcontent_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tabcontent_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tabcontent(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tabcontent_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tabcontent(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tabcontent_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: kbtextarea
//

void init_style_kbtextarea_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_border_width(style, 1);
    lv_style_set_border_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_margin_top(style, 0);
    lv_style_set_margin_bottom(style, 0);
    lv_style_set_margin_left(style, 0);
    lv_style_set_margin_right(style, 0);
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_kbtextarea_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_kbtextarea_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_kbtextarea(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_kbtextarea_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_kbtextarea(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_kbtextarea_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: dropdown
//

void init_style_dropdown_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][6]));
    lv_style_set_text_font(style, &lv_font_montserrat_12);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_border_width(style, 0);
};

lv_style_t *get_style_dropdown_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_dropdown_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_dropdown(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_dropdown_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_dropdown(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_dropdown_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: checkbox
//

void init_style_checkbox_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_text_font(style, &lv_font_montserrat_12);
};

lv_style_t *get_style_checkbox_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_checkbox_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_border_width(style, 0);
};

lv_style_t *get_style_checkbox_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_checkbox(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_checkbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_checkbox_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_checkbox(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_checkbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_checkbox_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
// Style: slider
//

void add_style_slider(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_slider(lv_obj_t *obj) {
    (void)obj;
};

//
// Style: roller
//

void init_style_roller_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_BOTTOM_MID);
};

lv_style_t *get_style_roller_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_roller_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_roller(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_roller_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_roller(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_roller_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_tile,
        add_style_s_button,
        add_style_label_button,
        add_style_label_values,
        add_style_label_topbar,
        add_style_chart,
        add_style_textbox,
        add_style_tabview,
        add_style_tabbar,
        add_style_tabcontent,
        add_style_kbtextarea,
        add_style_dropdown,
        add_style_checkbox,
        add_style_slider,
        add_style_roller,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_tile,
        remove_style_s_button,
        remove_style_label_button,
        remove_style_label_values,
        remove_style_label_topbar,
        remove_style_chart,
        remove_style_textbox,
        remove_style_tabview,
        remove_style_tabbar,
        remove_style_tabcontent,
        remove_style_kbtextarea,
        remove_style_dropdown,
        remove_style_checkbox,
        remove_style_slider,
        remove_style_roller,
    };
    remove_style_funcs[styleIndex](obj);
}

