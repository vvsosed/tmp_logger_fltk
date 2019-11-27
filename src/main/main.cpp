#include "main.h"
#include "server.h"

#include <thread>
#include <string>
#include <iostream>
#include <chrono>

struct IdleContext {
	std::future<std::string> timeFuture;
	Fl_Group* infoLabel;
};

void idleClbk(IdleContext* context ) {
	auto& timeFuture = context->timeFuture;
	if (timeFuture.valid())
	{
		auto status = timeFuture.wait_for(std::chrono::milliseconds(1));
		if (status == std::future_status::ready) {
			auto msg = timeFuture.get();
			std::cout << "main: " << msg << std::endl;
			context->infoLabel->copy_label(msg.c_str());
			timeFuture = getTimeString();
		}
	}
}

int main(int argc, char**argv) {
    Fl_Window* window = make_window();
		window->end();

		//Fl::lock();
		window->show(argc, argv);

		bool isRun = true;

		std::thread serverThread([&isRun]() { run_server(isRun); });
		IdleContext idleCtx;
		idleCtx.infoLabel = infoLabel;
		idleCtx.timeFuture = getTimeString();
		Fl::add_idle(reinterpret_cast<Fl_Idle_Handler>(idleClbk), &idleCtx);
		
		int res = Fl::run();
		isRun = false;
		serverThread.join();
		
		return res;
}