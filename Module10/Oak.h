#pragma once

#include <iostream>

#include "Tree.h"

/// <summary>
/// Класс дуб
/// </summary>
class Oak : public Tree
{
public:
  Oak(std::string name) : Tree(name, TreeType::Oak) { ++_oakCount; }
  ~Oak() { --_oakCount; }

  void wind() const override
  {
    std::cout << "Oak tree: " << _name << std::endl;
  }

  static int getOakCount() { return _oakCount; }

private:
  static int _oakCount;
};
