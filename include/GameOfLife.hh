#pragma once

#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "xtensor/xtensor.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xrandom.hpp"
#include "Window.hh"

using namespace ci;

class GameOfLife {
  private:
    Window window;
    xt::xarray<unsigned> state {xt::zeros<unsigned>({window.rows, window.cols})};
    //xt::xarray<unsigned> state {xt::random::randint<unsigned>({rows, cols}, 0, 2)};

  public:
    GameOfLife(Window& window);

    bool isCellActive(size_t i, size_t j) const;
    void setCellActive(size_t i, size_t j);
    void setCellInactive(size_t i, size_t j);
    void drawCell(size_t i, size_t j) const;

    unsigned countNeighbours(size_t i, size_t j) const;
    void next();
};
