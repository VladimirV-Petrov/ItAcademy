#pragma once

#include <tgbot/tgbot.h>

class TelegramBotHandler;

class ExecutableBotCommand : public TgBot::BotCommand 
{
public:
  typedef std::shared_ptr<ExecutableBotCommand> Ptr;

  ExecutableBotCommand() = default;
  ExecutableBotCommand(const std::string& cmd, const std::string& descr) : TgBot::BotCommand()
  {
    command = cmd;
    description = descr;
  }
  
  virtual ~ExecutableBotCommand() = default;

  /// <summary>
  /// Выполняет необходимые действия.
  /// </summary>
  virtual void execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message);
  
  /// <summary>
  /// Показывает какие параметры принимает команда.
  /// </summary>
  virtual std::string showParametersFormat();
  
  /// <summary>
  /// Показывает полный формат команды.
  /// </summary>
  virtual std::string showFullFormat();

  /// <summary>
  /// Получает параметры на основе входной строки.
  /// </summary>
  static std::vector<std::string> getParametersForCommand(const std::string& str, const std::string& descr);
};