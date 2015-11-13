#include "CommandArgManager.h"

void CommandArgManager::declare_supported_arguments()
{
  namespace po = boost::program_options;
  desc.add_options()
    ("help", "print this help and exit")
    ("version", "print version information and exit")
    ("config", po::value<std::string>()->default_value(default_config_filename), "set path to the config file")
    ("gm", "start the game with gm commands enabled")
    ("cheat", "start the game with cheats enabled")
    ("fullscreen", "forces the game to start in full screen mode")
    ("worldsizex", po::value<int>(), "set the x dimension of the world")
    ("worldsizey", po::value<int>(), "set the y dimension of the world")
    ("hijack", "take control of an existing instance of the game, if any, instead of complaining about already running")
    ("load", po::value<std::string>(), "load a previous game state")
    ("verbosity", po::value<std::string>()->default_value("0"), "verbosity level")
    ;
}

void CommandArgManager::store_the_supported_arguments(int argc, char * argv[])
{
  using namespace boost::program_options;
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);
}

void CommandArgManager::read_from_configuration_file()
{
  using namespace boost::program_options;
  std::ifstream config_stream;
  config_stream.open(default_config_filename);
  if (!config_stream) {
    std::cout << "[FAILED] Could not open config file " << vm["config"].as<std::string>() << "\n";
  }
  else {
    std::cout << "[SUCCESS] Config file found" << default_config_filename << "\n";;
    store(parse_config_file(config_stream, desc), vm);
  }
}

void CommandArgManager::parse_commands()
{
  using namespace std;
  if (vm.count("help")) { cout << desc << "\n"; exit(0); }

  if (vm.count("worldsizex")) {
  cout << "World size level was set to "
  << vm["worldsizex"].as<int>() << ".\n";
  }
  else { cout << "World size level was not set.\n"; }
}

std::string CommandArgManager::get_val(std::string key)
{
  return vm["config"].as<std::string>();
}

boost::program_options::variables_map& CommandArgManager::get_vm()
{
  return vm;
}
