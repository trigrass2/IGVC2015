
/**
\file ReportGlobalVector.h

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

#include <openjaus.h>
#include "openjaus/mobility/Triggers/ReportGlobalVector.h"

namespace openjaus
{
namespace mobility
{

ReportGlobalVector::ReportGlobalVector() : 
	model::Message(),
	speed_mps(),
	altitude_m(),
	heading_rad(),
	roll_rad(),
	pitch_rad()
{
	this->id = ReportGlobalVector::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);

	this->presenceVector = 0;

	fields.push_back(&speed_mps);
	speed_mps.setName("Speed");
	speed_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&altitude_m);
	altitude_m.setName("Altitude");
	altitude_m.setOptional(true);
	// Nothing to init

	fields.push_back(&heading_rad);
	heading_rad.setName("Heading");
	heading_rad.setOptional(true);
	// Nothing to init

	fields.push_back(&roll_rad);
	roll_rad.setName("Roll");
	roll_rad.setOptional(true);
	// Nothing to init

	fields.push_back(&pitch_rad);
	pitch_rad.setName("Pitch");
	pitch_rad.setOptional(true);
	// Nothing to init

}

ReportGlobalVector::ReportGlobalVector(model::Message *message) :
	model::Message(message),
	speed_mps(),
	altitude_m(),
	heading_rad(),
	roll_rad(),
	pitch_rad()
{
	this->id = ReportGlobalVector::ID; // Initialize id member
	setType(transport::JAUS_MESSAGE);

	this->presenceVector = 0;

	fields.push_back(&speed_mps);
	speed_mps.setName("Speed");
	speed_mps.setOptional(true);
	// Nothing to init

	fields.push_back(&altitude_m);
	altitude_m.setName("Altitude");
	altitude_m.setOptional(true);
	// Nothing to init

	fields.push_back(&heading_rad);
	heading_rad.setName("Heading");
	heading_rad.setOptional(true);
	// Nothing to init

	fields.push_back(&roll_rad);
	roll_rad.setName("Roll");
	roll_rad.setOptional(true);
	// Nothing to init

	fields.push_back(&pitch_rad);
	pitch_rad.setName("Pitch");
	pitch_rad.setOptional(true);
	// Nothing to init


	system::Buffer *payloadBuffer = dynamic_cast<system::Buffer *>(message->getPayload());
	if(payloadBuffer)
	{
		this->from(payloadBuffer);
		payloadBuffer->reset();
	}
}

ReportGlobalVector::~ReportGlobalVector()
{

}


double ReportGlobalVector::getSpeed_mps(void)
{
	return this->speed_mps.getValue();
}

void ReportGlobalVector::setSpeed_mps(double value)
{
	this->speed_mps.setValue(value);
}

double ReportGlobalVector::getAltitude_m(void)
{
	return this->altitude_m.getValue();
}

void ReportGlobalVector::setAltitude_m(double value)
{
	this->altitude_m.setValue(value);
}

double ReportGlobalVector::getHeading_rad(void)
{
	return this->heading_rad.getValue();
}

void ReportGlobalVector::setHeading_rad(double value)
{
	this->heading_rad.setValue(value);
}

double ReportGlobalVector::getRoll_rad(void)
{
	return this->roll_rad.getValue();
}

void ReportGlobalVector::setRoll_rad(double value)
{
	this->roll_rad.setValue(value);
}

double ReportGlobalVector::getPitch_rad(void)
{
	return this->pitch_rad.getValue();
}

void ReportGlobalVector::setPitch_rad(double value)
{
	this->pitch_rad.setValue(value);
}

int ReportGlobalVector::to(system::Buffer *dst)
{
	int byteSize = dst->pack(this->id);
	byteSize += dst->pack(this->presenceVector);
	if(this->isSpeedEnabled())
	{
		byteSize += dst->pack(speed_mps);
	}
	if(this->isAltitudeEnabled())
	{
		byteSize += dst->pack(altitude_m);
	}
	if(this->isHeadingEnabled())
	{
		byteSize += dst->pack(heading_rad);
	}
	if(this->isRollEnabled())
	{
		byteSize += dst->pack(roll_rad);
	}
	if(this->isPitchEnabled())
	{
		byteSize += dst->pack(pitch_rad);
	}
	return byteSize;
}

int ReportGlobalVector::from(system::Buffer *src)
{
	int byteSize = src->unpack(this->id);
	byteSize += src->unpack(this->presenceVector);
	if(this->isSpeedEnabled())
	{
		byteSize += src->unpack(speed_mps);
	}
	if(this->isAltitudeEnabled())
	{
		byteSize += src->unpack(altitude_m);
	}
	if(this->isHeadingEnabled())
	{
		byteSize += src->unpack(heading_rad);
	}
	if(this->isRollEnabled())
	{
		byteSize += src->unpack(roll_rad);
	}
	if(this->isPitchEnabled())
	{
		byteSize += src->unpack(pitch_rad);
	}
	return byteSize;
}

int ReportGlobalVector::length(void)
{
	int length = 0;
	length += sizeof(uint16_t); // Message ID
	length += sizeof(uint8_t); // PresenceVector
	if(this->isSpeedEnabled())
	{
		length += speed_mps.length(); // speed_mps
	}
	if(this->isAltitudeEnabled())
	{
		length += altitude_m.length(); // altitude_m
	}
	if(this->isHeadingEnabled())
	{
		length += heading_rad.length(); // heading_rad
	}
	if(this->isRollEnabled())
	{
		length += roll_rad.length(); // roll_rad
	}
	if(this->isPitchEnabled())
	{
		length += pitch_rad.length(); // pitch_rad
	}
	return length;
}

std::string ReportGlobalVector::toXml(unsigned char level) const
{
	std::ostringstream prefix;
	for(unsigned char i = 0; i < level; i++)
	{
		prefix << "\t";
	}

	std::ostringstream oss;
	oss << prefix.str() << "<Message name=\"ReportGlobalVector\"";
	oss << " id=\"0x4407\" >\n";
	oss << prefix.str() << "\t" << "<PresenceVector size=\"uint8_t\">\n";
	oss << prefix.str() << "\t" << "\t" << "<value>0x" << std::hex << (uint64_t)this->getPresenceVector() << std::dec << "</value>\n";
	oss << prefix.str() << "\t" << "\t" << "<isSpeedEnabled value=\"" << std::boolalpha << this->isSpeedEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isAltitudeEnabled value=\"" << std::boolalpha << this->isAltitudeEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isHeadingEnabled value=\"" << std::boolalpha << this->isHeadingEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isRollEnabled value=\"" << std::boolalpha << this->isRollEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "\t" << "<isPitchEnabled value=\"" << std::boolalpha << this->isPitchEnabled() << "\"/>\n";
	oss << prefix.str() << "\t" << "</PresenceVector>\n";
	if(this->isSpeedEnabled())
	{
		oss << speed_mps.toXml(level+1); // speed_mps
	}
	if(this->isAltitudeEnabled())
	{
		oss << altitude_m.toXml(level+1); // altitude_m
	}
	if(this->isHeadingEnabled())
	{
		oss << heading_rad.toXml(level+1); // heading_rad
	}
	if(this->isRollEnabled())
	{
		oss << roll_rad.toXml(level+1); // roll_rad
	}
	if(this->isPitchEnabled())
	{
		oss << pitch_rad.toXml(level+1); // pitch_rad
	}
	oss << prefix.str() << "</Message>\n";
	return oss.str();
}

void ReportGlobalVector::setPresenceVector(uint8_t value)
{
	this->presenceVector = value;
}

uint8_t ReportGlobalVector::getPresenceVector(void) const
{
	return this->presenceVector;
}

bool ReportGlobalVector::isSpeedEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportGlobalVector::SPEED_MPS));
}

void ReportGlobalVector::enableSpeed(void)
{
	this->presenceVector |= 0x01 << ReportGlobalVector::SPEED_MPS;
}

void ReportGlobalVector::disableSpeed(void)
{
	this->presenceVector &= ~(0x01 << ReportGlobalVector::SPEED_MPS);
}

bool ReportGlobalVector::isAltitudeEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportGlobalVector::ALTITUDE_M));
}

void ReportGlobalVector::enableAltitude(void)
{
	this->presenceVector |= 0x01 << ReportGlobalVector::ALTITUDE_M;
}

void ReportGlobalVector::disableAltitude(void)
{
	this->presenceVector &= ~(0x01 << ReportGlobalVector::ALTITUDE_M);
}

bool ReportGlobalVector::isHeadingEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportGlobalVector::HEADING_RAD));
}

void ReportGlobalVector::enableHeading(void)
{
	this->presenceVector |= 0x01 << ReportGlobalVector::HEADING_RAD;
}

void ReportGlobalVector::disableHeading(void)
{
	this->presenceVector &= ~(0x01 << ReportGlobalVector::HEADING_RAD);
}

bool ReportGlobalVector::isRollEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportGlobalVector::ROLL_RAD));
}

void ReportGlobalVector::enableRoll(void)
{
	this->presenceVector |= 0x01 << ReportGlobalVector::ROLL_RAD;
}

void ReportGlobalVector::disableRoll(void)
{
	this->presenceVector &= ~(0x01 << ReportGlobalVector::ROLL_RAD);
}

bool ReportGlobalVector::isPitchEnabled(void) const
{
	return (this->presenceVector & (0x01 << ReportGlobalVector::PITCH_RAD));
}

void ReportGlobalVector::enablePitch(void)
{
	this->presenceVector |= 0x01 << ReportGlobalVector::PITCH_RAD;
}

void ReportGlobalVector::disablePitch(void)
{
	this->presenceVector &= ~(0x01 << ReportGlobalVector::PITCH_RAD);
}

} // namespace mobility
} // namespace openjaus


