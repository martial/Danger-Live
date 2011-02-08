/*
 *  dgOscReceiver.cpp
 *  danger_live
 *
 *  Created by Martial Geoffre on 07/02/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "DgOscReceiver.h"

void DgOscReceiver::setup () {
	
	receiver.setup( OSC_PORT );
	cout << "listening for osc messages on port " << OSC_PORT << "\n";
	
	current_msg_string = 0;

}


void DgOscReceiver::update () {
	
	// hide old messages
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
	}
	
	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		
		// clean vector 
		
		/*
		for (int i=0; i<messages.size(); i++ ) {
			delete messages[i];
		}
		
		messages.clear();
		
		customOscMessage * msg = new customOscMessage();
		messages.push_back(msg);
		msg->address = m.getAddress();
		
		for ( int i=0; i<m.getNumArgs(); i++ )
		{
			if ( m.getArgType( i ) == OFXOSC_TYPE_STRING ) {
				msg->stringArgs.push_back(m.getArgAsString(i));
			}
		}
		
		*/
		
		
		
		
			/*
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ": ";
			for ( int i=0; i<m.getNumArgs(); i++ )
			{
				// get the argument type
				//msg_string += m.getArgTypeName( i );
				msg_string += ":";
				// display the argument - make sure we get the right type
				
				if ( m.getArgType( i ) == OFXOSC_TYPE_STRING ) {
					
				}
				
				
				if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
					
					
					msg_string += ofToString( m.getArgAsInt32( i ) );
				
				
				else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
					
					
					msg_string += ofToString( m.getArgAsFloat( i ) );
				
				else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
					
					msg_string += m.getArgAsString( i );
				else
					
					msg_string += "unknown";
			}
			// add to the list of strings to display
			msg_strings[current_msg_string] = msg_string;
			timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
			current_msg_string = ( current_msg_string + 1 ) % NUM_MSG_STRINGS;
			// clear the next line
			msg_strings[current_msg_string] = "";
			 */
		
	}
	
}

void DgOscReceiver::debugDraw () {
	
	ofSetColor(255, 0, 0);
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{	
		ofDrawBitmapString( msg_strings[i], 10, 400+15*i );
	}
	ofSetColor(255, 255, 255);
	
}
