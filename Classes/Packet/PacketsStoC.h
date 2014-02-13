#ifndef _SSU_PACKETSSTOC_H_
#define _SSU_PACKETSSTOC_H_

#include <stdint.h>
#include "SsuObject.h"

namespace game {
namespace net {
namespace data {
namespace StoC {

class SCLogIn_0x01: public ::ssu::Object {
 public:
  inline SCLogIn_0x01(): _testid(0) { }

  virtual ~SCLogIn_0x01() { }

 public:
  virtual uint8_t * PackBuffer(uint8_t * buf);
  virtual bool UnpackBuffer(const uint8_t *& buf, size_t& leftSize);
  virtual size_t Size() const;

 public:
  inline const std::string& Username() const { return _username; }
  inline void SetUsername(const std::string& val__) { _username = val__; }
  inline std::string& MutableUsername() { return _username; }

  inline const std::string& Passwd() const { return _passwd; }
  inline void SetPasswd(const std::string& val__) { _passwd = val__; }
  inline std::string& MutablePasswd() { return _passwd; }

  inline int Testid() const { return _testid; }
  inline void SetTestid(int val__) { _testid = val__; }

 protected:
  std::string _username;
  std::string _passwd;
  int _testid;

};

}
}
}
}

#endif // _SSU_PACKETSSTOC_H_
