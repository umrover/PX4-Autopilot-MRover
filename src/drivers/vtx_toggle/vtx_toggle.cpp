#include "vtx_toggle.h"

#include <px4_platform_common/getopt.h>
#include <px4_platform_common/log.h>
#include <drivers/drv_hrt.h>
#include <drivers/drv_io_heater.h>

#if defined(BOARD_USES_PX4IO_VERSION) and defined(PX4IO_HEATER_ENABLED)
// Heater on some boards is on IO MCU
// Use ioctl calls to IO driver to turn heater on/off
#  define HEATER_PX4IO
#else
// Use direct calls to turn GPIO pin on/off
#  ifndef GPIO_HEATER_OUTPUT
#  error "To use the heater driver, the board_config.h must define and initialize GPIO_HEATER_OUTPUT"
#  endif
#  define HEATER_GPIO
#endif

vtx_toggle::vtx_toggle() {}

virtual vtx_toggle::

//Sets the vtx state (on, off) using a commandline input
static int vtx_toggle::custom_command(int argc, char * argv[]) {
	if (argc > 0 && strcmp("toggle", argv[0] == 0)){
		if(argc == 1){
			PX4_INFO("Provide input to toggle on or off")
		} else if (strcmp("on", argv[1]) == 0){
			vtx_on();
		} else if (strcmp("off", argv[1] == 0)){
			vtx_off();
		} else{
			PX4_INFO("invalid input, please turn vtx on or off");
		}
	}
	else {
		PX4_INFO("Invalid Command");
	}

}

void vtx_toggle::vtx_on() {
	VTX_TOGGLE_OUTPUT_EN(false); // Turns on BEC
}
void vtx_toggle::vtx_off() {
	VTX_TOGGLE_OUTPUT_EN(true); // Turns off BEC
}
void vtx_toggle::initialize() {
	// initialize the GPIO pin to output and set it to off
	px4_arch_configgpio(GPIO_VTX_TOGGLE_OUTPUT);
	vtx_off();
}

vtx_toggle::~vtx_toggle() {
	// make sure to turn off the VTX when exiting
	vtx_off();
}
