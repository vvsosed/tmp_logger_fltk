#include "main_window.h"
#include "server.h"

#include <thread>
#include <string>
#include <sstream>
#include <iostream>
#include <chrono>
#include <map>

namespace {
	struct IdleContext {
		FutureType timeFuture;
		MainWindow* window;
	};

	std::map<decltype(TempMsg::id), decltype(TempMsg::temp_cels)> sensIdToTemp;
} // unnamed namespace

void idleClbk(IdleContext* context ) {
	auto& timeFuture = context->timeFuture;
	if (timeFuture.valid())
	{
		auto status = timeFuture.wait_for(std::chrono::milliseconds(1));
		if (status == std::future_status::ready) {
			auto msg = timeFuture.get();
			sensIdToTemp[msg.id] = msg.temp_cels;
			std::stringstream ss;
			ss << "id=" << msg.id << " t=" << msg.temp_cels << std::endl;
			context->window->setLabel(ss.str().c_str());
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