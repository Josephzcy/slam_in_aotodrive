
#include "chapter.h"

#include <iostream>
int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_stderrthreshold = google::INFO;
  FLAGS_colorlogtostderr = true;
  google::ParseCommandLineFlags(&argc, &argv, true);

  std::cout << "chaptet2 hello world" << std::endl;
  if (argc > 1) {
    for (auto i = 1; i < argc; i++) {
      std::cout << argv[i] << std::endl;
    }
  }

  RQMotion rq_motion;
  rq_motion.start();

  return 0;
}