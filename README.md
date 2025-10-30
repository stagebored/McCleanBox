# McCleanBox
- blame: f.leask@dundee.ac.uk

## M5 Tough based counter box for impeller river gauging kits. 
- Basic: Timed Counter only
- Full: River flow computation & basic analysis.
- Can possibly be used for certain field notes (if I do things).
- Also possibly ananemometer?

### Background

tbc

### Captain William Newsam McClean

<i>
W. N. McClean was a pioneer in the development and publication of river flow measurements in Scotland using current metering and chart recorders to produce runoff records for the River Garry, 1913–1915. In 1929 McClean began to establish a much more extensive hydrometric network comprising rainfall and
runoff stations throughout the Ness, Lochy, Spey and Aberdeenshire Dee basins. /n
/n
This work was pursued with remarkable vigour until 1949 and was partly instrumental in establishing the UK Inland Water Survey in 1935. The flow record on the Dee commenced in 1929 and, still operational today, is one of the longest continuous runoff records in the UK. McClean’s data were collected at a time when many of the catchments were little modified by human interventions. They constitute a unique record of the natural runoff regime for this part of the British uplands and include two of the largest UK floods ever reported.
</i>
/n
<sub>- Alan Werritty & Andrew Black (18 Dec 2024): W. N. McClean – pioneer of
Scottish hydrometry
Hydrological Sciences Journal, DOI: 10.1080/02626667.2024.2435537
https://discovery.dundee.ac.uk/ws/portalfiles/portal/142939056/W._N._McClean_pioneer_of_Scottish_hydrometry.pdf</sub>

### potentially working functions
 -recording rotations over time (time check needed)
 -clock display (clock setting needed, date not working)
 -some of the ui

### todo
-ui disable scrolling (almost) globally
-ui sort formatting of tabs
-skip count check (does it miss counts when busy?)
-set clock (ideally w/ wifi NTP)
-velocity calculation
-depth  
-distance input 
-flow calculation (mid section)
-flow calculation (mean section)
-gauging sites 
-data structure (list/JSON?)
-insert point 
-move between points 
-verticals other than 0.4
-field testing 
-inclement weather testing
-delete points
-file saving
-settings [ui / kit / calculation]
-distance polarity check (in ui)
-table view
-graphs
-monospace font
-stress testing / optimisation / checking for bodges, nonsense, leftovers from testing
-license
-working with physical keypad
-method for getting files off (USB mass storage?)

### wish list
-alt UI for stupid cold wet fingers
-allow recording of stage values, possibly logger download, rain gauge, site survey etc. 
-translation
-imperial units
-working on other arduino/pi devices (seperate UI from function)
-custom rugged device
-DIY impeller finished (seperate project)
-Calibration mode
-reverse flow detection(DIY impeller only)
-previous gauging / rating view for sites 
-data syncing 
-working with OEM or custom fancy sensors (such as Electro Magnetic)


### tested with following impellers
- OTT C-1 (1974)
- OTT C-1 (later)
- OTT C-31 
- Valeport ???
- M-o-T DIY impeller


### build:
- via arduino IDE
- via EEZ Stuidi 2
- M5Unified
- lvgl 9.4


### may contain traces of:
- https://github.com/bareboat-necessities/bbn-m5stack-tough
- https://github.com/WhiteBr0wnie-24/EEZ-Studio-Arduino-Starter
- https://fonts.google.com/specimen/Roboto+Mono?lang=en_Latn&categoryFilters=Appearance:%2FMonospace%2FMonospace
- My brain refusing to accept data as a plural. 
- https://github.com/miroslavpetrov/m5core2-interactive-toy/tree/main
- http://gammon.com.au/interrupts



