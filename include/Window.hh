#pragma once

#include "cinder/app/App.h"

using namespace ci;

struct Window {
  const size_t res {10};
  const size_t rows {app::getWindowWidth() / res};
  const size_t cols {app::getWindowHeight() / res};
};