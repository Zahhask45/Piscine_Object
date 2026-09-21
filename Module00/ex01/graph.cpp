/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   graph.cpp                                                  _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/18 13:32:51 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/21 14:29:09 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "graph.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

Graph::Graph(const Vector2& size): size(size), line(Vector2(0.0f, 0.0f)){}

bool Graph::isInside(const Vector2& point) const{
	return point.getX() >= 0
		&& point.getY() >= 0
		&& point.getX() < size.getX()
		&& point.getY() < size.getY();
}

bool Graph::addPoint(const Vector2& point){
	if (!isInside(point))
		return false;
	points.push_back(point);
	calculateLine();
	return true;
}


void Graph::loadPoints(const std::string& filename){
	std::ifstream file(filename.c_str());
	float x;
	float y;

	if (!file)
		throw std::runtime_error("Could not open points file");
	while (file >> x >> y){
		if (!addPoint(Vector2(x, y)))
			throw std::runtime_error("Point is outside the graph");
	}
	if (!file.eof())
		throw std::runtime_error("Invalid point file format");
	calculateLine();
}

bool Graph::hasPoint(int x, int y) const{
	std::vector<Vector2>::const_iterator it;

	for (it = points.begin(); it != points.end(); ++it){
		if (static_cast<int>(it->getX()) == x
			&& static_cast<int>(it->getY()) == y)
			return true;
	}
	return false;
}

void Graph::display() const{
	int x;
	int y;

	for (y = static_cast<int>(size.getY()) - 1; y >= 0; --y){
		std::cout << y << " ";
		for (x = 0; x < static_cast<int>(size.getX()); ++x){
			if (hasPoint(x, y))
				std::cout << "X ";
			else
				std::cout << ". ";
		}
		std::cout << std::endl;
	}
	std::cout << "  ";
	for (x = 0; x < static_cast<int>(size.getX()); ++x)
		std::cout << x << " ";
	std::cout << std::endl;
}

const std::vector<Vector2>& Graph::getPoints() const {
	return points;
}

const Vector2& Graph::getSize() const {
	return size;
}

// Rendering PNG

void drawDigit(std::vector<std::vector<unsigned char> >& image, int digit, int startX, int startY){
	static const char digits[10][7][6] = {
		{
			"01110",
			"10001",
			"10011",
			"10101",
			"11001",
			"10001",
			"01110"
		},
		{
			"00100",
			"01100",
			"00100",
			"00100",
			"00100",
			"00100",
			"01110"
		},
		{
			"01110",
			"10001",
			"00001",
			"00010",
			"00100",
			"01000",
			"11111"
		},
		{
			"11110",
			"00001",
			"00001",
			"01110",
			"00001",
			"00001",
			"11110"
		},
		{
			"00010",
			"00110",
			"01010",
			"10010",
			"11111",
			"00010",
			"00010"
		},
		{
			"11111",
			"10000",
			"10000",
			"11110",
			"00001",
			"00001",
			"11110"
		},
		{
			"00110",
			"01000",
			"10000",
			"11110",
			"10001",
			"10001",
			"01110"
		},
		{
			"11111",
			"00001",
			"00010",
			"00100",
			"01000",
			"01000",
			"01000"
		},
		{
			"01110",
			"10001",
			"10001",
			"01110",
			"10001",
			"10001",
			"01110"
		},
		{
			"01110",
			"10001",
			"10001",
			"01111",
			"00001",
			"00010",
			"01100"
		}
	};

	if (digit < 0 || digit > 9)
		return ;

	for (int y = 0; y < 7; ++y){
		for (int x = 0; x < 5; ++x){
			if (digits[digit][x][y] == '1'){
				int pixelX = startX + x;
				int pixelY = startY + y;

				if (pixelX >= 0
					&& pixelX < static_cast<int>(image[0].size() / 3)
					&& pixelY >= 0
					&& pixelY < static_cast<int>(image.size())
				){
					image[pixelY][pixelX * 3] = 0;
					image[pixelY][pixelX * 3 + 1] = 0;
					image[pixelY][pixelX * 3 + 2] = 0;
				}
			}
		}
	}
}

void drawNumber(std::vector<std::vector<unsigned char> >& image,
	int number,
	int centerX,
	int centerY
){
	if (number < 0)
		return;

	if (number < 10){
		drawDigit(image, number, centerX - 2, centerY - 3);
		return ;
	}

	int whole = number / 10;
	int small = number % 10;

	drawNumber(image, whole, centerX - 5, centerY - 3);
	drawDigit(image, small, centerX + 1, centerY - 3);
}

