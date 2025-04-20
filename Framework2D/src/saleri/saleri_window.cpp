#include "saleri_window.h"

#include <iostream>

#include "imgui.h"

namespace USTC_CG
{
MiniDraw::MiniDraw(const std::string& window_name) : Window(window_name)
{
    canvasShow = true;
    draw_status_ = false;
}
MiniDraw::~MiniDraw()
{
}

void MiniDraw::draw()
{
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    if (ImGui::Begin("Canvas", &canvasShow, ImGuiWindowFlags_NoDecoration))
    {
        if (ImGui::Button("Line"))
            std::cout << "This is a line button" << std::endl;
        if (ImGui::Button("Rect"))
            std::cout << "This is a Rect button" << std::endl;

        // 绘制元素列表
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        const auto& canvas_main = ImGui::GetCursorPos();
        const auto& canvas_size = ImGui::GetContentRegionAvail();
        const auto& canvas_max = ImVec2(
            canvas_main.x + canvas_size.x, canvas_main.y + canvas_size.y);
        draw_list->AddRectFilled(
            canvas_main, canvas_max, IM_COL32(50, 50, 50, 255));
        draw_list->AddRect(
            canvas_main, canvas_max, IM_COL32(255, 255, 255, 255));

        ImGui::SetCursorScreenPos(canvas_main);
        ImGui::InvisibleButton(
            "Canvas.InvisibleButton",
            canvas_size,
            ImGuiButtonFlags_MouseButtonLeft);
        bool is_hovered = ImGui::IsItemHovered();
        ImGuiIO& io = ImGui::GetIO();
        const ImVec2 mouse_pos = io.MousePos;
        if (is_hovered && !draw_status_ &&
            ImGui::IsMouseClicked(ImGuiMouseButton_Left))
        {
            draw_status_ = true;
            start_point_ = end_point_ = mouse_pos;
        }
        if (draw_status_)
        {
            end_point_ = mouse_pos;
            if (!ImGui::IsMouseDown(ImGuiMouseButton_Left))
            {
                draw_status_ = false;
                std::shared_ptr<Line> p_line = std::make_shared<Line>(
                    start_point_.x, start_point_.y, end_point_.x, end_point_.y);
                line_list_.push_back(p_line);
            }
        }
        for (const auto& p_line : line_list_)
        {
            p_line->draw();
        }
        if (draw_status_)
            draw_list->AddLine(
                start_point_, end_point_, IM_COL32(255, 0, 0, 255), 2.0f);
    }
    ImGui::End();
}
}  // namespace USTC_CG