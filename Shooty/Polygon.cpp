#include "stdafx.h"
#include "Polygon.h"

Polygon::Polygon(void) {}

Polygon::Polygon(std::vector<sf::Vertex> vertices_) : vertices(vertices_) {}

void Polygon::addVertex(sf::Vertex vertex) {
	vertices.push_back(vertex);
}

std::vector<sf::Vertex>* Polygon::getVertices() {
	return &vertices;
}

bool Polygon::contains(sf::Vector2f point) const {
		bool isContained = false;
		std::vector<sf::Vertex>::const_iterator i, j;
		for (i = vertices.begin(), j = vertices.end() - 1; i != vertices.end(); j = i++) {
			if (((i->position.y > point.y) != (j->position.y > point.y)) &&
				(point.x <  (point.y - i->position.y) * (j->position.x - i->position.x) / (j->position.y - i->position.y) + i->position.x))
				isContained = !isContained;
		}
		return isContained;
}

bool Polygon::contains(sf::Vertex point) {
	return false;
}
