#pragma once

#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "GameOfLife.hh"
#include "GolViewer.hh"

class Game : public app::App {
  private:
    const size_t res {10};
    const size_t rows {app::getWindowWidth() / res};
    const size_t cols {app::getWindowHeight() / res};

    GameOfLife gol {res, rows, cols};
    GolViewer viewer {};

  public:
    void setup() override;
    void draw() override;

    void keyDown(app::KeyEvent event) override { viewer.keyDown(event); }
    void mouseDown(app::MouseEvent event) override { viewer.mouseDown(event); }
    void mouseUp(app::MouseEvent event) override { viewer.mouseUp(event); }
    void mouseDrag(app::MouseEvent event) override { viewer.mouseDrag(event); }
};