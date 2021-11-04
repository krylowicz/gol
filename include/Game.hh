#pragma once

#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "GameOfLife.hh"
#include "GolViewer.hh"
#include "Window.hh"

using namespace ci;

class Game : public app::App {
  private:
    Window window {};
    GameOfLife gol {window};
    GolViewer viewer {gol, window};

  public:
    void setup() override;
    void draw() override;

    void keyDown(app::KeyEvent event) override { viewer.keyDown(event); }
    void mouseDown(app::MouseEvent event) override { viewer.mouseDown(event); }
    void mouseUp(app::MouseEvent event) override { viewer.mouseUp(event); }
    void mouseDrag(app::MouseEvent event) override { viewer.mouseDrag(event); }
};