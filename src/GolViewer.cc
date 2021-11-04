#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "GameOfLife.hh"
#include "GolViewer.hh"

using namespace ci;

GolViewer::GolViewer(GameOfLife& gol_): gol {gol_} {}

void GolViewer::keyDown(app::KeyEvent& event) {
  if (event.KEY_SPACE) {
    if (playing) {
      app::setFrameRate(0.0f);
      playing = false;  
    } else {
      app::setFrameRate(60.0f);
      playing = true;
    }  
  }
}

void GolViewer::mouseDown(app::MouseEvent& event) {
  if (event.isLeft()) {
    drawing = true;
    auto i {event.getX()};
    auto j {event.getY()};

    if (i > 0 && j > 0 && i < app::getWindowWidth() && j < app::getWindowHeight()) {
      i = (i * 60) / app::getWindowWidth();
      j = (j * 40) / app::getWindowHeight();

      gol.setCellActive(i, j);
    }
  }
  if (event.isRight()) {
    drawing = true;
    auto i {event.getX()};
    auto j {event.getY()};

    if (i > 0 && j > 0 && i < app::getWindowWidth() && j < app::getWindowHeight()) {
      i = (i * 60) / app::getWindowWidth();
      j = (j * 40) / app::getWindowHeight();

      gol.setCellInactive(i, j);
    }
  }
}

void GolViewer::mouseUp(app::MouseEvent& event) {
  if (drawing) {
    if (event.isLeft() || event.isRight()) {
      drawing = false;
    }
  }
}

void GolViewer::mouseDrag(app::MouseEvent& event) {
  if (drawing) {
    if (event.isLeft()) {
      auto i {event.getX()};
      auto j {event.getY()};

      i = (i * 60) / app::getWindowWidth();
      j = (j * 40) / app::getWindowHeight();

      gol.setCellActive(i, j);
    }
    if (event.isRight()) {
      auto i {event.getX()};
      auto j {event.getY()};

      i = (i * 60) / app::getWindowWidth();
      j = (j * 40) / app::getWindowHeight();

      gol.setCellInactive(i, j);
    }
  }
}