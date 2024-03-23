#!/bin/bash
workspace_dir=`pwd`
build_path=${workspace_dir}/build

if [ ! -d ${build_path}  ];then
  mkdir -p ${build_path} 
fi

cd ${build_path} && cmake .. ; make -j8

