/*
  A callback function for LLEMU's center button.

 When this callback is fired, it will toggle line 2 of the LCD text between
  "I was pressed!" and nothing.
  This is a nice testing function for when the screen seems locked up.
 */
void on_center_button() {
    	static bool pressed = false;
    	pressed = !pressed;

    	if (pressed) {
    		  pros::lcd::set_text(2, "I was pressed!");
    	} else {
    		  pros::lcd::clear_line(2);
    	}
}
