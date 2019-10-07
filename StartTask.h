#ifndef START_TASK_H
#define START_TASK_H

#include "Task.h"

class StartTask : public Task {
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void render() override;
};


#endif // !START_TASK_H
