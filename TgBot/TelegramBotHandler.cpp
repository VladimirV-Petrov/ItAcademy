#include <vector>

#include "Logger.h"
#include "TelegramBotHandler.h"
#include "StartBotCommand.h"
#include "PutBotCommand.h"
#include "GetBotCommand.h"
#include "DelBotCommand.h"

TelegramBotHandler::TelegramBotHandler(const std::string& token, SqlLiteDatabase& database) : _bot(token), _database(database)
{
  spdlog::info("Bot username: {}", _bot.getApi().getMe()->username);

  _bot.getEvents().onAnyMessage([this](TgBot::Message::Ptr message) 
    {
      if (isCommand(message->text.c_str()))
        return;

      _bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });

  addCommands();
  startPolling();
}

void TelegramBotHandler::addCommands()
{
  addCommand(ExecutableBotCommand::Ptr(new StartBotCommand("start", "Show all command")));
  addCommand(ExecutableBotCommand::Ptr(new GetBotCommand("get", "Get data from storage")));
  addCommand(ExecutableBotCommand::Ptr(new PutBotCommand("put", "Put data in storage")));
  addCommand(ExecutableBotCommand::Ptr(new DelBotCommand("del", "Delete data from storage")));
}

void TelegramBotHandler::startPolling()
{
  try 
  {
    TgBot::TgLongPoll longPoll(_bot);
    while (true) 
    {
      spdlog::debug("Long poll started");
      longPoll.start();
    }
  }
  catch (TgBot::TgException& e) 
  {
    spdlog::error("error: {}", e.what());
    throw;
  }
}

void TelegramBotHandler::addCommand(ExecutableBotCommand::Ptr command)
{
  _commands.push_back(command);
  _bot.getApi().setMyCommands(_commands);

  _bot.getEvents().onCommand(command.get()->command, [this, cmdPtr = command.get()](TgBot::Message::Ptr message)
    {
      cmdPtr->execute(*this, message);
    });
}

bool TelegramBotHandler::isCommand(const std::string& msg)
{
  for (std::vector<TgBot::BotCommand::Ptr>::iterator it = _commands.begin(); it != _commands.end(); ++it)
  {
    if (StringTools::startsWith(msg, "/" + (*it)->command))
    {
      return true;
    }
  }

  return false;
}
