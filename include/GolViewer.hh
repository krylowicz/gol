#pragma once

#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "GameOfLife.hh"

using namespace ci;

class GolViewer {
  private:
    GameOfLife& gol;

    bool playing {false};
    bool drawing {false};

  public:
    GolViewer(GameOfLife& gol);

    void keyDown(app::KeyEvent& event);
    void mouseDown(app::MouseEvent& event);
    void mouseUp(app::MouseEvent& event);
    void mouseDrag(app::MouseEvent& event);
};