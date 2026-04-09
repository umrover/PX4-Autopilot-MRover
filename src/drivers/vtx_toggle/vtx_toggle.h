#pragma once

#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/getopt.h>
#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <px4_platform_common/px4_work_queue/ScheduledWorkItem.hpp>
#include <uORB/Publication.hpp>
#include <uORB/SubscriptionInterval.hpp>
// #include <uORB/topics/heater_status.h>
#include <uORB/topics/parameter_update.h>
#include <uORB/topics/sensor_accel.h>

#include <mathlib/mathlib.h>

using namespace time_literals;

// note we will use GPIO in particular to access pins direct

class vtx_toggle : public ModuleBase<vtx_toggle>, public ModuleParams
{
public:
	// default
	vtx_toggle();

	// default
	virtual ~vtx_toggle();

	// See the base class for custom command
	// Should handle the command line args
	static int custom_command(int argc, char * argv[]);


private:
	// call up there ^
	void initialize();

	// disable the VTX through GPIO - SPECIFIC
	void vtx_disable();

	// turn on the VTX - GPIO
	void vtx_on();

	// turn off the VTX - GPIO
	void vtx_off();


};
