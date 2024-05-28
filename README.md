# fv1-dsp-controller
 A way of controlling Spin Semiconductor's FV-1 DSP using a Cypress PSoC 4 (CY8C4245AXI-483). 

 ## PSoC creator project

 In the "psoc_creator_project" directory you will find the project used to program the PSoC 4. 

 main.c has the main logic of how this works, basically it reads an analog potentiometer which translates to DSP program selection and an indication to the user via LEDs.  

 ![](/doc/IMG_0530%20Large.jpeg)


 ## Board directory

This directory includes an snippet of the schematic capture for the PSoC 4 

![fv-1 control](/doc/IMG_0531%20Large.jpeg)

![programming header](/doc/programming_header.jpeg)

## Use example on a prototype 

Use of this method in a prototype fx pedal 

![prototype2](/doc/prototype.GIF)
![board](/doc/board.GIF)
¡
## FV-1 info

http://www.spinsemi.com/Products/datasheets/spn1001/FV-1.pdf

## License 

Released under the Creative Commons Attribution 4.0 License
https://creativecommons.org/licenses/by/4.0/