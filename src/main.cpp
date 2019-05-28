#include <iostream>

#include "Application.h"

int main(void) {
	
	Application app = Application();
	
	int ret_code = app.start();

    return ret_code;
}
