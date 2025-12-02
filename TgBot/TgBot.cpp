// Используются библиотеки:
// 1) tgbot_cpp - https://github.com/reo7sp/tgbot-cpp?tab=readme-ov-file
// 2) nlohmann/json - https://github.com/nlohmann/json
// 3) sqlite3 - https://github.com/SRombauts/SQLiteCpp
// 4) spdlog - https://github.com/gabime/spdlog

//Установка библиотек через vcpkg - https://github.com/microsoft/vcpkg

#include "Logger.h"
#include "SqlLiteDatabase.h"
#include "ConfigReader.h"
#include "TelegramBotHandler.h"

int main()
{
  try 
  {
    Logger::instance().initialize("TgBot");

    signal(SIGINT, [](int s) 
      {
        spdlog::info("SIGINT got");
        Logger::instance().shutdown();
        exit(0);
      });

    //Чтение конфигурации
    ConfigReader config;
    if (!config.isValid()) 
    {
      spdlog::error("Invalid config");
      Logger::instance().shutdown();
    	return -1;
    }

    //Инициализация базы 
    SqlLiteDatabase sqlLileDb("test.db");
    if (!sqlLileDb.initialize())
    {
      spdlog::error("Failed to initialize database");
      Logger::instance().shutdown();
      return -1;
    }

    std::string token = config.getBotToken();

    //Создание и запуск бота
    TelegramBotHandler botHandler(token, sqlLileDb);
  }
  catch (const std::exception& e) 
  {
    spdlog::error("Exception caught: {}", e.what());
    Logger::instance().shutdown();
    throw;  
  }
  catch (...) 
  {
    spdlog::error("Unknown exception caught");
    Logger::instance().shutdown();
    throw;  
  }

  Logger::instance().shutdown();
  return 0;
}
