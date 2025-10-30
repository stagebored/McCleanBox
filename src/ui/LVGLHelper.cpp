#include <cstddef>
#include <Arduino.h>
#include <M5Unified.h>
#include <lvgl.h>
#include <esp_timer.h>
#include "src/ui/ui.h"

constexpr int32_t HOR_RES = 320;
constexpr int32_t VER_RES = 240;




lv_display_t *display;
lv_indev_t *indev;

uint32_t my_tick_function() {
  return (esp_timer_get_time() / 1000LL);
}


void flush_cb(lv_display_t *dispp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);
  lv_draw_sw_rgb565_swap(px_map, w * h);
  M5.Display.pushImage<uint16_t>(area->x1, area->y1, w, h, (uint16_t *)px_map);
  lv_disp_flush_ready(dispp);
}

void my_touchpad_read(lv_indev_t *drv, lv_indev_data_t *data) {
  M5.update();
  auto count = M5.Touch.getCount();

  if (count == 0) {
    data->state = LV_INDEV_STATE_RELEASED;
  } else {
    auto touch = M5.Touch.getDetail(0);
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = touch.x;
    data->point.y = touch.y;
  }
}


void lvgl_init() {
 
  lv_init();
  M5.Lcd.setRotation(1);
  lv_tick_set_cb(my_tick_function);
  lv_display_t *dispp = lv_display_create(HOR_RES, VER_RES);
  lv_display_set_flush_cb(dispp, flush_cb);
  
  static uint8_t buf1[(HOR_RES * VER_RES / 10 * (LV_COLOR_DEPTH / 8))];
  lv_display_set_buffers(dispp, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);
  
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);
  
  ui_init();
  Serial.println("screens made");
}
