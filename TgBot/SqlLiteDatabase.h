#pragma once

#include <string>
#include <sqlite3.h>

#include "DataType.h"

class SqlLiteDatabase
{
public:
  SqlLiteDatabase(const std::string& dbName);
  ~SqlLiteDatabase();

  /// <summary>
  /// Инациализация базы.
  /// </summary>
  bool initialize();

  //Методы работы с данными.
  bool insertData(const std::string& userName, const std::string& data, DataType dataType);
  std::string getAllData();
  std::string getUserData(const std::string& userName);
  std::string getUserDataByType(const std::string& userName, DataType dataType);
  bool deleteById(int id);

  bool isConnected() const;

private:
  bool createTables();

private:
  sqlite3* db;
  char* errorMessage;
};

