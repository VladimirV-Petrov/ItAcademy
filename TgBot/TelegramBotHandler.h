#pragma once

#include <string>

#include <tgbot/tgbot.h>

#include "SqlLiteDatabase.h"
#include "ExecutableBotCommand.h"

class TelegramBotHandler
{
public:
  TelegramBotHandler(const std::string& token, SqlLiteDatabase& database);

  // Геттеры
  SqlLiteDatabase& getDatabase() { return _database; }
  const TgBot::Bot& getBot() const { return _bot; }
  const std::vector<TgBot::BotCommand::Ptr>& getCommands() const { return _commands; }

private:
  /// <summary>
  /// Формирует список команд для бота.
  /// </summary>
  void addCommands();

  /// <summary>
  /// Запускает цикл обработки команд.
  /// </summary>
  void startPolling();

  /// <summary>
  /// Добавляет отдельную команду. 
  /// </summary>
  void addCommand(ExecutableBotCommand::Ptr command);

  /// <summary>
  /// Проверяет, является ли сообщение командой.
  /// </summary>
  bool isCommand(const std::string& msg);

private:
  TgBot::Bot _bot;
  SqlLiteDatabase _database;
  std::vector<TgBot::BotCommand::Ptr> _commands;
};

