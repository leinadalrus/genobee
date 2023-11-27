#include "../include/MissionScene.hpp"
#include <algorithm>
#include <numeric>

struct GridmapScalar {
  int x = 0, y = 0;
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

class ViewportPanorama {
  struct GridmapScalar gridmapData;

  int static deduce(std::vector<int> stream) {
    std::vector<int> temporaries;
    auto transformed =
        std::transform(stream.begin(), stream.end(), temporaries.begin(),
                       [](int output) { return output; });

    return *transformed;
  }

  int leftFoldMinMax(std::vector<int> columns) {
    return std::accumulate(columns.begin(), columns.end(), 0, deduce);
  }

  int rightFoldMinMax(std::vector<int> columns) {
    return std::accumulate(columns.rbegin(), columns.rend(), 0, deduce);
  }

public:
  struct GridmapScalar diagonalDifference(std::vector<int> columns) {
    auto x = this->leftFoldMinMax(columns);
    auto y = this->rightFoldMinMax(columns);

    return {x, y};
  }
};
