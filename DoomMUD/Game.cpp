#include <boost/program_options.hpp>

#include <boost/asio.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>

#include "ConnectionManager.h"
#include "CommandArgManager.h"

int main(int argc, char *argv[])
{
  using namespace std;
 
  CommandArgManager cam(argc, argv);
  // Declare the supported options.

  // Store supported options.

  // Read from configuration file.

  // Parse commands.
  /*
  if (vm.count("help")) { cout << desc << "\n"; return 1; }

  if (vm.count("worldsizex")) {
    cout << "World size level was set to "
      << vm["worldsizex"].as<int>() << ".\n";
  }
  else { cout << "World size level was not set.\n"; }

  */
  
  // Timer
  /*boost::asio::io_service io_service;
  boost::asio::ip::tcp::socket socket(io_service);
  boost::system::error_code ec; // major decision!
  socket.connect(server_endpoint, ec);
  socket.async_connect(server_endpoint, your_completion_handler);
  for (;;)
  {
  boost::array<char, 128> buf;
  boost::system::error_code error;

  size_t len = socket.read_some(boost::asio::buffer(buf), error);*/
  // Accept connections.
  try
  {
    boost::asio::io_service io_service;
    tcp_server server(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}