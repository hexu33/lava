// Copyright (C) 2021 Intel Corporation
// SPDX-License-Identifier: BSD-3-Clause
// See: https://spdx.org/licenses/

#ifndef MULTIPROCESSING_H_
#define MULTIPROCESSING_H_

#include <vector>
#include <functional>

#include "abstract_actor.h"
#include "shm.h"

namespace message_infrastructure {

class MultiProcessing {
 public:
  MultiProcessing();
  int ForceStop();
  int BuildActor(std::function<void()>);
  void CheckActor();
  std::vector<ActorPtr>& GetActors();
  SharedMemManager* GetSharedMemManager();

 private:
  std::vector<ActorPtr> actors_;
  SharedMemManager *shmm_;
};

}  // namespace message_infrastructure

#endif  // MULTIPROCESSING_H_
