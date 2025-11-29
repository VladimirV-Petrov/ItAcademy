#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>

enum class DataType
{
  Unknown,
	Note,
	Book,
	Film
};

static const char* dataTypeToString(DataType dataType)
{
  switch (dataType) 
  {
    case DataType::Note:  
      return "Note";
    case DataType::Book:  
      return "Book";
    case DataType::Film:  
      return "Film";
    default:              
      return "Unknown";
  }
}

static DataType stringToDataType(const std::string& str) 
{
  static const std::unordered_map<std::string, DataType> colorMap = 
  {
      {"note", DataType::Note},
      {"book", DataType::Book},
      {"film", DataType::Film},
      {"unknown", DataType::Unknown}
  };

  std::string lowerStr = str;
  std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return std::tolower(c); });

  auto it = colorMap.find(lowerStr);
  if (it != colorMap.end()) 
  {
    return it->second;
  }

  return DataType::Unknown;  // Default при ошибке
}