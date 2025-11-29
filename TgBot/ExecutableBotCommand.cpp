#include "ExecutableBotCommand.h"
#include "TelegramBotHandler.h"
#include "Logger.h"

void ExecutableBotCommand::execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message)
{
  spdlog::debug("Get command: {}", message->text);
}

std::string ExecutableBotCommand::showParametersFormat()
{
  return std::string();
}

std::string ExecutableBotCommand::showFullFormat()
{
  return "/" + command + showParametersFormat();
}

std::vector<std::string> ExecutableBotCommand::getParametersForCommand(const std::string& str, const std::string& descr)
{
  auto parameters = StringTools::split(str, ' ');
  parameters.erase(parameters.begin());

  std::string msg = descr;
  for (auto parameter : parameters)
  {
    msg += parameter + "\n";
  }
  spdlog::debug(msg);

  return parameters;
}
