#include <iostream>
#include <sstream>

#include "SqlLiteDatabase.h"
#include "Logger.h"

SqlLiteDatabase::SqlLiteDatabase(const std::string& dbName)
{
  int rc = sqlite3_open(dbName.c_str(), &db);
  if (rc) 
  {
    spdlog::error("Can't open database: {}", sqlite3_errmsg(db));
    db = nullptr;
  }
  else 
  {
    spdlog::info("Database opened successfully!");
  }
}

SqlLiteDatabase::~SqlLiteDatabase()
{
  if (db) 
  {
    sqlite3_close(db);
  }
}

bool SqlLiteDatabase::createTables()
{
  const char* sql = "CREATE TABLE IF NOT EXISTS UsersData ("
    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
    "user_name TEXT NOT NULL, "
    "data TEXT, "
    "data_type INTEGER NOT NULL);";

  int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errorMessage);
  if (rc != SQLITE_OK) 
  {
    spdlog::error("SQL error: {}", errorMessage);
    sqlite3_free(errorMessage);
    return false;
  }

  spdlog::info("Table created successfully!");
  return true;
}

bool SqlLiteDatabase::initialize()
{
  if (!isConnected()) 
  {
    spdlog::error("DB is not connected!");
    return false;
  }

  if (!createTables()) 
  {
    spdlog::error("Can not create tables!");
    return false;
  }

  return true;
}

bool SqlLiteDatabase::insertData(const std::string& userName, const std::string& data, DataType dataType)
{
  const char* sql = "INSERT INTO UsersData (user_name, data, data_type) VALUES (?, ?, ?);";
  sqlite3_stmt* stmt;

  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
  if (rc != SQLITE_OK) 
  {
    spdlog::error("Failed to prepare statement: {}", sqlite3_errmsg(db));
    return false;
  }

  // Привязываем параметры
  sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, data.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_int(stmt, 3, (int)dataType);

  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) 
  {
    spdlog::error("Insert failed: {}", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    return false;
  }

  sqlite3_finalize(stmt);
  spdlog::info("User data inserted successfully!");

  return true;
}

std::string SqlLiteDatabase::getAllData()
{
  const char* sql = "SELECT * FROM UsersData;";
  sqlite3_stmt* stmt;

  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
  if (rc != SQLITE_OK) 
  {
    spdlog::error("Failed to prepare statement: {}", sqlite3_errmsg(db));
    return std::string();
  }

  std::ostringstream oss;

  oss << "\n=== UsersData ===" << std::endl;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) 
  {
    int id = sqlite3_column_int(stmt, 0);
    const char* userName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    const char* data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    DataType dataType = (DataType)sqlite3_column_int(stmt, 3);

    oss << "ID: " << id
      << ", User Name: " << userName
      << ", Data: " << data
      << ", Type: " << dataTypeToString(dataType) << std::endl;
  }

  sqlite3_finalize(stmt);

  return oss.str();
}

std::string SqlLiteDatabase::getUserData(const std::string& userName)
{
  const char* sql = "SELECT * FROM UsersData WHERE user_name = ?;";
  sqlite3_stmt* stmt;

  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
  if (rc != SQLITE_OK)
  {
    spdlog::error("Failed to prepare statement: {}", sqlite3_errmsg(db));
    return std::string();
  }

  sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);

  std::ostringstream oss;

  oss << "\n=== UserData ===" << std::endl;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
  {
    int id = sqlite3_column_int(stmt, 0);
    const char* userName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    const char* data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    DataType dataType = (DataType)sqlite3_column_int(stmt, 3);

    oss << "ID: " << id
      << ", Data: " << data
      << ", Type: " << dataTypeToString(dataType) << std::endl;
  }

  sqlite3_finalize(stmt);

  return oss.str();
}

std::string SqlLiteDatabase::getUserDataByType(const std::string& userName, DataType dataType)
{
  const char* sql = "SELECT * FROM UsersData WHERE user_name = ? and data_type = ?;";
  sqlite3_stmt* stmt;

  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
  if (rc != SQLITE_OK)
  {
    spdlog::error("Failed to prepare statement: {}", sqlite3_errmsg(db));
    return std::string();
  }

  sqlite3_bind_text(stmt, 1, userName.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_int(stmt, 2, (int)dataType);

  std::ostringstream oss;

  oss << "\n=== UserData ===" << std::endl;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
  {
    int id = sqlite3_column_int(stmt, 0);
    const char* userName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    const char* data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    DataType dataType = (DataType)sqlite3_column_int(stmt, 3);

    oss << "ID: " << id
      << ", Data: " << data << std::endl;
  }

  sqlite3_finalize(stmt);

  return oss.str();
}

bool SqlLiteDatabase::deleteById(int id)
{
  const char* sql = "DELETE FROM UsersData WHERE id = ?;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) 
  {
    spdlog::error("Failed to prepare statement: {}", sqlite3_errmsg(db));
    return false;
  }

  sqlite3_bind_int(stmt, 1, id);

  bool success = false;
  if (sqlite3_step(stmt) == SQLITE_DONE) 
  {
    int changes = sqlite3_changes(db);
    if (changes > 0) 
    {
      spdlog::info("Successfully deleted data with ID: {}", id);
      success = true;
    }
    else 
    {
      spdlog::info("No user data found with ID: {}", id);
    }
  }
  else 
  {
    spdlog::error("Delete failed: {}", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);

  return success;
}

bool SqlLiteDatabase::isConnected() const
{
  return db != nullptr;
}
