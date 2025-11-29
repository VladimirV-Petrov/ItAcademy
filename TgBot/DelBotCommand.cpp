#include <optional>
#include <string>

#include "DelBotCommand.h"
#include "TelegramBotHandler.h"

std::optional<int> parseInt(const std::string& str) 
{
  try 
  {
    size_t pos;  
    int num = std::stoi(str, &pos);
    return num;
  }
  catch (const std::invalid_argument&) 
  {
    return std::nullopt;  // Не число
  }
  catch (const std::out_of_range&) 
  {
    return std::nullopt;  // Слишком большое для int
  }
}

void DelBotCommand::execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message)
{
  //Допустимый формат команды, смотри в showParametersFormat()

  ExecutableBotCommand::execute(botHandler, message);

  auto parameters = ExecutableBotCommand::getParametersForCommand(message->text, "Delete data from storage for parameters:\n");
  if (parameters.size() < 1)
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect parameters count.\n" + showFullFormat());
    return;
  }

  std::string idParam = *parameters.begin();

  auto id = parseInt(idParam);
  if (id.has_value()) 
  {
    botHandler.getDatabase().deleteById(id.value());
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Data deleted.");
  }
  else 
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect ID.");
  }
}

std::string DelBotCommand::showParametersFormat()
{
  return " <ID>";
}
