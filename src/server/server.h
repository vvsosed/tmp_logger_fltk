#pragma once

#include <future>
#include <string>

#pragma pack(push, 1) 
struct TempMsg {
	std::uint64_t id;
	float temp_cels;
};
#pragma pack(pop)

using PromiseType = std::promise<TempMsg>;
using FutureType = std::future<TempMsg>;

void run_server( volatile bool& isRun );

FutureType getTimeString();