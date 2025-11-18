#include <format>
#include <vector>
#include <glaze/glaze.hpp>

#pragma once

struct Point {
public:
    uint8_t x;
    uint8_t y;
    bool collision;
    Point(int x, int y, bool collision = false) : x(x), y(y), collision(collision) {};
    std::string toString() {
        return std::format("{},{}", this->x, this->y);
    }
    Point() : x(0), y(0), collision(false) {};
    bool operator==(const Point& otherpoint) const {
        return this->x == otherpoint.x && this->y == otherpoint.y;
    }
};


struct Edge {
public:
    int idMapConnect = 0;
    Point Grid1Point;
    Point Grid2Point;
    Edge(int idMapConnect, Point& Grid1Point, Point& Grid2Point) : idMapConnect(idMapConnect), Grid1Point(Grid1Point), Grid2Point(Grid2Point) {};
	Edge() : idMapConnect(0), Grid1Point(), Grid2Point() {};
};

class Grid {
public:
    std::vector<Point> points; //1D or 2D? x*ymax + y 
    std::vector<Edge> Edges;
    unsigned short  id = 0;
    uint8_t width = 0;
    uint8_t height = 0;
    Grid(int id, int width, int height) : id(id), width(width), height(height) {}
	Grid() : id(0), width(1), height(1) {}
    const Point& getPoint(int x, int y) const{
        return points[(x * height) + y];
    }
    const Edge getEdge(int mapidconnect,int& lengthoperations) const{
        for(auto& edge: Edges){
            lengthoperations += 2;
            if (edge.idMapConnect == mapidconnect) {
                return edge;
            }
        }
        return Edge();
    }
};


class Graph {
public:
    //Vector Siatek i generowanie miedzy nimi przejsc?
    std::vector<Grid>Grids;
    Graph() {};
};

template <>
struct glz::meta<Point> {
    using T = Point;
    static constexpr auto value = object(
        "x",& T::x,
        "y",& T::y,
        "collision",& T::collision
    );
};
template <>
struct glz::meta<Edge> {
    using T = Edge;
    static constexpr auto value = object(
        "idMapConnect",& T::idMapConnect,
        "Grid1Point",& T::Grid1Point,
        "Grid2Point",& T::Grid2Point
    );
};
template <>
struct glz::meta<Grid> {
    using T = Grid;
    static constexpr auto value = object(
        "points",& T::points,
        "Edges",& T::Edges,
        "id",& T::id,
        "width",& T::width,
        "height",& T::height
    );
};
template <>
struct glz::meta<Graph> {
    using T = Graph;
    static constexpr auto value = object(
        "Grids", &T::Grids
    );
};