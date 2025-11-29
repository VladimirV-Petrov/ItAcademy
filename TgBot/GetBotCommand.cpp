#include "GetBotCommand.h"
#include "TelegramBotHandler.h"

void GetBotCommand::execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message)
{
  //Допустимый формат команды, смотри в showParametersFormat()

  ExecutableBotCommand::execute(botHandler, message);

  auto parameters = ExecutableBotCommand::getParametersForCommand(message->text, "Get data from storage for parameters:\n");
  if (parameters.size() < 1)
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect parameters count.\n" + showFullFormat());
    return;
  }

  std::string firstParam = *parameters.begin();
  std::transform(firstParam.begin(), firstParam.end(), firstParam.begin(), [](unsigned char c) { return std::toupper(c); });
  if (firstParam == "ALL")
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, botHandler.getDatabase().getUserData(message->from->username));
  }
  else
  {
    parameters = StringTools::split(firstParam, ':');
    if (parameters.size() < 1)
    {
      botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect command format.\n" + showFullFormat());
      return;
    }

    firstParam = *parameters.begin();
    if (firstParam == "DATATYPE")
    {
      auto secondParam = ++parameters.begin();
      DataType dataType = stringToDataType(*secondParam);
      botHandler.getBot().getApi().sendMessage(message->chat->id, botHandler.getDatabase().getUserDataByType(message->from->username, dataType));
    }
    else
    {
      botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect command format.\n" + showFullFormat());
    }
  }
}

std::string GetBotCommand::showParametersFormat()
{
  return " all | dataType:<Note|Book|Film>";
}
