#pragma once

#include "imgui.h"
#include "line.h"
#include "shape.h"
#include <vector>

namespace USTC_CG {
class Polygon : public Shape {
public:
  Polygon() = default;
  Polygon(float x, float y) { points_.emplace_back(x, y); }
  virtual ~Polygon() = default;
  //   void AddPolyline(const ImVec2 *points, int num_points, ImU32 col,
  //                    ImDrawFlags flags, float thickness)

  void draw(const Config &config) const override;
  void draw_preview(const Config &config, ImVec2 mouse_pos) const;
  void update(float x, float y) override;

  void finish();

private:
  std::vector<ImVec2> points_;
  bool finished_ = false;
};
}; // namespace USTC_CG