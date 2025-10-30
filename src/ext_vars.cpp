#include <stdint.h>
#include "src/ext_vars.h"
#include "src/ui/vars.h"
#include <string>

std::string gtimerv;
extern "C" const char *get_var_gtimerv() {
    return gtimerv.c_str();}
extern "C" void set_var_gtimerv(const char *value) { gtimerv = value; }

std::string rotcount;
extern "C" const char *get_var_rotcount() {
    return rotcount.c_str();}
extern "C" void set_var_rotcount(const char *value) { rotcount = value; }


std::string prevresults;
extern "C" const char *get_var_prevresults() {
    return prevresults.c_str();}
extern "C" void set_var_prevresults(const char *value) {
    prevresults = value;}
void add_var_prevresults(const char *value) {
    prevresults += value;}

std::string time;
extern "C" const char *get_var_time() {
    return time.c_str();}
extern "C" void set_var_time(const char *value) {
    time = value;}

std::string infobox;
extern "C" const char *get_var_infobox() {
    return infobox.c_str();}
extern "C" void set_var_infobox(const char *value) {
    infobox = value;}
void add_var_infobox(const char *value) {
    infobox =+ value;}

