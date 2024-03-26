#include "chapter.h"

#include <thread>
RQMotion::RQMotion() { angular_velocity_rad_ = 10.0f * sad::math::kDEG2RAD; }
void RQMotion::start() {
  use_quaternion_ = true;
  linear_velocity_ = 5.0;
  UpdateNavState();
}
bool RQMotion::UpdateNavState() {
  sad::ui::PangolinWindow ui;
  if (ui.Init() == false) {
    return false;
  }
  Vec3d v_body(linear_velocity_, 0, 0);  // body frame
  SE3 pose;

  // LOG(INFO)<< "se3 pose:"<< pose.so3() << std::endl;
  Vec3d v_world = pose.so3() * v_body;
  Vec3d omega(0, 0, angular_velocity_rad_);  // world frame
  double dt = 0.05;
  while (true) {
    if (use_quaternion_) {
      Quatd q = pose.unit_quaternion() * Quatd(0, 0.5 * omega(0) * dt, 0.5 * omega(1) * dt, 0.5 * omega(2) * dt);
      q.normalize();
    } else {
      pose.so3() = pose.so3() * SO3::exp(omega);  //需要注意
    }
    LOG(INFO) << "pose:" << pose.translation().transpose() << std::endl;
    ui.UpdateNavState(sad::NavState(0, pose, v_world));
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}