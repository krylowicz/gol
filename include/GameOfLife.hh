#include "cinder/app/App.h"
#include "xtensor/xtensor.hpp"
#include "xtensor/xarray.hpp"

using namespace ci;

class GameOfLife : public app::App {
  private:
    const size_t res {10};
    const size_t rows {app::getWindowWidth() / res};
    const size_t cols {app::getWindowHeight() / res};
    xt::xarray<double> state = xt::ones<double>({rows, cols});

  public:
    bool isCellActive(size_t i, size_t j) const;
    void setCellActive(size_t i, size_t j);
    void setCellInactive(size_t i, size_t j);

    void setup() override;
    void draw() override;
};
