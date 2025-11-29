#include <fstream>
#include <iostream>

#include "Logger.h"
#include "ConfigReader.h"

ConfigReader::ConfigReader(const std::string& configPath) 
{
  std::ifstream config_file(configPath);
  if (!config_file.is_open()) 
  {
    spdlog::error("Failed to open  {}", configPath);
    return;
  }

  config_file >> _config;
}

std::string ConfigReader::getBotToken() const 
{
  if (_config.contains("telegram_bot_token")) 
  {
    return _config["telegram_bot_token"];
  }

  throw std::runtime_error("telegram_bot_token not found in config");
}

bool ConfigReader::isValid() const 
{
  return _config.contains("telegram_bot_token");
}