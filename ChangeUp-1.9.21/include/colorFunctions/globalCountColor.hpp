#include "main.h"
using namespace okapi;

extern int ballCount;
extern int filterCount;
extern bool ballIn();
extern bool ballOut();
extern bool ballFiltering();

void ballCountTask();
void filterCountTask();