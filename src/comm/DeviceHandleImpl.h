/*----------------------------------------------------------------------------------------------------------------------   

                 %%%%%%%%%%%%%%%%%                
                 %%%%%%%%%%%%%%%%%
                 %%%           %%%
                 %%%           %%%
                 %%%           %%%
%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% www.shaduzlabs.com %%%%%

------------------------------------------------------------------------------------------------------------------------

  Copyright (C) 2014 Vincenzo Pacella

  This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
  License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later
  version.

  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along with this program.  
  If not, see <http://www.gnu.org/licenses/>.

----------------------------------------------------------------------------------------------------------------------*/
#pragma once

namespace sl
{
namespace kio
{

//----------------------------------------------------------------------------------------------------------------------

class Transfer;

//----------------------------------------------------------------------------------------------------------------------

class DeviceHandleImpl
{

public:
  
  virtual ~DeviceHandleImpl(){}

  virtual void disconnect() = 0;

  virtual bool read( Transfer&, uint8_t ) = 0;
  virtual bool write( const Transfer&, uint8_t ) const = 0;

};
  
//----------------------------------------------------------------------------------------------------------------------

} // kio
} // sl
