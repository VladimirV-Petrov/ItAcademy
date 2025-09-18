#pragma once

namespace Shapes
{
	/**
	 * \brief Множество фигур.
	 */
	enum class Shape
	{
		CIRCLE,
		SQUARE,
		TRIANGLE
	};

	/**
	 * \brief Функция печати перечисления Shape.
	 * \param shape Перечисление.
	 */
	void printShape(Shape shape);

	/**
	 * \brief Функция печати перечисления после конвертации из строки.
	 * \param str Исходная строка с текстом.
	 */
	void printShapeByString(const std::string& str);
}