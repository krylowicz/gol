#pragma once

#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "xtensor/xtensor.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xrandom.hpp"

using namespace ci;

class GameOfLife {
  public:
    const size_t res;
    const size_t rows;
    const size_t cols;
    xt::xarray<unsigned> state {xt::random::randint<unsigned>({rows, cols}, 0, 2)};    

  public:
    GameOfLife(const size_t res, const size_t rows, const size_t cols);

    bool isCellActive(size_t i, size_t j) const;
    void setCellActive(size_t i, size_t j);
    void setCellInactive(size_t i, size_t j);

    unsigned countNeighbours(size_t i, size_t j) const;
    void next();
};
