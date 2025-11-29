#pragma once

#include "ExecutableBotCommand.h"

/// <summary>
/// Справочная команда.
/// </summary>
class StartBotCommand : public ExecutableBotCommand
{
public:
  StartBotCommand() = default;
  StartBotCommand(const std::string& cmd, const std::string& descr) : ExecutableBotCommand(cmd, descr) {}

  virtual ~StartBotCommand() = default;

  virtual void execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message) override;
};

