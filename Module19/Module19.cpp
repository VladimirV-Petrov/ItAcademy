#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// Общие ресурсы и мьютексы для синхронизации
int sum = 0;
int maxElement = -1;
int minElement = 9999;
std::mutex sumMutex;
std::mutex maxMutex;
std::mutex minMutex;

/// <summary>
/// Функция для вычисления суммы элементов массива
/// </summary>
void calculateSum(const std::vector<int>& arr) 
{
  int localSum = 0;
  for (int num : arr) 
  {
    localSum += num;
  }

  std::lock_guard<std::mutex> lock(sumMutex);
  sum = localSum;
}

/// <summary>
/// Функция для поиска максимального элемента
/// </summary>
void calculateMax(const std::vector<int>& arr) 
{
  int localMax = arr[0];
  for (int num : arr) 
  {
    if (num > localMax) 
    {
      localMax = num;
    }
  }

  std::lock_guard<std::mutex> lock(maxMutex);
  maxElement = localMax;
}

/// <summary>
/// Функция для поиска минимального элемента
/// </summary>
void calculateMin(const std::vector<int>& arr) 
{
  int localMin = arr[0];
  for (int num : arr) 
  {
    if (num < localMin) 
    {
      localMin = num;
    }
  }

  std::lock_guard<std::mutex> lock(minMutex);
  minElement = localMin;
}

int main() 
{
  std::cout << "Module 19" << std::endl;

  std::vector<int> array(100);

  for (int i = 0; i < 100; ++i) 
  {
    array[i] = rand() % 100 + 1;
    std::cout << "array[" << i << "]: " << array[i] << std::endl;
  }
  std::cout << std::endl;

  maxElement = array[0];
  minElement = array[0];

  std::thread threadSum(calculateSum, array);
  std::thread threadMax(calculateMax, array);
  std::thread threadMin(calculateMin, array);

  threadSum.join();
  threadMax.join();
  threadMin.join();

  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Max: " << maxElement << std::endl;
  std::cout << "Min: " << minElement << std::endl;

  return 0;
}
