#include "main.h"

extern int posC; //Current position of each selection

extern int posP; //Previous position of each selection

extern int lineC; //Current line of order

extern int lineP; //Line Backup

extern bool Blink;

void updatePage(std::string selC[]);

void blinkTimer();

void contDisplay();
extern std::string autoSel;

extern std::string lineM[]; //Total line memory
extern std::string page; //Current Page
void centerText(std::string str);
extern std::string odomDetails;
extern std::string trackLeft;
extern std::string trackMiddle;
extern std::string trackRight;
