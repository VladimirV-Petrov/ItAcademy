#pragma once

#include "ExecutableBotCommand.h"

/// <summary>
/// Команда на удаление данных.
/// </summary>
class DelBotCommand : public ExecutableBotCommand
{
public:
  DelBotCommand() = default;
  DelBotCommand(const std::string& cmd, const std::string& descr) : ExecutableBotCommand(cmd, descr) {}

  virtual ~DelBotCommand() = default;

  virtual void execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message) override;

  virtual std::string showParametersFormat() override;
};

