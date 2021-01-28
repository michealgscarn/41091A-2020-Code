/*-----------------------------------------------------------------------------
  __  __         _
 |  \/  |  __ _ (_) _ __
 | |\/| | / _` || || '_ \
 | |  | || (_| || || | | |
 |_|  |_| \__,_||_||_| |_|

Created on 7/14/2020 by Logan and Taylor
Last Updated on 1/28/2021 by Logan

-----------------------------------------------------------------------------*/

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * You should add more #includes here
 */
#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include "subsystems/lift.hpp"
#include "subsystems/intake.hpp"
#include "subsystems/globals.hpp"
#include "subsystems/delivery.hpp"
#include "subsystems/drivetrain.hpp"
#include "autonomousFunctions/scoring.hpp"
#include "autonomousFunctions/autoSelector.hpp"
#include "autonomousFunctions/OdomDrive.hpp"
#include "brainAttributes/brainButtons.hpp" //older vex display
#include "brainAttributes/brainDisplay.hpp" //older vex display
//#include "legacyDisplay/dwightImage.h" //image file for dwight schrute
#include "autonomousPrograms/A-HMC-HRC.hpp"
#include "autonomousPrograms/A-MMF-HLC.hpp"
#include "autonomousPrograms/A-HMC-HLC-MM1.hpp"
#include "autonomousPrograms/A-HRC-HMC-HLC.hpp"
#include "autonomousPrograms/A-SKILLS-BROKEN-ARM-DISTANCE-FILTER.hpp"
#include "autonomousPrograms/A-SKILLS-BROKEN-ARM-DISTANCE-FILTER-IGNITE.hpp"
#include "autonomousPrograms/A-SKILLS-JANUARY.hpp"
#include "odomDebug/odomDebug.hpp"
#include "odomPosition/odomPosition.hpp"
#include "odomPosition/quickAlign.hpp"
#include "odomPosition/resetOdom.hpp"
#include "odomPosition/wallAlign.hpp"
#include "colorFunctions/checkColor.hpp"
#include "colorFunctions/filterColor.hpp"
#include "colorFunctions/globalCountColor.hpp"
#include "controllerAttributes/controllerSelect.hpp"
#include "controllerAttributes/controllerButtons.hpp"

#include "pros/apix.h"  //LVGLs


//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
