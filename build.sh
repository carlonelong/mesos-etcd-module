mkdir -p build
cd build
MESOS_SRC_DIR="/root/mesos"
# ../configure --with-mesos=$MESOS_SRC_DIR CXXFLAGS="-I$MESOS_SRC_DIR/include -I$MESOS_SRC_DIR/lib/mesos/3rdparty/include -I$MESOS_SRC_DIR/lib/mesos/3rdparty/usr/local/include -I$MESOS_SRC_DIR/3rdparty/libprocess/include -I$MESOS_SRC_DIR/3rdparty/stout/include -I/root/mesos/build/3rdparty/picojson-1.3.0 -I/root/mesos/build/3rdparty/rapidjson-1.1.0/include -I/root/mesos/build/include -I/root/mesos/build/3rdparty/protobuf-3.5.0/src" LDFLAGS="-L$MESOS_SRC_DIR/build/src/.libs"
make
