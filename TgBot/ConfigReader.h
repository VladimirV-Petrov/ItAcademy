#pragma once

#include <string>
#include <nlohmann/json.hpp>

class ConfigReader
{
public:
  ConfigReader(const std::string& configPath = "config.json");
  std::string getBotToken() const;
  bool isValid() const;

private:
	nlohmann::json _config;
};

