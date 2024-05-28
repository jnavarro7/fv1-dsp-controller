# THIS FILE IS AUTOMATICALLY GENERATED
# Project: Z:\Electronics Win7\PSoC projects\FV-1 Controller\fv1_controller.cydsn\fv1_controller.cyprj
# Date: Tue, 04 Apr 2017 04:28:52 GMT
#set_units -time ns
create_clock -name {ADC_intClock(FFB)} -period 375 -waveform {0 187.5} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 19} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for Z:\Electronics Win7\PSoC projects\FV-1 Controller\fv1_controller.cydsn\TopDesign\TopDesign.cysch
# Project: Z:\Electronics Win7\PSoC projects\FV-1 Controller\fv1_controller.cydsn\fv1_controller.cyprj
# Date: Tue, 04 Apr 2017 04:28:47 GMT