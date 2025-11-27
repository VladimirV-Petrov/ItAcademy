#pragma once

#include <iostream>

#include "Tree.h"

/// <summary>
/// Класс сосна
/// </summary>
class Pine : public Tree
{
public:
  Pine(std::string name) : Tree(name, TreeType::Pine) { ++_pineCount; }
  ~Pine() { --_pineCount; }

  void wind() const override
  {
    std::cout << "Pine tree: " << _name << std::endl;
  }

  static int getPineCount() { return _pineCount; }

private:
  static int _pineCount;
};