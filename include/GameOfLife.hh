#pragma once

#include "cinder/app/App.h"
#include "xtensor/xtensor.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xrandom.hpp"

using namespace ci;

class GameOfLife : public app::App {
  private:
    const size_t res {10};
    const size_t rows {app::getWindowWidth() / res};
    const size_t cols {app::getWindowHeight() / res};
    xt::xarray<unsigned> state {xt::random::randint<unsigned>({rows, cols}, 0, 2)};
  
  public:
    bool isCellActive(size_t i, size_t j) const;
    void setCellActive(size_t i, size_t j);
    void setCellInactive(size_t i, size_t j);

    unsigned countNeighbours(size_t i, size_t j) const;
    void next();

    void setup() override;
    void draw() override;
};
