#include "scene_objects.hh"
#include "colour/colour.hh"
#include "geometry/sphere.hh"
#include "geometry/triangle.hh"
#include "vectors/vector_definitions.hh"

using Colours::BasicColour;
using Vectors::Vec;

auto SceneObjects::add_triangle(const Geometry &triangle) -> void {
  shapes.push_back(std::move(triangle));
}
auto SceneObjects::add_sphere(const Geometry &sphere) -> void {
  shapes.push_back(std::move(sphere));
}

auto SceneObjects::add_cuboid(Vec<3, double> LDB, Vec<3, double> RDB,
                              Vec<3, double> RDF, Vec<3, double> LDF,
                              Vec<3, double> LUB, Vec<3, double> RUB,
                              Vec<3, double> RUF, Vec<3, double> LUF, //
                              BasicColour D1, BasicColour D2, BasicColour L1,
                              BasicColour L2, BasicColour R1, BasicColour R2,
                              BasicColour B1, BasicColour B2, BasicColour F1,
                              BasicColour F2, BasicColour U1, BasicColour U2)
    -> void {
  // Form the 12 triangles

  // Down
  add_triangle(Geometry(Triangle(LDB, RDB, RDF, B1)));
  add_triangle(Geometry(Triangle(LDB, LDF, RDF, B2)));

  // Up
  add_triangle(Geometry(Triangle(LUB, RUB, RUF, U1)));
  add_triangle(Geometry(Triangle(LUB, LUF, RUF, U2)));

  // Left
  add_triangle(Geometry(Triangle(LDB, LUB, LUF, L1)));
  add_triangle(Geometry(Triangle(LDB, LDF, LUF, L2)));

  // Right
  add_triangle(Geometry(Triangle(RDB, RUB, RUF, R1)));
  add_triangle(Geometry(Triangle(RDB, RDF, RUF, R2)));

  // Back
  add_triangle(Geometry(Triangle(LDB, RDB, RUB, B1)));
  add_triangle(Geometry(Triangle(LDB, LUB, RUB, B2)));

  // Forward
  add_triangle(Geometry(Triangle(LDF, RDF, RUF, F1)));
  add_triangle(Geometry(Triangle(LDF, LUF, RUF, F2)));
}

auto SceneObjects::get_shapes() -> std::vector<Geometry> & { return shapes; }
