#include "PutBotCommand.h"
#include "TelegramBotHandler.h"
#include "DataType.h"

void PutBotCommand::execute(TelegramBotHandler& botHandler, TgBot::Message::Ptr message)
{
  //Допустимый формат команды, смотри в showParametersFormat()

  ExecutableBotCommand::execute(botHandler, message);

  auto parameters = ExecutableBotCommand::getParametersForCommand(message->text, "Put data in storage with parameters:\n");
  if (parameters.size() < 2)
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect parameters count.\n" + showFullFormat());
    return;
  }

  std::string firstParam = *parameters.begin();
  std::transform(firstParam.begin(), firstParam.end(), firstParam.begin(), [](unsigned char c) { return std::toupper(c); });

  size_t posDataType = firstParam.find("DATATYPE:");
  if (posDataType == std::string::npos)
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect command format.\n" + showFullFormat());
    return;
  }

  auto dataTypeParams = StringTools::split(firstParam, ':');
  if (dataTypeParams.size() < 1)
  {
    botHandler.getBot().getApi().sendMessage(message->chat->id, "Incorrect command format.\n" + showFullFormat());
    return;
  }

  auto dataTypeSecondParam = ++dataTypeParams.begin();
  DataType dataType = stringToDataType(*dataTypeSecondParam);

  std::string data;
  std::string msg = "";
  auto itData = ++parameters.begin();
  for (; itData != parameters.end(); ++itData)
  {
    msg += " " + *itData;
  }

  botHandler.getDatabase().insertData(message->from->username, msg, dataType);

  botHandler.getBot().getApi().sendMessage(message->chat->id, "Data saved.");
}

std::string PutBotCommand::showParametersFormat()
{
  return " dataType:<Note|Book|Film> <DATA>";
}
