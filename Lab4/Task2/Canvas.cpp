#include "stdafx.h"
#include "Canvas.h"

CCanvas::CCanvas(unsigned width, unsigned height)
: m_width(width)
, m_height(height)
{
	m_canvas.assign(m_height, std::vector<char>(m_width, ' '));
}

unsigned CCanvas::GetWidth() const
{
	return m_width;
}

unsigned CCanvas::GetHeight() const
{
	return m_height;
}

char CCanvas::GetPixel(int x, int y) const
{
	return InCanvas(x, y) ? m_canvas[y][x] : ' ';
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (InCanvas(x, y) && IsCharCorrect(code))
	{
		m_canvas[y][x] = code;
	}
}

void CCanvas::Clear(char code)
{
	if (IsCharCorrect(code))
	{
		for (auto& canvaRow : m_canvas)
		{
			std::fill(canvaRow.begin(), canvaRow.end(), code);
		}
	}
}

void CCanvas::Write(std::ostream & ostream) const
{
	for (auto& canvaRow : m_canvas)
	{
		std::ostream_iterator<char> oIt(ostream);
		copy(canvaRow.begin(), canvaRow.end(), oIt);
		ostream << '\n';
	}
}

bool CCanvas::InCanvas(unsigned x, unsigned y) const
{
	return !(x >= m_width || x < 0 || y < 0 || y >= m_height);
}

bool CCanvas::IsCharCorrect(char c) const
{
	return (c > MIN_CHAR);
}