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


static int vtx_toggle::custom_command(int argc, char * argv[]) {
	// do the thingy mabob
}



