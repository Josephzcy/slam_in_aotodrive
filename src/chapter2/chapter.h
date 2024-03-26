#ifndef CHAPTER_H_
#define CHAPTER_H_

#include<gflags/gflags.h>
#include<glog/logging.h>
#include "common/eigen_types.h"
#include "common/math_utils.h"

#include "utils/ui/pangolin_window.h"


class RQMotion {
 public:
  RQMotion();
  ~RQMotion() = default;
  void start();

 public:
  bool UpdateNavState();
  double angular_velocity_rad_{0.0f};

  double linear_velocity_{0.0f};
  bool use_quaternion_{false};
};
#endif