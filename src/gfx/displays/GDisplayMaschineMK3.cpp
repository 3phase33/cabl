/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#include "gfx/displays/GDisplayMaschineMK3.h"

#include "cabl/util/Functions.h"

//--------------------------------------------------------------------------------------------------

namespace sl
{
namespace cabl
{

//--------------------------------------------------------------------------------------------------

void GDisplayMaschineMK3::setPixel(
  unsigned x_, unsigned y_, const Color& color_, bool bSetDirtyChunk_)
{
  if (x_ >= width() || y_ >= height() || color_.transparent())
  {
    return;
  }

  unsigned byteIndex = (canvasWidthInBytes() * y_) + (x_ * 2);

  data()[byteIndex+1] = (uint8_t)color_.getRGB565() >> 8;
  data()[byteIndex] = (uint8_t)color_.getRGB565() & 0xFF;
}

//--------------------------------------------------------------------------------------------------

Color GDisplayMaschineMK3::pixel(unsigned x_, unsigned y_) const
{
  if (x_ >= width() || y_ >= height())
  {
    return {};
  }

  unsigned byteIndex = (canvasWidthInBytes() * y_) + (x_ * 2);

  if ((data()[(canvasWidthInBytes() * y_) + (x_ >> 3)] & (0x80 >> (x_ & 7))) == 0)
  {
    return {0};
  }

  uint16_t color = (data()[byteIndex+1] << 8) +data()[byteIndex];


  return { (uint8_t)((color & 0x001F) << 3), (uint8_t)((color & 0x07E0) >> 3), (uint8_t)((color & 0xF800) >> 8)  };
}

//--------------------------------------------------------------------------------------------------

} // namespace cabl
} // namespace sl
