#include "view/shapes/ellipse.h"

#include <math.h>

#include "imgui.h"

namespace USTC_CG
{
void Ellipse::draw(const Config& config) const
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    draw_list->AddEllipse(
        ImVec2(
            config.bias[0] + center_point_x_, config.bias[1] + center_point_y_),
        radius_x_,
        radius_y_,
        IM_COL32(
            config.line_color[0],
            config.line_color[1],
            config.line_color[2],
            config.line_color[3],
            0.f,
            0,
            config.line_thickness));
}

void Ellipse::update(float x, float y)
{
    radius_x_ = fabsf(center_point_x_ - x);
    radius_y_ = fabsf(center_point_y_ - y);
}
};  // namespace USTC_CG