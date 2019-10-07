#ifndef CONTINUOUS_TASK_H
#define CONTINUOUS_TASK_H

#include "Task.h"

class ContinuousTask : public Task {
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void render() override;
	void process() override;
};


#endif // !CONTINUOUS_TASK_H
