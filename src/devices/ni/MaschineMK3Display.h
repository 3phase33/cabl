/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#pragma once

#include <array>
#include <map>

#include "cabl/devices/Device.h"
#include "gfx/displays/GDisplayMaschineMK3.h"

namespace sl
{
    namespace cabl
    {

//--------------------------------------------------------------------------------------------------

        class MaschineMK3Display : public Device
        {

        public:

            void setButtonLed(Device::Button, const Color&) override
            {
            }
            void setKeyLed(unsigned, const Color&) override
            {
            }

            Canvas* graphicDisplay(size_t displayIndex_) override;

            size_t numOfGraphicDisplays() const override
            {
                return 2;
            }

            size_t numOfTextDisplays() const override
            {
                return 0;
            }

            size_t numOfLedMatrices() const override
            {
                return 0;
            }

            size_t numOfLedArrays() const override
            {
                return 0;
            }

            bool tick() override;

        private:
            static constexpr uint8_t kMASMK3_nDisplays = 2;

            bool sendDisplayData() const;

            void init() override;
            bool sendFrame(uint8_t displayIndex);
            void initDisplay() const;

            GDisplayMaschineMK3 m_displays[kMASMK3_nDisplays];
        };

//--------------------------------------------------------------------------------------------------

        M_REGISTER_DEVICE_CLASS(
                MaschineMK3Display, "Maschine MK3 Displays", DeviceDescriptor::Type::USB, 0x17CC, 0x1600);

//--------------------------------------------------------------------------------------------------

    } // namespace cabl
} // namespace sl
