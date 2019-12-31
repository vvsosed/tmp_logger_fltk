#include "main_window.h"
#include "server.h"

#include <thread>
#include <string>
#include <iostream>
#include <chrono>

struct IdleContext {
	std::future<std::string> timeFuture;
	MainWindow *window;
};

void idleClbk(IdleContext* context ) {
	auto& timeFuture = context->timeFuture;
	if (timeFuture.valid())
	{
		auto status = timeFuture.wait_for(std::chrono::milliseconds(1));
		if (status == std::future_status::ready) {
			auto msg = timeFuture.get();
			std::cout << "main: " << msg << std::endl;
			context->window->setLabel(msg.c_str());
			timeFuture = getTimeString();
		}
	}
}

int main(int argc, char**argv) {
    auto* window = new MainWindow();
		window->end();

		window->show(argc, argv);

		bool isRun = true;

		std::thread serverThread([&isRun]() { run_server(isRun); });
		IdleContext idleCtx;
		idleCtx.window = window;
		idleCtx.timeFuture = getTimeString();
		Fl::add_idle(reinterpret_cast<Fl_Idle_Handler>(idleClbk), &idleCtx);
		
		int res = Fl::run();
		isRun = false;
		serverThread.join();
		
		return res;
}