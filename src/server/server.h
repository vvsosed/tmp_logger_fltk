#pragma once

#include <future>
#include <string>

void run_server( volatile bool& isRun );

std::future<std::string> getTimeString();