#ifndef __MESOS_ETCD_CLIENT_HPP__
#define __MESOS_ETCD_CLIENT_HPP__

#include <string>

#include <stout/error.hpp>
#include <stout/option.hpp>
#include <stout/strings.hpp>
#include <stout/try.hpp>

#include "url.hpp"

namespace etcd {
class EtcdClientProcess;

class Node
{
public:
  Node(){}
  static Try<Node*> parse(const JSON::Object& object);
  Option<std::string> key; 
  Option<std::string> value; 
  Option<long unsigned int> createdIndex; 
  Option<long unsigned int> modifiedIndex; 
  Option<Node*> previous; 
  Option<JSON::String> expiration; 
  Option<Duration> ttl; 
  //FIXME: xxx
  void reset(const Node* node){}
  ~Node(){}
};

class Response
{
public:
  Response(){}
  Option<std::string> action; 
  Option<Node> node; 
  Option<uint64_t> index; 
  Option<int> errorCode; 
  Option<std::string> message; 
  Option<std::string> cause; 
  ~Response(){}
  static Try<Response> parse(const Try<JSON::Object>& object);
};

class EtcdClient
{
public:
  EtcdClient(const URL& url, const Option<Duration>& defaultTTL = None());

  process::Future<Option<Node>> get();

  process::Future<Option<Node>> create(
    const Option<std::string>& key,
    const Option<std::string>& value,
    const Option<Duration>& ttl,
    const Option<bool> prevExist = None(),
    const Option<uint64_t>& prevIndex = None(),
    const Option<std::string>& prevValue = None(),
    const Option<bool> refresh = None());

  process::Future<Option<Node>> watch(
    const Option<uint64_t>& waitIndex,
    const Option<std::string>& key = None() ,
    const Option<bool> recursive = None());

  ~EtcdClient(){}
private:
  EtcdClientProcess* process;

}; // class EtcdClient 

} // namespace etcd

#endif // __MESOS_ETCD_CLIENT_HPP__

