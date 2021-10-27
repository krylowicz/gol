#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "GameOfLife.hh"

using namespace ci;

bool GameOfLife::isCellActive(size_t i, size_t j) const {
  return state(i, j);
}

void GameOfLife::setCellActive(size_t i, size_t j) {
  state(i, j) = 1;
}

void GameOfLife::setCellInactive(size_t i, size_t j) {
  state(i, j) = 1;
}

void GameOfLife::setup() {}

void GameOfLife::draw() {
  gl::clear();
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (isCellActive(i, j)) {
        auto top {ci::vec2(i * res, j * res)};
        auto bottom {ci::vec2((i + 1) * res - 1, (j + 1) * res - 1)};        

        gl::drawSolidRect(Rectf(top, bottom));
      }
    }
  }
}
