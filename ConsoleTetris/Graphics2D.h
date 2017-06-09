#pragma once
#include "Color.h"
#include <string>

class Graphics2D
{
public:
	Graphics2D();
	Graphics2D(size_t width, size_t height);
	Graphics2D(const Graphics2D &obj);
	~Graphics2D();

	size_t getWidth();
	size_t getHeigth();

	void setColor(int x, int y, Color color);
	Color getColor(size_t x, size_t y);
	void drawPoint(int x, int y, Color color);
	void setRectangle(int x, int y, size_t width, size_t height, Color color);
	void drawRectange(int x, int y, size_t width, size_t height, Color color);
	void setText(int x, int y, std::string text);
	void drawText(int x, int y, std::string text);
	void fill(char color);
	void clear();
	void setImage(int x, int y, Graphics2D image);
	void drawImage(int x, int y, Graphics2D image);

protected:
	void print();
	void setSize(size_t x, size_t y);

private:
	size_t width_, height_;
	char* graphics_;

	void setText(int x, int y, std::string text, size_t offset, size_t length);
	void drawText(int x, int y, std::string text, size_t offset, size_t length);
	inline size_t getLength(size_t width, size_t height);
	inline size_t getPosition(size_t x, size_t y);
	inline bool checkCoordinates(int x, int y);
	inline bool checkRectangle(int x, int y, size_t width, size_t height);
	inline void checkCoordinatesAndThrow(size_t x, size_t y);
};

