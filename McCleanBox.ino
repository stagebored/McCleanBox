#include <lvgl.h>
#include <Arduino.h>
#include <M5Unified.h>
#include <esp_timer.h>
#include <string>
#include "src/ui/LVGLHelper.h"
#include "src/ui/ui.h"
#include "src/ui_actions.h"
#include "src/ext_vars.h"
#include "src/ui/vars.h"
#include "src/ext_vars.h"
//#include "src/MBsettings.h"
#include "src/file.h"

m5::rtc_datetime_t dt;
static constexpr const char* const wd[] = {"Sun","Mon","Tue","Wed","Thr","Fri","Sat","ERR"};

int inPin = 27;
int cnt = 0;
const int debounceTime = 20;  // debounce in milliseconds
volatile boolean rotated = false;
bool timeron = false;
int32_t currentMillis = millis();
int32_t startMillis = millis();
int32_t previousMillis = millis();
int32_t TpreviousMillis = millis();


void improt() {
   rotated = true;
}

//maybe move to UI actions
void gtimer() {
  timeron = true;
  currentMillis = millis();
  startMillis = millis();
  previousMillis = millis();
  cnt = 0;
  set_var_rotcount("000");  
  set_var_gtimerv("00.0");
}

void deBounce () //debounce function borrowed from http://gammon.com.au/interrupts
{
  unsigned long now = millis ();
  do
  {
    // on bounce, reset time-out
    if (digitalRead (inPin) == LOW)
      now = millis ();
  } 
  while (digitalRead (inPin) == LOW ||
    (millis () - now) <= debounceTime);
}  // end of deBounce



void setup()
{
  M5.begin();
  ///fix this
  if (M5.Rtc.isEnabled()) { M5.Rtc.setDateTime( {{ 2021, 12, 31 }, { 12, 34, 56 }} );}
  pinMode(27,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(27),improt,CHANGE);
  Serial.begin( 115200 );
  M5.Display.setBrightness(128);
  M5.Display.startWrite();
  M5.Display.println("M5 Tough");
  Serial.println("M5 Tough");
  lvgl_init();
  newfile();
  if (M5.Rtc.isEnabled()) {
    M5.Rtc.getDateTime(&dt);
    char tm[5];
    sprintf(tm, "%02d:%02d", dt.time.hours,dt.time.minutes);
    set_var_time(tm);
    if (M5.Rtc.getDateTime(&dt)) { /*
      char dt[32];
      snprintf( dt, 30, "%04d/%02d/%02d(%s)"
                  , dt.date.year
                  , dt.date.month
                  , dt.date.date
                  , wd[dt.date.weekDay & 7]
                  ); 
      set_var_infobox(dt);
      add_var_infobox("\n"); */
    }
  }
  else { add_var_infobox("rtc err"); }
  add_var_infobox("add software version info\n");
  add_var_infobox("add impeller info\n");
  add_var_infobox("add timer info\n");
  Serial.println( "Setup done" ); 
}

void loop()
{
   vTaskDelay(1);
   lv_task_handler();
   if (rotated == true) {
     deBounce ();
     cnt++;
     rotated = false;
     if (timeron == true) { 
       char cto_lv[5];
       sprintf(cto_lv, "%03d", cnt);
       //Serial.println(to_lv);  
       set_var_rotcount(cto_lv);
      }
   }
   currentMillis = millis();
   if (timeron == true) {
     if (currentMillis - startMillis >= 10000) {
       float td = ((currentMillis - startMillis)*0.001);
       char to_lv[5];
       sprintf(to_lv, "%04.1f", td);
       //Serial.println(to_lv);       
       set_var_gtimerv(to_lv);
       timeron = false;
       add_var_prevresults (to_lv);
       add_var_prevresults ("s ");
       char cto_lv[5];
       sprintf(cto_lv, "%03d", cnt);
       add_var_prevresults (cto_lv);
       add_var_prevresults ("r ");
       add_var_prevresults ("\n");
      }
     if (currentMillis - previousMillis >= 99) { 
       float td = ((currentMillis - startMillis)*0.001);
       char to_lv[5];
       sprintf(to_lv, "%04.1f", td);   
       set_var_gtimerv(to_lv);
       previousMillis = currentMillis;
      }
      
    }   
    ui_tick();
    if (currentMillis - TpreviousMillis >= 350) {     
      M5.Rtc.getDateTime(&dt);
      char tm[5];
      sprintf(tm, "%02d:%02d", dt.time.hours,dt.time.minutes);
      set_var_time(tm);
      TpreviousMillis = currentMillis;
    }

}


/*
Serial.print(F("- int ram tot: "));
Serial.println(ESP.getHeapSize());
Serial.print(F("- int ram left: "));
Serial.println(ESP.getFreeHeap());
Serial.print(F("- spi ram tot: "));
Serial.println(ESP.getPsramSize());
Serial.print(F("- spi ram left: "));
Serial.println(ESP.getFreePsram());*/
