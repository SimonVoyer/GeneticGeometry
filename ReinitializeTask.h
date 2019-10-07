//entête
#ifndef REINITIALIZE_TASK_H
#define REINITIALIZE_TASK_H

#include "Task.h"

class ReinitializeTask : public Task {
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void render() override;
};


#endif // !REINITIALIZE_TASK_H
