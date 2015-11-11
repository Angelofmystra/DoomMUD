#include <boost/program_options.hpp>

#include <boost/asio.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>

#include <fstream>

#include "ConnectionManager.h"

int main(int argc, char *argv[])
{
  namespace po = boost::program_options;
  using namespace std;

  const std::string default_config_filename = "config.ini";
  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("config", po::value<std::string>()->default_value(default_config_filename), "path to the config file")
    ("gm", "start the game with gm commands enabled")
    ("cheat", "start the game with cheats enabled")
    ("fullscreen", "forces the game to start in full screen mode")
    ("worldsizex", po::value<int>(), "sets the x dimension of the world")
    ("worldsizey", po::value<int>(), "sets the y dimension of the world")
    ("hijack", "take control of an existing instance of the game, if any, instead of complaining about already running")
    ("load", po::value<std::string>(),"loads a previous game state")
    ("verbosity", po::value<std::string>()->default_value("0"), "verbosity level")
    ;
  // Store supported options.
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);
  // Read from configuration file.
  ifstream config_stream;
  config_stream.open(default_config_filename);
  if (!config_stream) { 
    std::cout << "[FAILED] Could not open config file " << vm["config"].as<string>();
  }
  else {
    std::cout << "[SUCCESS] Config file found" << default_config_filename;
    po::store(po::parse_config_file(config_stream, desc), vm);
  }
  // Parse commands.
  if (vm.count("help")) { cout << desc << "\n"; return 1; }

  if (vm.count("worldsizex")) {
    cout << "World size level was set to "
      << vm["worldsizex"].as<int>() << ".\n";
  }
  else { cout << "World size level was not set.\n"; }
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