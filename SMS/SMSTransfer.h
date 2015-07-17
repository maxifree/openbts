/*
* Copyright 2008 Free Software Foundation, Inc.
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



#ifndef SMS_TRANSFER_H
#define SMS_TRANSFER_H

#include <ostream>
#include <BitVector.h>
#include <GSMTransfer.h>

namespace SMS {

// GSM 4.11 8.2
class RLFrame : public GSM::L3Frame 
{	
	public:
	unsigned MTI() const { return peekField(5,3); }	
	unsigned reference() const { return peekField(8,8); }
	// GSM 4.11 7.3.4 for RP-ERROR fields 8.2.5.4 for RP-Cause.
	unsigned RPErrorCause() const { return size() >= 32 ? peekField(25,7) : 0; }	// Only valid for RP-Error message.
	
#if ORIGINAL
	RLFrame(SMSPrimitive wPrimitive=SMS_UNDEFINED_PRIMITIVE, size_t len=0)
		:L3Frame(GSM::L3_DATA,len), mPrimitive(wPrimitive)
	{ }

	RLFrame(const BitVector2& source, SMSPrimitive wPrimitive=SMS_UNDEFINED_PRIMITIVE)
		:L3Frame(source), mPrimitive(wPrimitive)
	{ }
#endif
	RLFrame(size_t bitsNeeded=0) :L3Frame(GSM::L3_DATA,bitsNeeded,GSM::SAPI3) { /*RLFrameInit();*/ }
	RLFrame(const BitVector2& source) :L3Frame(GSM::SAPI3,source) { /*RLFrameInit();*/ }
	void text(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const RLFrame& );


class TLFrame : public GSM::L3Frame 
{
	public:
	unsigned MTI() const { return peekField(6,2); }	
	
#if ORIGINAL
	TLFrame(SMSPrimitive wPrimitive=SMS_UNDEFINED_PRIMITIVE, size_t len=0)
		:L3Frame(GSM::L3_DATA,len), mPrimitive(wPrimitive)
	{ }

	TLFrame(const BitVector2& source, SMSPrimitive wPrimitive=SMS_UNDEFINED_PRIMITIVE)
		:L3Frame(source), mPrimitive(wPrimitive)
	{ }
#endif
	TLFrame(size_t bitsNeeded=0) :L3Frame(GSM::L3_DATA,bitsNeeded,GSM::SAPI3) { /*TLFrameInit();*/ }
	TLFrame(const BitVector2& source) :L3Frame(GSM::SAPI3,source) { /*TLFrameInit();*/ }

};


std::ostream& operator<<( std::ostream& os, const TLFrame& );

};  //namespace SMS {

#endif 
 
