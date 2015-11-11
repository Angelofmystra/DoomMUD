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

  // Declare the supported options.
  // Store supported options.
  // Read from configuration file. 
  // Parse commands.
  CommandArgManager cam(argc, argv);

  // Timer

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