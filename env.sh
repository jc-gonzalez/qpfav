export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/build/qslog.dir
export PATH=$PATH:$(pwd)/build/qpfav.dir
export CFG=$HOME/qpf/cfg/qpf-test-localhost.json
export IP=$(ifconfig |grep inet|grep netmask|grep -v "\.1 "|awk '{print $2;}')
