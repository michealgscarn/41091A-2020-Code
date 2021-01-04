/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
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
#include "subsystemHeaders/lift.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/delivery.hpp"
#include "subsystemHeaders/drivetrain.hpp"
#include "autoFunctionsHeaders/strafe.hpp"
#include "autoFunctionsHeaders/scoring.hpp"
#include "autoFunctionsHeaders/autoSelector.hpp"
#include "autoFunctionsHeaders/holonomicFunctions.hpp"
#include "autoFunctionsHeaders/fieldCentric.hpp"
#include "autoFunctionsHeaders/OdomDrive.hpp"
#include "legacyDisplay/legacyDisplay.hpp" //older vex display
//#include "legacyDisplay/dwightImage.h" //image file for dwight schrute
#include "autoFunctionsHeaders/A-HMC-HRC.hpp"
#include "autoFunctionsHeaders/A-HMC-HLC.hpp"
#include "autoFunctionsHeaders/A-HLC-MM1.hpp"
#include "autoFunctionsHeaders/A-MMF-HL1.hpp"
#include "autoFunctionsHeaders/A-HRC-MM1.hpp"
#include "autoFunctionsHeaders/A-HRF.hpp"
#include "autoFunctionsHeaders/A-HLF-MM1.hpp"
#include "autoFunctionsHeaders/A-HMP-HLC-MM1.hpp"
#include "autoFunctionsHeaders/A-HMP-HLC-MM1-I.hpp"
#include "autoFunctionsHeaders/A-HMC-HLC-MM1.hpp"
#include "autoFunctionsHeaders/A-HMP-HLC-HRC.hpp"
#include "autoFunctionsHeaders/A-SKILLS.hpp"
#include "autoFunctionsHeaders/A-SKILLS-2.hpp"
#include "autoFunctionsHeaders/A-SKILLS-FINALE.hpp"
#include "autoFunctionsHeaders/A-SKILLS-FINALE-PART2.hpp"
#include "autoFunctionsHeaders/A-SKILLS-SEQUEL.hpp"
#include "autoFunctionsHeaders/A-SKILLS-SPINOFF.hpp"
#include "autoFunctionsHeaders/A-SKILLS-SPINOFF-SEQUEL.hpp"
#include "autoFunctionsHeaders/A-SKILLS-BROKEN-ARM.hpp"
#include "autoFunctionsHeaders/A-SKILLS-BROKEN-ARM-DISTANCE.hpp"
#include "autoFunctionsHeaders/A-SKILLS-BROKEN-ARM-DISTANCE-FILTER.hpp"
#include "odomDebug/odomDebug.hpp"
#include "odomPosition/odomPosition.hpp"
#include "odomPosition/wallAlign.hpp"
#include "colorFunctions/checkColor.hpp"
#include "colorFunctions/filterColor.hpp"
#include "colorFunctions/globalCountColor.hpp"

#include "pros/apix.h"  //LVGLs


//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
