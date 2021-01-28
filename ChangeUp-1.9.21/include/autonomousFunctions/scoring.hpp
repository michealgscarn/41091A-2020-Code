#include "main.h"
using namespace okapi;

//SCORING FUNCTION
void driveAndScore(int timeBeforeScore,int timeToScore);

void scoreFormation(int cycleBall);

void cycleGoal(std::string alliance, int ballCount);

extern bool filter;
extern int startTime;
void cycleScoreFilter();
void cycleScore(int cycleBall,double timeToScore);
void cycleScoreShort(int cycleBall,double timeToScore);
void cycleScoreSlow(int cycleBall,double timeToScore);
void cycleScoreSlower(int cycleBall,double timeToScore);
