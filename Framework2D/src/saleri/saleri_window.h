#pragma once

#include <memory>

#include "shapes/Line.h"
#include "view/comp_canvas.h"
#include "view/comp_image.h"
#include "view/window.h"

namespace USTC_CG
{
class MiniDraw : public Window
{
   public:
    explicit MiniDraw(const std::string &window_name);
    ~MiniDraw();

    void draw();

   private:
    bool canvasShow;
    bool draw_status_;
    ImVec2 start_point_, end_point_;

    std::vector<std::shared_ptr<Line>> line_list_;
};
}  // namespace USTC_CG
