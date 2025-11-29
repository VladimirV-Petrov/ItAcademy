#pragma once

#include <memory>
#include <iostream>
#include <mutex>
#include <vector>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class Logger
{
public:
  static Logger& instance()
  {
    static Logger logger;
    return logger;
  }

  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;

  void initialize(const std::string& app_name = "TelegramBot")
  {
    std::call_once(_initFlag, [&app_name]()
      {
        try
        {
          auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
          consoleSink->set_level(spdlog::level::debug);
          consoleSink->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] [%n] %v");

          auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
            "logs/" + app_name + ".log", 1024 * 1024 * 10, 5);
          fileSink->set_level(spdlog::level::debug);
          fileSink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] [%n] [%s:%#] %v");

          std::vector<spdlog::sink_ptr> sinks{ consoleSink, fileSink };
          auto logger = std::make_shared<spdlog::logger>(app_name, begin(sinks), end(sinks));
          logger->set_level(spdlog::level::debug);
          logger->flush_on(spdlog::level::warn);

          spdlog::register_logger(logger);
          spdlog::set_default_logger(logger);

          spdlog::info("Logger initialized successfully");
        }
        catch (const spdlog::spdlog_ex& ex)
        {
          std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        }
      });
  }

  void shutdown()
  {
    spdlog::shutdown();
  }

private:
  Logger() = default; 
  mutable std::once_flag _initFlag;
};