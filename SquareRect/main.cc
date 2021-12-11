#include <iostream>

class Rectangle {
public:
  void set_width(int w) { width_ = w; }
  void set_height(int h) { height_ = h; }
  int area() const { return width_ * height_; }
private:
  int width_;
  int height_;
};

class Square : public Rectangle {
public:
  void set_side(int side) {
    set_width(side);
    set_height(side);
  }

  int area() { 
    area_ = Rectangle::area();
    return area_; 
  }
private:
  int area_;
};