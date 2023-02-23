#include "Amf3_BitStream.h"

#include "Game.h"
#include "dLogger.h"

// Writes an AMFValue pointer to a RakNet::BitStream
template<>
void RakNet::BitStream::Write<AMFValue*>(AMFValue* value) {
	if (value != nullptr) {
		eAmf type = value->GetValueType();

		switch (type) {
			// These 4 just need to write their marker
		case eAmf::Undefined:
		case eAmf::Null:
		case eAmf::False:
		case eAmf::True:
			this->Write(value->GetValueType());
			break;
		case eAmf::Integer:
			this->Write(dynamic_cast<AMFIntegerValue*>(value));
			break;

		case eAmf::Double:
			this->Write(dynamic_cast<AMFDoubleValue*>(value));
			break;

		case eAmf::String:
			this->Write(dynamic_cast<AMFStringValue*>(value));
			break;

		case eAmf::Array:
			this->Write(dynamic_cast<AMFArrayValue*>(value));
			break;

		default: {
			Game::logger->Log("Amf3_BitStream", "Encountered unwritable AMFType %i!", type);
		}
		}
	}
}

/**
 * A private function to write an value to a RakNet::BitStream
 * RakNet writes in the correct byte order - do not reverse this.
 */
void WriteUInt29(RakNet::BitStream* bs, uint32_t v) {
	unsigned char b4 = (unsigned char)v;
	if (v < 0x00200000) {
		b4 = b4 & 0x7F;
		if (v > 0x7F) {
			unsigned char b3;
			v = v >> 7;
			b3 = ((unsigned char)(v)) | 0x80;
			if (v > 0x7F) {
				unsigned char b2;
				v = v >> 7;
				b2 = ((unsigned char)(v)) | 0x80;
				bs->Write(b2);
			}

			bs->Write(b3);
		}
	} else {
		unsigned char b1;
		unsigned char b2;
		unsigned char b3;

		v = v >> 8;
		b3 = ((unsigned char)(v)) | 0x80;
		v = v >> 7;
		b2 = ((unsigned char)(v)) | 0x80;
		v = v >> 7;
		b1 = ((unsigned char)(v)) | 0x80;

		bs->Write(b1);
		bs->Write(b2);
		bs->Write(b3);
	}

	bs->Write(b4);
}

/**
 * Writes a flag number to a RakNet::BitStream
 * RakNet writes in the correct byte order - do not reverse this.
 */
void WriteFlagNumber(RakNet::BitStream* bs, uint32_t v) {
	v = (v << 1) | 0x01;
	WriteUInt29(bs, v);
}

/**
 * Writes an AMFString to a RakNet::BitStream
 *
 * RakNet writes in the correct byte order - do not reverse this.
 */
void WriteAmfString(RakNet::BitStream* bs, const std::string& str) {
	WriteFlagNumber(bs, (uint32_t)str.size());
	bs->Write(str.c_str(), (uint32_t)str.size());
}

// Writes an AMFIntegerValue to BitStream
template<>
void RakNet::BitStream::Write<AMFIntegerValue*>(AMFIntegerValue* value) {
	this->Write(value->GetValueType());
	WriteUInt29(this, value->GetValue());
}

// Writes an AMFDoubleValue to BitStream
template<>
void RakNet::BitStream::Write<AMFDoubleValue*>(AMFDoubleValue* value) {
	this->Write(value->GetValueType());
	double d = value->GetValue();
	this->Write<uint64_t>(*((unsigned long long*) & d));
}

// Writes an AMFStringValue to BitStream
template<>
void RakNet::BitStream::Write<AMFStringValue*>(AMFStringValue* value) {
	this->Write(value->GetValueType());
	WriteAmfString(this, value->GetValue());
}

// Writes an AMFArrayValue to BitStream
template<>
void RakNet::BitStream::Write<AMFArrayValue*>(AMFArrayValue* value) {
	this->Write(value->GetValueType());
	uint32_t denseSize = value->GetDense().size();
	WriteFlagNumber(this, denseSize);

	auto associativeIterator = value->GetAssociative().begin();
	auto associativeEnd = value->GetAssociative().end();

	while (associativeIterator != associativeEnd) {
		WriteAmfString(this, associativeIterator->first); // TODO Use references to earlier strings in the amf to save BitStream data.
		this->Write(associativeIterator->second);
		associativeIterator++;
	}

	this->Write(eAmf::Null);

	auto denseIterator = value->GetDense().begin();
	auto denseEnd = value->GetDense().end();

	while (denseIterator != denseEnd) {
		this->Write(*denseIterator);
		denseIterator++;
	}
}
