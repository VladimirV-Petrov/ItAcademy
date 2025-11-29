#include <typeinfo>

#include "StartBotCommand.h"
#include "TelegramBotHandler.h"

void StartBotCommand::execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message)
{
  ExecutableBotCommand::execute(botHandler, message);

  std::string resMsg = "Available commands:\n\n";

  std::vector<TgBot::BotCommand::Ptr> commands = botHandler.getCommands();
  for (std::vector<TgBot::BotCommand::Ptr>::iterator it = commands.begin(); it != commands.end(); ++it)
  {
    ExecutableBotCommand* executableCommand = dynamic_cast<ExecutableBotCommand*>(it->get());
    resMsg += (*it)->description + "\n";
    resMsg += "Format: " + (executableCommand ? executableCommand->showFullFormat() : (*it)->command) + "\n\n";
  }
  botHandler.getBot().getApi().sendMessage(message->chat->id, resMsg);
}
