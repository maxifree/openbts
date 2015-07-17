/*
* Copyright 2008, 2014 Free Software Foundation, Inc.
* Copyright 2014 Range Networks, Inc.
*

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

* This software is distributed under multiple licenses; see the COPYING file in the main directory for licensing information for this specific distribution.
*
* This use of this software may be subject to additional restrictions.
* See the LEGAL file in the main directory for details.
*/


#define LOG_GROUP LogGroup::SMS

#include <BitVector.h>
#include "SMSTransfer.h"
#include "SMSMessages.h"

using namespace std;
using namespace SMS;

void RLFrame::text(std::ostream& os) const
{
	if (size() >= 16) {
		os <<LOGVAR2("MTI",MTI());
		switch (MTI()) {
			case 0: case 1: os << " (RP-DATA)";
				try {
					// GSM 4.11 7.3.1
					size_t rp = 16;
					RPData rpdata;
					rpdata.parseBody(*this,rp);
					rpdata.text(os);
					//os << "RP-Originator=("; rpdata.mOriginator.text(os); os << ")";
					//os << "RP-Destination=("; rpdata.mDestination.text(os); os << ")";
					// The rpdata.mUserData.mTPDU is a TLFrame, which we must parse into one of the messages in GSM 3.40 9.2
					TLMessage *tlmsg = parseTPDU(rpdata.mUserData.mTPDU);
					if (tlmsg) {
						os << " TLMessage=(";
						tlmsg->text(os);
						os << ")";
						delete tlmsg;
					}
				} catch (...) {
					os << " (error parsing rp-data) ";
				}
				break;
			case 2: case 3: os << " (RP-ACK)"; break;
			case 4: case 5:
				os << " (RP-ERROR)";
				os << " cause="<<RPErrorCause();
				break;
			case 6: case 7: os << " (RP-SMMA)"; break;
		}
		os <<LOGVAR2("reference",reference());
	}

	os<<" data=(";
	hex(os);
	os<< ")";
}

ostream& SMS::operator<<(ostream& os, const RLFrame& msg)
{
	msg.text(os);
	return os;
}

ostream& SMS::operator<<(ostream& os, const TLFrame& msg)
{
	if (msg.size() >= 8) { os <<LOGVAR2("MTI",msg.MTI()); }
	os<<" data=(";
	msg.hex(os);
	os<< ")";
	return os;
}



