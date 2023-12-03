#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

#include "../include/PanoramaMap.hpp"
#include "../include/ICommand.hpp"
#include "../include/IDisposal.hpp"

struct PanoramaMapScalar {
  // NOTE(tuple): ...
  float x = 0, y = 0, z = 0;
};

class CompositeCommand {
public:
  void virtual Execute();
};

class InputHandler : public CompositeCommand {

public:
  void Execute() override { this->Handle(); }

  void Handle() {}
};

class PanoramaCommand {
  struct PanoramaMapScalar panoramaMapScalar;

  int const epsilon = 1.000000; // accurate up to 6 decimal points

  int static deduce(std::vector<int> stream) {
    std::vector<int> temporaries;
    auto transformed =
        std::transform(stream.begin(), stream.end(), temporaries.begin(),
                       [](int output) { return output; });

    return *transformed;
  }

  int leftFoldMinMax(std::vector<int> columns) {
    return std::accumulate(columns.begin(), columns.end(), deduce(columns));
  }

  // NOTE(reverse): ..rbegin and ..rend are a means to create a reverse fold
  int rightFoldMinMax(std::vector<int> columns) {
    return std::accumulate(columns.rbegin(), columns.rend(), deduce(columns));
  }

public:
  struct PanoramaMapScalar diagonalDifference(std::vector<int> columns) {
    float x = this->leftFoldMinMax(columns);
    float y = this->rightFoldMinMax(columns);

    return {x, y};
  }

  struct PanoramaMapScalar plot_vertex_point(float x, float y, float z) {
    return { .x = x, .y = y, .z = z};
  }

  bool are_vertices_equal(float column,
		float index) {
    if (index == column)
      return true;
  }

  int magnitude_of_tuple(float n) {
    plot_vertex_point(n, n, n); // NOTE(test)
    are_vertices_equal(n, n); // NOTE(test)
    n = std::abs(n);
    return n;
  };
};
