/**
\file PrimitiveEndEffector.cpp

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


#include "openjaus/manipulator/PrimitiveEndEffector.h"
// Start of user code for additional headers:
// End of user code

namespace openjaus
{
namespace manipulator
{

PrimitiveEndEffector::PrimitiveEndEffector() : Managed(),
	primitiveEndEffectorDefaultLoop(),
	primitiveEndEffectorControlledLoop()
{
	// Add Service Identification Data to implements list
	name = "PrimitiveEndEffector";
	
	model::Service *primitiveEndEffectorService = new model::Service();
	primitiveEndEffectorService->setName("PrimitiveEndEffector");
	primitiveEndEffectorService->setUri("urn:jaus:jss:manipulator:PrimitiveEndEffector");
	primitiveEndEffectorService->setVersionMajor(1);
	primitiveEndEffectorService->setVersionMinor(0);
	this->implements->push_back(primitiveEndEffectorService);
	
	

	primitiveEndEffectorDefaultLoop.setInterface(this);
	primitiveEndEffectorDefaultLoop.setTransportInterface(this);
	accessStateMachine.addDefaultStateTransition(primitiveEndEffectorDefaultLoop);
	
	primitiveEndEffectorControlledLoop.setInterface(this);
	primitiveEndEffectorControlledLoop.setTransportInterface(this);
	controlled.addTransition(primitiveEndEffectorControlledLoop);
	
    
    
	// Start of user code for Constructor:
	// End of user code
}

PrimitiveEndEffector::~PrimitiveEndEffector()
{
	// Start of user code for Destructor:
	// End of user code
}

bool PrimitiveEndEffector::setEndEffectorEffort(SetEndEffectorEffort *setEndEffectorEffort)
{
	// Start of user code for action setEndEffectorEffort(SetEndEffectorEffort *setEndEffectorEffort):
	return false;
	// End of user code
}

manipulator::ReportEndEffectorSpecification PrimitiveEndEffector::getReportEndEffectorSpecification(QueryEndEffectorSpecification *queryEndEffectorSpecification)
{
	// Start of user code for action getReportEndEffectorSpecification(QueryEndEffectorSpecification *queryEndEffectorSpecification):
	manipulator::ReportEndEffectorSpecification message;
	return message;
	// End of user code
}

manipulator::ReportEndEffectorEffort PrimitiveEndEffector::getReportEndEffectorEffort(QueryEndEffectorEffort *queryEndEffectorEffort)
{
	// Start of user code for action getReportEndEffectorEffort(QueryEndEffectorEffort *queryEndEffectorEffort):
	manipulator::ReportEndEffectorEffort message;
	return message;
	// End of user code
}


bool PrimitiveEndEffector::isControllingPrimitiveEndEffectorClient(SetEndEffectorEffort *setEndEffectorEffort)
{
	// Start of user code for action isControllingPrimitiveEndEffectorClient(SetEndEffectorEffort *setEndEffectorEffort):
	return false;
	// End of user code
}


// Start of user code for additional methods
// End of user code

} // namespace component
} // namespace openjaus

