#pragma once

class CRectangle
{
public:
	CRectangle(int left, int top, int width, int height);

	int GetLeft() const;
	void SetLeft(const int left);

	int GetRight() const;
	void SetRight(const int right);

	int GetTop() const;
	void SetTop(const int top);

	int GetBottom() const;
	void SetBottom(const int bottom);

	int GetWidth() const;
	void SetWidth(const int width);

	int GetHeight() const;
	void SetHeight(const int height);

	int GetArea() const;
	int GetPerimeter() const;

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);
		

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;

};