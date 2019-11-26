#include "main.h"
#include "server.h"

#include <thread>

int main(int argc, char**argv) {
    Fl_Window* window = make_window();
		window->end();
		window->show(argc, argv);

		bool isRun;

		std::thread serverThread([&isRun]() { run_server(isRun); });
		
		auto res = Fl::run();
		
		isRun = false;
		serverThread.join();
		
		return res;
}