#include "main.h"
using namespace okapi;

extern bool isCycleScoreSetup;
void cycleScoreSetup();

extern bool filter;
extern int startTime;
void cycleScoreFilter();
void cycleScoreNoIntake(int cycleBall,double cycleTime, int startBallCount);
void cycleScore(int cycleBall,double cycleTime, int startBallCount);
