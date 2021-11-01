#pragma once

#include "cinder/app/KeyEvent.h"

using namespace ci;

class GolViewer {
  private:
    bool playing {true};

  public:
    GolViewer() = default;

    void keyDown(app::KeyEvent& event);
};