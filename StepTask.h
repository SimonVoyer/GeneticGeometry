#ifndef STEP_TASK_H
#define STEP_TASK_H

#include "Task.h"

class StepTask : public Task {
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void render() override;
};


#endif // !STEP_TASK_H
