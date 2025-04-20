

namespace USTC_CG
{
class Line
{
   public:
    Line(void);
    Line(
        float start_point_x,
        float start_point_y,
        float end_point_x,
        float end_point_y)
    {
        start_point_x_ = start_point_x;
        start_point_y_ = start_point_y;
        end_point_x_ = end_point_x;
        end_point_y_ = end_point_y;
    }
    ~Line(void);

   public:
    void draw();

   private:
    float start_point_x_, start_point_y_, end_point_x_, end_point_y_;
};
};  // namespace USTC_CG