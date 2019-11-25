#include "main.h"

int main(int argc, char**argv) {
    Fl_Window* window = make_window();
		window->end();
		window->show(argc, argv);
		return Fl::run();
}