#include "PacketsStoC.h"

namespace game {
namespace net {
namespace data {
namespace StoC {

uint8_t * SCLogIn_0x01::PackBuffer(uint8_t * buf) {
  buf = ::ssu::Utils::PackStringTag(buf, 1, _username);
  buf = ::ssu::Utils::PackStringTag(buf, 2, _passwd);
  buf = ::ssu::Utils::PackInt32Tag(buf, 3, _testid);
  return buf;
}

bool SCLogIn_0x01::UnpackBuffer(const uint8_t *& buf, size_t& leftSize) {
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
     default: break;
    }
  }
  return true;
}

size_t SCLogIn_0x01::Size() const {
  return 1 + ::ssu::Utils::SizeString(_username) + 1 + ::ssu::Utils::SizeString(_passwd) + 1 + ::ssu::Utils::SizeInt32(_testid);
}

}
}
}
}
