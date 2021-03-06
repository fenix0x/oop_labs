#pragma once
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>

class CCanvas
{
public:
	// ������� ����� ��� ��������� �������� width*height
	// ����� ������ �������� ���������� ����� ��������� ����������� ���������
	// ����������� �������� ����� ������� ��������
	CCanvas(unsigned width, unsigned height);
	// ���������� ������ �����
	unsigned GetWidth()const;
	// ���������� ������ �����
	unsigned GetHeight()const;
	// ������� ����� (��������� ���������� ��������� � ��������� �����)
	// ���� ��� ������� ��������� � ��������� �� 0 �� ' ', ������� ������������
	void Clear(char code = ' ');
	// ������ ��� ������� code ��� ������� � ����������� (x, y)
	// ���������� �������� ������ ���� ����� ����������� ������� 0, 0.
	// ���� ���������� ������� �� ������� �����, ���� ��� �������
	// ��������� � ��������� �� 0 �� (' ' - 1), ���������� ����� �� ������ �������� 
	void SetPixel(int x, int y, char code);
	// ���������� ��� ������� ������� � ����������� (x, y)
	// ���������� �������� ������ ���� ����� ����������� ������� 0, 0.
	// ���� ���������� ������� ������� �� ������� �����, ������ ������������
	// ��� ������� "������"
	char GetPixel(int x, int y)const;
	// ������� ���������� � ����� ������, ����������� �� std::ostream 
	// (��������, std::cout, ��������� ofstream, ��� ostringstream)
	// � ����� ������ ������ ������ ���������� ������ \n
	void Write(std::ostream & ostream)const;
private:
	// �������� ������ � ������ ������
	const char MIN_CHAR = ' ' - 1;
	unsigned m_width;
	unsigned m_height;
 	std::vector<std::vector<char>> m_canvas;
	bool InCanvas(unsigned x, unsigned y) const;
	bool IsCharCorrect(char c) const;
};