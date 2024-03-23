#!/bin/bash


#TODO::设置依赖库
workspace_dir=`pwd`
bin_path=${workspace_dir}/build/bin
lib_path=${workspace_dir}/build/lib
node_name="chapter_node"

export LD_LIBRARY_PATH=${workspace_dir}/3rdparty/g2o/lib:${lib_path}
if [ ! -d ${bin_path}  ];then
  echo "please build first"
  exit 1
fi

#TODO::运行应用程序
${bin_path}/${node_name} 1 2

