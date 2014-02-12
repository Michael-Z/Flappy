#ifndef _WORKER_TCP_H_
#define _WORKER_TCP_H_

#include "Base.h"
#include "Classes/TcpNetwork/TcpNet.h"
namespace Worker
{
 class Tcp: public SimpleBase
 {
 public:
	 Tcp();
	 virtual ~Tcp();

	 bool addTimer(int, UInt32, UInt32 = 0, void * = NULL);
	 bool delTimer(int);
	 inline void initTcpInfo(const char *str, UInt16 port) { _serverIp = str; _serverPort = port; }
 protected:
	 virtual bool init();
	 virtual void uninit();
	 virtual void loop();
	 virtual void onTimer(int, void *) {}
 private:
	 bool _running;
	 std::string _serverIp;
	 UInt16 _serverPort;
	 TcpNetWork::TcpNet *_tcpnet;
 };
extern Tcp tcp;

}

#endif // _WORKER_TCP_H_
