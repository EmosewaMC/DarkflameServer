#pragma once

#include "Amf3.h"
#include "BitStream.h"

/**
 * A class that implements native writing of AMF values to RakNet::BitStream
 */

namespace RakNet {
	//! Writes an AMFValue pointer to a RakNet::BitStream
	/**
	 * @param value The value to write
	 */
	template <>
	void RakNet::BitStream::Write<AMFValue*>(AMFValue* value);

	template<>
	void RakNet::BitStream::Write<AMFIntegerValue*>(AMFIntegerValue* value);

	template <>
	void RakNet::BitStream::Write<AMFDoubleValue*>(AMFDoubleValue* value);

	template <>
	void RakNet::BitStream::Write<AMFStringValue*>(AMFStringValue* value);

	template <>
	void RakNet::BitStream::Write<AMFArrayValue*>(AMFArrayValue* value);
} // namespace RakNet
