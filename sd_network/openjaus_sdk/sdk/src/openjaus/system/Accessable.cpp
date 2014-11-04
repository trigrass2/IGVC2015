/**
\file Accessable.h

\par Copyright
Copyright (c) 2012, OpenJAUS, LLC
All rights reserved.

This file is part of the OpenJAUS Software Development Kit (SDK). This 
software is distributed under one of two licenses, the OpenJAUS SDK 
Commercial End User License Agreement or the OpenJAUS SDK Non-Commercial 
End User License Agreement. The appropriate licensing details were included 
in with your developer credentials and software download. See the LICENSE 
file included with this software for full details.
 
THIS SOFTWARE IS PROVIDED BY THE LICENSOR (OPENJAUS LCC) "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE LICENSOR BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THE SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE. THE LICENSOR DOES NOT WARRANT THAT THE LICENSED SOFTWARE WILL MEET
LICENSEE'S REQUIREMENTS OR THAT THE OPERATION OF THE LICENSED SOFTWARE
WILL BE UNINTERRUPTED OR ERROR-FREE, OR THAT ERRORS IN THE LICENSED
SOFTWARE WILL BE CORRECTED.

\ Software History
- [2011-08-23] - Added AS6057: Manipulators
- [2011-08-01] - Added AS6060: Environment Sensing
- [2011-06-16] - First Release 

*/

#include "openjaus/system/Accessable.h"
#include <sstream>
// Start of user code for additional includes
// End of user code

namespace openjaus
{
namespace system
{

// Start of user code for default constructor:
Accessable::Accessable()
{
}
// End of user code

// Start of user code for default destructor:
Accessable::~Accessable()
{
}
// End of user code

bool Accessable::isGlobalRead() const
{
	// Start of user code for accessor getGlobalRead:
	
	return globalRead;
	// End of user code
}

bool Accessable::setGlobalRead(bool globalRead)
{
	// Start of user code for accessor setGlobalRead:
	this->globalRead = globalRead;
	return true;
	// End of user code
}


bool Accessable::isControllerRead() const
{
	// Start of user code for accessor getControllerRead:
	
	return controllerRead;
	// End of user code
}

bool Accessable::setControllerRead(bool controllerRead)
{
	// Start of user code for accessor setControllerRead:
	this->controllerRead = controllerRead;
	return true;
	// End of user code
}


bool Accessable::isControllerWrite() const
{
	// Start of user code for accessor getControllerWrite:
	
	return controllerWrite;
	// End of user code
}

bool Accessable::setControllerWrite(bool controllerWrite)
{
	// Start of user code for accessor setControllerWrite:
	this->controllerWrite = controllerWrite;
	return true;
	// End of user code
}


std::vector< std::string > Accessable::getOwnerUri() const
{
	// Start of user code for accessor getOwnerUri:
	
	return ownerUri;
	// End of user code
}

bool Accessable::setOwnerUri(std::string ownerUri)
{
	// Start of user code for accessor setOwnerUri:
	return true;
	// End of user code
}



// Class Methods


std::string Accessable::toString() const
{	
	// Start of user code for toString
	std::ostringstream oss;
	oss << "";
	return oss.str();
	// End of user code
}

std::ostream& operator<<(std::ostream& output, const Accessable& object)
{
    output << object.toString();
    return output;
}
// Start of user code for additional methods
// End of user code

} // namespace system
} // namespace openjaus

