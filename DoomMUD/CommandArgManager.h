#pragma once
#include <boost/program_options.hpp>
#include <boost/asio.hpp>

#include <iostream>
#include <fstream>

using namespace boost::program_options;
/*
 Usage:
  Construct the class with:
    CommandArgManager cam(argc,argv);
      where, argc and argv are the parameters from the main function
  This sets up the command line arguments.
  
  Call cam.get_val("key_string"); to get the associated value.

  This program reads configuration information from the config.ini file
  in the current working directory.

  If you provide a config file path, it overrides it, like so:
    CommandArgManager cam(argc,argv,config_file_path);
      where config_file_path is a C++ string

  You can get the current config file path with:
    cam.get_config_path();
*/
class CommandArgManager {
public:
  CommandArgManager(int argc, char *argv[]) { 
    variables_map vm; 
    declare_supported_arguments();
    store_the_supported_arguments(argc, argv);
    read_from_configuration_file();
    parse_commands();
  }
  std::string get_val(std::string key);
  std::string get_config_path();

private:
  variables_map vm;
  options_description desc;
  const std::string default_config_filename = "config.ini";
  variables_map& get_vm();
  void declare_supported_arguments();
  void store_the_supported_arguments(int argc, char * argv[]);
  void read_from_configuration_file();
  void parse_commands();
};