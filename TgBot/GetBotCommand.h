#pragma once

#include "ExecutableBotCommand.h"

/// <summary>
/// Команда на получение данных.
/// </summary>
class GetBotCommand : public ExecutableBotCommand
{
public:
  GetBotCommand() = default;
  GetBotCommand(const std::string& cmd, const std::string& descr) : ExecutableBotCommand(cmd, descr) {}

  virtual ~GetBotCommand() = default;

  virtual void execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message) override;

  virtual std::string showParametersFormat() override;
};

