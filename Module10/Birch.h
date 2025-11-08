#pragma once

#include <iostream>

#include "Tree.h"

/// <summary>
/// Класс береза
/// </summary>
class Birch : public Tree
{
public:
  Birch(std::string name) : Tree(name, TreeType::Birch) { ++_birchCount; }
  ~Birch() { --_birchCount; }

  void wind() const override
  {
    std::cout << "Birch tree: " << _name << std::endl;
  }

  static int getBirchCount() { return _birchCount; }

private:
  static int _birchCount;
};