#include "Line.h"

#include "imgui.h"

namespace USTC_CG
{

Line::~Line() {

}
void Line::draw()
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    draw_list->AddLine(
        ImVec2(start_point_x_, start_point_y_),
        ImVec2(end_point_x_, end_point_y_),
        IM_COL32(255, 0, 0, 255),
        2.0f);
}
};  // namespace USTC_CG