#pragma once

#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "xtensor/xtensor.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xrandom.hpp"
#include "GolViewer.hh"

using namespace ci;

class GameOfLife : public app::App {
  private:
    GolViewer golViewer {};

    const size_t res {10};
    const size_t rows {app::getWindowWidth() / res};
    const size_t cols {app::getWindowHeight() / res};
    xt::xarray<unsigned> state {xt::random::randint<unsigned>({rows, cols}, 0, 2)};
  
  public:
    GameOfLife() = default;

    bool isCellActive(size_t i, size_t j) const;
    void setCellActive(size_t i, size_t j);
    void setCellInactive(size_t i, size_t j);

    unsigned countNeighbours(size_t i, size_t j) const;
    void next();

    void setup() override;
    void draw() override;

    void keyDown(app::KeyEvent event) override { golViewer.keyDown(event); }
};
