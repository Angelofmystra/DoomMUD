#include <boost/lambda/lambda.hpp>
#include <boost/program_options.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>

int main(int argc, char *argv[])
{
  namespace po = boost::program_options;
  using namespace std;

  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("config", po::value<std::string>(), "path to the config file")
    ("gm", "start the game with gm commands enabled")
    ("cheat", "start the game with cheats enabled")
    ("fullscreen", "forces the game to start in full screen mode")
    ("worldsizex", po::value<int>(), "sets the x dimension of the world")
    ("worldsizey", po::value<int>(), "sets the y dimension of the world")
    ("hijack", "take control of an existing instance of the game, if any, instead of complaining about already running")
    ("load", po::value<std::string>(),"loads a previous game state")
    ("verbosity", po::value<std::string>()->implicit_value("0"), "verbosity level")
    ;

  // Declare a group of options that will be 
  // allowed both on command line and in
  // config file
  po::options_description config("Configuration");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    cout << desc << "\n";
    return 1;
  }

  if (vm.count("worldsizex")) {
    cout << "World size level was set to "
      << vm["worldsizex"].as<int>() << ".\n";
  }
  else {
    cout << "World size level was not set.\n";
  }
}