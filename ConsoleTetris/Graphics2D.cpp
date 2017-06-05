#include "Graphics2D.h"

#include <stdio.h>
#include <cstring>
#include <stdexcept>
#include "Color.h"

Graphics2D::Graphics2D(size_t width, size_t height)
{
	width_ = width;
	height_ = height;

	size_t length = getLength(width, height);
	graphics_ = new char[length];
	fill(' ');
	graphics_[length - 1] = '\0';
}

Graphics2D::Graphics2D(const Graphics2D& obj)
{
	width_ = obj.width_;
	height_ = obj.height_;

	size_t length = getLength(width_, height_);
	graphics_ = new char[length];
	memcpy(graphics_, obj.graphics_, length);
}

Graphics2D::~Graphics2D()
{
	delete[] graphics_;
}

size_t Graphics2D::getWidth()
{
	return width_;
}

size_t Graphics2D::getHeigth()
{
	return height_;
}

void Graphics2D::setColor(int x, int y, Color color)
{
	if (!checkCoordinates(x, y)) return;

	size_t position = getPosition(x, y);
	graphics_[position] = color.getLeft();
	graphics_[position + 1] = color.getRight();
}

Color Graphics2D::getColor(size_t x, size_t y)
{
	checkCoordinatesAndThrow(x, y);

	size_t position = getPosition(x, y);
	return Color(graphics_[position], graphics_[position + 1]);
}

void Graphics2D::drawPoint(int x, int y, Color color)
{
	if (!checkCoordinates(x, y)) return;

	size_t position = getPosition(x, y);
	if (color.getLeft() != ' ') graphics_[position] = color.getLeft();
	if (color.getRight() != ' ') graphics_[position + 1] = color.getRight();
}

void Graphics2D::setRectangle(int x, int y, size_t width, size_t height, Color color)
{
	if (!checkRectangle(x, y, width, height)) return;

	if (x < 0) {
		width += x;
		x = 0;
	}
	if (y < 0) {
		height += y;
		y = 0;
	}
	if (x + width >= width_) width = width_ - x;
	if (y + height >= height_) height = height_ - y;

	size_t x1 = x + width;
	size_t y1 = y + height;

	for (size_t yi = y; yi < y1; yi++) {
		for (size_t xi = x; xi < x1; xi++) {
			setColor(xi, yi, color);
		}
	}
}

void Graphics2D::drawRectange(int x, int y, size_t width, size_t height, Color color)
{
	if ((x + width <= 0) || (static_cast<size_t>(x) >= width_) || (y + height <= 0) || (static_cast<size_t>(y) >= height_)) return;

	if (x < 0) {
		width += x;
		x = 0;
	}
	if (y < 0) {
		height += y;
		y = 0;
	}
	if (x + width >= width_) width = width_ - x;
	if (y + height >= height_) height = height_ - y;

	size_t x1 = x + width;
	size_t y1 = y + height;

	for (size_t yi = y; yi < y1; yi++) {
		for (size_t xi = x; xi < x1; xi++) {
			drawPoint(xi, yi, color);
		}
	}
}

void Graphics2D::setText(int x, int y, std::string text)
{
	size_t previousNewLinePosition = -1, newLinePosition;
	while ((newLinePosition = text.find('\n', previousNewLinePosition + 1)) != std::string::npos) {
		setText(x, y, text, previousNewLinePosition + 1, newLinePosition - (previousNewLinePosition + 1));
		previousNewLinePosition = newLinePosition;
		y++;
	}
	setText(x, y, text, previousNewLinePosition + 1, text.length() - (previousNewLinePosition + 1));
}

void Graphics2D::drawText(int x, int y, std::string text)
{
	size_t previousNewLinePosition = -1, newLinePosition;
	while ((newLinePosition = text.find('\n', previousNewLinePosition + 1)) != std::string::npos) {
		drawText(x, y, text, previousNewLinePosition + 1, newLinePosition - (previousNewLinePosition + 1));
		previousNewLinePosition = newLinePosition;
		y++;
	}
	drawText(x, y, text, previousNewLinePosition + 1, text.length() - (previousNewLinePosition + 1));
}

void Graphics2D::setText(int x, int y, std::string text, size_t offset, size_t length)
{
	size_t width = length / 2 + (length % 2);
	if (!checkRectangle(x, y, width, 1)) return;

	int offsetX = (x >= 0) ? 0 : -x;
	if (x + width > width_) length = (width_ - x) * 2;
	length -= offsetX * 2;
	text.copy(graphics_ + getPosition(x + offsetX, y), length, offset + offsetX * 2);
}

