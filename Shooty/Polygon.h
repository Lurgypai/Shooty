#pragma once
#include "stdafx.h"

class Polygon {
private:
	std::vector<sf::Vertex> vertices;
public:
	Polygon(void);
	Polygon(std::vector<sf::Vertex> vertices_);
	void addVertex(sf::Vertex vertex);

	std::vector<sf::Vertex>* getVertices();
	bool contains(sf::Vector2f point) const;
	bool contains(sf::Vertex point);
};