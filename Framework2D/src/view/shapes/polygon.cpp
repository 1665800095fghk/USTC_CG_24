#include "view/shapes/polygon.h"

namespace USTC_CG {
void Polygon::draw(const Config &config) const {
  if (points_.size() < 2)
    return;
  ImDrawList *draw_list = ImGui::GetWindowDrawList();
  draw_list->AddPolyline(points_.data(), points_.size(),
                         IM_COL32(config.line_color[0], config.line_color[1],
                                  config.line_color[2], config.line_color[3]),
                         ImDrawFlags_Closed, config.line_thickness);
}

void Polygon::draw_preview(const Config &config, ImVec2 mouse_pos) const {
  if (points_.empty())
    return;

  ImDrawList *draw_list = ImGui::GetWindowDrawList();
  for (size_t i = 1; i < points_.size(); ++i) {
    draw_list->AddLine(points_[i - 1], points_[i],
                       IM_COL32(config.line_color[0], config.line_color[1],
                                config.line_color[2], config.line_color[3]),
                       config.line_thickness);
  }
  draw_list->AddLine(points_.back(), mouse_pos,
                     IM_COL32(config.line_color[0], config.line_color[1],
                              config.line_color[2], config.line_color[3]),
                     config.line_thickness);
}

void Polygon::update(float x, float y) {
  if (!finished_)
    points_.emplace_back(x, y);
}

void Polygon::finish() { finished_ = true; }
}; // namespace USTC_CG