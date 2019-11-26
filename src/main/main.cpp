#include "main.h"
#include "server.h"

#include <thread>
#include <string>
#include <iostream>
#include <chrono>

void idleClbk(std::future<std::string> *future ) {
	auto& timeFuture = *future;
	if (timeFuture.valid())
	{
		auto status = timeFuture.wait_for(std::chrono::milliseconds(1));
		if (status == std::future_status::ready) {
			auto msg = timeFuture.get();
			std::cout << "main: " << msg << std::endl;
			timeFuture = getTimeString();
		}
	}
}

int main(int argc, char**argv) {
    Fl_Window* window = make_window();
		window->end();

		//Fl::lock();
		window->show(argc, argv);

		bool isRun;

		std::thread serverThread([&isRun]() { run_server(isRun); });
		auto timeFuture = getTimeString();
		Fl::add_idle(reinterpret_cast<Fl_Idle_Handler>(idleClbk), &timeFuture);
		
		int res = Fl::run();
		isRun = false;
		serverThread.join();
		
		return res;
}