#include "PacketsCtoS.h"

namespace game {
namespace net {
namespace data {
namespace CtoS {

uint8_t * HeadPack::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackFixed32Tag(buf, 1, _cmdtype);
  buf = ::ssu::Utils::PackFixed32Tag(buf, 2, _cmdlength);
  buf = ::ssu::Utils::PackFixed32Tag(buf, 3, _cliid);
  buf = ::ssu::Utils::PackFixed32Tag(buf, 4, _svrid);
  return buf;
}

bool HeadPack::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 5 || !::ssu::Utils::UnpackFixed32(buf, leftSize, _cmdtype)) return false;
      break;
     case 2:
      if(type_ != 5 || !::ssu::Utils::UnpackFixed32(buf, leftSize, _cmdlength)) return false;
      break;
     case 3:
      if(type_ != 5 || !::ssu::Utils::UnpackFixed32(buf, leftSize, _cliid)) return false;
      break;
     case 4:
      if(type_ != 5 || !::ssu::Utils::UnpackFixed32(buf, leftSize, _svrid)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t HeadPack::Size() const {
  return 1 + ::ssu::Utils::SizeFixed32(_cmdtype) + 1 + ::ssu::Utils::SizeFixed32(_cmdlength) + 1 + ::ssu::Utils::SizeFixed32(_cliid) + 1 + ::ssu::Utils::SizeFixed32(_svrid);
}

uint8_t * CSLogIn_0x01::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackStringTag(buf, 1, _username);
  buf = ::ssu::Utils::PackStringTag(buf, 2, _passwd);
  buf = ::ssu::Utils::PackInt32Tag(buf, 3, _testid);
  buf = ::ssu::Utils::PackUInt32Tag(buf, 4, _testuint);
  return buf;
}

bool CSLogIn_0x01::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
  uint32_t tag_; uint8_t type_;
  while(leftSize > 0) {
    if(!::ssu::Utils::UnpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_) {
     case 1:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _username)) return false;
      break;
     case 2:
      if(type_ != 2 || !::ssu::Utils::UnpackString(buf, leftSize, _passwd)) return false;
      break;
     case 3:
      if(type_ != 0 || !::ssu::Utils::UnpackInt32(buf, leftSize, _testid)) return false;
      break;
     case 4:
      if(type_ != 0 || !::ssu::Utils::UnpackUInt32(buf, leftSize, _testuint)) return false;
      break;
     default: break;
    }
  }
  return true;
}

size_t CSLogIn_0x01::Size() const {
  return 1 + ::ssu::Utils::SizeString(_username) + 1 + ::ssu::Utils::SizeString(_passwd) + 1 + ::ssu::Utils::SizeInt32(_testid) + 1 + ::ssu::Utils::SizeUInt32(_testuint);
}

}
}
}
}
