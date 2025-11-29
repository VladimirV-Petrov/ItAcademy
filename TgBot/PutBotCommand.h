#pragma once

#include "ExecutableBotCommand.h"

/// <summary>
/// Команда на запись данных.
/// </summary>
class PutBotCommand : public ExecutableBotCommand
{
public:
  PutBotCommand() = default;
  PutBotCommand(const std::string& cmd, const std::string& descr) : ExecutableBotCommand(cmd, descr) {}

  virtual ~PutBotCommand() = default;

  virtual void execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message) override;

  virtual std::string showParametersFormat() override;
};

