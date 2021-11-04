#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "GameOfLife.hh"

using namespace ci;

GameOfLife::GameOfLife(const size_t res_, const size_t rows_, const size_t cols_)
  : res {res_}, rows {rows_}, cols {cols_} {};

bool GameOfLife::isCellActive(size_t i, size_t j) const {
  return state(i, j);
}

void GameOfLife::setCellActive(size_t i, size_t j) {
  state(i, j) = 1;
}

void GameOfLife::setCellInactive(size_t i, size_t j) {
  state(i, j) = 0;
}

unsigned GameOfLife::countNeighbours(size_t x, size_t y) const {
  unsigned neighbours {0};
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (isCellActive(x + i, y + j)) neighbours++;
    }
  }

  return neighbours - 1;
}

void GameOfLife::drawCell(size_t i, size_t j) const {
  if (isCellActive(i, j)) {
    auto top {ci::vec2(i * res, j * res)};
    auto bottom {ci::vec2((i + 1) * res, (j + 1) * res)};

    gl::drawSolidRect(Rectf(top, bottom));
  }
}

void GameOfLife::next() {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      auto neighbours {countNeighbours(i, j)};

      if (isCellActive(i, j) && neighbours == 0 || neighbours == 1) {
        setCellInactive(i, j);
      } else if (isCellActive(i, j) && neighbours >= 4) {
        setCellInactive(i, j);
      } else if (isCellActive(i, j) && neighbours >= 2 && neighbours <= 3) {
        setCellActive(i, j);
      } else if (!isCellActive(i, j) && neighbours == 3) {
        setCellActive(i, j);
      }
    }
  }
}