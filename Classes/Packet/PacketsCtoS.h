#ifndef _SSU_PACKETSCTOS_H_
#define _SSU_PACKETSCTOS_H_

#include <stdint.h>
#include "SsuObject.h"

namespace game {
namespace net {
namespace data {
namespace CtoS {

class HeadPack: public ::ssu::Object {
 public:
  inline HeadPack(): _cmdtype(0), _cmdlength(0), _cliid(0), _svrid(0) { }

  virtual ~HeadPack() { }

 public:
  virtual uint8_t * PackBuffer(uint8_t * buf);
  virtual bool UnpackBuffer(const uint8_t *& buf, size_t& leftSize);
  virtual size_t Size() const;

 public:
  inline int Cmdtype() const { return _cmdtype; }
  inline void SetCmdtype(int val__) { _cmdtype = val__; }

  inline int Cmdlength() const { return _cmdlength; }
  inline void SetCmdlength(int val__) { _cmdlength = val__; }

  inline int Cliid() const { return _cliid; }
  inline void SetCliid(int val__) { _cliid = val__; }

  inline int Svrid() const { return _svrid; }
  inline void SetSvrid(int val__) { _svrid = val__; }

 protected:
  int _cmdtype;
  int _cmdlength;
  int _cliid;
  int _svrid;

};

class CSLogIn_0x01: public ::ssu::Object {
 public:
  inline CSLogIn_0x01(): _testid(0), _testuint(0) { }

  virtual ~CSLogIn_0x01() { }

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

  inline uint32_t Testuint() const { return _testuint; }
  inline void SetTestuint(uint32_t val__) { _testuint = val__; }

 protected:
  std::string _username;
  std::string _passwd;
  int _testid;
  uint32_t _testuint;

};

}
}
}
}

#endif // _SSU_PACKETSCTOS_H_
