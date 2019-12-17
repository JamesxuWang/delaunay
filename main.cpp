#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>

#include "vector2.h"
#include "triangle.h"
#include "delaunay.h"

float RandomFloat(float a, float b) {
    const float random = ((float) rand()) / (float) RAND_MAX;
    const float diff = b - a;
    const float r = random * diff;
    return a + r;
}

int main(int argc, char * argv[])
{
	int numberPoints = 40;
	if (argc==1)
	{
		numberPoints = (int) roundf(RandomFloat(14, numberPoints));
	}
	else if (argc>1)
	{
		numberPoints = atoi(argv[1]);
	}
	srand (time(NULL));

	std::cout << "Generating " << numberPoints << " random points" << std::endl;

	std::vector<Vector2<float> > points;
	for(int i = 0; i < numberPoints; ++i) {
		points.push_back(Vector2<float>(RandomFloat(0, 800), RandomFloat(0, 600)));
	}

	Delaunay<float> triangulation;
	const std::vector<Triangle<float> > triangles = triangulation.triangulate(points);
	std::cout << triangles.size() << " triangles generated\n";
	const std::vector<Edge<float> > edges = triangulation.getEdges();

	std::cout << " ========= ";

	std::cout << "\nPoints : " << points.size() << std::endl;
	for(const auto &p : points)
		std::cout << p << std::endl;

	std::cout << "\nTriangles : " << triangles.size() << std::endl;
	for(const auto &t : triangles)
		std::cout << t << std::endl;

	std::cout << "\nEdges : " << edges.size() << std::endl;
	for(const auto &e : edges)
		std::cout << e << std::endl;

	
	return 0;
}
