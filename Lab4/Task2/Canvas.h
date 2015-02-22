#pragma once
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>

class CCanvas
{
public:
	// Создает канву для рисования размером width*height
	// После своего создания содержимое канвы заполнено пробельными символами
	// Допускается создание канвы нулевых размеров
	CCanvas(unsigned width, unsigned height);
	// Возвращает ширину канвы
	unsigned GetWidth()const;
	// Возвращает высоту канвы
	unsigned GetHeight()const;
	// Очищает канву (заполняет содержимое символами с указанным кодом)
	// Если код символа находится в диапазоне от 0 до ' ', команда игнорируется
	void Clear(char code = ' ');
	// Задает код символа code для пикселя в координатах (x, y)
	// Координаты верхнего левого угла канвы принимаются равными 0, 0.
	// Если координаты выходят за пределы канвы, либо код символа
	// находится в диапазоне от 0 до (' ' - 1), содержимое канвы не должно меняться 
	void SetPixel(int x, int y, char code);
	// Возвращает код символа пикселя в координатах (x, y)
	// Координаты верхнего левого угла канвы принимаются равными 0, 0.
	// Если координаты пикселя выходят за пределы канвы, должен возвращаться
	// код символа "пробел"
	char GetPixel(int x, int y)const;
	// Выводит содержимое в поток вывода, производный от std::ostream 
	// (например, std::cout, экземпляр ofstream, или ostringstream)
	// В конце каждой строки должен выводиться символ \n
	void Write(std::ostream & ostream)const;
private:
	// Закрытые данные и методы класса
	const char MIN_CHAR = ' ' - 1;
	unsigned m_width;
	unsigned m_height;
 	std::vector<std::vector<char>> m_canvas;
	bool InCanvas(unsigned x, unsigned y) const;
	bool IsCharCorrect(char c) const;
};