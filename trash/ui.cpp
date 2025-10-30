#include "src/ui/LVGLHelper.h"
#include "src/ui/ui.h"
#include <lvgl.h>

static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    if(code == LV_EVENT_CLICKED) {
        //Serial.println("clicked");

        
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Butt");
    }
}


void ui_init()
{

  lv_obj_t *screen = lv_obj_create(lv_screen_active());
  lv_obj_set_size(screen, 320, 240);
  lv_obj_set_pos(screen, 0, 0);
  lv_obj_set_style_bg_color(screen, lv_color_hex(0x009900), LV_PART_MAIN | LV_STATE_DEFAULT);


  lv_obj_t * btn = lv_button_create(lv_screen_active());    
  lv_obj_set_pos(btn, 10, 10);                            
  lv_obj_set_size(btn, 120, 50);                          
  lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);          

  lv_obj_t * label = lv_label_create(btn);          
  lv_label_set_text(label, "Button");                     
  lv_obj_center(label);
  //Serial.println("ui init2");
}



