/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#include "devices/ni/MaschineMK3.h"

#include "cabl/comm/Driver.h"
#include "cabl/comm/Transfer.h"
#include "cabl/util/Functions.h"

#include <thread>
#include "gfx/displays/NullCanvas.h"
#include <sstream>
#include <iostream>

#include "cabl/gfx/TextDisplay.h"
#include "MaschineMK3Display.h"

//--------------------------------------------------------------------------------------------------

namespace
{
    const uint8_t kMASMK3_epDisplay = 0x04;
} // namespace

//--------------------------------------------------------------------------------------------------

namespace sl
{
    namespace cabl
    {

        Canvas* MaschineMK3Display::graphicDisplay(size_t displayIndex_)
        {
            static NullCanvas s_dummyDisplay;
            if (displayIndex_ > 1)
            {
                return &s_dummyDisplay;
            }

            return &m_displays[displayIndex_];
        }

//--------------------------------------------------------------------------------------------------

        bool MaschineMK3Display::tick()
        {
            bool success;

            for (uint8_t displayIndex = 0; displayIndex < 2; displayIndex++)
            {
                if (m_displays[displayIndex].dirty())
                {
                    success = sendFrame(displayIndex);
                    m_displays[displayIndex].resetDirtyFlags();
                }
                else
                {
                    success = true;
                }
            }

            return success;
        }

//--------------------------------------------------------------------------------------------------

        void MaschineMK3Display::init()
        {
            m_displays[0].white();
            m_displays[1].white();
        }

//--------------------------------------------------------------------------------------------------

        void MaschineMK3Display::initDisplay() const
        {
            //!\todo set backlight
            return;
        }

//--------------------------------------------------------------------------------------------------

        bool MaschineMK3Display::sendFrame(uint8_t displayIndex_)
        {
            if (displayIndex_ > 1)
            {
                return false;
            }
            std::cout << "Sending frame123" << std::endl;



            for (uint16_t row=0; row<272;row++) {
                const uint8_t* ptr = m_displays[displayIndex_].buffer() + (row*480*2);

            if (!writeToDeviceHandle(Transfer(
                    {0x84, 0x00, displayIndex_, 0x60, 0x00, 0x00, 0x00, 0x00,
                     0x00, 0x00, (uint8_t)(row) << 8, (uint8_t)row, 0x01, 0xE0, 0x00, 0x01,
                     0x00, 0x00, 0x00, 0xF0},
                    ptr, 480 * 2,
                    { 0x03, 0x00,0x00, 0x00, 0x40,0x00,0x00,0x00}
                                     ),
                                     kMASMK3_epDisplay)) {
                std::cout << "Sending frame 3" << std::endl;
                return false;
            }
            }

            m_displays[displayIndex_].resetDirtyFlags();
            return true;
        }


//--------------------------------------------------------------------------------------------------

    } // namespace cabl
} // namespace sl
