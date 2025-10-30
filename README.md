# McCleanBox
- blame: f.leask@dundee.ac.uk

## M5 Tough based counter box for impeller river gauging kits. 
- Still very much a work in progress
- Basic: Timed Counter only
- Full: River flow computation & basic analysis.
- Can possibly be used for certain field notes (if I do things).
- Also possibly an anemometer?

<img width="578" height="435" alt="Screenshot 2025-10-30 at 11 54 06" src="https://github.com/user-attachments/assets/71762f41-f159-4026-94f3-fc3779e51b42" />
Various screens and themes. 

### Background

This project started off as an idea revitalise / make impeller gauging kit for minimal cost for UoD. Initially it was a timer and counter board - this didn't work because the timer switched the negative circuit. By the time I had acquired a relay to fix it I had also bought an M5 Tough and started making a UI and program in UiFlow 2. At the same time with a bit of TLC I had got some old gauging kit working (one dating from 1974!) for an upcoming field trip, and while there was no longer a need for this project at work I continued working on it in my own time, alongside a related project to make a DIY impeller from off the shelf parts - the main ones being a reed switch and an RC boat prop. 
<br>
<br>
This project, the <i>McClean-o-Tron</i> got to a semi working stage before I got frustrated and started again writing it directly in micropython. The second iteration had enough functionality to measure flow, take distance and depth inputs and produce a flow value but was very laggy, and I was frustrated with micropython and m5ui. I looked at (and failed to get working) various options before settling upon Arduino IDE with lvgl. This fresh start was given named the <i>McClean Box</i>, a reference to pioneer in the field William Newsam McClean and my youthful fascination with blue boxes and other assorted phone hacking devices. 
<br>
<br>
I'm absolutely not a programmer, so any constructive comments about what I'm doing wrong are very much appreciated. On the other hand I have spent almost 20 years standing in rivers using varuious gauging kits and a lot of the inspiration for this project has come from that experience. I have found modern gauging kits to be very capable, but their UI's to be slightly frustrating, and I hope to fix as many of those frustrations as i can in this project. 
<br>
<br>
This is a personal project only tangentially related to my work at UoD, and is not an officialy sanctioned UoD project. 

### Captain McClean

<i>
W. N. McClean was a pioneer in the development and publication of river flow measurements in Scotland using current metering and chart recorders to produce runoff records for the River Garry, 1913–1915. In 1929 McClean began to establish a much more extensive hydrometric network comprising rainfall and
runoff stations throughout the Ness, Lochy, Spey and Aberdeenshire Dee basins. 
<br>
<br>
This work was pursued with remarkable vigour until 1949 and was partly instrumental in establishing the UK Inland Water Survey in 1935. The flow record on the Dee commenced in 1929 and, still operational today, is one of the longest continuous runoff records in the UK. McClean’s data were collected at a time when many of the catchments were little modified by human interventions. They constitute a unique record of the natural runoff regime for this part of the British uplands and include two of the largest UK floods ever reported.
</i>
<br>
<sub>
Alan Werritty & Andrew Black (18 Dec 2024): W. N. McClean – pioneer of Scottish hydrometry <br>
https://discovery.dundee.ac.uk/ws/portalfiles/portal/142939056/W._N._McClean_pioneer_of_Scottish_hydrometry.pdf<br>
Hydrological Sciences Journal, DOI: 10.1080/02626667.2024.2435537
</sub>

# Dev Info


### potentially working functions
- recording rotations over time (time check needed)
- clock display (clock setting needed, date not working)
- some of the ui

### todo
- ui disable scrolling (almost) globally
- ui sort formatting of tabs
- skip count check (does it miss counts when busy?)
- set clock (ideally w/ wifi NTP)
- velocity calculation
- depth  
- distance input 
- flow calculation (mid section)
- flow calculation (mean section)
- gauging sites 
- data structure (list/JSON?)
- insert point 
- move between points 
- verticals other than 0.4
- field testing 
- inclement weather testing
- delete points
- file saving
- settings [ui / kit / calculation]
- distance polarity check (in ui)
- table view
- graphs
- monospace font
- multi threading... am i? can i? should i?
- stress testing / optimisation / checking for bodges, nonsense, leftovers from testing
- license
- working with physical keypad
- method for getting files off (USB mass storage?)

### wish list
- alt UI for stupid cold wet fingers
- allow recording of stage values, possibly logger download, rain gauge, site survey etc. 
- translation
- imperial units
- working on other Arduino/pi devices (separate UI from function)
- custom rugged device
- DIY impeller finished (separate project)
- Calibration mode
- reverse flow detection(DIY impeller only)
- previous gauging / rating view for sites 
- data syncing 
- working with OEM or custom fancy sensors (such as Electro Magnetic)


### (to be) tested with following impellers
- OTT C-1 (1974)
- OTT C-1 (later)
- OTT C-31 
- Valeport ???
- M-o-T DIY impeller


### build:
- Arduino IDE
- EEZ Studio 2
- M5Unified
- lvgl 9.4


### may contain traces of, or inspiration from:
- https://github.com/bareboat-necessities/bbn-m5stack-tough
- https://github.com/WhiteBr0wnie-24/EEZ-Studio-Arduino-Starter
- https://fonts.google.com/specimen/Roboto+Mono?lang=en_Latn&categoryFilters=Appearance:%2FMonospace%2FMonospace
- My brain refusing to accept data as a plural. 
- https://github.com/miroslavpetrov/m5core2-interactive-toy/tree/main
- http://gammon.com.au/interrupts
