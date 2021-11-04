#pragma once

#include <array>
#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "GameOfLife.hh"
#include "Window.hh"

using namespace ci;

class GolViewer {
  private:
    Window& window;
    GameOfLife& gol;

    bool drawing {false};
    bool playing {false};

  public:
    GolViewer(GameOfLife& gol, Window& window);

    bool isPlaying();

    bool isMouseInWindow(size_t, size_t j) const;
    std::array<size_t, 2> getCoordinates(size_t i, size_t j);

    void keyDown(app::KeyEvent& event);
    void mouseDown(app::MouseEvent& event);
    void mouseUp(app::MouseEvent& event);
    void mouseDrag(app::MouseEvent& event);
};