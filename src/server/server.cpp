#include <ctime>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

namespace {
	using MsgTypePtr = std::shared_ptr<std::string>;

	const auto PORT = 3333;
	const auto RECV_BUFSIZE = 1024;
} // private namespace

std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;
	time_t now = time(0);
	return ctime(&now);
}

class UdpServer
{
public:
	UdpServer(boost::asio::io_context& io_context)
		: m_socket(io_context, udp::endpoint(udp::v4(), PORT))
	{
		do_receive();
	}

private:
	void do_receive()
	{
		auto recv_handler = [this](const boost::system::error_code& err, std::size_t bytes_recvd)
		{
			if (!err && bytes_recvd > 0)
			{
				std::string msg(m_recv_buffer.begin(), m_recv_buffer.begin() + bytes_recvd);
				std::cout << "received: " << msg << std::endl;
				do_send(bytes_recvd);
			}
			else
			{
				do_receive();
			}
		};
		m_socket.async_receive_from( boost::asio::buffer(m_recv_buffer), m_remote_endpoint, recv_handler);
	}

	void do_send(std::size_t length)
	{
		MsgTypePtr message(new std::string(make_daytime_string()));
		auto send_handler = [this, message](const boost::system::error_code& err, std::size_t bytes) 
		{ 
			do_receive();
		};
		m_socket.async_send_to(boost::asio::buffer(*message), m_remote_endpoint, send_handler);
	}

	udp::socket m_socket;
	udp::endpoint m_remote_endpoint;
	std::array<char, RECV_BUFSIZE> m_recv_buffer;
};

void run_server( volatile bool& isRun )
{
	try
	{
		boost::asio::io_context io_context;
		UdpServer server(io_context);
		
		//io_context.run();
		while ( isRun ) {
			io_context.run_one();
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}