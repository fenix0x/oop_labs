#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(int left, int top, int width, int height)
:m_left(left), m_top(top), m_width(0), m_height(0)
{
	m_width = width > 0 ? width : 0;
	m_height = height > 0 ? height : 0;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

void CRectangle::SetLeft(const int left)
{
	m_left = left;
}

int CRectangle::GetRight() const
{
	return m_left + m_width;
}

void CRectangle::SetRight(const int right)
{
	if (right > m_left)
	{
		m_width = right - m_left;
	}
}

int CRectangle::GetTop() const
{
	return m_top;
}

void CRectangle::SetTop(const int top)
{
	m_top = top;
}

int CRectangle::GetBottom() const
{
	return m_top + m_height;
}

void CRectangle::SetBottom(const int bottom)
{
	if (bottom >= m_top)
	{
		m_height = bottom - m_top;
	}
}

int CRectangle::GetWidth() const
{
	return m_width;
}

void CRectangle::SetWidth(const int width)
{
	if (width >= 0)
	{
		m_width = width;
	}
}

int CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetHeight(const int height)
{
	if (height >= 0)
	{
		m_height = height;
	}

}

int CRectangle::GetArea() const
{
	return m_width * m_height;
}

int CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);

}

void CRectangle::Move(int dx, int dy)
{
	m_left += dx;
	m_top += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if ((sx >= 0) && (sy >= 0))
	{
		m_width *= sx;
		m_height *= sy;
	}
}

bool CRectangle::Intersect(CRectangle const& other)
{
	if ((GetLeft() > other.GetRight()) || (GetRight() < other.GetLeft())
		|| (GetTop() > other.GetBottom()) || (GetBottom() < other.GetTop()))
	{
		m_height = 0;
		m_width = 0;
		return false;
	}
	else
	{
		if (GetLeft() < other.GetLeft())
		{
			int newLeft = other.GetLeft();
			m_width = m_width - (newLeft - m_left);
			m_left = newLeft;
		}
		if (GetRight() > other.GetRight())
		{
			SetRight(other.GetRight());
		}
		if (GetTop() < other.GetTop())
		{
			int newTop = other.GetTop();
			m_height = m_height - (newTop - m_top);
			m_top = newTop;
		}
		if (GetBottom() > other.GetBottom())
		{
			SetBottom(other.GetBottom());
		}
		return true;
	}
	
}