void Graphics2D::drawText(int x, int y, std::string text, size_t offset, size_t length)
{
	size_t width = length / 2 + (length % 2);
	if (!checkRectangle(x, y, width, 1)) return;

	int offsetX = (x >= 0) ? 0 : -x;
	if (x + width > width_) length = (width_ - x) * 2;
	offset += offsetX * 2;
	length -= offsetX * 2;

	size_t start = getPosition(x + offsetX, y);
	size_t previousSpacePosition = offset - 1, spacePosition;
	while (((spacePosition = text.find(' ', previousSpacePosition + 1)) != std::string::npos) && (spacePosition < offset + length)) {
		text.copy(graphics_ + start + (previousSpacePosition - offset) + 1, spacePosition - previousSpacePosition - 1, offset + offsetX * 2 + (previousSpacePosition - offset) + 1);
		previousSpacePosition = spacePosition;
	}
	text.copy(graphics_ + start + (previousSpacePosition - offset) + 1, length - previousSpacePosition - 1, offset + offsetX * 2 + (previousSpacePosition - offset) + 1);
}

void Graphics2D::fill(char color)
{
	size_t length = getLength(width_, height_);
	memset(graphics_, color, sizeof(*graphics_) * (length - 1));
	for (size_t i = width_ * 2; i < length; i += width_ * 2 + 1) {
		graphics_[i] = '\n';
	}
}

void Graphics2D::clear()
{
	fill(' ');
}

void Graphics2D::setImage(int x, int y, Graphics2D image)
{
	if (!checkRectangle(x, y, image.width_, image.height_)) return;

	size_t offset = (x >= 0) ? 0 : -x;
	size_t length = (((x + image.width_ <= width_) ? image.width_ : width_ - x) - offset) * 2;

	for (size_t i = (y >= 0) ? y : 0; (i - y < image.height_) && (i < height_); i++) {
		memcpy(graphics_ + getPosition(x + offset, i), image.graphics_ + image.getPosition(offset, i - y), length);
	}
}

void Graphics2D::drawImage(int x, int y, Graphics2D image)
{
	if (!checkRectangle(x, y, image.width_, image.height_)) return;

	size_t offset = (x >= 0) ? 0 : -x;
	size_t length = ((x + image.width_ <= width_) ? image.width_ : width_ - x) - offset;

	for (size_t yi = (y >= 0) ? y : 0; (yi - y < image.height_) && (yi < height_); yi++) {
		for (size_t xi = x + offset; xi < x + offset + length; xi++) {
			size_t position = getPosition(xi, yi);
			size_t imagePosition = image.getPosition(xi - x, yi - y);
			if (image.graphics_[imagePosition] != ' ') graphics_[position] = image.graphics_[imagePosition];
			if (image.graphics_[imagePosition + 1] != ' ') graphics_[position + 1] = image.graphics_[imagePosition + 1];
		}
	}
}

void Graphics2D::print()
{
	printf("%s", graphics_);
}

void Graphics2D::setSize(size_t width, size_t height)
{
	if ((width == width_) && (height == height_)) return;

	delete[] graphics_;

	width_ = width;
	height_ = height;

	int length = getLength(width, height);
	graphics_ = new char[length];
	fill(' ');
	graphics_[length - 1] = '\0';
}

inline size_t Graphics2D::getLength(size_t width, size_t height)
{
	return (width * 2 + 1) * height + 1;
}

inline size_t Graphics2D::getPosition(size_t x, size_t y)
{
	return y * (width_ * 2 + 1) + x * 2;
}

inline bool Graphics2D::checkCoordinates(int x, int y)
{
	bool checkX = ((x >= 0) && (static_cast<size_t>(x) < width_));
	bool checkY = ((y >= 0) && (static_cast<size_t>(y) < height_));
	return (checkX && checkY);
}

inline bool Graphics2D::checkRectangle(int x, int y, size_t width, size_t height)
{
	bool checkX = (x >= 0) ?
		(static_cast<size_t>(x) < width_) :
		(static_cast<size_t>(-x) < width);
	bool checkY = (y >= 0) ?
		(static_cast<size_t>(y) < height_) :
		(static_cast<size_t>(-y) < height);
	return (checkX && checkY);
}

inline void Graphics2D::checkCoordinatesAndThrow(size_t x, size_t y)
{
	if (x >= width_)
		throw std::invalid_argument("Неверное значение координаты по x");
	if (y >= height_)
		throw std::invalid_argument("Неверное значение координаты по y");
}
