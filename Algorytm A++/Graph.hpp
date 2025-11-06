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
};


struct Edge {
public:
    int idMapConnect = 0;
    Point* Grid1Point = nullptr;
    Point* Grid2Point = nullptr;
    Edge(int idMapConnect, Point* Grid1Point, Point* Grid2Point) : idMapConnect(idMapConnect), Grid1Point(Grid1Point), Grid2Point(Grid2Point) {};
};

class Grid {
public:
    std::vector<Point> points; //1D or 2D? x*ymax + y 
    std::vector<Edge> Edges;
    unsigned short  id = 0;
    uint8_t width = 0;
    uint8_t height = 0;
    Grid(int id = 0, int width = 1, int height = 1) : id(id), width(width), height(height) {}
};


class Graph {
public:
    //Vector Siatek i generowanie miedzy nimi przejsc?
    std::vector<Grid>Grids;

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