void generatePNG(const Graph& graph, const std::string& filename){
	FILE *file = std::fopen(filename.c_str(), "wb");
	if (!file)
		return ;

	png_structp png = png_create_write_struct(
		PNG_LIBPNG_VER_STRING,
		NULL, NULL, NULL
	);
	if (!png){
		std::fclose(file);
		return ;
	}

	png_infop info = png_create_info_struct(png);
	if (!info){
		png_destroy_write_struct(&png, NULL);
		std::fclose(file);
		return ;
	}

	png_init_io(png, file);

	int scale = 100;
	int point_size = 10;
	int margin = 50;
	
	int graph_width = static_cast<int>(graph.getSize().getX());
	int graph_height = static_cast<int>(graph.getSize().getY());

	int graph_pixel_width = (graph_width - 1) * scale;
	int graph_pixel_height = (graph_height - 1) * scale;

	int width = graph_pixel_width + margin * 2;
	int height = graph_pixel_height + margin * 2;

	png_set_IHDR(
		png,
		info,
		static_cast<png_uint_32>(width),
		static_cast<png_uint_32>(height),
		8,
		PNG_COLOR_TYPE_RGB,
		PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_DEFAULT,
		PNG_FILTER_TYPE_DEFAULT
	);

	png_write_info(png, info);

	std::vector<std::vector<unsigned char> > image(
		height,
		std::vector<unsigned char>(width * 3, 255)
	);

	// Draw Grid
	for (int y = 0; y < graph_height; ++y){
		int pixelY = margin + y * scale;
		for (int x =0; x < width; ++x){
			if (x % scale == 0 || y % scale == 0){
				image[pixelY][x * 3] = 220;
				image[pixelY][x * 3 + 1] = 220;
				image[pixelY][x * 3 + 2] = 220;
			}
		}
	}
	
	// Draw Grid
	for (int x = 0; x < graph_width; ++x){
		int pixelX = margin + x * scale;
		for (int y =0; y < height; ++y){
			if (y % scale == 0 || x % scale == 0){
				image[y][pixelX * 3] = 220;
				image[y][pixelX * 3 + 1] = 220;
				image[y][pixelX * 3 + 2] = 220;
			}
		}
	}

	// Draw axis
	int x_axis = margin + graph_pixel_height;

	for (int x = margin; x <= margin + graph_pixel_width; ++x){
		for (int thic = 0; thic < 3; ++thic){
			int y = x_axis + thic;

			if (y < height)
			{
				image[y][x * 3] = 0;
				image[y][x * 3 + 1] = 0;
				image[y][x * 3 + 2] = 0;
			}
		}
	}
	
	int y_axis = margin;

	for (int y = margin; y < margin + graph_pixel_height; ++y){
		for (int thic = 0; thic < 3; ++thic){
			int x = y_axis + thic;

			if (x < width)
			{
				image[y][x * 3] = 0;
				image[y][x * 3 + 1] = 0;
				image[y][x * 3 + 2] = 0;
			}
		}
	}

	
	// Draw Line
	Vector2 line = graph.getLine();
	
	float a = line.getX();
	float b = line.getY();

	for (int x = 0; x < graph_width - 1; ++x){
		float x1 = static_cast<float>(x);
		float x2 = static_cast<float>(x + 1);

		float y1 = a * x1 + b;
		float y2 = a * x2 + b;

		int pixelX1 = margin + x * scale;
		int pixelX2 = margin + (x + 1) * scale;

		int pixelY1 = margin + static_cast<int>((graph_height - 1 - y1) * scale);
		int pixelY2 = margin + static_cast<int>((graph_height - 1 - y2) * scale);

		int dx = pixelX2 - pixelX1;
		int dy = pixelY2 - pixelY1;

		int steps = std::abs(dx);

		if (std::abs(dy) > steps)
			steps = std::abs(dy);

		if (steps == 0)
			steps = 1;

		for (int i = 0; i <= steps; ++i){
			int pixelX = pixelX1 + dx * i / steps;
			int pixelY = pixelY1 + dy * i / steps;

			if (pixelX >= 0 && pixelX < width && pixelY >= 0 && pixelY < height){
				image[pixelY][pixelX * 3] = 100;
				image[pixelY][pixelX * 3 + 1] = 100;
				image[pixelY][pixelX * 3 + 2] = 100;
			}
		}
		
	}

	// Draw Points
	const std::vector<Vector2>& points = graph.getPoints();
	for (std::vector<Vector2>::const_iterator it = points.begin();
		it != points.end(); ++it)
	{
		int centerX = margin + static_cast<int>(it->getX()) * scale;
		int centerY = margin + (graph_height - 1 - static_cast<int>(it->getY())) * scale;

		int point_startX = centerX - point_size / 2;
		int point_startY = centerY - point_size / 2;

		for (int y = point_startY; y < point_startY + point_size; ++y){
			for (int x = point_startX; x < point_startX + point_size; ++x){
				image[y][x * 3] = 0;
				image[y][x * 3 + 1] = 0;
				image[y][x * 3 + 2] = 0;
			}
		}
	}

	// Draw numbers
	for (int x = 0; x < graph_width; ++x){
		int pixelX = margin + x * scale;

		drawNumber(image, x, pixelX, x_axis + 12);
	}
	
	for (int y = 0; y < graph_height; ++y){
		int pixelY = margin + (graph_height - 1 - y) * scale;

		drawNumber(image, y, margin - 12, pixelY);
	}

	

	std::vector<png_bytep> rows(height);

	for (int y = 0; y < height; ++y)
		rows[y] = &image[y][0];

	png_write_image(png, &rows[0]);
	png_write_end(png, NULL);
	png_destroy_write_struct(&png, &info);
	std::fclose(file);

	return ;
}



// Line part

void Graph::calculateLine(){
	float sumX = 0.0f;
	float sumY = 0.0f;
	float sumXY = 0.0f;
	float sumX2 = 0.0f;

	int n = static_cast<int>(points.size());

	if (n == 0){
		line = Vector2(0.0f, 0.0f);
		return ;
	}

	for (std::vector<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it){
		float x = it->getX();
		float y = it->getY();

		sumX += x;
		sumY += y;
		sumXY += x * y;
		sumX2 += x * x;
	}

	float denominator = n * sumX2 - sumX * sumX;

	if (denominator == 0.0f){
		line = Vector2(0.0f, sumY / n);
		return ;
	}

	float a = (n * sumXY - sumX * sumY) / denominator;
	float b = (sumY - a * sumX) / n;

	line = Vector2(a, b);
}

const Vector2& Graph::getLine() const {
	return line;
}
