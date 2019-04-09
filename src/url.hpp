#ifndef __MESOS_ETCD_URL_HPP__
#define __MESOS_ETCD_URL_HPP__

#include <string>
#include <process/http.hpp>

#include <stout/error.hpp>
#include <stout/option.hpp>
#include <stout/strings.hpp>
#include <stout/try.hpp>

namespace etcd {

// Describes a etcd URL of the form:
//
//     etcd://servers/path
//
class URL
{
public:
  static Try<URL> parse(std::string url);

  static const char* scheme()
  {
    return "etcd://";
  }

  class Server {
  public:
    std::string host;
    uint16_t port;
    Server(std::string _ip, uint16_t _port):host(_ip), port(_port) {}
    ~Server(){}
  };
  std::vector<Server> servers;
  const std::string path;

private:
  // URL(const std::string& _servers,
  //     const std::string& _path)
  //   : servers(_servers),
  //     path(_path) {}
};

} // namespace etcd {

#endif // __MESOS_ETCD_URL_HPP__

