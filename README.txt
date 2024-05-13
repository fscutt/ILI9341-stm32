FINLAY SCUTT ILI9341 stm32 library

This library uses 8080-parallel interface, for this 12 pins need to be initialised
4 command pins set to GPIO-Output labeled CS,CD,WR,RD
8 data lines set to GPIO-Output labeled DATA0-7

functions with the prefix "draw" can be used to draw to any location

for rendering the UI
first use "setSetting" functions to set setting values
then use "render" functions to render the names and values of the settings 
finally use "print" functions to draw the rendered ui to the display

each setting represents a physical dial and has a name, value, and type
the name is a string
the value can be any float within range of the type
the type can be INT,FREQ,PERC,DB,MULTI depending on the setting type it represents in ableton
