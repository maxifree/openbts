/**@file Idle-mode dispatcher for dedicated control channels. */

/*
* Copyright 2008, 2009 Free Software Foundation, Inc.
* Copyright 2011, 2014 Range Networks, Inc.
*
* This software is distributed under multiple licenses;
* see the COPYING file in the main directory for licensing
* information for this specific distribution.
*
* This use of this software may be subject to additional restrictions.
* See the LEGAL file in the main directory for details.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/


#define LOG_GROUP LogGroup::Control


#include "ControlCommon.h"
//#include "L3CallControl.h"
#include "L3MobilityManagement.h"
#include "L3StateMachine.h"
#include "L3LogicalChannel.h"
#include <GSMConfig.h>

#include <Logger.h>
#undef WARNING
#include <Reporting.h>
#include <Globals.h>

using namespace std;
using namespace GSM;
using namespace Control;




/** Example of a closed-loop, persistent-thread control function for the DCCH. */
// (pat) DCCH is a TCHFACCHLogicalChannel or SDCCHLogicalChannel
void Control::DCCHDispatcher(L3LogicalChannel *DCCH)
{
	while (! gBTS.btsShutdown()) {
		// This 'try' is redundant, but we are ultra-cautious here since a mistake means a crash.
		try {
			// Wait for a transaction to start.
			LOG(DEBUG);
			LOG(DEBUG) << "waiting for " << *DCCH << " ESTABLISH or HANDOVER_ACCESS";
			L3Frame *frame = DCCH->waitForEstablishOrHandover();
			LOG(DEBUG) << *DCCH << " received " << *frame;
			gResetWatchdog();
			L3DCCHLoop(DCCH,frame); // This will not return until the channel is released.
		}
		catch (...) {
			LOG(ERR) << "channel killed by unexpected exception ";
		}
	}
}




// vim: ts=4 sw=4
