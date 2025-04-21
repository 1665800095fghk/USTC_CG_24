#pragma once

#include "shape.h"

namespace USTC_CG
{
class Ellipse : public Shape
{
   public:
    Ellipse() = default;

    // void AddEllipse(const ImVec2& center, float radius_x, float radius_y,
    // ImU32 col, float rot = 0.0f, int num_segments = 0, float thickness
    // = 1.0f);
    Ellipse(
        float center_point_x,
        float center_point_y,
        float radius_x,
        float radius_y)
        : center_point_x_(center_point_x),
          center_point_y_(center_point_y),
          radius_x_(radius_x),
          radius_y_(radius_y)
    {
    }

    virtual ~Ellipse() = default;

    void draw(const Config& config) const override;

    void update(float x, float y) override;

   private:
    float center_point_x_, center_point_y_, radius_x_, radius_y_;
};
};  // namespace USTC_CG